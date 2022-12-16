/*
 * Copyright (c) 2015-2022, Renesas Electronics Corporation.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#define DDR_PHY_SLICE_REGSET_OFS_M3  0x0800
#define DDR_PHY_ADR_V_REGSET_OFS_M3  0x0a00
#define DDR_PHY_ADR_I_REGSET_OFS_M3  0x0a80
#define DDR_PHY_ADR_G_REGSET_OFS_M3  0x0b80
#define DDR_PI_REGSET_OFS_M3         0x0200

#define DDR_PHY_SLICE_REGSET_SIZE_M3 0x80
#define DDR_PHY_ADR_V_REGSET_SIZE_M3 0x80
#define DDR_PHY_ADR_I_REGSET_SIZE_M3 0x80
#define DDR_PHY_ADR_G_REGSET_SIZE_M3 0x80
#define DDR_PI_REGSET_SIZE_M3        0x100

#define DDR_PHY_SLICE_REGSET_NUM_M3  89
#define DDR_PHY_ADR_V_REGSET_NUM_M3  37
#define DDR_PHY_ADR_I_REGSET_NUM_M3  37
#define DDR_PHY_ADR_G_REGSET_NUM_M3  64
#define DDR_PI_REGSET_NUM_M3         202

static const uint32_t DDR_PHY_SLICE_REGSET_M3[DDR_PHY_SLICE_REGSET_NUM_M3] = {
	/*0800*/ 0x76543210,
	/*0801*/ 0x0004f008,
	/*0802*/ 0x00000000,
	/*0803*/ 0x00000000,
	/*0804*/ 0x00010000,
	/*0805*/ 0x036e6e0e,
	/*0806*/ 0x026e6e0e,
	/*0807*/ 0x00010300,
	/*0808*/ 0x04000100,
	/*0809*/ 0x00000300,
	/*080a*/ 0x001700c0,
	/*080b*/ 0x00b00201,
	/*080c*/ 0x00030020,
	/*080d*/ 0x00000000,
	/*080e*/ 0x00000000,
	/*080f*/ 0x00000000,
	/*0810*/ 0x00000000,
	/*0811*/ 0x00000000,
	/*0812*/ 0x00000000,
	/*0813*/ 0x00000000,
	/*0814*/ 0x09000000,
	/*0815*/ 0x04080000,
	/*0816*/ 0x04080400,
	/*0817*/ 0x00000000,
	/*0818*/ 0x32103210,
	/*0819*/ 0x00800708,
	/*081a*/ 0x000f000c,
	/*081b*/ 0x00000100,
	/*081c*/ 0x55aa55aa,
	/*081d*/ 0x33cc33cc,
	/*081e*/ 0x0ff00ff0,
	/*081f*/ 0x0f0ff0f0,
	/*0820*/ 0x00018e38,
	/*0821*/ 0x00000000,
	/*0822*/ 0x00000000,
	/*0823*/ 0x00000000,
	/*0824*/ 0x00000000,
	/*0825*/ 0x00000000,
	/*0826*/ 0x00000000,
	/*0827*/ 0x00000000,
	/*0828*/ 0x00000000,
	/*0829*/ 0x00000000,
	/*082a*/ 0x00000000,
	/*082b*/ 0x00000000,
	/*082c*/ 0x00000000,
	/*082d*/ 0x00000000,
	/*082e*/ 0x00000000,
	/*082f*/ 0x00000000,
	/*0830*/ 0x00000000,
	/*0831*/ 0x00000000,
	/*0832*/ 0x00000000,
	/*0833*/ 0x00200000,
	/*0834*/ 0x08200820,
	/*0835*/ 0x08200820,
	/*0836*/ 0x08200820,
	/*0837*/ 0x08200820,
	/*0838*/ 0x08200820,
	/*0839*/ 0x00000820,
	/*083a*/ 0x03000300,
	/*083b*/ 0x03000300,
	/*083c*/ 0x03000300,
	/*083d*/ 0x03000300,
	/*083e*/ 0x00000300,
	/*083f*/ 0x00000000,
	/*0840*/ 0x00000000,
	/*0841*/ 0x00000000,
	/*0842*/ 0x00000000,
	/*0843*/ 0x00a00000,
	/*0844*/ 0x00a000a0,
	/*0845*/ 0x00a000a0,
	/*0846*/ 0x00a000a0,
	/*0847*/ 0x00a000a0,
	/*0848*/ 0x00a000a0,
	/*0849*/ 0x00a000a0,
	/*084a*/ 0x00a000a0,
	/*084b*/ 0x00a000a0,
	/*084c*/ 0x010900a0,
	/*084d*/ 0x02000104,
	/*084e*/ 0x00000000,
	/*084f*/ 0x00010000,
	/*0850*/ 0x00000200,
	/*0851*/ 0x4041a151,
	/*0852*/ 0xc00141a0,
	/*0853*/ 0x0e0100c0,
	/*0854*/ 0x0010000c,
	/*0855*/ 0x0c064208,
	/*0856*/ 0x000f0c18,
	/*0857*/ 0x00e00140,
	/*0858*/ 0x00000c20
};

