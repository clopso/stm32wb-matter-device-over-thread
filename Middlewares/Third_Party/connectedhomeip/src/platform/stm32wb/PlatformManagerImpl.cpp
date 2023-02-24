/*
 *
 *    Copyright (c) 2021 Project CHIP Authors
 *    All rights reserved.
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */

/**
 *    @file
 *          Stub for PlatformManagerImpl for fake platform.
 */
#include "main.h"


#include <platform/FreeRTOS/SystemTimeSupport.h>
#include <platform/internal/CHIPDeviceLayerInternal.h>

#include <platform/PlatformManager.h>

#include <platform/internal/GenericPlatformManagerImpl_FreeRTOS.cpp>
#include <platform/stm32wb/DiagnosticDataProviderImpl.h>
#include <platform/CommissionableDataProvider.h>
//#include <lwip/tcpip.h>


namespace chip {
namespace DeviceLayer {
namespace Internal {
CHIP_ERROR InitLwIPCoreLock(void);
}

/** Singleton instance of the KeyValueStoreManager implementation object.
 */
PlatformManagerImpl PlatformManagerImpl::sInstance;


CHIP_ERROR PlatformManagerImpl::_InitChipStack(void)
{
    System::Clock::InitClock_RealTime();
	ReturnErrorOnFailure(Internal::GenericPlatformManagerImpl_FreeRTOS<PlatformManagerImpl>::_InitChipStack());
	return CHIP_NO_ERROR;
}

void PlatformManagerImpl::_RunEventLoop(void)
{
	Internal::GenericPlatformManagerImpl_FreeRTOS<PlatformManagerImpl>::_RunEventLoop();
}

CHIP_ERROR PlatformManagerImpl::_Shutdown()
{
    return CHIP_ERROR_UNSUPPORTED_CHIP_FEATURE;
}

CHIP_ERROR PlatformManagerImpl::_GetCurrentHeapFree(uint64_t & currentHeapFree)
{

	return CHIP_NO_ERROR;
}

CHIP_ERROR PlatformManagerImpl::_GetCurrentHeapUsed(uint64_t & currentHeapUsed)
{

	return CHIP_NO_ERROR;
}

CHIP_ERROR PlatformManagerImpl::_GetCurrentHeapHighWatermark(uint64_t & currentHeapHighWatermark)
{

	return CHIP_NO_ERROR;
}

CHIP_ERROR PlatformManagerImpl::_GetTotalOperationalHours(uint32_t & totalOperationalHours)
{
    return CHIP_ERROR_UNSUPPORTED_CHIP_FEATURE;
}

CHIP_ERROR PlatformManagerImpl::_GetRebootCount(uint16_t & rebootCount)
{
    return CHIP_ERROR_UNSUPPORTED_CHIP_FEATURE;
}

CHIP_ERROR PlatformManagerImpl::_GetUpTime(uint64_t & upTime)
{
    return CHIP_ERROR_UNSUPPORTED_CHIP_FEATURE;
}

CHIP_ERROR PlatformManagerImpl::_GetBootReasons(uint8_t & bootReasons)
{
    return CHIP_ERROR_UNSUPPORTED_CHIP_FEATURE;
}

} // namespace DeviceLayer
} // namespace chip