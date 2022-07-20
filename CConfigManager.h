//Just for demo
//Just for demo again
//


#ifndef _CONFIG_MANAGER_H
#define _CONFIG_MANAGER_H

#include "fiTypes.h"
#include "fiImage.h"

// for polnav dialog popup notify
typedef void (*DialogPopupHandler)();

/////////////////////////////////////////////////////////////////////////////////
enum HSTATE
{
	HSTATE_2D_NORTH_UP=0,//正北朝上	(圖不動;轉車頭;無Tilt)
	HSTATE_2D_HEADING_UP=1,//車頭朝上	(圖旋轉;車不動;無Tilt)
	HSTATE_3D_HEADING_UP=2,//車頭朝上	(圖旋轉;車不動;有Tilt)
	HSTATE_HUD_NAVI=3,

	TOTAL_HEADING_STATE
};

enum DAY_NIGHT_MODE
{
	DAYNIGHT_AUTO=0,
	DAYNIGHT_DAY=1,
	DAYNIGHT_NIGHT=2,

	TOTAL_DAYNIGHT_MODE
};

enum LANDMARK_MODE
{
	LANDMARK_3D_OFF=0,
	LANDMARK_3D_LESS=1,
	LANDMARK_3D_MORE=2,

	TOTAL_LANDMARK_STATE
};

enum SATELLITE_SYSTEM {
	SATELLITE_GPS = 0,
	SATELLITE_GLONASS = 1,

	SATELLITE_SYSTEM_NUM
};

enum GPS_POS_MODE {
	GPSPOS_MODE_NETWORK = 1,
	GPSPOS_MODE_GPS,
	GPSPOS_MODE_GPS_NMEA,
	GPSPOS_MODE_NUM
};


class CConfigManager
{
public:

	CConfigManager();
	~CConfigManager();

	/////////////////////////////////////////////////////////////////////////////////
	// Volume:
	/////////////////////////////////////////////////////////////////////////////////
	FI_INT GetVolumeValue();
	FI_VOID TurnUpVolume();
	FI_VOID TurnDownVolume();
	FI_INT GetVolumeLevelCount();
	FI_VOID SetVolumeLevelAt(FI_INT nIndex);
	FI_VOID SetVolumeMute(FI_BOOL bOn);
	FI_BOOL IsVolumeMuteOn();
	FI_VOID SetApplyExtVolume(FI_BOOL bApply);

	/////////////////////////////////////////////////////////////////////////////////
	// Speed Camera:
	/////////////////////////////////////////////////////////////////////////////////
	FI_BOOL IsSpeedCameraSoundOn();
	FI_VOID SetSpeedCameraSound(FI_BOOL bIsOn);
	FI_BOOL IsSpeedCameraVisualOn();
	FI_VOID SetSpeedCameraVisual(FI_BOOL bIsOn);

	/////////////////////////////////////////////////////////////////////////////////
	// Heading State:
	// HSTATE_2D_NORTH_UP=0
	// HSTATE_2D_HEADING_UP=1
	// HSTATE_3D_HEADING_UP=2
	// HSTATE_HUD_NAVI=3
	/////////////////////////////////////////////////////////////////////////////////
	FI_INT GetVehicleHeadingState();
	FI_VOID SetVehicleHeadingState(FI_INT nState);

	/////////////////////////////////////////////////////////////////////////////////
	// Voice Language:
	//
	// SetVoiceLanguageAt
	// return value:
	// 1. FI_FALSE => setting failed
	// 2. FI_TRUE => setting succeeded
	/////////////////////////////////////////////////////////////////////////////////
	FI_INT GetTotalVoiceLanguage();
	FI_INT GetCurrentTextLangIndex();
	FI_CHAR *GetVoiceLanguageAt(FI_INT nIndex);
	FI_BOOL SetVoiceLanguageAt(FI_INT nIndex);
	FI_VOID SwitchToNextVoiceLanguage();
	FI_VOID SwitchToPrevVoiceLanguage();