static const uint32_t DDR_PHY_ADR_V_REGSET_M3[DDR_PHY_ADR_V_REGSET_NUM_M3] = {
	/*0a00*/ 0x00000000,
	/*0a01*/ 0x00000000,
	/*0a02*/ 0x00000000,
	/*0a03*/ 0x00000000,
	/*0a04*/ 0x00000000,
	/*0a05*/ 0x00000000,
	/*0a06*/ 0x00000002,
	/*0a07*/ 0x00000000,
	/*0a08*/ 0x00000000,
	/*0a09*/ 0x00000000,
	/*0a0a*/ 0x00400320,
	/*0a0b*/ 0x00000040,
	/*0a0c*/ 0x00dcba98,
	/*0a0d*/ 0x00000000,
	/*0a0e*/ 0x00dcba98,
	/*0a0f*/ 0x01000000,
	/*0a10*/ 0x00020003,
	/*0a11*/ 0x00000000,
	/*0a12*/ 0x00000000,
	/*0a13*/ 0x00000000,
	/*0a14*/ 0x0000002a,
	/*0a15*/ 0x00000015,
	/*0a16*/ 0x00000015,
	/*0a17*/ 0x0000002a,
	/*0a18*/ 0x00000033,
	/*0a19*/ 0x0000000c,
	/*0a1a*/ 0x0000000c,
	/*0a1b*/ 0x00000033,
	/*0a1c*/ 0x0a418820,
	/*0a1d*/ 0x003f0000,
	/*0a1e*/ 0x0000003f,
	/*0a1f*/ 0x0002c06e,
	/*0a20*/ 0x02c002c0,
	/*0a21*/ 0x02c002c0,
	/*0a22*/ 0x000002c0,
	/*0a23*/ 0x42080010,
	/*0a24*/ 0x00000003
};

static const uint32_t DDR_PHY_ADR_I_REGSET_M3[DDR_PHY_ADR_I_REGSET_NUM_M3] = {
	/*0a80*/ 0x04040404,
	/*0a81*/ 0x00000404,
	/*0a82*/ 0x00000000,
	/*0a83*/ 0x00000000,
	/*0a84*/ 0x00000000,
	/*0a85*/ 0x00000000,
	/*0a86*/ 0x00000002,
	/*0a87*/ 0x00000000,
	/*0a88*/ 0x00000000,
	/*0a89*/ 0x00000000,
	/*0a8a*/ 0x00400320,
	/*0a8b*/ 0x00000040,
	/*0a8c*/ 0x00000000,
	/*0a8d*/ 0x00000000,
	/*0a8e*/ 0x00000000,
	/*0a8f*/ 0x01000000,
	/*0a90*/ 0x00020003,
	/*0a91*/ 0x00000000,
	/*0a92*/ 0x00000000,
	/*0a93*/ 0x00000000,
	/*0a94*/ 0x0000002a,
	/*0a95*/ 0x00000015,
	/*0a96*/ 0x00000015,
	/*0a97*/ 0x0000002a,
	/*0a98*/ 0x00000033,
	/*0a99*/ 0x0000000c,
	/*0a9a*/ 0x0000000c,
	/*0a9b*/ 0x00000033,
	/*0a9c*/ 0x00000000,
	/*0a9d*/ 0x00000000,
	/*0a9e*/ 0x00000000,
	/*0a9f*/ 0x0002c06e,
	/*0aa0*/ 0x02c002c0,
	/*0aa1*/ 0x02c002c0,
	/*0aa2*/ 0x000002c0,
	/*0aa3*/ 0x42080010,
	/*0aa4*/ 0x00000003
};

