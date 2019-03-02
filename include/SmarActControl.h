/**********************************************************************
* Copyright (c) 2017 SmarAct GmbH
*
* File name: SmarActControl.h
*
* THIS  SOFTWARE, DOCUMENTS, FILES AND INFORMATION ARE PROVIDED 'AS IS'
* WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING,
* BUT  NOT  LIMITED  TO,  THE  IMPLIED  WARRANTIES  OF MERCHANTABILITY,
* FITNESS FOR A PURPOSE, OR THE WARRANTY OF NON-INFRINGEMENT.
* THE  ENTIRE  RISK  ARISING OUT OF USE OR PERFORMANCE OF THIS SOFTWARE
* REMAINS WITH YOU.
* IN  NO  EVENT  SHALL  THE  SMARACT  GMBH  BE  LIABLE  FOR ANY DIRECT,
* INDIRECT, SPECIAL, INCIDENTAL, CONSEQUENTIAL OR OTHER DAMAGES ARISING
* OUT OF THE USE OR INABILITY TO USE THIS SOFTWARE.
**********************************************************************/

#ifndef SMARACT_CTL_H
#define SMARACT_CTL_H

#include <stdlib.h>
#include <stdint.h>
#include <SmarActControlConstants.h>

#define SA_CTL_VERSION_MAJOR    1
#define SA_CTL_VERSION_MINOR    1
#define SA_CTL_VERSION_UPDATE   18

#if defined(_WIN32)
#  define SA_CTL_PLATFORM_WINDOWS
#elif defined(__linux__)
#  define SA_CTL_PLATFORM_LINUX
#else
#  error "unsupported platform"
#endif


#if defined(SA_CTL_PLATFORM_WINDOWS)
#  if !defined(_SA_CTL_DIRECTLINK)
#    ifdef SA_CTL_EXPORTS
#      define SA_CTL_API __declspec(dllexport)
#    else
#      define SA_CTL_API __declspec(dllimport)
#    endif
#  else
#    define SA_CTL_API
#  endif
#  define SA_CTL_CC __cdecl
#else
#  define SA_CTL_API __attribute__ ((visibility ("default")))
#  define SA_CTL_CC
#endif




