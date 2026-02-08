/*
 * N2kSeatalkNG.cpp
 *
 * Copyright (c) 2019-2025 Luis Soltero,
 *                        Vassilis Bourdakis,
 *                        Timo Lappalainen, Kave Oy, www.kave.fi,
 *
 * Authors  Luis Soltero
 *          Vassilis Bourdakis
 *          Timo Lappalainen          
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the
 * Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
 * PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
 * CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE
 * OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include "N2kTypes.h"
#include "N2kSeatalkNG.h"

#define RaymarineManufacturerCode 1851
#define RaymarineCode ( N2kStNG_Marine<<13 | 0x11<<11 | (RaymarineManufacturerCode & 0x7ff)) // 11 bit manufacturer code followed by 2 bits reserved followed by 3 bits for industry code (4)

//*****************************************************************************
// PGN 65288 - Raymarine Seatalk: Alarm
// Device sends this TO MFD to raise alarms
//*****************************************************************************
void SetN2kSeatalkPGN65288(tN2kMsg &N2kMsg, tN2kSeatalkAlarmStatus status, tN2kSeatalkAlarmID alarm, tN2kSeatalkAlarmGroup group, uint16_t priority, uint8_t SID)
{
  N2kMsg.SetPGN(65288L);
  N2kMsg.Add2ByteInt(RaymarineCode);
  N2kMsg.AddByte(SID);
  N2kMsg.AddByte(status);
  N2kMsg.AddByte(alarm);
  N2kMsg.AddByte(group);
  N2kMsg.Add2ByteUInt(priority);
}

bool ParseN2kSeatalkPGN65288(const tN2kMsg &N2kMsg, tN2kSeatalkAlarmStatus &status, tN2kSeatalkAlarmID &alarm, tN2kSeatalkAlarmGroup &group, uint8_t &SID)
{
  if (N2kMsg.PGN!=65288L) return false;
  int Index=2;  // Skip manufacturer code

  SID=N2kMsg.GetByte(Index);
  status=(tN2kSeatalkAlarmStatus)N2kMsg.GetByte(Index);
  alarm=(tN2kSeatalkAlarmID)N2kMsg.GetByte(Index);
  group=(tN2kSeatalkAlarmGroup)N2kMsg.GetByte(Index);
  return true;
}

//*****************************************************************************
// PGN 65361 - Raymarine Seatalk: Silence Alarm
// MFD sends this TO device to silence/acknowledge alarms
//*****************************************************************************
void SetN2kSeatalkPGN65361(tN2kMsg &N2kMsg, tN2kSeatalkAlarmID alarm, tN2kSeatalkAlarmGroup group, uint8_t SID)
{
  N2kMsg.SetPGN(65361L);
  N2kMsg.Add2ByteInt(RaymarineCode);
  N2kMsg.AddByte(SID);
  N2kMsg.AddByte(alarm);
  N2kMsg.AddByte(group);
}

bool ParseN2kSeatalkPGN65361(const tN2kMsg &N2kMsg, tN2kSeatalkAlarmID &alarm, tN2kSeatalkAlarmGroup &group, uint8_t &SID)
{
  if (N2kMsg.PGN!=65361L) return false;
  int Index=2;  // Skip manufacturer code

  SID=N2kMsg.GetByte(Index);
  alarm=(tN2kSeatalkAlarmID)N2kMsg.GetByte(Index);
  group=(tN2kSeatalkAlarmGroup)N2kMsg.GetByte(Index);
  return true;
}