static const uint32_t DDR_PHY_ADR_G_REGSET_M3[DDR_PHY_ADR_G_REGSET_NUM_M3] = {
	/*0b80*/ 0x00000001,
	/*0b81*/ 0x00000000,
	/*0b82*/ 0x00000005,
	/*0b83*/ 0x04000f00,
	/*0b84*/ 0x00020080,
	/*0b85*/ 0x00020055,
	/*0b86*/ 0x00000000,
	/*0b87*/ 0x00000000,
	/*0b88*/ 0x00000000,
	/*0b89*/ 0x00000050,
	/*0b8a*/ 0x00000000,
	/*0b8b*/ 0x01010100,
	/*0b8c*/ 0x00000600,
	/*0b8d*/ 0x50640000,
	/*0b8e*/ 0x03421342,
	/*0b8f*/ 0x00000342,
	/*0b90*/ 0x00000000,
	/*0b91*/ 0x000f1600,
	/*0b92*/ 0x0f160f16,
	/*0b93*/ 0x0f160f16,
	/*0b94*/ 0x00000003,
	/*0b95*/ 0x0002c000,
	/*0b96*/ 0x02c002c0,
	/*0b97*/ 0x000002c0,
	/*0b98*/ 0x03421342,
	/*0b99*/ 0x00000342,
	/*0b9a*/ 0x00000000,
	/*0b9b*/ 0x00000000,
	/*0b9c*/ 0x05020000,
	/*0b9d*/ 0x00000000,
	/*0b9e*/ 0x00027f6e,
	/*0b9f*/ 0x047f027f,
	/*0ba0*/ 0x00027f6e,
	/*0ba1*/ 0x00047f6e,
	/*0ba2*/ 0x0003554f,
	/*0ba3*/ 0x0001554f,
	/*0ba4*/ 0x0001554f,
	/*0ba5*/ 0x0001554f,
	/*0ba6*/ 0x0001554f,
	/*0ba7*/ 0x00003fee,
	/*0ba8*/ 0x0001554f,
	/*0ba9*/ 0x00003fee,
	/*0baa*/ 0x0001554f,
	/*0bab*/ 0x00027f6e,
	/*0bac*/ 0x0001554f,
	/*0bad*/ 0x00000000,
	/*0bae*/ 0x00000000,
	/*0baf*/ 0x00000000,
	/*0bb0*/ 0x65000000,
	/*0bb1*/ 0x00000000,
	/*0bb2*/ 0x00000000,
	/*0bb3*/ 0x00000201,
	/*0bb4*/ 0x00000000,
	/*0bb5*/ 0x00000000,
	/*0bb6*/ 0x00000000,
	/*0bb7*/ 0x00000000,
	/*0bb8*/ 0x00000000,
	/*0bb9*/ 0x00000000,
	/*0bba*/ 0x00000000,
	/*0bbb*/ 0x00000000,
	/*0bbc*/ 0x06e40000,
	/*0bbd*/ 0x00000000,
	/*0bbe*/ 0x00000000,
	/*0bbf*/ 0x00010000
};

