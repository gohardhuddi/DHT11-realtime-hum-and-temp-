#include <ESP8266WiFi.h>                                         
#include <FirebaseArduino.h> 
#include "DHT.h" 
// #include <Adafruit_Sensor.h>
#define DHTPIN 4
#define DHTTYPE DHT11                                  
#define FIREBASE_HOST "temp-and-hum-e4726.firebaseio.com" //Without http:// or https:// schemes
#define FIREBASE_AUTH "PBeCbZWqq7y9PRj85RyvahzbBKeDlFupioGqvSYg"
#define WIFI_SSID "TP-LINK_9F82"
#define WIFI_PASSWORD "huawei10"
DHT dht(DHTPIN, DHTTYPE);
float tValue;
float hValue;
float temp=1.2;
float hum=20.2;                                                                                
void setup() {
  Serial.begin(9600);                     
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);                                      
  Serial.print("Connecting:");
 while (WiFi.status() != WL_CONNECTED) {
   Serial.print(".");
  delay(500);
 }
  Serial.println();
  Serial.print("Connected: ");
  Serial.println(WiFi.localIP());                                                     
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);      
  String b;
  
                                                                
}
String a;
void loop() {
   float c = dht.readTemperature();// Read temperature as Celsius (the default)
 float h = dht.readHumidity();// Reading humidity 
 Serial.println(c);
 Serial.println(h);
  Firebase.setFloat("Temp",c);
  Firebase.setFloat("Hum",h);
  delay(15000); 
}