	/////////////////////////////////////////////////////////////////////////////////
	// Text Language:
	//
	// SetTextLanguageAt
	// return value:
	// 1. FI_FALSE => setting failed
	// 2. FI_TRUE => setting succeeded
	/////////////////////////////////////////////////////////////////////////////////
	FI_INT GetTotalTextLanguage();
	FI_INT GetCurrentVoiceLangIndex();
	FI_CHAR *GetTextLanguageAt(FI_INT nIndex);
	FI_BOOL SetTextLanguageAt(FI_INT nIndex, FI_BOOL bInit = FI_TRUE);
	FI_VOID SwitchToNextTextLanguage();
	FI_VOID SwitchToPrevTextLanguage();

	/////////////////////////////////////////////////////////////////////////////////
	// Day/Night Mode :
	// DAYNIGHT_AUTO=0
	// DAYNIGHT_DAY=1
	// DAYNIGHT_NIGHT=2
	/////////////////////////////////////////////////////////////////////////////////
	FI_INT GetCurrentDayNightMode();
	FI_VOID SetDayNightMode(FI_INT nMode);

	/////////////////////////////////////////////////////////////////////////////////
	// 3D Landmark(rectangle blocks) :
	// 3D_LANDMARK_OFF=0
	// 3D_LANDMARK_LESS=1
	// 3D_LANDMARK_MORE=2
	/////////////////////////////////////////////////////////////////////////////////
	FI_INT Get3DLandmarkDisplayState();
	FI_VOID Set3DLandmarkDisplayState(FI_INT nState);

	/////////////////////////////////////////////////////////////////////////////////
	// 3D Buildings:
	/////////////////////////////////////////////////////////////////////////////////
	FI_BOOL Is3DLandmarkGLDisplayed();
	FI_VOID SetIs3DLandmarkGLDisplayed(FI_BOOL bIsDisplayed);

	/////////////////////////////////////////////////////////////////////////////////
	// Auto Zoom:
	/////////////////////////////////////////////////////////////////////////////////
	FI_BOOL IsAutoZoomOn();
	FI_VOID SetIsAutoZoomOn(FI_BOOL bIsOn);

	/////////////////////////////////////////////////////////////////////////////////
	// Skin Option:
	/////////////////////////////////////////////////////////////////////////////////
	FI_INT GetCurrentDaySkinIndex();
	FI_VOID SetCurrentDaySkin(FI_INT nIndex);
	FI_INT GetCurrentNightSkinIndex();
	FI_VOID SetCurrentNightSkin(FI_INT nIndex);

	/////////////////////////////////////////////////////////////////////////////////
	// GPS info values:
	//
	// Fixmode=1 None
	// Fixmode=2 2D Fix
	// Fixmode=3 3D Fix
	// Fixmode=4 Unknown
	//
	// nIndex for obtaining satellite informaion should be from 0 to 11
	// A total of 12 satellites can be queried
	/////////////////////////////////////////////////////////////////////////////////
	FI_DOUBLE GetGPSInfoLatitude();
	FI_DOUBLE GetGPSInfoLongitude();
	FI_DOUBLE GetGPSInfoCarAltitude();
	FI_DOUBLE GetGPSInfoCarSpeed(); // km/hr

	unsigned short GetGPSInfoYear();
	unsigned char GetGPSInfoMonth();
	unsigned char GetGPSInfoDay();
	unsigned char GetGPSInfoHour();
	unsigned char GetGPSInfoMinute();
	unsigned char GetGPSInfoSecond();

	FI_CHAR* GetGPSInfoFixModeText();
	FI_INT GetGPSInfoFixMode();

	unsigned short GetGPSTotalNumSatsInView(SATELLITE_SYSTEM system);

	unsigned short GetGPSInfoAzimuthAt(FI_INT nIndex, SATELLITE_SYSTEM system);
	unsigned short GetGPSInfoElevationAt(FI_INT nIndex, SATELLITE_SYSTEM system);

	unsigned short GetGPSInfoSignalQualityAt(FI_INT nIndex, SATELLITE_SYSTEM system);
	unsigned short GetGPSInfoSatelliteNumberAt(FI_INT nIndex, SATELLITE_SYSTEM system);

