#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
char auth[] = "<your Blynk Auth Token>";
const char* ssid = "<ssid>";
const char* pass = "<password>";
uint8_t ledPin = D1;
uint8_t ledPin2 = D2;
int brightness;
int isState1;
void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass,IPAddress(192,168,43,6),8080);
}
void loop()
{
  Blynk.run();
  isState1=digitalRead(ledPin2);
  analogWrite(D1,brightness);
  if(isState1==1)
  {
    Blynk.virtualWrite(V0,255);
  }
  else
  {
    Blynk.virtualWrite(V0,0);
  }
  int displayValue=map(brightness,0,255,0,100); 
  Blynk.virtualWrite(V10,displayValue);
}
BLYNK_WRITE(V5)//To read Blynk Virtual Pins
{
  brightness = param.asInt();
}
