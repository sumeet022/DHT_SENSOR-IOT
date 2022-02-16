#include<ESP8266WiFi.h>
#include<ThingSpeak.h>
#include<DHT.h>
DHT sensor(D1,DHT11);
char* ssid = "G01";  // Wifi Name
char* pass = "cutiepie";  // Wifi Password
String api = "O9N4QH1U38MZZRUB";  // Write API keys
long id =  1528895; // Thingspeak channel ID
char ip[] = "184.106.153.149";  // Thingspeak website’s IP Address
float h,t;
WiFiClient client;
void setup() {
  Serial.begin(9600);
  sensor.begin();
  Serial.println("Connecting to Wifi");
  WiFi.begin(ssid,pass);
  while(WiFi.status()!= WL_CONNECTED){
      Serial.print(".");
      delay(500);
    }
  Serial.println("WiFi Connected");
  ThingSpeak.begin(client);
}

void loop() {
  if(client.connect(ip,80)){
      h = sensor.readHumidity();
      t = sensor.readTemperature();
      Serial.print(h);Serial.print(",");Serial.println(t);
      String msg = "The temp of my room is "+String(t);
      String data = "api_key="+api+"&status="+msg;
      client.print("POST /apps/thingtweet/1/statuses/update HTTP/1.1\n");
      client.print("Host: api.thingspeak.com\n");
      client.print("Connection: close\n");  // close the conn. after sending
      client.print("Content-Type: application/x-www-form-urlencoded\n");  // type of data
      client.print("Content-Length: ");   // length of data
      client.print(data.length());
      client.print("\n\n");
      client.print(data);
      Serial.println("Tweeted !");
  }
    client.stop();
    delay(30000); }
