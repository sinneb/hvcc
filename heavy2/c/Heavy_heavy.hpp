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

#ifndef _HEAVY_CONTEXT_HEAVY_HPP_
#define _HEAVY_CONTEXT_HEAVY_HPP_

// object includes
#include "HeavyContext.hpp"
#include "HvControlIf.h"
#include "HvControlBinop.h"
#include "HvControlVar.h"
#include "HvControlSystem.h"
#include "HvSignalVar.h"
#include "HvSignalPhasor.h"
#include "HvControlDelay.h"
#include "HvMath.h"
#include "HvControlCast.h"

class Heavy_heavy : public HeavyContext {

 public:
  Heavy_heavy(double sampleRate, int poolKb=10, int inQueueKb=2, int outQueueKb=0);
  ~Heavy_heavy();

  const char *getName() override { return "heavy"; }
  int getNumInputChannels() override { return 0; }
  int getNumOutputChannels() override { return 2; }

  int process(float **inputBuffers, float **outputBuffer, int n) override;
  int processInline(float *inputBuffers, float *outputBuffer, int n) override;
  int processInlineInterleaved(float *inputBuffers, float *outputBuffer, int n) override;

  int getParameterInfo(int index, HvParameterInfo *info) override;

 private:
  HvTable *getTableForHash(hv_uint32_t tableHash) override;
  void scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) override;

  // static sendMessage functions
  static void cBinop_UqMijgLr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_glQJI5DS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_wm0k0eHV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_YVuRZGVy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_jbRFdUg1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_8Pa3Vand_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_l5fj8c73_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_80Gu8lmP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_Ky5tiYB6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_l00EpmoQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_ph6bvFhj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_8uNSKwKA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_2BVCWRV2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_l9qgZ2NA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_nprlC36d_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_K2YEdK8E_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_cKgHYDfh_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_zcxB0LPx_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cVar_X3j5GwCD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_GR6yIOWQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_0oxFPgSr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_AYR5NOcH_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cVar_gPCB9kBf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_S0AA2Hpm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_DyewxqHk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_y2fMMaLr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_WG2ZkPFB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_rbr2QRbL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_p1BiaD0f_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_iHAQG5a5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_0yEXEX2K_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_EH58xvCJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_FBAvzBzl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_M8zNrtn8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_hBYzVXxf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_MA4HqQ4N_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_hi0B0UVz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_jEbmU0Gy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_k8SOELOT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_P4LLYNos_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_USnyxO9V_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_Z6qg46JT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_lvu2B1sp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_50nyLCDV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_4R0SSzug_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_W9BoVtYY_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cVar_Ijy5P9OV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_PLoCtKiN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_MftKKdqK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_oZOukefY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_h5bUog1b_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_j7txEiCD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_Z5EeZNk0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_BSWSksPW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_RLjyhKAs_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_832r3Lyf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_fmDjzPz8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_aOWFeScc_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  SignalPhasor sPhasor_nbKLueSt;
  SignalPhasor sPhasor_c1LE1bqk;
  ControlBinop cBinop_UqMijgLr;
  ControlVar cVar_wm0k0eHV;
  ControlIf cIf_l00EpmoQ;
  ControlBinop cBinop_l9qgZ2NA;
  ControlVar cVar_nprlC36d;
  ControlVar cVar_K2YEdK8E;
  ControlVar cVar_X3j5GwCD;
  ControlVar cVar_gPCB9kBf;
  ControlBinop cBinop_DyewxqHk;
  ControlVar cVar_y2fMMaLr;
  ControlVar cVar_WG2ZkPFB;
  ControlBinop cBinop_p1BiaD0f;
  SignalVarf sVarf_uNdCC1uH;
  SignalVarf sVarf_Q68E5rhl;
  ControlBinop cBinop_EH58xvCJ;
  ControlVar cVar_hBYzVXxf;
  ControlIf cIf_MA4HqQ4N;
  ControlVar cVar_jEbmU0Gy;
  ControlVar cVar_50nyLCDV;
  ControlVar cVar_Ijy5P9OV;
  ControlBinop cBinop_PLoCtKiN;
  ControlBinop cBinop_MftKKdqK;
  ControlDelay cDelay_Z5EeZNk0;
  ControlBinop cBinop_BSWSksPW;
  ControlVar cVar_832r3Lyf;
  ControlVar cVar_fmDjzPz8;
};

#endif // _HEAVY_CONTEXT_HEAVY_HPP_
