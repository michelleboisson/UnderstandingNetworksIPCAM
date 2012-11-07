//enCoder
#include <PinChangeInt.h> // necessary otherwise we get undefined reference errors.
#include <AdaEncoder.h>
#define a_PINA 2
#define a_PINB 3
int8_t clicks=0;
char id=0;

void setup(){
  Serial.begin(9600);
  
  //enCoder
  AdaEncoder::addEncoder('a', a_PINA, a_PINB);

}

void loop () {
  //read the sensor
  int sensorValue = analogRead(A0);
  //print the results
  Serial.print(sensorValue);
  Serial.print(",");  

  sensorValue = analogRead(A1);
  //print the results
  Serial.print(sensorValue);  
  Serial.print(",");

  sensorValue = analogRead(A2);
  //print the results
  Serial.print(sensorValue);  
  Serial.print(",");

  sensorValue = analogRead(A3);
  //print the results
  Serial.print(sensorValue);
  Serial.print(",");


//JoyStick
  sensorValue = analogRead(A4);
  //print the results
  Serial.print(sensorValue);
  Serial.print(",");

  sensorValue = analogRead(A5);
  //print the results
  Serial.println(sensorValue);  

//enCoder
  encoder *thisEncoder;
  thisEncoder=AdaEncoder::genie(&clicks, &id);
  if (thisEncoder != NULL) {
//    Serial.print(id); Serial.print(':');
    if (clicks > 0) {
      Serial.println("GO RIGHT");
    }
    if (clicks < 0) {
       Serial.println(" GO LEFT");
    }
  }

}




