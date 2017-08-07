/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/common/gpu_structs.h $                                    */
/*                                                                        */
/* OpenPOWER OnChipController Project                                     */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* Licensed under the Apache License, Version 2.0 (the "License");        */
/* you may not use this file except in compliance with the License.       */
/* You may obtain a copy of the License at                                */
/*                                                                        */
/*     http://www.apache.org/licenses/LICENSE-2.0                         */
/*                                                                        */
/* Unless required by applicable law or agreed to in writing, software    */
/* distributed under the License is distributed on an "AS IS" BASIS,      */
/* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or        */
/* implied. See the License for the specific language governing           */
/* permissions and limitations under the License.                         */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */

/* This header file is used by both occ_405 and occ_gpe1.                 */
/* Contains common structures and globals.                                */

#ifndef _GPU_STRUCTS_H
#define _GPU_STRUCTS_H

#include "occ_util.h"
#include <gpe_export.h>
#include "gpe_err.h"

#define MAX_GPUS 3

#define GPU_RESET_REQ_MASTER        1
#define GPU_RESET_REQ_SLV           2
#define GPU_RESET_REQ_SLV_COMPLETE  3

typedef enum
{
    ID_GPU0 = 0x00,
    ID_GPU1 = 0x01,
    ID_GPU2 = 0x02,
    ID_ALL_GPUS = 0xFF
} GPU_ID;

typedef enum
{
    GPU_STATE_PRESENT = 0x00000001,
    GPU_STATE_FAILED  = 0x80000000,
} GPU_STATE;

// GPU Request Operations
typedef enum
{
    GPU_REQ_INIT                        = 0x01, // Init interrupt registers
    GPU_REQ_READ_CAPS_START             = 0x02, // Start reading capabilities
    GPU_REQ_READ_CAPS_STOP              = 0x03,
    GPU_REQ_READ_CAPS                   = 0x04,
    GPU_REQ_READ_TEMP_SIMPLE_START      = 0x05, // Start reading GPU information
    GPU_REQ_READ_TEMP_SIMPLE_STOP       = 0x06, // Read GPU temp register
    GPU_REQ_READ_TEMP_SIMPLE            = 0x07, // Start reading GPU temperature
    GPU_REQ_READ_TEMP_START             = 0x08, // Start reading GPU information
    GPU_REQ_READ_TEMP_STOP              = 0x09, // Read GPU temp register
    GPU_REQ_READ_TEMP                   = 0x0A, // Start reading GPU temperature
    GPU_REQ_READ_PWR_LIMIT_START        = 0x0B, // Start reading GPU information
    GPU_REQ_READ_PWR_LIMIT_STOP         = 0x0C, // Read GPU temp register
    GPU_REQ_READ_PWR_LIMIT              = 0x0D, // Start reading pwr limit
    GPU_REQ_RESET                       = 0x60, // Reset
} gpu_op_req_e;

// GPU arguments
typedef struct
{
  GpeErrorStruct error;
  uint8_t gpu_id;
  uint8_t operation;
  uint32_t data[MAX_GPUS];
} gpu_sm_args_t;


#endif // _GPU_STRUCTS_H

