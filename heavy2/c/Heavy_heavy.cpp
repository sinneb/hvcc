/**
 * Copyright (c) 2020 Enzien Audio, Ltd.
 * 
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 * 
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions, and the following disclaimer.
 * 
 * 2. Redistributions in binary form must reproduce the phrase "powered by heavy",
 *    the heavy logo, and a hyperlink to https://enzienaudio.com, all in a visible
 *    form.
 * 
 *   2.1 If the Application is distributed in a store system (for example,
 *       the Apple "App Store" or "Google Play"), the phrase "powered by heavy"
 *       shall be included in the app description or the copyright text as well as
 *       the in the app itself. The heavy logo will shall be visible in the app
 *       itself as well.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * 
 */

#include "Heavy_heavy.hpp"

#define Context(_c) reinterpret_cast<Heavy_heavy *>(_c)



/*
 * C Functions
 */

extern "C" {
  HV_EXPORT HeavyContextInterface *hv_heavy_new(double sampleRate) {
    return new Heavy_heavy(sampleRate);
  }

  HV_EXPORT HeavyContextInterface *hv_heavy_new_with_options(double sampleRate,
      int poolKb, int inQueueKb, int outQueueKb) {
    return new Heavy_heavy(sampleRate, poolKb, inQueueKb, outQueueKb);
  }
} // extern "C"







/*
 * Class Functions
 */

Heavy_heavy::Heavy_heavy(double sampleRate, int poolKb, int inQueueKb, int outQueueKb)
    : HeavyContext(sampleRate, poolKb, inQueueKb, outQueueKb) {
  numBytes += sPhasor_k_init(&sPhasor_nbKLueSt, 440.0f, sampleRate);
  numBytes += sPhasor_init(&sPhasor_c1LE1bqk, sampleRate);
  numBytes += cVar_init_f(&cVar_wm0k0eHV, 0.0f);
  numBytes += cIf_init(&cIf_l00EpmoQ, true);
  numBytes += cVar_init_f(&cVar_nprlC36d, 1.0f);
  numBytes += cVar_init_f(&cVar_K2YEdK8E, 0.0f);
  numBytes += cVar_init_f(&cVar_X3j5GwCD, 0.0f);
  numBytes += cVar_init_f(&cVar_gPCB9kBf, 0.0f);
  numBytes += cVar_init_f(&cVar_y2fMMaLr, 0.0f);
  numBytes += cVar_init_f(&cVar_WG2ZkPFB, 0.0f);
  numBytes += sVarf_init(&sVarf_uNdCC1uH, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_Q68E5rhl, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_hBYzVXxf, 0.0f);
  numBytes += cIf_init(&cIf_MA4HqQ4N, false);
  numBytes += cVar_init_f(&cVar_jEbmU0Gy, 0.0f);
  numBytes += cVar_init_f(&cVar_50nyLCDV, 0.0f);
  numBytes += cVar_init_f(&cVar_Ijy5P9OV, 2000.0f);
  numBytes += cBinop_init(&cBinop_MftKKdqK, 0.0f); // __mul
  numBytes += cDelay_init(this, &cDelay_Z5EeZNk0, 0.0f);
  numBytes += cVar_init_f(&cVar_832r3Lyf, 0.0f);
  numBytes += cVar_init_f(&cVar_fmDjzPz8, 0.0f);
  
  // schedule a message to trigger all loadbangs via the __hv_init receiver
  scheduleMessageForReceiver(0xCE5CC65B, msg_initWithBang(HV_MESSAGE_ON_STACK(1), 0));
}

Heavy_heavy::~Heavy_heavy() {
  // nothing to free
}

HvTable *Heavy_heavy::getTableForHash(hv_uint32_t tableHash) {
  return nullptr;
}

void Heavy_heavy::scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) {
  switch (receiverHash) {
    case 0xCE5CC65B: { // __hv_init
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_iHAQG5a5_sendMessage);
      break;
    }
    case 0xA8BFDCCE: { // current
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_aOWFeScc_sendMessage);
      break;
    }
    case 0xD020B8D1: { // metrospeed
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_USnyxO9V_sendMessage);
      break;
    }
    case 0xFDE4431F: { // slider1
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_S0AA2Hpm_sendMessage);
      break;
    }
    default: return;
  }
}

