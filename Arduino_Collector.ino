//------------------------------------------
#include <SoftwareSerial.h>
SoftwareSerial espSerial(5, 6);//Rx,TX

String send_value_sensor_1;
String send_value_sensor_2;
String send_value_sensor_3;
String send_value_sensor_4;
//--------------------------------------------

const int AirValue = 825;   //you need to replace this value with Value_1 864
const int WaterValue = 401;  //you need to replace this value with Value_2 461

//------------------SENSOR 1-----------------------
int soilMoistureValue_sensor_1 = 0;
int soilMoisturePercent_sensor_1=0;

//------------------SENSOR 2-----------------------
int soilMoistureValue_sensor_2 = 0;
int soilMoisturePercent_sensor_2=0;

//------------------SENSOR 3-----------------------
int soilMoistureValue_sensor_3 = 0;
int soilMoisturePercent_sensor_3=0;

//------------------SENSOR 4-----------------------
int soilMoistureValue_sensor_4 = 0;
int soilMoisturePercent_sensor_4=0;

void setup() {
  Serial.begin(9600); 
  espSerial.begin(9600);
}

void loop() {
  //-------------------------------------------------------------------------------
  //-----------------READ DATA FOR SENSOR 1-------------------------------------
  soilMoistureValue_sensor_1 = analogRead(A0);  
  Serial.println(soilMoistureValue_sensor_1);

  soilMoisturePercent_sensor_1 = map(soilMoistureValue_sensor_1, AirValue, WaterValue, 0, 100);
  if(soilMoisturePercent_sensor_1 >= 100)
  {
    Serial.println("100 %");
    soilMoisturePercent_sensor_1=100;
  }
  else if(soilMoisturePercent_sensor_1 <=0)
  {
    Serial.println("0 %");
    soilMoisturePercent_sensor_1 =0;
  }
  else if(soilMoisturePercent_sensor_1 >0 && soilMoisturePercent_sensor_1 < 100)
  {
    Serial.print(soilMoisturePercent_sensor_1);
    Serial.println("%"); 
    
  }
  //-------------------------------------------------------------------------------
  //-----------------READ DATA FOR SENSOR 2-------------------------------------
  soilMoistureValue_sensor_2 = analogRead(A1);  
  Serial.println(soilMoistureValue_sensor_2);

  soilMoisturePercent_sensor_2 = map(soilMoistureValue_sensor_2, AirValue, WaterValue, 0, 100);
  if(soilMoisturePercent_sensor_2 >= 100)
  {
    Serial.println("100 %");
    soilMoisturePercent_sensor_2=100;
  }
  else if(soilMoisturePercent_sensor_2 <=0)
  {
    Serial.println("0 %");
    soilMoisturePercent_sensor_2 =0;
  }
  else if(soilMoisturePercent_sensor_2 >0 && soilMoisturePercent_sensor_2 < 100)
  {
    Serial.print(soilMoisturePercent_sensor_2);
    Serial.println("%"); 
    
  }

    //-----------------READ DATA FOR SENSOR 3-------------------------------------
  soilMoistureValue_sensor_3 = analogRead(A2);  
  Serial.println(soilMoistureValue_sensor_3);

  soilMoisturePercent_sensor_3 = map(soilMoistureValue_sensor_3, AirValue, WaterValue, 0, 100);
  if(soilMoisturePercent_sensor_3 >= 100)
  {
    Serial.println("100 %");
    soilMoisturePercent_sensor_3=100;
  }
  else if(soilMoisturePercent_sensor_3 <=0)
  {
    Serial.println("0 %");
    soilMoisturePercent_sensor_3 =0;
  }
  else if(soilMoisturePercent_sensor_3 >0 && soilMoisturePercent_sensor_3 < 100)
  {
    Serial.print(soilMoisturePercent_sensor_3);
    Serial.println("%"); 
    
  }
    //-----------------READ DATA FOR SENSOR 4-------------------------------------
  soilMoistureValue_sensor_4 = analogRead(A3);  
  Serial.println(soilMoistureValue_sensor_4);

  soilMoisturePercent_sensor_4 = map(soilMoistureValue_sensor_4, AirValue, WaterValue, 0, 100);
  if(soilMoisturePercent_sensor_4 >= 100)
  {
    Serial.println("100 %");
    soilMoisturePercent_sensor_4=100;
  }
  else if(soilMoisturePercent_sensor_4 <=0)
  {
    Serial.println("0 %");
    soilMoisturePercent_sensor_4 =0;
  }
  else if(soilMoisturePercent_sensor_4 >0 && soilMoisturePercent_sensor_4 < 100)
  {
    Serial.print(soilMoisturePercent_sensor_4);
    Serial.println("%"); 
    
  }


//--------------------------SENDIG VALUES------------------------------------------------------
  send_value_sensor_1 = "1,"+String(soilMoisturePercent_sensor_1);
  espSerial.println(send_value_sensor_1);
  //delay(600000);
  delay(60000);

  send_value_sensor_2 = "2,"+String(soilMoisturePercent_sensor_2);
  espSerial.println(send_value_sensor_2);
  //delay(600000);
  delay(60000);

  send_value_sensor_3 = "3,"+String(soilMoisturePercent_sensor_3);
  espSerial.println(send_value_sensor_3);
  //delay(600000);
  delay(60000);

  send_value_sensor_4 = "4,"+String(soilMoisturePercent_sensor_4);
  espSerial.println(send_value_sensor_4);
  //delay(600000);
  delay(60000);
}
