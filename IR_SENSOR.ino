#include "ThingSpeak.h"
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
//Replace your wifi credentials here
const char* ssid = "Galaxy M14";//Replace with your Wifi Name
const char* password = "12345678";// Replace with your wifi Password
const char* server ="api.thingspeak.com";
const char* apikey= "1J7I7DRNB52IFACQ";
WiFiClient client;
void setup() {
Serial.begin(115200);
pinMode(D1,OUTPUT);
delay(100);
// We start by connecting to a WiFi network
Serial.println();
Serial.println();
Serial.print("Connecting to ");
Serial.println(ssid);
WiFi.begin(ssid, password);

while (WiFi.status() != WL_CONNECTED)
{
delay(500);
Serial.print(".");
}

Serial.println("");
Serial.println("WiFi connected");
Serial.println("IP address: ");
Serial.println(WiFi.localIP());
Serial.print("Netmask: ");
Serial.println(WiFi.subnetMask());
Serial.print("Gateway: ");
Serial.println(WiFi.gatewayIP());
ThingSpeak.begin(client);
}

void loop() {
int sensorvalue = analogRead(A0);
int radiation = sensorvalue;
Serial.print("Radiation");
Serial.print(radiation);
Serial.println("cm");
ThingSpeak.writeField(2831460,1,sensorvalue,"7HEFPF3M9EUI65IJ");
if(sensorvalue<100)
  {
    digitalWrite(D1,HIGH);
    Serial.println("D1 is ON..");
  }
  else{
    digitalWrite(D1,LOW);
    Serial.println("D1 is OFF..");
  }
  delay(500);
}