int Heavy_heavy::getParameterInfo(int index, HvParameterInfo *info) {
  if (info != nullptr) {
    switch (index) {
      default: {
        info->name = "invalid parameter index";
        info->hash = 0;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 0.0f;
        info->defaultVal = 0.0f;
        break;
      }
    }
  }
  return 0;
}



/*
 * Send Function Implementations
 */


void Heavy_heavy::cBinop_UqMijgLr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_uNdCC1uH, m);
}

void Heavy_heavy::cCast_glQJI5DS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_jEbmU0Gy, 0, m, &cVar_jEbmU0Gy_sendMessage);
}

void Heavy_heavy::cVar_wm0k0eHV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_heavy::cMsg_YVuRZGVy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 440.0f);
  sVarf_onMessage(_c, &Context(_c)->sVarf_uNdCC1uH, m);
}

void Heavy_heavy::cCast_jbRFdUg1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_heavy::cCast_8Pa3Vand_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_K2YEdK8E, 0, m, &cVar_K2YEdK8E_sendMessage);
}

void Heavy_heavy::cCast_l5fj8c73_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_W9BoVtYY_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cSend_80Gu8lmP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_heavy::cSend_Ky5tiYB6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_S0AA2Hpm_sendMessage(_c, 0, m);
}

void Heavy_heavy::cIf_l00EpmoQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cVar_onMessage(_c, &Context(_c)->cVar_X3j5GwCD, 0, m, &cVar_X3j5GwCD_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cMsg_ph6bvFhj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 200.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_50nyLCDV, 0, m, &cVar_50nyLCDV_sendMessage);
}

void Heavy_heavy::cMsg_8uNSKwKA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1000.0f);
  cSend_k8SOELOT_sendMessage(_c, 0, m);
}

void Heavy_heavy::cMsg_2BVCWRV2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, -1.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_832r3Lyf, 0, m, &cVar_832r3Lyf_sendMessage);
}

void Heavy_heavy::cBinop_l9qgZ2NA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_nprlC36d, 1, m, &cVar_nprlC36d_sendMessage);
}

void Heavy_heavy::cVar_nprlC36d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_l9qgZ2NA_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_MA4HqQ4N, 1, m, &cIf_MA4HqQ4N_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_DyewxqHk_sendMessage);
}

void Heavy_heavy::cVar_K2YEdK8E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_jEbmU0Gy, 0, m, &cVar_jEbmU0Gy_sendMessage);
}

void Heavy_heavy::cCast_cKgHYDfh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_jbRFdUg1_sendMessage);
  cMsg_8uNSKwKA_sendMessage(_c, 0, m);
}

void Heavy_heavy::cSwitchcase_zcxB0LPx_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_cKgHYDfh_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_heavy::cVar_X3j5GwCD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_Ky5tiYB6_sendMessage(_c, 0, m);
}

void Heavy_heavy::cBinop_GR6yIOWQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_hBYzVXxf, 0, m, &cVar_hBYzVXxf_sendMessage);
}

void Heavy_heavy::cCast_0oxFPgSr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_RLjyhKAs_sendMessage);
  cMsg_lvu2B1sp_sendMessage(_c, 0, m);
}

void Heavy_heavy::cSwitchcase_AYR5NOcH_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_0oxFPgSr_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_heavy::cVar_gPCB9kBf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_80Gu8lmP_sendMessage(_c, 0, m);
}

void Heavy_heavy::cReceive_S0AA2Hpm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_UqMijgLr_sendMessage);
}

void Heavy_heavy::cBinop_DyewxqHk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_l00EpmoQ, 1, m, &cIf_l00EpmoQ_sendMessage);
}

void Heavy_heavy::cVar_y2fMMaLr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_rbr2QRbL_sendMessage(_c, 0, m);
}

void Heavy_heavy::cVar_WG2ZkPFB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_wm0k0eHV, 0, m, &cVar_wm0k0eHV_sendMessage);
  cSend_Z6qg46JT_sendMessage(_c, 0, m);
}

