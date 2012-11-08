//Encoder Library
#include <PinChangeInt.h> // necessary otherwise we get undefined reference errors.
#include <AdaEncoder.h>
#define a_PINA 2
#define a_PINB 3
int8_t clicks=0;
char id=0;
//CREATE A STRING TO HOLD ENCODER "VALUE"
String encoderValue;


void setup(){
  //Begin Serial Communication 
  Serial.begin(9600);

  //Encoder object creation
  AdaEncoder::addEncoder('a', a_PINA, a_PINB);

}

void loop () {



  //___READING THE DATA___//
  int tilt = analogRead(A0);
  delay(1);

  int focus = analogRead(A1);
  delay(1);

  int zoom = analogRead(A2);
  delay(1);

  int iris = analogRead(A3);
  delay(1);

  int cameraSelectX = analogRead(A4);
  delay(1);

  int cameraSelectY = analogRead(A5);
  delay(1);



  //enCoder
  encoder *thisEncoder;
  thisEncoder=AdaEncoder::genie(&clicks, &id);
  if (thisEncoder != NULL) {
    if (clicks > 0) {
      encoderValue = "Going Right";
    }
    if (clicks < 0) {
      encoderValue = "Going Left";
    }
  }

  else if (thisEncoder == NULL){
    encoderValue = "Not Changing";
  }

  // form a JSON-formatted string:
  String jsonString = "{\"tilt\":\"";
  jsonString += tilt;
  jsonString +="\",\"focus\":\"";
  jsonString += focus;
  jsonString +="\",\"zoom\":\"";
  jsonString += zoom;
  jsonString +="\",\"iris\":\"";
  jsonString += iris;
  jsonString +="\",\"cameraSelectX\":\"";
  jsonString += cameraSelectX;
  jsonString +="\",\"cameraSelectY\":\"";
  jsonString += cameraSelectY;
  jsonString +="\",\"encoderValue\":\"";
  jsonString += encoderValue;
  jsonString +="\"}";

  // print it:
  Serial.println(jsonString);

}