	FI_BOOL IsGPSInfoUsedInSolutionAt(FI_INT nIndex, SATELLITE_SYSTEM system);

	FI_BOOL IsGPSInfoValid();
	FI_VOID GetCarLocation(FI_INT &nLongitude, FI_INT &nLatitude);
	FI_INT GetCarOrientation();

	/*! \brief Get DR state
	 *
	 *  Check if Polnav SDK is in DR state.
	 *
	 *  \return true on DR state, false on others.
	 */
	FI_BOOL GetGPSDrState();

	/*! \brief Get GPS positioning mode
	 *
	 *  Get current positioning mode in Polnav SDK. Valid modes are as follows:
	 *  GPSPOS_MODE_NETWORK, GPSPOS_MODE_GPS, GPSPOS_MODE_GPS_NMEA.
	 *
	 *  \return One of the valid modes above. Or 0 for failure.
	 */
	FI_INT GetGPSPosMode();

	/*! \brief Set GPS positioning mode
	 *
	 *  Change positioning mode in Polnav SDK.
	 *
	 *	\param posMode One of three modes: GPSPOS_MODE_NETWORK, GPSPOS_MODE_GPS, GPSPOS_MODE_GPS_NMEA.
	 *  \return No return value;
	 */
	FI_VOID SetGPSPosMode(FI_INT posMode);

	/////////////////////////////////////////////////////////////////////////////////
	// EXIF JPG info:
	// Note that return value is long, not FI_DOUBLE
	/////////////////////////////////////////////////////////////////////////////////
	long GetJpegExifLatitude(FI_CHAR *photoPath);
	long GetJpegExifLongitude(FI_CHAR *photoPath);
	FI_VOID GetJpegExifPoint(FI_CHAR *photoPath, FI_INT &nLongitude, FI_INT &nLatitude);
	FI_VOID GetJpegExifSize(FI_CHAR *photoPath, FI_INT &nWidth, FI_INT &nHeight);

	/////////////////////////////////////////////////////////////////////////////////
	// Map / SDK version:
	/////////////////////////////////////////////////////////////////////////////////
	FI_INT GetTotalMapCount();
	FI_CHAR *GetMapVersionAt(FI_INT nIndex);
	FI_CHAR *GetMapRegionAt(FI_INT nIndex);
	FI_CHAR *GetSDKVersion();

	/////////////////////////////////////////////////////////////////////////////////
	// POI Show:
	/////////////////////////////////////////////////////////////////////////////////
	FI_VOID SetShowAllPOI(FI_BOOL bIsShow);
	FI_INT GetPOICategoryCount();
	fiImage *GetPOIIconAt(FI_INT nIndex);
	FI_CHAR *GetPOITextAt(FI_INT nIndex);
	FI_VOID SetShowPOIAt(FI_INT nIndex, FI_BOOL bIsShow);
	FI_BOOL GetIsShowPOIAt(FI_INT nIndex);

	/////////////////////////////////////////////////////////////////////////////////
	// GPS com port/baud rate:
	/////////////////////////////////////////////////////////////////////////////////
	FI_INT GetGpsComPortCount();
	FI_INT GetGpsBaudRateCount();
	FI_INT GetGpsComPortIndex();
	FI_INT GetGpsComPortAt(FI_INT nIndex);
	FI_INT GetGpsBaudRateIndex();
	FI_INT GetGpsBaudRateAt(FI_INT nIndex);
	FI_BOOL SetGpsComPortAt(FI_INT nIndex);
	FI_BOOL SetGpsBaudRateAt(FI_INT nIndex);

	/////////////////////////////////////////////////////////////////////////////////
	// Draw Real Car/Draw Triangle:
	/////////////////////////////////////////////////////////////////////////////////
	FI_VOID SetDrawRealCar(FI_BOOL bDrawCar);

	/////////////////////////////////////////////////////////////////////////////////
	// Approach view:
	/////////////////////////////////////////////////////////////////////////////////
	FI_VOID EnableApproachingView(FI_BOOL bIsEnable);
	FI_BOOL IsEnableApproachingView();

