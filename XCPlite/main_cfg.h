#pragma once
#define __MAIN_CFG_H__

// main_cfg.h
// XCPlite

/* Copyright(c) Vector Informatik GmbH.All rights reserved.
   Licensed under the MIT license.See LICENSE file in the project root for details. */


// Application configuration:
// XCP configuration is in xcp_cfg.h (Protocol Layer) and xcptl_cfg.h (Transport Layer)

/*
  XCP library build options:

  // Logging
  #define OPTION_ENABLE_DBG_PRINTS    Enable debug prints
  #define OPTION_DEFAULT_DBG_LEVEL  Default log level: 1 - Error, 2 - Warn, 3 - Info, 4 - Trace, 5 - Debug

  // Clock
  #define OPTION_CLOCK_EPOCH_ARB      Arbitrary epoch or since 1.1.1970
  #define OPTION_CLOCK_EPOCH_PTP      
  
  #define OPTION_CLOCK_TICKS_1NS      Resolution 1ns or 1us, granularity depends on platform
  #define OPTION_CLOCK_TICKS_1US

  // XCP  
  #define OPTION_ENABLE_TCP
  #define OPTION_ENABLE_UDP
  #define OPTION_MTU                  UDP MTU
  #define OPTION_QUEUE_SIZE           Size of the DAQ queue in XCP DTO/CRM packets (not messages as in V1.x) 
  #define OPTION_DAQ_MEM_SIZE         Size of memory for DAQ setup in bytes
  #define OPTION_ENABLE_A2L_UPLOAD    Enable GET_ID A2L upload
    
*/

// Ethernet Transport Layer
#define OPTION_ENABLE_UDP
//#define OPTION_ENABLE_TCP
#define OPTION_MTU                      1500            // Ethernet MTU
#define OPTION_SERVER_PORT              5555            // Default UDP port
#define OPTION_SERVER_ADDR              {127,0,0,1}     // IP addr to bind, 0.0.0.0 = ANY

#if defined(_LINUX) && !defined(_MACOS)
  #define XCP_SERVER_FORCEFULL_TERMINATION // @@@@
#endif

// Platform options
#define PLATFORM_ENABLE_GET_LOCAL_ADDR
#define PLATFORM_ENABLE_KEYBOARD

// Clock
#define OPTION_CLOCK_EPOCH_ARB
#define OPTION_CLOCK_TICKS_1NS // OPTION_CLOCK_TICKS_1NS or OPTION_CLOCK_TICKS_1US

// Enable demo how to create a calibration segment with page switching
// #define OPTION_ENABLE_CAL_SEGMENT 

// Enable A2L generation and upload
#define OPTION_ENABLE_A2L_GEN // Enable A2L generation
#define OPTION_ENABLE_A2L_UPLOAD
#ifdef OPTION_ENABLE_A2L_GEN
#define OPTION_A2L_NAME                 "XCPlite"     // A2L name 
#define OPTION_A2L_FILE_NAME            "XCPlite.a2l" // A2L filename 
#endif

// Debug prints
#define OPTION_ENABLE_DBG_PRINTS        
#define OPTION_DEFAULT_DBG_LEVEL 4 // 1 - Error, 2 - Warn, 3 - Info, 4 - Trace, 5 - Debug 