static const uint32_t DDR_PI_REGSET_M3[DDR_PI_REGSET_NUM_M3] = {
	/*0200*/ 0x00000b00,
	/*0201*/ 0x00000100,
	/*0202*/ 0x00000000,
	/*0203*/ 0x0000ffff,
	/*0204*/ 0x00000000,
	/*0205*/ 0x0000ffff,
	/*0206*/ 0x00000000,
	/*0207*/ 0x304cffff,
	/*0208*/ 0x00000200,
	/*0209*/ 0x00000200,
	/*020a*/ 0x00000200,
	/*020b*/ 0x00000200,
	/*020c*/ 0x0000304c,
	/*020d*/ 0x00000200,
	/*020e*/ 0x00000200,
	/*020f*/ 0x00000200,
	/*0210*/ 0x00000200,
	/*0211*/ 0x0000304c,
	/*0212*/ 0x00000200,
	/*0213*/ 0x00000200,
	/*0214*/ 0x00000200,
	/*0215*/ 0x00000200,
	/*0216*/ 0x00010000,
	/*0217*/ 0x00000003,
	/*0218*/ 0x01000001,
	/*0219*/ 0x00000000,
	/*021a*/ 0x00000000,
	/*021b*/ 0x00000000,
	/*021c*/ 0x00000000,
	/*021d*/ 0x00000000,
	/*021e*/ 0x00000000,
	/*021f*/ 0x00000000,
	/*0220*/ 0x00000000,
	/*0221*/ 0x00000000,
	/*0222*/ 0x00000000,
	/*0223*/ 0x00000000,
	/*0224*/ 0x00000000,
	/*0225*/ 0x00000000,
	/*0226*/ 0x00000000,
	/*0227*/ 0x00000000,
	/*0228*/ 0x00000000,
	/*0229*/ 0x0f000101,
	/*022a*/ 0x08492d25,
	/*022b*/ 0x0e0c0004,
	/*022c*/ 0x000e5000,
	/*022d*/ 0x00000250,
	/*022e*/ 0x00460003,
	/*022f*/ 0x182600cf,
	/*0230*/ 0x182600cf,
	/*0231*/ 0x00000005,
	/*0232*/ 0x00000000,
	/*0233*/ 0x00000000,
	/*0234*/ 0x00000000,
	/*0235*/ 0x00000000,
	/*0236*/ 0x00000000,
	/*0237*/ 0x00000000,
	/*0238*/ 0x00000000,
	/*0239*/ 0x01000000,
	/*023a*/ 0x00040404,
	/*023b*/ 0x01280a00,
	/*023c*/ 0x00000000,
	/*023d*/ 0x000f0000,
	/*023e*/ 0x00001803,
	/*023f*/ 0x00000000,
	/*0240*/ 0x00000000,
	/*0241*/ 0x00060002,
	/*0242*/ 0x00010001,
	/*0243*/ 0x01000101,
	/*0244*/ 0x04020201,
	/*0245*/ 0x00080804,
	/*0246*/ 0x00000000,
	/*0247*/ 0x08030000,
	/*0248*/ 0x15150408,
	/*0249*/ 0x00000000,
	/*024a*/ 0x00000000,
	/*024b*/ 0x00000000,
	/*024c*/ 0x000f0f00,
	/*024d*/ 0x0000001e,
	/*024e*/ 0x00000000,
	/*024f*/ 0x01000300,
	/*0250*/ 0x00000000,
	/*0251*/ 0x00000000,
	/*0252*/ 0x01000000,
	/*0253*/ 0x00010101,
	/*0254*/ 0x000e0e0e,
	/*0255*/ 0x000c0c0c,
	/*0256*/ 0x02060601,
	/*0257*/ 0x00000000,
	/*0258*/ 0x00000003,
	/*0259*/ 0x00181703,
	/*025a*/ 0x00280006,
	/*025b*/ 0x00280016,
	/*025c*/ 0x00000016,
	/*025d*/ 0x00000000,
	/*025e*/ 0x00000000,
	/*025f*/ 0x00000000,
	/*0260*/ 0x140a0000,
	/*0261*/ 0x0005010a,
	/*0262*/ 0x03018d03,
	/*0263*/ 0x000a018d,
	/*0264*/ 0x00060100,
	/*0265*/ 0x01000006,
	/*0266*/ 0x018e018e,
	/*0267*/ 0x018e0100,
	/*0268*/ 0x1111018e,
	/*0269*/ 0x10010204,
	/*026a*/ 0x09090650,
	/*026b*/ 0x20110202,
	/*026c*/ 0x00201000,
	/*026d*/ 0x00201000,
	/*026e*/ 0x04041000,
	/*026f*/ 0x18020100,
	/*0270*/ 0x00010118,
	/*0271*/ 0x004b004a,
	/*0272*/ 0x050f0000,
	/*0273*/ 0x0c01021e,
	/*0274*/ 0x34000000,
	/*0275*/ 0x00000000,
	/*0276*/ 0x00000000,
	/*0277*/ 0x00000000,
	/*0278*/ 0x0000d400,
	/*0279*/ 0x0031002e,
	/*027a*/ 0x00111136,
	/*027b*/ 0x002e00d4,
	/*027c*/ 0x11360031,
	/*027d*/ 0x0000d411,
	/*027e*/ 0x0031002e,
	/*027f*/ 0x00111136,
	/*0280*/ 0x002e00d4,
	/*0281*/ 0x11360031,
	/*0282*/ 0x0000d411,
	/*0283*/ 0x0031002e,
	/*0284*/ 0x00111136,
	/*0285*/ 0x002e00d4,
	/*0286*/ 0x11360031,
	/*0287*/ 0x00d40011,
	/*0288*/ 0x0031002e,
	/*0289*/ 0x00111136,
	/*028a*/ 0x002e00d4,
	/*028b*/ 0x11360031,
	/*028c*/ 0x0000d411,
	/*028d*/ 0x0031002e,
	/*028e*/ 0x00111136,
	/*028f*/ 0x002e00d4,
	/*0290*/ 0x11360031,
	/*0291*/ 0x0000d411,
	/*0292*/ 0x0031002e,
	/*0293*/ 0x00111136,
	/*0294*/ 0x002e00d4,
	/*0295*/ 0x11360031,
	/*0296*/ 0x02000011,
	/*0297*/ 0x018d018d,
	/*0298*/ 0x0c08018d,
	/*0299*/ 0x1f121d22,
	/*029a*/ 0x4301b344,
	/*029b*/ 0x10172006,
	/*029c*/ 0x1d220c10,
	/*029d*/ 0x00001f12,
	/*029e*/ 0x4301b344,
	/*029f*/ 0x10172006,
	/*02a0*/ 0x1d220c10,
	/*02a1*/ 0x00001f12,
	/*02a2*/ 0x4301b344,
	/*02a3*/ 0x10172006,
	/*02a4*/ 0x02000210,
	/*02a5*/ 0x02000200,
	/*02a6*/ 0x02000200,
	/*02a7*/ 0x02000200,
	/*02a8*/ 0x02000200,
	/*02a9*/ 0x00000000,
	/*02aa*/ 0x00000000,
	/*02ab*/ 0x00000000,
	/*02ac*/ 0x00000000,
	/*02ad*/ 0x00000000,
	/*02ae*/ 0x00000000,
	/*02af*/ 0x00000000,
	/*02b0*/ 0x00000000,
	/*02b1*/ 0x00000000,
	/*02b2*/ 0x00000000,
	/*02b3*/ 0x00000000,
	/*02b4*/ 0x00000000,
	/*02b5*/ 0x00000400,
	/*02b6*/ 0x15141312,
	/*02b7*/ 0x11100f0e,
	/*02b8*/ 0x080b0c0d,
	/*02b9*/ 0x05040a09,
	/*02ba*/ 0x01000706,
	/*02bb*/ 0x00000302,
	/*02bc*/ 0x01030201,
	/*02bd*/ 0x00304c00,
	/*02be*/ 0x0001e2f8,
	/*02bf*/ 0x0000304c,
	/*02c0*/ 0x0001e2f8,
	/*02c1*/ 0x0000304c,
	/*02c2*/ 0x0001e2f8,
	/*02c3*/ 0x08000000,
	/*02c4*/ 0x00000100,
	/*02c5*/ 0x00000000,
	/*02c6*/ 0x00000000,
	/*02c7*/ 0x00000000,
	/*02c8*/ 0x00000000,
	/*02c9*/ 0x00000002
};