	/////////////////////////////////////////////////////////////////////////////////
	// Repeat Simulation:
	/////////////////////////////////////////////////////////////////////////////////
	FI_VOID SetRepeatSimulate(FI_BOOL bIsRepeat);
	FI_BOOL IsSimualationRepeated();

	/////////////////////////////////////////////////////////////////////////////////
	// License:
	/////////////////////////////////////////////////////////////////////////////////
	FI_BOOL IsLicenseValid();


	/////////////////////////////////////////////////////////////////////////////////
	// For polnav dialog popup notify
	/////////////////////////////////////////////////////////////////////////////////
	FI_VOID SetDialogPopupHandler(DialogPopupHandler pFunc);

	/////////////////////////////////////////////////////////////////////////////////
	// Turn on/off speed camera released voice
	/////////////////////////////////////////////////////////////////////////////////
	FI_BOOL IsNoSpeedCamRelease();
	FI_VOID SetNoSpeedCamRelease(FI_BOOL bNoSpeedCamRelease);

	/////////////////////////////////////////////////////////////////////////////////
	// switcher for save car location procedure
	/////////////////////////////////////////////////////////////////////////////////
	FI_VOID SetSaveCarLoc(FI_BOOL bSave);
	FI_BOOL IsSaveCarAllowed();

	/////////////////////////////////////////////////////////////////////////////////
	// Set POI icon size
	/////////////////////////////////////////////////////////////////////////////////
	FI_VOID SetPOISizeOnMap(FI_INT size=0);

	/////////////////////////////////////////////////////////////////////////////////
	// Set font size of street lable:
	//	0=Small,Small
	//	1=Medium,Medium
	//	2=Large,Large
	//	3=Off,Off
	/////////////////////////////////////////////////////////////////////////////////
	FI_VOID SetDisplayFontSize(FI_INT type=0);

	FI_VOID EnableGPSFixedPrompt(FI_BOOL bIsGPSFixedPromptEnable);
	FI_BOOL IsGPSFixedPromptEnable();

	FI_VOID EnableEearlyPrompt(FI_BOOL bIsEarlyPromptEnable);
	FI_BOOL IsEarlyPromptEnable();

	FI_VOID SetVoicePromptDelayLoopTimes(FI_INT nVoicePromptDelayLoopTimes);
	FI_INT GetVoicePromptDelayLoopTimes();

	/////////////////////////////////////////////////////////////////////////////////
	// Turn on/off all guidance voice play by tts
	/////////////////////////////////////////////////////////////////////////////////
	FI_BOOL IsAllTTSGuidanceVoiceEnable();
	FI_VOID EnableAllTTSGuidanceVoice(FI_BOOL bAllTTSGuidanceVoice);

	/////////////////////////////////////////////////////////////////////////////////
	// Turn on/off tts for speed camera alert
	/////////////////////////////////////////////////////////////////////////////////
	FI_BOOL IsTTSForSpeedCameraAlertEnable();
	FI_VOID EnableTTSForSpeedCameraAlert(FI_BOOL bIsTTSForSCAEnable);

	/////////////////////////////////////////////////////////////////////////////////
	// Get/Set TimeZone index (the value ref. to Option.ini [TimeZone_Zone])
	// Get current time.
	/////////////////////////////////////////////////////////////////////////////////
	FI_INT GetCurrentTimeZoneIndex();
	FI_VOID SetCurrentTimeZone(FI_INT nTimeZoneIndex);

	FI_INT GetCurrentTimeYear();
	FI_INT GetCurrentTimeMonth();
	FI_INT GetCurrentTimeDay();
	FI_INT GetCurrentTimeHour();
	FI_INT GetCurrentTimeMinute();
	FI_INT GetCurrentTimeSecond();

	/////////////////////////////////////////////////////////////////////////////////
	// Get Polnav format device id
	/////////////////////////////////////////////////////////////////////////////////
	FI_CHAR *GetPolnavDeviceId();

};

#endif

