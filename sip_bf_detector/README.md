# SIP Brute-Force Detector


## Table of Contents

* [Module description](#module-description)
* [How it works](#how-it-works)
* [Required data](#required-data)
* [How to use](#how-to-use)
* [Compilation and linking](#compilation-and-linking)


## <a name="module-description">Module description</a>

Module for detecting brute-force attacks on Session Initiation Protocol.
It analyses SIP response traffic and is capable of detecting distributed
brute-force attacks.


## <a name="how-it-works">How it works</a>

This module checks status codes of SIP servers and looks for
"401 Unauthorized" responses to Register requests.
Once the count of these responses for a certain user name exceeds a threshold,
alert is generated.

The alert itself is in JSON format. It contains vital information about the ongoing attack:

 - EventID: number unique for this alert
 - ObsoleteID: number of alert which is replaced by this alert
 - TargetIP: IP address of targeted server
 - SIPTo: name of targeted user
 - AttemptCount: total count of attempts to breach user's password
 - EventTime: time of first attack message received
 - CeaseTime: time of last attack message received
 - LinkBitField: indicator of particular monitoring probe
 - Protocol: TCP or UDP
 - Breach: flag signalizing, whether attack was successful
 - BreacherIP: IP of the attacker, who made successful attack
 - BreachTime: time of breach occurrence
 - Sources: array of attackers, contains:
    - SourceIP: IP address of attacker
    - AttemptCount: number of attack messages
    - EventTime: time of first attack message sent from this IP


There are 3 types of alerts:

 - Alert #1: number of attack messages exceeds given threshold
 - Alert #2: the user password is breached
 - Alert #3: when the attack is considered as ceased


## <a name="required-data">Required data</a>

This module is implemented on TRAP platform, so it receives data on
TRAP input interface in Unirec format.

Unirec fields required:

 - DST\_IP
 - SRC\_IP
 - LINK\_BIT\_FIELD
 - PROTOCOL
 - TIME\_FIRST
 - SIP\_MSG\_TYPE
 - SIP\_STATUS\_CODE
 - SIP\_CSEQ
 - SIP\_CALLING\_PARTY

All of Unirec fields mentioned above can be obtained from module flow meter launched with SIP plugin. (-p sip)

## <a name="how-to-use">How to use</a>

Since this module uses TRAP, input and output interfaces need to be specified.

Usage:

```
./sip_bf_detector -i <trap_interfaces> <Additional parameters>
```

Additional parameters:

    -a <num>		Number of unsuccessful authentication
                  attempts to consider this behaviour as
                  an attack (20 by default).

    -c <num>		Number of seconds between the checks on
                  ceased attacks (300 by default).

    -f <num>		Number of seconds after the last action to
                  consider attack as ceased (1800 by default).

    -s <num>		 Stop generating alerts of type #1 (-s 1) or
                  both alerts of type #1 and #2 (-s 2) (0 by default).

Example:

```
./sip_bf_detector -i "t:7500,f:~/sip_bf_alerts:w" -a 20 -c 300 -f 1800 -s 2
```

The example of use of this module above receives data in Unirec format on
TRAP tcp interface on port 7500 and uses TRAP file interface to store
generated alerts to the given file (~/sip\_bf\_alerts) in mode "w" (write).

Additional parameters ensure that:

 - 20 unsuccessful authentication attempts are considered as an attack (-a 20)

 - every 300 seconds (5 minutes) all ongoing attacks are checked whether they ceased or not (-c 300)

 - during every check, an attack is considered ceased if the last attack message was received
   more than 1800 seconds (30 minutes) from the currently processed message (-f 1800)

 - skip alerts #1 and #2, so only alerts of type #3 will be generated (-s 2)

## <a name="compilation-and-linking">Compilation and linking</a>

No special compilation parameters are needed. For linking add -ltrap -lunirec -lnemea-common
(the module must be compiled as a part of [NEMEA](https://github.com/CESNET/Nemea) repository or using installed libtrap-devel and unirec packages).

Doxygen documentation can be generated with `make doc` command.