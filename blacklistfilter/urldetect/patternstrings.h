/**
 * \file patternstrings.h
 * \brief  Contains pattern string for nemea configurator.
 * \author Erik Sabik, xsabik02@stud.fit.vutbr.cz
 * \date 2015
 */

/*
 * Copyright (C) 2015 CESNET
 *
 * LICENSE TERMS
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name of the Company nor the names of its contributors
 *    may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * ALTERNATIVELY, provided that this notice is retained in full, this
 * product may be distributed under the terms of the GNU General Public
 * License (GPL) version 2 or later, in which case the provisions
 * of the GPL apply INSTEAD OF those given above.
 *
 * This software is provided ``as is'', and any express or implied
 * warranties, including, but not limited to, the implied warranties of
 * merchantability and fitness for a particular purpose are disclaimed.
 * In no event shall the company or contributors be liable for any
 * direct, indirect, incidental, special, exemplary, or consequential
 * damages (including, but not limited to, procurement of substitute
 * goods or services; loss of use, data, or profits; or business
 * interruption) however caused and on any theory of liability, whether
 * in contract, strict liability, or tort (including negligence or
 * otherwise) arising in any way out of the use of this software, even
 * if advised of the possibility of such damage.
 *
 */


#ifndef _IPBLACKLISTFILTER_PATTERN_H
#define _IPBLACKLISTFILTER_PATTERN_H

/**
 * String specifying pattern structure with default values.
 */
static char const *MODULE_CONFIG_PATTERN_STRING =
"<?xml version=\"1.0\" encoding=\"UTF-8\"?>"
"<configuration>"
    "<struct name=\"main struct\">"
        "<element type=\"required\">"
            "<name>file</name>"
            "<type size=\"256\">string</type>"
            "<default-value>-</default-value>"
        "</element>"
        "<element type=\"optional\">"
            "<name>delay</name>"
            "<type>uint32_t</type>"
            "<default-value>300</default-value>"
        "</element>"
        "<element type=\"required\">"
            "<name>update_mode</name>"
            "<type size=\"16\">string</type>"
            "<default-value>0</default-value>"
        "</element>"
        "<element type=\"optional\">"
            "<name>line_max_len</name>"
            "<type>uint32_t</type>"
            "<default-value>1024</default-value>"
        "</element>"
        "<element type=\"optional\">"
            "<name>element_max_len</name>"
            "<type>uint32_t</type>"
            "<default-value>64</default-value>"
        "</element>"
        "<element type=\"optional\">"
            "<name>element_max_cnt</name>"
            "<type>uint32_t</type>"
            "<default-value>10000</default-value>"
        "</element>"
        "<array name=\"blacklist_arr\">"
            "<element type=\"required\">"
                "<name>blacklist_name</name>"
                "<type size=\"32\">string</type>"
                "<default-value>0</default-value>"
            "</element>"
        "</array>"
    "</struct>"
"</configuration>";


/**
 * String specifying pattern structure with default values.
 */
char const *BLD_CONFIG_PATTERN_STRING =
"<?xml version=\"1.0\" encoding=\"UTF-8\"?>"
"<configuration>"
    "<struct name=\"main struct\">"
        "<array name=\"blacklist_arr\">"
            "<struct>"
                "<element type=\"required\">"
                    "<name>id</name>"
                    "<type>uint64_t</type>"
                    "<default-value>0</default-value>"
                "</element>"
                "<element type=\"optional\">"
                    "<name>method</name>"
                    "<type size=\"16\">string</type>"
                    "<default-value>0</default-value>"
                "</element>"
                "<element type=\"required\">"
                    "<name>name</name>"
                    "<type size=\"64\">string</type>"
                    "<default-value>0</default-value>"
                "</element>"
                "<element type=\"required\">"
                    "<name>source</name>"
                    "<type size=\"256\">string</type>"
                    "<default-value>0</default-value>"
                "</element>"
                "<element type=\"required\">"
                    "<name>type</name>"
                    "<type size=\"32\">string</type>"
                    "<default-value>0</default-value>"
                "</element>"
                "<element type=\"required\">"
                    "<name>regex</name>"
                    "<type size=\"128\">string</type>"
                    "<default-value>0</default-value>"
                "</element>"
            "</struct>"
        "</array>"
    "</struct>"
"</configuration>";

#endif