#ifdef __cplusplus
extern "C" {
#endif

/************
 * TYPEDEFS *
 ***********/

typedef uint32_t SA_CTL_DeviceHandle_t;
typedef uint32_t SA_CTL_TransmitHandle_t;
typedef uint32_t SA_CTL_StreamHandle_t;

typedef uint8_t SA_CTL_RequestID_t;
typedef uint32_t SA_CTL_PropertyKey_t;
typedef uint32_t SA_CTL_Result_t;

typedef struct {
    uint32_t idx;
    uint32_t type;
    union {
        int32_t i32;
        int64_t i64;
        uint8_t unused[24];
    };
} SA_CTL_Event_t;

/**************************
* MISCELLANEOUS FUNCTIONS *
**************************/

/* returns the library version as a string */
SA_CTL_API
const char* SA_CTL_CC SA_CTL_GetFullVersionString();

/* returns human readable string for given result code */
SA_CTL_API
const char* SA_CTL_CC SA_CTL_GetResultInfo(SA_CTL_Result_t result);

/* returns human readable string for given event */
SA_CTL_API
const char* SA_CTL_CC SA_CTL_GetEventInfo(const SA_CTL_Event_t *event);

/***************************
* INITIALIZATION FUNCTIONS *
***************************/

/* opens a SmarAct device specified by a locator */
SA_CTL_API
SA_CTL_Result_t SA_CTL_CC SA_CTL_Open(SA_CTL_DeviceHandle_t *dHandle, const char *locator, const char *config);

/* closes a device */
SA_CTL_API
SA_CTL_Result_t SA_CTL_CC SA_CTL_Close(SA_CTL_DeviceHandle_t dHandle);

/* aborts waiting functions like WaitForEvent which will return with SA_CTL_API_ERROR_CANCELED */
SA_CTL_API
SA_CTL_Result_t SA_CTL_CC SA_CTL_Cancel(SA_CTL_DeviceHandle_t dHandle);

/* writes a list of all supported SmarAct devices currently connected to the PC to deviceList.
   each line is a device locator. the lines are separated by a newline. */
SA_CTL_API
SA_CTL_Result_t SA_CTL_CC SA_CTL_FindDevices(const char *options, char *deviceList, size_t *deviceListLen);


/***********************************
* BLOCKING READ/WRITE ACCESS - i32 *
***********************************/

/* reads a value(-array) for the given module/channel index and property-key.
if ioArraySize is a null pointer or *ioArraySize is 1, the value pointer p points
to one int32_t value. if *ioArraySize is > 1, p is an array of at least *ioArraySize
int32_t elements.
*/
SA_CTL_API
SA_CTL_Result_t SA_CTL_CC SA_CTL_GetProperty_i32(SA_CTL_DeviceHandle_t dHandle, int8_t idx, SA_CTL_PropertyKey_t pkey, int32_t *value, size_t *ioArraySize);

/* writes a value for the given module/channel index and property-key */
SA_CTL_API
SA_CTL_Result_t SA_CTL_CC SA_CTL_SetProperty_i32(SA_CTL_DeviceHandle_t dHandle, int8_t idx, SA_CTL_PropertyKey_t pkey, int32_t value);

/* writes an array of values for the given module/channel index and property-key */
SA_CTL_API
SA_CTL_Result_t SA_CTL_CC SA_CTL_SetPropertyArray_i32(SA_CTL_DeviceHandle_t dHandle, int8_t idx, SA_CTL_PropertyKey_t pkey, const int32_t *values, size_t arraySize);

/***********************************
* BLOCKING READ/WRITE ACCESS - i64 *
***********************************/

/* reads a value(-array) for the given module/channel index and property-key.
if ioArraySize is a null pointer or *ioArraySize is 1, the value pointer p points
to one int64_t value. if *ioArraySize is > 1, p is an array of at least *ioArraySizeq
int64_t elements.
*/
SA_CTL_API
SA_CTL_Result_t SA_CTL_CC SA_CTL_GetProperty_i64(SA_CTL_DeviceHandle_t dHandle, int8_t idx, SA_CTL_PropertyKey_t pkey, int64_t *value, size_t *ioArraySize);

/* writes a value for the given module/channel index and property-key */
SA_CTL_API
SA_CTL_Result_t SA_CTL_CC SA_CTL_SetProperty_i64(SA_CTL_DeviceHandle_t dHandle, int8_t idx, SA_CTL_PropertyKey_t pkey, int64_t value);

/* writes an array of values for the given module/channel index and property-key */
SA_CTL_API
SA_CTL_Result_t SA_CTL_CC SA_CTL_SetPropertyArray_i64(SA_CTL_DeviceHandle_t dHandle, int8_t idx, SA_CTL_PropertyKey_t pkey, const int64_t *values, size_t arraySize);

/**************************************
* BLOCKING READ/WRITE ACCESS - String *
**************************************/

/* reads a value for the given module/channel index and property-key.
ioArraySize must contain the size of the array 'value' when calling SA_CTL_GetValue_s and
contains the length of the string when the function returns.
*/
SA_CTL_API
SA_CTL_Result_t SA_CTL_CC SA_CTL_GetProperty_s(SA_CTL_DeviceHandle_t dHandle, int8_t idx, SA_CTL_PropertyKey_t pkey, char *value, size_t *ioArraySize);

/* writes a value for the given module/channel index and property-key. value must be a null-terminated string */
SA_CTL_API
SA_CTL_Result_t SA_CTL_CC SA_CTL_SetProperty_s(SA_CTL_DeviceHandle_t dHandle, int8_t idx, SA_CTL_PropertyKey_t pkey, const char *value);


/****************************/
/* NON-BLOCKING READ ACCESS */
/****************************/

/* issues a general read request for the given module/channel index and property-key.
received values can later be accessed via the obtained request ID and the corresponding ReadProperty function */
SA_CTL_API
SA_CTL_Result_t SA_CTL_CC SA_CTL_RequestReadProperty(SA_CTL_DeviceHandle_t dHandle, int8_t idx, SA_CTL_PropertyKey_t pkey, SA_CTL_RequestID_t *rID, SA_CTL_TransmitHandle_t tHandle);

/* reads a value(-array) for the given request ID.
if ioArraySize is a null pointer or *ioArraySize is 1, the value pointer p points
to one value of the called functions data type. if *ioArraySize is > 1, p is an array of at least *ioArraySize
elements of the functions data type. While the Request function is non-blocking the Read functions block until the desired data has arrived;
*/
SA_CTL_API
SA_CTL_Result_t SA_CTL_CC SA_CTL_ReadProperty_i32(SA_CTL_DeviceHandle_t dHandle, SA_CTL_RequestID_t rID, int32_t *value, size_t *ioArraySize);

SA_CTL_API
SA_CTL_Result_t SA_CTL_CC SA_CTL_ReadProperty_i64(SA_CTL_DeviceHandle_t dHandle, SA_CTL_RequestID_t rID, int64_t *value, size_t *ioArraySize);

SA_CTL_API
SA_CTL_Result_t SA_CTL_CC SA_CTL_ReadProperty_s(SA_CTL_DeviceHandle_t dHandle, SA_CTL_RequestID_t rID, char *value, size_t *ioArraySize);

/*****************************/
/* NON-BLOCKING WRITE ACCESS */
/*****************************/

/* issues a write request for the given module/channel index and property-key.
received results can later be accessed via the obtained request ID and the general WaitForWrite function */
SA_CTL_API
SA_CTL_Result_t SA_CTL_CC SA_CTL_RequestWriteProperty_i32(SA_CTL_DeviceHandle_t dHandle, int8_t idx, SA_CTL_PropertyKey_t pkey, int32_t value, SA_CTL_RequestID_t *rID, SA_CTL_TransmitHandle_t tHandle);

SA_CTL_API
SA_CTL_Result_t SA_CTL_CC SA_CTL_RequestWriteProperty_i64(SA_CTL_DeviceHandle_t dHandle, int8_t idx, SA_CTL_PropertyKey_t pkey, int64_t value, SA_CTL_RequestID_t *rID, SA_CTL_TransmitHandle_t tHandle);

SA_CTL_API
SA_CTL_Result_t SA_CTL_CC SA_CTL_RequestWriteProperty_s(SA_CTL_DeviceHandle_t dHandle, int8_t idx, SA_CTL_PropertyKey_t pkey, const char *value, SA_CTL_RequestID_t *rID, SA_CTL_TransmitHandle_t tHandle);

/* issues a write array request for the given module/channel index and property-key.
received results can later be accessed via the obtained request ID and the general WaitForWrite function */
SA_CTL_API
SA_CTL_Result_t SA_CTL_CC SA_CTL_RequestWritePropertyArray_i32(SA_CTL_DeviceHandle_t dHandle, int8_t idx, SA_CTL_PropertyKey_t pkey, const int32_t *values, size_t arraySize, SA_CTL_RequestID_t *rID, SA_CTL_TransmitHandle_t tHandle);

SA_CTL_API
SA_CTL_Result_t SA_CTL_CC SA_CTL_RequestWritePropertyArray_i64(SA_CTL_DeviceHandle_t dHandle, int8_t idx, SA_CTL_PropertyKey_t pkey, const int64_t *values, size_t arraySize, SA_CTL_RequestID_t *rID, SA_CTL_TransmitHandle_t tHandle);


/* returns the write accesses result for the given request ID.
While the Request function is non-blocking the WaitForWrite function blocks until the result has arrived;
*/
SA_CTL_API
SA_CTL_Result_t SA_CTL_CC SA_CTL_WaitForWrite(SA_CTL_DeviceHandle_t dHandle, SA_CTL_RequestID_t rID);


/* Cancel a non-blocking read or write access. Note that without output buffering
the request has already been sent. In this case only the answer will be discarded but
property writes will still be executed.
*/
SA_CTL_API
SA_CTL_Result_t SA_CTL_CC SA_CTL_CancelRequest(SA_CTL_DeviceHandle_t dHandle, SA_CTL_RequestID_t rID);

/**************************/
/* OUTPUT BUFFER HANDLING */
/**************************/

SA_CTL_API
SA_CTL_Result_t SA_CTL_CC SA_CTL_CreateOutputBuffer(SA_CTL_DeviceHandle_t dHandle, SA_CTL_TransmitHandle_t *tHandle);

SA_CTL_API
SA_CTL_Result_t SA_CTL_CC SA_CTL_FlushOutputBuffer(SA_CTL_DeviceHandle_t dHandle, SA_CTL_TransmitHandle_t tHandle);

SA_CTL_API
SA_CTL_Result_t SA_CTL_CC SA_CTL_CancelOutputBuffer(SA_CTL_DeviceHandle_t dHandle, SA_CTL_TransmitHandle_t tHandle);

/**************************/
/* COMMAND GROUP HANDLING */
/**************************/

SA_CTL_API
SA_CTL_Result_t SA_CTL_CC SA_CTL_OpenCommandGroup(SA_CTL_DeviceHandle_t dHandle, SA_CTL_TransmitHandle_t *tHandle, uint32_t triggerMode);

SA_CTL_API
SA_CTL_Result_t SA_CTL_CC SA_CTL_CloseCommandGroup(SA_CTL_DeviceHandle_t dHandle, SA_CTL_TransmitHandle_t tHandle);

SA_CTL_API
SA_CTL_Result_t SA_CTL_CC SA_CTL_CancelCommandGroup(SA_CTL_DeviceHandle_t dHandle, SA_CTL_TransmitHandle_t tHandle);

/***************************/
/* WAIT AND RECEIVE EVENTS */
/***************************/

SA_CTL_API
SA_CTL_Result_t SA_CTL_CC SA_CTL_WaitForEvent(SA_CTL_DeviceHandle_t dHandle, SA_CTL_Event_t *event, uint32_t timeout);

/**********************/
/* MOVEMENT FUNCTIONS */
/**********************/

/* start calibration for given channel index
- desired configuration must be done previously using SetProperty commands (e.g. mode) */
SA_CTL_API
SA_CTL_Result_t SA_CTL_CC SA_CTL_Calibrate(SA_CTL_DeviceHandle_t dHandle, int8_t idx, SA_CTL_TransmitHandle_t tHandle);

/* start referencing for given channel index
- desired configuration must be done previously using SetProperty commands (e.g. mode) */
SA_CTL_API
SA_CTL_Result_t SA_CTL_CC SA_CTL_Reference(SA_CTL_DeviceHandle_t dHandle, int8_t idx, SA_CTL_TransmitHandle_t tHandle);

/* move to position by considering the desired settings
- implicit parameters must be configured before executing a movement using SetProperty commands
- possible parameters are: OpenLoop/ClosedLoop, Rel./Abs., Freq., Ampl., HoldTime, Speed, Accel., queued, abort conditions */
SA_CTL_API
SA_CTL_Result_t SA_CTL_CC SA_CTL_Move(SA_CTL_DeviceHandle_t dHandle, int8_t idx, int64_t moveValue, SA_CTL_TransmitHandle_t tHandle);

/* stops the given channels movement */
SA_CTL_API
SA_CTL_Result_t SA_CTL_CC SA_CTL_Stop(SA_CTL_DeviceHandle_t dHandle, int8_t idx, SA_CTL_TransmitHandle_t tHandle);

/***********************/
/* STREAMING FUNCTIONS */
/***********************/

/* opens a connection to a new stream */
SA_CTL_API
SA_CTL_Result_t SA_CTL_CC SA_CTL_OpenStream(SA_CTL_DeviceHandle_t dHandle, SA_CTL_StreamHandle_t *sHandle, uint32_t triggerMode);

/* send a frame to the device containing position information for every channel that takes part in streaming.
The flow control necessary to prevent buffer overflows on the controller is handled by the DLL. Therefore
the StreamFrame() method will block until the system is ready to receive the next frame.
- note: setting of the desired Streamrate as well as the external Syncrate must be done via get-/setProperty commands */
SA_CTL_API
SA_CTL_Result_t SA_CTL_CC SA_CTL_StreamFrame(SA_CTL_DeviceHandle_t dHandle, SA_CTL_StreamHandle_t sHandle, const uint8_t *frameData, uint32_t frameSize);

/* closes the Stream for the given handle */
SA_CTL_API
SA_CTL_Result_t SA_CTL_CC SA_CTL_CloseStream(SA_CTL_DeviceHandle_t dHandle, SA_CTL_StreamHandle_t sHandle);

/* aborts the current stream */
SA_CTL_API
SA_CTL_Result_t SA_CTL_CC SA_CTL_AbortStream(SA_CTL_DeviceHandle_t dHandle, SA_CTL_StreamHandle_t sHandle);

#ifdef __cplusplus
}
#endif

#endif // SMARACT_CTL_H
