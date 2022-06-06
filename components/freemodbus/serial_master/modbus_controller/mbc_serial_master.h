/* Copyright 2018 Espressif Systems (Shanghai) PTE LTD
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

//  mbc_serial_master.h Modbus controller serial master implementation header file

#ifndef _MODBUS_SERIAL_CONTROLLER_MASTER
#define _MODBUS_SERIAL_CONTROLLER_MASTER

#include <stdint.h>            // for standard int types definition
#include <stddef.h>            // for NULL and std defines
#include "soc/soc.h"           // for BITN definitions
#include "esp_err.h"           // for esp_err_t
#include "esp_modbus_common.h" // for common defines

/* Add-on to fix endianness issues */
// BigEndian 32bit swap
//   just swap the two 16 bit registers since the two bytes in each
//   register are already swapped (BigEndian) as per modbus standard.
#define __beswap_32(x) \
    (__extension__({ uint32_t __bsx = (x);					      \
        ((((__bsx) >> 16) & 0xffff) | (((__bsx) & 0xffff) << 16)); }))

/**
 * @brief Initialize Modbus controller and stack
 *
 * @param[out] handler handler(pointer) to master data structure
 * @return
 *     - ESP_OK   Success
 *     - ESP_ERR_NO_MEM Parameter error
 */
esp_err_t mbc_serial_master_create(void **handler);

#endif // _MODBUS_SERIAL_CONTROLLER_MASTER