void Heavy_heavy::cSend_rbr2QRbL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_S0AA2Hpm_sendMessage(_c, 0, m);
}

void Heavy_heavy::cBinop_p1BiaD0f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_jEbmU0Gy, 1, m, &cVar_jEbmU0Gy_sendMessage);
}

void Heavy_heavy::cReceive_iHAQG5a5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_M8zNrtn8_sendMessage(_c, 0, m);
  cMsg_oZOukefY_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_Ijy5P9OV, 0, m, &cVar_Ijy5P9OV_sendMessage);
  cMsg_2BVCWRV2_sendMessage(_c, 0, m);
  cSwitchcase_W9BoVtYY_onMessage(_c, NULL, 0, m, NULL);
  cMsg_ph6bvFhj_sendMessage(_c, 0, m);
}

void Heavy_heavy::cMsg_0yEXEX2K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_EH58xvCJ_sendMessage);
}

void Heavy_heavy::cBinop_EH58xvCJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_Q68E5rhl, m);
}

void Heavy_heavy::cSystem_FBAvzBzl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_0yEXEX2K_sendMessage(_c, 0, m);
}

void Heavy_heavy::cMsg_M8zNrtn8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_FBAvzBzl_sendMessage);
}

void Heavy_heavy::cVar_hBYzVXxf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_WG2ZkPFB, 0, m, &cVar_WG2ZkPFB_sendMessage);
}

void Heavy_heavy::cIf_MA4HqQ4N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cVar_onMessage(_c, &Context(_c)->cVar_gPCB9kBf, 0, m, &cVar_gPCB9kBf_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSend_hi0B0UVz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_USnyxO9V_sendMessage(_c, 0, m);
}

void Heavy_heavy::cVar_jEbmU0Gy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_p1BiaD0f_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MOD_UNIPOLAR, 8.0f, 0, m, &cBinop_GR6yIOWQ_sendMessage);
}

void Heavy_heavy::cSend_k8SOELOT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_USnyxO9V_sendMessage(_c, 0, m);
}

void Heavy_heavy::cCast_P4LLYNos_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_heavy::cReceive_USnyxO9V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Ijy5P9OV, 0, m, &cVar_Ijy5P9OV_sendMessage);
}

void Heavy_heavy::cSend_Z6qg46JT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_aOWFeScc_sendMessage(_c, 0, m);
}

void Heavy_heavy::cMsg_lvu2B1sp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 200.0f);
  cSend_hi0B0UVz_sendMessage(_c, 0, m);
}

void Heavy_heavy::cVar_50nyLCDV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_MA4HqQ4N, 0, m, &cIf_MA4HqQ4N_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_l00EpmoQ, 0, m, &cIf_l00EpmoQ_sendMessage);
}

void Heavy_heavy::cCast_4R0SSzug_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_j7txEiCD_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Z5EeZNk0, 0, m, &cDelay_Z5EeZNk0_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_P4LLYNos_sendMessage);
}

void Heavy_heavy::cSwitchcase_W9BoVtYY_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_j7txEiCD_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_j7txEiCD_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_4R0SSzug_sendMessage);
      break;
    }
  }
}

void Heavy_heavy::cVar_Ijy5P9OV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MftKKdqK, HV_BINOP_MULTIPLY, 0, m, &cBinop_MftKKdqK_sendMessage);
}

void Heavy_heavy::cBinop_PLoCtKiN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Z5EeZNk0, 2, m, &cDelay_Z5EeZNk0_sendMessage);
}

void Heavy_heavy::cBinop_MftKKdqK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_PLoCtKiN_sendMessage);
}

void Heavy_heavy::cMsg_oZOukefY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_h5bUog1b_sendMessage);
}

void Heavy_heavy::cSystem_h5bUog1b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_BSWSksPW_sendMessage);
}

void Heavy_heavy::cMsg_j7txEiCD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_Z5EeZNk0, 0, m, &cDelay_Z5EeZNk0_sendMessage);
}

void Heavy_heavy::cDelay_Z5EeZNk0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Z5EeZNk0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Z5EeZNk0, 0, m, &cDelay_Z5EeZNk0_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_P4LLYNos_sendMessage);
}

