#ifndef VPEOPLECOUNTAPI_H
#define VPEOPLECOUNTAPI_H

#include "Vztypes.h"

/**
* @file VzPeopleCountAPI.h
* @brief Vzense API header file.
* Copyright (c) 2018-2019 Vzense Interactive, Inc.
*/

/*! \mainpage Vzense API Documentation
*
* \section intro_sec Introduction
*
* Welcome to the Vzense API documentation. This documentation enables you to quickly get started in your development efforts to programmatically interact with CSI100.
*/

/**
* @brief 		Initializes the API on the device. This function must be invoked before any other Vzense APIs.
* @return		::PsRetOK if the function succeeded, or one of the error values defined by ::VzReturnStatus.
*/
VZENSE_C_API_EXPORT VzReturnStatus Vz_PCInitialize(void);

/**
* @brief 		Shuts down the API on the device and clears all resources allocated by the API. After invoking this function, no other Vzense APIs can be invoked.
* @return		::PsRetOK	if the function succeeded, or one of the error values defined by ::VzReturnStatus.
*/
VZENSE_C_API_EXPORT VzReturnStatus Vz_PCShutdown(void);

/**
* @brief 		Opens device. The device must be subsequently closed using Vz_CloseDevice().
* @param[out]	pDeviceHandler:	the handler of the device on which to open.
* @return: 		::VzRetOK	    if the function succeeded, or one of the error values defined by ::VzReturnStatus.
*/
VZENSE_C_API_EXPORT VzReturnStatus Vz_PCOpenDevice(VzDeviceHandler* pDeviceHandler);

/**
* @brief 		Closes the device that was opened using Vz_OpenDevice.
* @param[in/out]	pDeviceHandler: The handler of the device to close.After that, *pDeviceHandler will be set to NULL and can no longer be used.
* @return: 		::VzRetOK           if the function succeeded, or one of the error values defined by ::VzReturnStatus.
*/
VZENSE_C_API_EXPORT VzReturnStatus Vz_PCCloseDevice(VzDeviceHandler* pDeviceHandler);

/**
* @brief 		Sets the mounting height of the camera.
* @param[in]	height:	    camera mounting height(1900mm~2300mm).
* @return: 		::VzRetOK   if the function succeeded, or one of the error values defined by ::VzReturnStatus.
*/
VZENSE_C_API_EXPORT VzReturnStatus Vz_PCSetCameraHeight(const uint16_t height);

/**
* @brief 		Sets the threshold for person dwell time
* @param[in]	threshold:	the threshold for person dwell time
* @return: 		::VzRetOK	if the function succeeded, or one of the error values defined by ::VzReturnStatus.
*/
VZENSE_C_API_EXPORT VzReturnStatus Vz_PCSetDwelltimeThreshold(const uint16_t threshold);

/**
* @brief 		Get information about the person detected.
* @param[in]	deviceHandler:	    The handler of the device on which to get information about the person detected.
* @param[out]	VzPeopleInfoCount:	The Pointer to a buffer in which to store information about the person detected.
* @return: 		::VzRetOK	        if the function succeeded, or one of the error values defined by ::VzReturnStatus.
*/
VZENSE_C_API_EXPORT VzReturnStatus Vz_PCGetPeopleInfoCount(const VzDeviceHandler deviceHandler, VzPeopleInfoCount* pPeopleInfoCount);

/**
*  @brief       Set to enable or disable the low power mode
*  @param[in]	deviceHandler:   The handler of the device on which to set low power mode.
*  @param[In]   enable:         true to enable the low power mode, false to disable the low power mod
*  @return:     ::VzRetOK	    if the function succeeded, or one of the error values defined by ::VzReturnStatus.
*/
VZENSE_C_API_EXPORT VzReturnStatus Vz_PCSetLowpowerModeEnable(const VzDeviceHandler deviceHandler, bool enable);


/**
*  @brief       Switch the open state of the door
*  @param[In]   isOpened:  true means the door is open, false means the door is not open.
*  @return:     ::VzRetOK	if the function succeeded, or one of the error values defined by ::VzReturnStatus.
*/
VZENSE_C_API_EXPORT VzReturnStatus Vz_PCSetDoorOpenState(bool isOpened);

/**
*  @brief       Registers the Camera State Callback Function
* @param[in]	pCallback:	The Pointer to the callback function. See ::PtrDeviceHotplugStateCallback 
* @return 		::PsRetOK	if the function succeeded, or one of the error values defined by ::PsReturnStatus.
*/
VZENSE_C_API_EXPORT VzReturnStatus Vz_PCRegDeviceHotplugStateCallbackFunc(const PtrDeviceHotplugStateCallback pCallback);

/**
*  @brief       Starts upgrading device firmware
* @param[in]	deviceHandler:      The handler of the device on which to start upgrading device firmware. 
* @param[in]	pImgPath:           The Pointer to the memory device firmware path. 
* @return 		::PsRetOK           if the function succeeded, or one of the error values defined by ::PsReturnStatus.
*/
VZENSE_C_API_EXPORT VzReturnStatus Vz_PCStartUpgradeFirmWare(const VzDeviceHandler deviceHandler, const char* pImgPath);

/**
*  @brief       Registers the callback function to return the device firmware update status
* @param[in]	deviceHandler:   The handler of the device on which to return to firmware upgrade status. 
* @param[in]	pCallback:       The Pointer to the callback function. See ::PtrUpgradeStateCallback 
* @return 		::PsRetOK       if the function succeeded, or one of the error values defined by ::PsReturnStatus.
*/
VZENSE_C_API_EXPORT VzReturnStatus Vz_PCRegUpgradeStateCallbackFunc(const VzDeviceHandler deviceHandler, const PtrUpgradeStateCallback pCallback);

/**
*  @brief       Sets whether to return images for debugging
*  @param[In]   isShow:  true means it returns the image, false means it doesn't.
*  @return:     ::VzRetOK	if the function succeeded, or one of the error values defined by ::VzReturnStatus.
*/
VZENSE_C_API_EXPORT VzReturnStatus Vz_PCSetShowImg(bool isShow);


#endif //VPEOPLECOUNTAPI_H