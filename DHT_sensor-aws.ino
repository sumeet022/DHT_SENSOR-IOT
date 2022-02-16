#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <DHT.h>
DHT sensor(D2,DHT11);
float hum,temp;
char* ssid = "G01";
char* pass = "cutiepie";



void setup() {
  Serial.begin(9600);
  Serial.println("Connecting to Wifi");
  WiFi.begin(ssid,pass);
  while(WiFi.status()!=WL_CONNECTED){
    Serial.print(".");
    delay(500);
    }
  Serial.println("WiFi Connected");
  sensor.begin();
}


void loop(){


  hum =sensor.readHumidity();
  
  temp=sensor.readTemperature();
  Serial.print("Humidity--");Serial.print(hum);  
  Serial.print("Temperature -- ");Serial.println(temp);

  String api = "http://157.175.87.229/iot_code.php?hum="+String(hum)+"&temp="+String(temp);
  HTTPClient http;
  http.begin(api); // this is just to hit the line 29 of API
  int code = http.GET();  // if you get 40x then fail if 20x then successful
  String response = http.getString();
  Serial.println(code);
  Serial.println(response);
  
  delay(5000);
      }