void Heavy_heavy::cBinop_BSWSksPW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MftKKdqK, HV_BINOP_MULTIPLY, 1, m, &cBinop_MftKKdqK_sendMessage);
}

void Heavy_heavy::cCast_RLjyhKAs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_heavy::cVar_832r3Lyf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_heavy::cVar_fmDjzPz8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_y2fMMaLr, 0, m, &cVar_y2fMMaLr_sendMessage);
}

void Heavy_heavy::cReceive_aOWFeScc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_zcxB0LPx_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_AYR5NOcH_onMessage(_c, NULL, 0, m, NULL);
}




/*
 * Context Process Implementation
 */

int Heavy_heavy::process(float **inputBuffers, float **outputBuffers, int n) {
  while (hLp_hasData(&inQueue)) {
    hv_uint32_t numBytes = 0;
    ReceiverMessagePair *p = reinterpret_cast<ReceiverMessagePair *>(hLp_getReadBuffer(&inQueue, &numBytes));
    hv_assert(numBytes >= sizeof(ReceiverMessagePair));
    scheduleMessageForReceiver(p->receiverHash, &p->msg);
    hLp_consume(&inQueue);
  }
  const int n4 = n & ~HV_N_SIMD_MASK; // ensure that the block size is a multiple of HV_N_SIMD

  // temporary signal vars
  hv_bufferf_t Bf0, Bf1, Bf2, Bf3, Bf4, Bf5, Bf6, Bf7;

  // input and output vars
  hv_bufferf_t O0, O1;

  // declare and init the zero buffer
  hv_bufferf_t ZERO; __hv_zero_f(VOf(ZERO));

  hv_uint32_t nextBlock = blockStartTimestamp;
  for (int n = 0; n < n4; n += HV_N_SIMD) {

    // process all of the messages for this block
    nextBlock += HV_N_SIMD;
    while (mq_hasMessageBefore(&mq, nextBlock)) {
      MessageNode *const node = mq_peek(&mq);
      node->sendMessage(this, node->let, node->m);
      mq_pop(&mq);
    }

    

    // zero output buffers
    __hv_zero_f(VOf(O0));
    __hv_zero_f(VOf(O1));

    // process all signal functions
    __hv_phasor_k_f(&sPhasor_nbKLueSt, VOf(Bf0));
    __hv_var_k_f(VOf(Bf1), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_abs_f(VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf0), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf1), 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f);
    __hv_mul_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_mul_f(VIf(Bf1), VIf(Bf1), VOf(Bf0));
    __hv_mul_f(VIf(Bf1), VIf(Bf0), VOf(Bf2));
    __hv_mul_f(VIf(Bf2), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf3), 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f);
    __hv_var_k_f(VOf(Bf4), -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f);
    __hv_fma_f(VIf(Bf2), VIf(Bf4), VIf(Bf1), VOf(Bf1));
    __hv_fma_f(VIf(Bf0), VIf(Bf3), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf3), 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f);
    __hv_mul_f(VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_add_f(VIf(Bf3), VIf(O0), VOf(O0));
    __hv_varread_f(&sVarf_uNdCC1uH, VOf(Bf3));
    __hv_phasor_f(&sPhasor_c1LE1bqk, VIf(Bf3), VOf(Bf1));
    __hv_add_f(VIf(Bf1), VIf(Bf1), VOf(Bf0));
    __hv_var_k_f(VOf(Bf4), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_sub_f(VIf(Bf0), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_Q68E5rhl, VOf(Bf0));
    __hv_mul_f(VIf(Bf3), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf3), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_div_f(VIf(Bf3), VIf(Bf0), VOf(Bf2));
    __hv_mul_f(VIf(Bf1), VIf(Bf2), VOf(Bf5));
    __hv_sub_f(VIf(Bf5), VIf(Bf3), VOf(Bf6));
    __hv_mul_f(VIf(Bf6), VIf(Bf6), VOf(Bf6));
    __hv_lte_f(VIf(Bf1), VIf(Bf0), VOf(Bf7));
    __hv_and_f(VIf(Bf6), VIf(Bf7), VOf(Bf7));
    __hv_sub_f(VIf(Bf2), VIf(Bf3), VOf(Bf2));
    __hv_sub_f(VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_mul_f(VIf(Bf2), VIf(Bf2), VOf(Bf2));
    __hv_sub_f(VIf(Bf3), VIf(Bf0), VOf(Bf0));
    __hv_gte_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_and_f(VIf(Bf2), VIf(Bf0), VOf(Bf0));
    __hv_sub_f(VIf(Bf7), VIf(Bf0), VOf(Bf0));
    __hv_add_f(VIf(Bf4), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf4), 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f);
    __hv_mul_f(VIf(Bf0), VIf(Bf4), VOf(Bf4));
    __hv_add_f(VIf(Bf4), VIf(O1), VOf(O1));

    // save output vars to output buffer
    __hv_store_f(outputBuffers[0]+n, VIf(O0));
    __hv_store_f(outputBuffers[1]+n, VIf(O1));
  }

  blockStartTimestamp = nextBlock;

  return n4; // return the number of frames processed
}

