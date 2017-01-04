#include "RestClient.h"

RestClient client = RestClient("192.168.168.24");
const char* TURN_ON =   "{on:true}";
const char* TURN_OFF =   "{on:false}";

//Setup
void setup() {
  Serial.begin(9600);
  Serial.println("");
  Serial.println("Connect to WiFi network");
  client.begin("SSID", "WIFIPASSWD");
  Serial.println("Setup!");
}

String response;
void loop(){

  response = "";
  Serial.println("Get status:");
  int statusCode = client.get("/api/YCzo6Ysx87BQaI4sT1Jn9zTXuYyL57dDVtJxWR73/lights/1/", &response);
  Serial.print("Status: Status code from server: ");
  Serial.println(statusCode);
  Serial.print("Status: Response body from server: ");
  Serial.println(response);
  
  Serial.println("============");
  response = "";
  Serial.println("Set status:");  
  statusCode = client.put("/api/YCzo6Ysx87BQaI4sT1Jn9zTXuYyL57dDVtJxWR73/lights/1/state", "{\"on\":true}", &response);
  Serial.print("SET Status code from server: ");
  Serial.println(statusCode);
  Serial.print("SET Response body from server: ");
  Serial.println(response);
  delay(5000);

    
  Serial.println("============");
  response = "";
  Serial.println("Set status:");  
  statusCode = client.put("/api/YCzo6Ysx87BQaI4sT1Jn9zTXuYyL57dDVtJxWR73/lights/1/state", "{\"on\":false}", &response);
  Serial.print("SET Status code from server: ");
  Serial.println(statusCode);
  Serial.print("SET Response body from server: ");
  Serial.println(response);
  delay(5000);

  
  Serial.println("==========================================");
}
