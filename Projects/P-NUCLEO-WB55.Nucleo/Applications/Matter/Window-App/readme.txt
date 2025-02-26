****
  @page Window_App
  @verbatim
  ******************************************************************************
  * @file    Matter/Window_App
  * @author  MCD Application Team
  * @brief   This file lists the modification done by STMicroelectronics on
  *          Matter for integration with STM32Cube solution.
  ******************************************************************************
  *
  * Copyright (c) 2019-2021 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  @endverbatim

### 12-Apr-2023 ###
========================

STM32WB-Matter-BLE-Thread example is based on Matter and behaves as a Matter accessory communicating over a 802.15.4 Thread network.
It can be paired into an existing matter network and can be controlled by this network.
The STM32WB55xx-Nucleo board running the window-covering application is capable 
of BLE and OpenThread activity at the same time.

@par Keywords

COAP,THREAD,BLE,Matter

@par Directory contents 

 
  Using Matter v1.0.0 SDK.
  

  - Matter/Window-App/STM32_WPAN/App/app_ble.h            Header for app_ble.c module
  - Matter/Window-App/Core/Core/Inc/app_common.h          Header for all modules with common definition
  - Matter/Window-App/Core/Core/Inc/app_conf.h            Parameters configuration file of the application
  - Matter/Window-App/Core/Core/Inc/app_entry.h           Parameters configuration file of the application
  - Matter/Window-App/STM32_WPAN/App/app_thread.h         Header for app_thread.c module
  - Matter/Window-App/STM32_WPAN/App/ble_conf.h           BLE Services configuration
  - Matter/Window-App/STM32_WPAN/App/ble_dbg_conf.h       BLE Traces configuration of the BLE services
  - Matter/Window-App/Core/Core/Inc/hw_conf.h             Configuration file of the HW
  - Matter/Window-App/Core/Inc/main.h                     Header for main.c module
  - Matter/Window-App/STM32_WPAN/App/p2p_server_app.h     Header for BLE P2P Server application
  - Matter/Window-App/Core/Inc/stm32wbxx_hal_conf.h       HAL configuration file
  - Matter/Window-App/Core/Inc/stm32wbxx_it.h             Interrupt handlers header file
  - Matter/Window-App/STM32_WPAN/App/app_ble.c            BLE Profile implementation
  - Matter/Window-App/STM32_WPAN/App/app_matter.c         Matter Profile implementation
  - Matter/Window-App/STM32_WPAN/app/app_thread.c         Thread application implementation
  - Matter/Window-App/STM32_WPAN/Target/hw_ipcc.c         IPCC Driver
  - Matter/Window-App/Core/Src/app_entry.cpp              Initialization of the application
  - Matter/Window-App/Core/Core/Src/stm32_lpm_if.c        Low Power Manager Interface
  - Matter/Window-App/Core/Core/Src/hw_timerserver.c      Timer Server based on RTC
  - Matter/Window-App/Core/Core/Src/hw_uart.c             UART Driver
  - Matter/Window-App/Core/Src/app_main.cpp               Main program
  - Matter/Window-App/STM32_WPAN/App/p2p_server_app.c     BLE P2P Server application implementation
  - Matter/Window-App/Core/Src/stm32wbxx_it.c             Interrupt handlers
  - Matter/Window-App/Core/Src/system_stm32wbxx.c         stm32wbxx system source file
  - Matter/Window-App/Core/Src/AppTask.cpp                Entry application source file for matter 
  - Matter/Window-App/Core/Src/ZclCallbacks.cpp           Cluster output source file for Matter 
  - Matter/Window-App/Core/Src/WindowCovering.cpp         Window Cluster callback handler
  - Matter/Window-App/Core/Src/freertos_port.c            Custom porting of FreeRTOS functionalities
  - Matter/Window-App/Core/Src/entropy_hardware_poll.c    Custom porting of entropy with MbedTLS
  - Matter/Window-App/Core/Inc/FreeRTOSConfig.h           FreeRTOS specific defines
  - Matter/Window-App/Core/Inc/mbedtls_user_config.h      MbedTLS specific defines
  - Matter/Window-App/Core/Inc/CHIPProjectConfig.h        Matter specific defines
  - Matter/Window-App/Core/Inc/AppEvent.h                 Window App event handler
  - Matter/Window-App/Core/Inc/AppTask.h                  Header for AppTask.cpp module
  
 
@par Hardware and Software environment

  - This example has been tested with an STMicroelectronics STM32WB55RG-Nucleo 
    board 
    
  - On STM32WB55RG-Nucleo, the jumpers must be configured as described
    in this section. Starting from the top left position up to the bottom 
    right position, the jumpers on the Board must be set as follows:

     CN11:    GND         [OFF]
     JP4:     VDDRF       [ON]
     JP6:     VC0         [ON]
     JP2:     +3V3        [ON] 
     JP1:     USB_STL     [ON]   All others [OFF]
     CN12:    GND         [OFF]
     CN7:     <All>       [OFF]
     JP3:     VDD_MCU     [ON]
     JP5:     GND         [OFF]  All others [ON]
     CN10:    <All>       [OFF]


@par How to use it ? 

This application requests having the stm32wb5x_BLE_Thread_ForMatter_fw.bin binary flashed on the Wireless Coprocessor.
If it is not the case, you need to use STM32CubeProgrammer to load the appropriate binary.
All available binaries are located under /Projects/STM32_Copro_Wireless_Binaries directory.
Refer to UM2237 to learn how to use/install STM32CubeProgrammer.
Refer to /Projects/STM32_Copro_Wireless_Binaries/ReleaseNote.html for the detailed procedure to load the proper
Wireless Coprocessor binary. 


Minimum requirements for the demo:
- 1 STM32WB5MM-DK board with Window-App firmware.
- 1 Openthread Border router available in the market or ChipTool application on Linux or RaspberryPi.
- 1 STM32WB55xx-Nucleo board running a Thread RCP connected to a Raspberry pi 4 (recommanded) via FTDI (if needed).


In order to make the program work, you must do the following: 
 - Connect each STM32WB55xx-Nucleo boards to your PC 
 - Open STM32CubdeIDE version 1.9.0 or above
 - Rebuild all files and load your image into target memory
 - Run the example
 
To get the traces in real time, you can connect an HyperTerminal to the STLink Virtual Com Port. 
    
 For the Cli control and for the traces, the UART must be configured as follows:
    - BaudRate = 115200 baud  
    - Word Length = 8 Bits 
    - Stop Bit = 1 bit
    - Parity = none
    - Flow control = none

**** START DEMO ****
By default, after a reset, the board will start both protocols BLE and OpenThread.
So you BLE activity and OpenThread activity can be done in parallel :

**** BLE ACTIVITY ****
The BLE activity demonstrates a Point-to-Point communication using BLE component. 
The Peripheral device (P2P Server) starts a fast advertising after reset for 30 seconds.


**** THREAD ACTIVITY ****
After reset, OpenThread is started and nodes tries to build up a Thread network or attach to a existing one


**** LED SUMMARY ****
LED Mapping :
- LED 1 Blue  : ON when the STM32WB55xx-Nucleo board is paired via BLE to an Android Smartphone, OFF otherwise.
- LED 2 Green : ON when the STM32WB55xx-Nucleo board is connected to a Thread network, OFF otherwise.


****  BUTTON SUMMARY ****
Button Mapping:
- SW1 1 : Press the button for at least 10 seconds to do a factory reset.
          Push the button the save the non-volatile memory after unpairing the device then power off the board.


Coprocessor firmware:
The Coprocessor firmware remains unchanged. It has been tested with the binary listed above.



 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */
 


 
	   