int Heavy_heavy::processInline(float *inputBuffers, float *outputBuffers, int n4) {
  hv_assert(!(n4 & HV_N_SIMD_MASK)); // ensure that n4 is a multiple of HV_N_SIMD

  // define the heavy input buffer for 0 channel(s)
  float **const bIn = NULL;

  // define the heavy output buffer for 2 channel(s)
  float **const bOut = reinterpret_cast<float **>(hv_alloca(2*sizeof(float *)));
  bOut[0] = outputBuffers+(0*n4);
  bOut[1] = outputBuffers+(1*n4);

  int n = process(bIn, bOut, n4);
  return n;
}

int Heavy_heavy::processInlineInterleaved(float *inputBuffers, float *outputBuffers, int n4) {
  hv_assert(n4 & ~HV_N_SIMD_MASK); // ensure that n4 is a multiple of HV_N_SIMD

  // define the heavy input buffer for 0 channel(s), uninterleave
  float *const bIn = NULL;

  // define the heavy output buffer for 2 channel(s)
  float *const bOut = reinterpret_cast<float *>(hv_alloca(2*n4*sizeof(float)));

  int n = processInline(bIn, bOut, n4);

  // interleave the heavy output into the output buffer
  #if HV_SIMD_AVX
  for (int i = 0, j = 0; j < n4; j += 8, i += 16) {
    __m256 x = _mm256_load_ps(bOut+j);    // LLLLLLLL
    __m256 y = _mm256_load_ps(bOut+n4+j); // RRRRRRRR
    __m256 a = _mm256_unpacklo_ps(x, y);  // LRLRLRLR
    __m256 b = _mm256_unpackhi_ps(x, y);  // LRLRLRLR
    _mm256_store_ps(outputBuffers+i, a);
    _mm256_store_ps(outputBuffers+8+i, b);
  }
  #elif HV_SIMD_SSE
  for (int i = 0, j = 0; j < n4; j += 4, i += 8) {
    __m128 x = _mm_load_ps(bOut+j);    // LLLL
    __m128 y = _mm_load_ps(bOut+n4+j); // RRRR
    __m128 a = _mm_unpacklo_ps(x, y);  // LRLR
    __m128 b = _mm_unpackhi_ps(x, y);  // LRLR
    _mm_store_ps(outputBuffers+i, a);
    _mm_store_ps(outputBuffers+4+i, b);
  }
  #elif HV_SIMD_NEON
  // https://community.arm.com/groups/processors/blog/2012/03/13/coding-for-neon--part-5-rearranging-vectors
  for (int i = 0, j = 0; j < n4; j += 4, i += 8) {
    float32x4_t x = vld1q_f32(bOut+j);
    float32x4_t y = vld1q_f32(bOut+n4+j);
    float32x4x2_t z = {x, y};
    vst2q_f32(outputBuffers+i, z); // interleave and store
  }
  #else // HV_SIMD_NONE
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < n4; ++j) {
      outputBuffers[i+2*j] = bOut[i*n4+j];
    }
  }
  #endif

  return n;
}
