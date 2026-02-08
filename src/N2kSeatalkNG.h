/*
 * N2kSeatalkNG.h
 * 
 * Copyright (c) 2019-2025 Luis Soltero,
 *                        Timo Lappalainen, Kave Oy, www.kave.fi, 
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS 
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
*/

#ifndef _N2kSeatalkNG_H_
#define _N2kSeatalkNG_H_

#include "N2kMsg.h"
#include "N2kTypes.h"
#include <stdint.h>

// https://canboat.github.io/canboat/canboat.html

/*************************************************************************//**
 * \enum tN2kSeatalkIndustryCode
 * \brief Enumeration of Seatalk industry codes
 */                          
enum tN2kSeatalkIndustryCode {
			      N2kStNG_Global = 0,
			      N2kStNG_Highway,
			      N2kStNG_Agricultrure,
			      N2kStNG_Construction,
			      N2kStNG_Marine,
			      N2kStNG_Industrial
};

/*************************************************************************//**
 * \enum tN2kSeatalkAlarmStatus
 * \brief Enumeration of Seatalk Alarm status codes
 */                          
enum tN2kSeatalkAlarmStatus {
			     N2kStNG_AlarmCondNotMet = 0,           // Alarm cleared
			     N2kStNG_AlarmCondMetNotSilenced = 1,   // Alarm active, sounding
			     N2kStNG_AlarmCondMetSilenced = 2,      // Alarm active, acknowledged/silenced
};

/*************************************************************************//**
 * \enum tN2kSeatalkAlarmID
 * \brief Enumeration of Seatalk Alarm conditions
 */                          
enum tN2kSeatalkAlarmID {
			 N2kStNG_NoAlarm 				= 0,
			 N2kStNG_ShallowDepth				= 1,
			 N2kStNG_DeepDepth				= 2,
			 N2kStNG_ShallowAnchor				= 3,
			 N2kStNG_DeepAnchor				= 4,
			 N2kStNG_OffCourse				= 5,
			 N2kStNG_AWAHigh				= 6,
			 N2kStNG_AWALow					= 7,
			 N2kStNG_AWSHigh				= 8,
			 N2kStNG_AWSLow					= 9,
			 N2kStNG_TWAHigh				= 10,
			 N2kStNG_TWALow					= 11,
			 N2kStNG_TWSHigh				= 12,
			 N2kStNG_TWSLow					= 13,
			 N2kStNG_WPArrival				= 14,
			 N2kStNG_BoatSpeedHigh				= 15,
			 N2kStNG_BoatSpeedLow				= 16,
			 N2kStNG_SeaTempHigh				= 17,
			 N2kStNG_SeaTempLow				= 18,
			 N2kStNG_PilotWatch				= 19,
			 N2kStNG_PilotOffCourse				= 20,
			 N2kStNG_PilotWindShift				= 21,
			 N2kStNG_PilotLowBattery			= 22,
			 N2kStNG_PilotLastMinOfWatch			= 23,
			 N2kStNG_PilotNoNMEAData			= 24,
			 N2kStNG_PilotLargeXTE				= 25,
			 N2kStNG_PilotNMEADataError			= 26,
			 N2kStNG_PilotCUDIsconnected			= 27,
			 N2kStNG_PilotAutoRelease			= 28,
			 N2kStNG_PilotWayPointAdvance			= 29,
			 N2kStNG_PilotDriveStopped			= 30,
			 N2kStNG_PilotTypeUnspecified			= 31,
			 N2kStNG_PilotCalibrationRequired		= 32,
			 N2kStNG_PilotLastHeading			= 33,
			 N2kStNG_PilotNoPilot				= 34,
			 N2kStNG_PilotRouteComplete			= 35,
			 N2kStNG_PilotVariableText			= 36,
			 N2kStNG_GPSFailure				= 37,
			 N2kStNG_MOB					= 38,
			 N2kStNG_Seatalk1Anchor				= 39,
			 N2kStNG_PilotSwappedMotorPower			= 40,
			 N2kStNG_PilotStandbyTooFastToFish		= 41,
			 N2kStNG_PilotNoGPSFix				= 42,
			 N2kStNG_PilotNoGPSCOG				= 43,
			 N2kStNG_PilotStartUp				= 44,
			 N2kStNG_PilotTooSlow				= 45,
			 N2kStNG_PilotNoCOmpass				= 46,
			 N2kStNG_PilotRateGyroFault			= 47,
			 N2kStNG_PilotCurrentLimit			= 48,
			 N2kStNG_PilotWPTAdvancePort			= 49,
			 N2kStNG_PilotWPTAdvanceStbd			= 50,
			 N2kStNG_PilotNoWindData			= 51,
			 N2kStNG_PilotNoWindSpeed			= 52,
			 N2kStNG_PilotSeatalkFail1			= 53,
			 N2kStNG_PilotSeatalkFail2			= 54,
			 N2kStNG_PilotWarnTooFastToFish			= 55,
			 N2kStNG_PilotAutoDockFail			= 56,
			 N2kStNG_PilotTurnTooFast			= 57,
			 N2kStNG_PilotNoNavData				= 58,
			 N2kStNG_PilotLostWPTData			= 59,
			 N2kStNG_PilotEEPROMCorrupt			= 60,
			 N2kStNG_PilotRudderFeedbackFail		= 61,
			 N2kStNG_PilotAuotlearnFail1			= 62,
			 N2kStNG_PilotAutolearnFail2			= 63,
			 N2kStNG_PilotAutoleanrFail3			= 64,
			 N2kStNG_PilotAutolearnFail4			= 65,
			 N2kStNG_PilotAutolearnFail5			= 66,
			 N2kStNG_PilotAutolearnFail6			= 67,
			 N2kStNG_PilotWarnCalRequired			= 68,
			 N2kStNG_PilotWarnOffCourse			= 69,
			 N2kStNG_PilotWarnXTE				= 70,
			 N2kStNG_PilotWarnWindShift			= 71,
			 N2kStNG_PilotWardnDriveShort			= 72,
			 N2kStNG_PilotWarnClutchShort			= 73,
			 N2kStNG_PilotWarnSolenoidShort			= 74,
			 N2kStNG_PilotJoystickFault			= 75,
			 N2kStNG_PilotNoJoystickData			= 76,
			 N2kStNG_PilotInvalidCommand 			= 80,
			 N2kStNG_AISTXMalfunction			= 81,
			 N2kStNG_AISAntennaVSWRFault			= 82,
			 N2kStNG_AISRxChan1Malfunction			= 83,
			 N2kStNG_AISRxChan2Maulfunction			= 84,
			 N2kStNG_AISNoSensorPositionInUse		= 85,
			 N2kStNG_AISInvalidSOG				= 86,
			 N2kStNG_AISInvalidCOG				= 87,
			 N2kStNG_AIS12VAlrm				= 88,
			 N2kStNG_AIS6VAlrm				= 89,
			 N2kStNG_AISNoiseChanA				= 90,
			 N2kStNG_AISNoiseChanB				= 91,
			 N2kStNG_AISXmitPAFault				= 92,
			 N2kStNG_AIS3V3Alrm				= 93,
			 N2kStNG_AIXRxCh70Fail				= 94,
			 N2kStNG_AISHDGFail				= 95,
			 N2kStNG_AISGPSFail				= 96,
			 N2kStNG_AISNoSensorPosition			= 97,
			 N2kStNG_AISLockFail				= 98,
			 N2kStNG_AISGGATimeout				= 99,
			 N2kStNG_AISRestart				= 100,
			 N2kStNG_PilotNoIPSCom				= 101,
			 N2kStNG_PilotPowerOnOrSleepWhileOn		= 102,
			 N2kStNG_PilotResetWhileOn			= 103,
			 N2kStNG_AISDangerTarget			= 104,
			 N2kStNG_AISLostTarget				= 105,
			 N2kStNG_AISSARMessage				= 106,
			 N2kStNG_AISConnectionLost			= 107,
			 N2kStNG_NoFix					= 108,
};

