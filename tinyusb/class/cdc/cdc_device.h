/**************************************************************************/
/*!
    @file     cdc_device.h
    @author   hathach (tinyusb.org)

    @section LICENSE

    Software License Agreement (BSD License)

    Copyright (c) 2013, hathach (tinyusb.org)
    All rights reserved.

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions are met:
    1. Redistributions of source code must retain the above copyright
    notice, this list of conditions and the following disclaimer.
    2. Redistributions in binary form must reproduce the above copyright
    notice, this list of conditions and the following disclaimer in the
    documentation and/or other materials provided with the distribution.
    3. Neither the name of the copyright holders nor the
    names of its contributors may be used to endorse or promote products
    derived from this software without specific prior written permission.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS ''AS IS'' AND ANY
    EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
    WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
    DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER BE LIABLE FOR ANY
    DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
    (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
    LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
    ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
    (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
    SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

    This file is part of the tinyusb stack.
*/
/**************************************************************************/

#ifndef _TUSB_CDC_DEVICE_H_
#define _TUSB_CDC_DEVICE_H_

#include "common/common.h"
#include "device/usbd.h"
#include "cdc.h"

#ifdef __cplusplus
 extern "C" {
#endif

/** \addtogroup CDC_Serial Serial
 *  @{
 *  \defgroup   CDC_Serial_Device Device
 *  @{ */

//--------------------------------------------------------------------+
// APPLICATION API
//--------------------------------------------------------------------+
bool     tud_cdc_connected(uint8_t coreid);
uint32_t tud_cdc_available(uint8_t coreid);

int      tud_cdc_read_char(uint8_t coreid);
uint32_t tud_cdc_read(uint8_t coreid, void* buffer, uint32_t bufsize);

uint32_t tud_cdc_write_char(uint8_t coreid, char ch);
uint32_t tud_cdc_write(uint8_t coreid, void const* buffer, uint32_t bufsize);


//--------------------------------------------------------------------+
// APPLICATION CALLBACK API
//--------------------------------------------------------------------+
//void tud_cdc_line_coding_changed_cb(uint8_t coreid, cdc_line_coding_t* p_line_coding);
void tud_cdc_rx_cb(uint8_t coreid);

//--------------------------------------------------------------------+
// USBD-CLASS DRIVER API
//--------------------------------------------------------------------+
#ifdef _TINY_USB_SOURCE_FILE_

void cdcd_init(void);
tusb_error_t cdcd_open(uint8_t coreid, tusb_descriptor_interface_t const * p_interface_desc, uint16_t *p_length);
tusb_error_t cdcd_control_request_subtask(uint8_t coreid, tusb_control_request_t const * p_request);
tusb_error_t cdcd_xfer_cb(endpoint_handle_t edpt_hdl, tusb_event_t event, uint32_t xferred_bytes);
void cdcd_close(uint8_t coreid);

void cdcd_sof(uint8_t coreid);

#endif

#ifdef __cplusplus
 }
#endif

#endif /* _TUSB_CDC_DEVICE_H_ */

/** @} */
/** @} */
