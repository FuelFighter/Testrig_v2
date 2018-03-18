#include <Wire.h>
#include <Adafruit_ADS1015.h>

Adafruit_ADS1015 ads;

uint8_t 	iter = 0;

int16_t		reading = 0;

float 		temp = 0.0;

float 		torque_mNm = 0.0;
float 		torque_multiplier = 0.125f; 
float 		voltage_mV = 0.0;
float 		voltage_multiplier = 1.375f;
float 		current_mA = 0.0;
float 		current_multiplier = 0.125f;

void setup() {
  
	Serial.begin(9600);
	Serial.println("Initializing");
	Serial.println("Getting differential reading of torque in mNm on A0/A1, current in mA from A2 and voltage from A3");
	Serial.println("ADC Range: +/- 4.096V (1 bit = 0.125mV");
	ads.setGain(GAIN_ONE);
	ads.begin();
}

void loop() {

	/*reading = ads.readADC_Differential_0_1()-1;
	temp = reading*torque_multiplier;
	torque_mNm = (0.1*temp + 0.9*torque_mNm);*/

	reading = ads.readADC_SingleEnded(2);
	//temp = (reading*current_multiplier-2500);
	//dcurrent_mA = (0.1*temp + 0.9*current_mA);
	
	/*reading = ads.readADC_SingleEnded(3);
	temp = reading*voltage_multiplier;
	voltage_mV = (0.1*temp + 0.9*voltage_mV);*/
	
	if(iter >= 0)	
	{
		Serial.print(temp);Serial.print(", ");Serial.print(reading);Serial.print("\n");
		iter = 0;
	}
	iter = iter + 1;
	delay(100);
}