/*************************************************************************//**
 * \enum tN2kSeatalkAlarmGroup
 * \brief Enumeration of Seatalk Alarm groups/categories
 */                          
enum tN2kSeatalkAlarmGroup {
			    N2kStNG_Instrument = 0,
			    N2kStNG_Autopilot,
			    N2kStNG_Radar,
			    N2kStNG_ChartPlotter,
			    N2kStNG_AIS,
};

/************************************************************************//**
 * \brief Setting up PGN 65288 for Raymarine Seatalk-NG "Alarm"
 *
 * This PGN is sent BY devices TO MFDs to raise alarms.
 * Set, Unset, or report Alarm status
 *
 * \param N2kMsg          Reference to a N2kMsg Object, 
 *                        Output: NMEA2000 message ready to be send.
 *
 * \param status	  Alarm status to set \ref tN2kSeatalkAlarmStatus
 *                        0 = Alarm cleared
 *                        1 = Alarm active, not silenced (sounding)
 *                        2 = Alarm active, silenced (acknowledged)
 * \param alarm           Alarm to set \ref tN2kSeatalkAlarmID
 * \param group           Instrument group to alarm \ref tN2kSeatalkAlarmGroup
 * \param priority        Alarm priority. Default is 7
 * \param SID             Sequence identifier. In most cases you can use just 0xff for SID. See \ref secRefTermSID.
 *
 *                        The sequence identifier field is used to tie different PGNs data together to same 
 *                        sampling or calculation time.
 *
 */

void SetN2kSeatalkPGN65288(tN2kMsg &N2kMsg, tN2kSeatalkAlarmStatus status, tN2kSeatalkAlarmID alarm, tN2kSeatalkAlarmGroup group, uint16_t priority = 7, uint8_t SID = N2kUInt8NA);

