#include <Wire.h>
#include <I2C_RTC.h>

static DS3231 RTC;
const int onpin = 12;
const int relay = 13;
void setup()
{
  pinMode(onpin, OUTPUT);
  pinMode(relay, OUTPUT);
  Serial.begin(9600);
  RTC.begin();

  RTC.setHourMode(CLOCK_H24);
  //RTC.setHourMode(CLOCK_H24);

  if (RTC.getHourMode() == CLOCK_H12)
  {
    //RTC.setMeridiem(HOUR_PM);
  }

  RTC.setDay(14);
  RTC.setMonth(7);
  RTC.setYear(2024);

  RTC.setHours(13);
  RTC.setMinutes(30);
  RTC.setSeconds(0);

  RTC.setWeek(1);

  //RTC.setDate(22,07,29);
  //RTC.setTime(22,10,20);


}

void loop()
{

  switch (RTC.getWeek())
  {
    case 1:
      Serial.print("SUN");
      break;
    case 2:
      Serial.print("MON");
      break;
    case 3:
      Serial.print("TUE");
      break;
    case 4:
      Serial.print("WED");
      break;
    case 5:
      Serial.print("THU");
      break;
    case 6:
      Serial.print("FRI");
      break;
    case 7:
      Serial.print("SAT");
      break;
  }
  Serial.print(" ");
  Serial.print(RTC.getDay());
  Serial.print("-");
  Serial.print(RTC.getMonth());
  Serial.print("-");
  Serial.print(RTC.getYear());

  Serial.print(" ");

  Serial.print(RTC.getHours());
  Serial.print(":");
  Serial.print(RTC.getMinutes());
  Serial.print(":");
  Serial.print(RTC.getSeconds());
  Serial.print(" ");

  if (RTC.getHourMode() == CLOCK_H12)
  {
    if(RTC.getMeridiem() == HOUR_AM)
      Serial.println(" AM");
    if (RTC.getMeridiem() == HOUR_PM)
      Serial.println(" PM");     
  }
  delay(1000);
  if (RTC.getHours() == 0){
    digitalWrite(relay, HIGH);
  
  }
  if (RTC.getHours() == 8){
    digitalWrite(relay, LOW);
  
  }
}
