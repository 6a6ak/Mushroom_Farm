
#include "DHT.h"
#include <gprs.h>
#include <SoftwareSerial.h>

GPRS gprs;
DHT dht;
int Temp;
int Humi;
int CO2;
#define RELAY1  4   //coller on
#define RELAY2  5   //heater on
#define RELAY3  6   //wcoller on
#define RELAY4  9   //Fan in
#define RELAY5  10   //Fan out
#define RELAY6  11   //Co2
#define RELAY7  12   //extra
#define RELAY8  13   //extra

void setup()
{
  Serial.begin(9600);

  dht.setup(2); // data pin 2

  pinMode(RELAY1, OUTPUT); //digitalWrite(RELAY1,1);
  pinMode(RELAY2, OUTPUT); //digitalWrite(RELAY2,1);
  pinMode(RELAY3, OUTPUT); //digitalWrite(RELAY3,1);
  pinMode(RELAY4, OUTPUT); //digitalWrite(RELAY4,1);
  pinMode(RELAY5, OUTPUT); //digitalWrite(RELAY5,1);
  pinMode(RELAY6, OUTPUT);// digitalWrite(RELAY6,1);
  pinMode(RELAY7, OUTPUT); //digitalWrite(RELAY7,1);
  pinMode(RELAY8, OUTPUT); //digitalWrite(RELAY8,1);
//////////////////call info/////////////////
  while(!Serial);
  Serial.println("GPRS - Call up Test...");
  gprs.preInit();//power on SIM800
  delay(1000);
  while(0 !=gprs.init()) { //gprs init
      delay(1000);
      Serial.print("init error\r\n");
  }
 ////////////////////////////////// 
}



void loop()
{


  //forsensor humidity&temp//
  delay(dht.getMinimumSamplingPeriod());
 // Serial.print("Humidity =");Serial.println(dht.getHumidity());
 // Serial.print("\t");
 // Serial.print("Temp =");Serial.println(dht.getTemperature());
  Temp=dht.getTemperature();
  Humi=dht.getHumidity();
  Serial.print("Tempperature ="); Serial.println(Temp);
   Serial.print("\t");
  Serial.print("Humidity ="); Serial.println(Humi);


//Programing Starts//
if( Temp>24 ){  digitalWrite(RELAY1,1);  digitalWrite(RELAY2,0);     Serial.println("temp is that  hot cooler -> ON");  } 
  else {  digitalWrite(RELAY1,0); digitalWrite(RELAY2,0); Serial.println("temp is OK  cooler -> OFF");   } delay(2000); //Wather is that Hot so Turn cooler ON 
  
if( Temp<23 ){  digitalWrite(RELAY2,0);  digitalWrite(RELAY1,0);     Serial.println("Wather is going to Cold ");  } 
  else {  digitalWrite(RELAY2,0); digitalWrite(RELAY1,1);  } delay(2000);  //Weather is going to a little cold so turn the heater on 
  
if( Humi<55 ){  digitalWrite(RELAY3,1);   delay(2000); gprs.callUp("Phone Number");  Serial.println("humidity is to low & call up");   } 
else {   digitalWrite(RELAY3,0);  //Humidity is that low and turn water coler on& fan in & fan out turn off
//  
//if( Humi>80 ){  digitalWrite(RELAY3,1);    Serial.println("humidity is that high ");  }
//else {  digitalWrite(RELAY3,0); }    // humidity is that high so turn watercoler off
//  
////if( CO2>30 ){  digitalWrite(RELAY5,0);    Serial.println("CO2 is that high ");  } 
////  else {  digitalWrite(RELAY5,1);  }  delay(2000);
//  
////if( CO2<10 ){  digitalWrite(RELAY5,1);    Serial.println("CO2 is Normal ");  }   delay(2000); //CO2 is Normal 
// //call series\\ 
//if( Temp>28 ){    gprs.callUp("Phone Number");   Serial.println("very hot"); }  
//if( Temp<20 ){     Serial.println(" call and send SMS Wather is that cold ");  } 
//if( Humi<50 ){     Serial.println(" call and send SMS Humidity  is that Hot ");  } 
//if( Humi>85 ){      gprs.sendSMS("Phone Number","Himidity "); delay(3000);  gprs.callUp("Phone Number");    Serial.println("humidity is high");   } 
//   
//  
//Programing Starts//



//
//L1:

//  goto L1;


}