/************************************************************************//**
 * \brief Alias for setting up Seatalk Alarm PGN 65288
 *
 * Alias of PGN 65288 added to improve readability. See parameters details on \ref SetN2kSeatalkPGN65288
 */

inline void SetN2kSeatalkAlarm(tN2kMsg &N2kMsg, tN2kSeatalkAlarmStatus status, tN2kSeatalkAlarmID alarm, tN2kSeatalkAlarmGroup group, uint16_t priority = 7, uint8_t SID = N2kUInt8NA) {
  return SetN2kSeatalkPGN65288(N2kMsg, status, alarm, group, priority, SID);
}

/************************************************************************//**
 * \brief Parsing of Seatalk Alarm PGN 65288
 * \param N2kMsg          Reference to a N2kMsg Object, 
 *                        Input: NMEA2000 message to parse
 *
 * \param status	  Alarm status \ref tN2kSeatalkAlarmStatus
 * \param alarm           Alarm ID \ref tN2kSeatalkAlarmID
 * \param group           Instrument group \ref tN2kSeatalkAlarmGroup
 * \param SID             Sequence identifier. See \ref secRefTermSID.
 *
 *                        The sequence identifier field is used to tie different PGNs data together to same 
 *                        sampling or calculation time.
 */
bool ParseN2kSeatalkPGN65288(const tN2kMsg &N2kMsg, tN2kSeatalkAlarmStatus &status, tN2kSeatalkAlarmID &alarm, tN2kSeatalkAlarmGroup &group, uint8_t &SID);

/************************************************************************//**
 * \brief Alias for parsing Seatalk Alarm PGN 65288
 *
 * Alias of PGN 65288 added to improve readability. See parameters details on \ref ParseN2kSeatalkPGN65288
 */
inline bool ParseN2kSeatalkAlarm(const tN2kMsg &N2kMsg, tN2kSeatalkAlarmStatus &status, tN2kSeatalkAlarmID &alarm, tN2kSeatalkAlarmGroup &group, uint8_t &SID) {
  return ParseN2kSeatalkPGN65288(N2kMsg, status, alarm, group, SID);
}

/************************************************************************//**
 * \brief Setting up PGN 65361 for Raymarine Seatalk-NG "Silence Alarm"
 *
 * This PGN is sent BY MFDs TO devices to silence/acknowledge alarms.
 * Typically you RECEIVE this message when user silences alarm on MFD.
 *
 * \param N2kMsg          Reference to a N2kMsg Object, 
 *                        Output: NMEA2000 message ready to be send.
 *
 * \param alarm           Alarm to silence \ref tN2kSeatalkAlarmID
 * \param group           Instrument group \ref tN2kSeatalkAlarmGroup
 * \param SID             Sequence identifier. In most cases you can use just 0xff for SID. See \ref secRefTermSID.
 *
 */

void SetN2kSeatalkPGN65361(tN2kMsg &N2kMsg, tN2kSeatalkAlarmID alarm, tN2kSeatalkAlarmGroup group, uint8_t SID = N2kUInt8NA);

/************************************************************************//**
 * \brief Alias for setting up Seatalk Silence Alarm PGN 65361
 *
 * Alias of PGN 65361 added to improve readability. See parameters details on \ref SetN2kSeatalkPGN65361
 */

inline void SetN2kSeatalkSilenceAlarm(tN2kMsg &N2kMsg, tN2kSeatalkAlarmID alarm, tN2kSeatalkAlarmGroup group, uint8_t SID = N2kUInt8NA) {
  return SetN2kSeatalkPGN65361(N2kMsg, alarm, group, SID);
}

/************************************************************************//**
 * \brief Parsing of Seatalk Silence Alarm PGN 65361
 * \param N2kMsg          Reference to a N2kMsg Object, 
 *                        Input: NMEA2000 message to parse
 *
 * \param alarm           Alarm to silence \ref tN2kSeatalkAlarmID
 * \param group           Instrument group \ref tN2kSeatalkAlarmGroup
 * \param SID             Sequence identifier. See \ref secRefTermSID.
 *
 */
bool ParseN2kSeatalkPGN65361(const tN2kMsg &N2kMsg, tN2kSeatalkAlarmID &alarm, tN2kSeatalkAlarmGroup &group, uint8_t &SID);

/************************************************************************//**
 * \brief Alias for parsing Seatalk Silence Alarm PGN 65361
 *
 * Alias of PGN 65361 added to improve readability. See parameters details on \ref ParseN2kSeatalkPGN65361
 */
inline bool ParseN2kSeatalkSilenceAlarm(const tN2kMsg &N2kMsg, tN2kSeatalkAlarmID &alarm, tN2kSeatalkAlarmGroup &group, uint8_t &SID) {
  return ParseN2kSeatalkPGN65361(N2kMsg, alarm, group, SID);
}


#endif
