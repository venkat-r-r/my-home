#include <HomeSpan.h>
#include "Devices.h"

void setup() {
  Serial.begin(115200);       // start the Serial interface
  
  init ();

  homeSpan.begin(Category::Bridges,"HomeSpan Bridge");           // initialize HomeSpan
  
  new SpanAccessory();
    new Service::AccessoryInformation();
      new Characteristic::Identify();

  new SpanAccessory();
    new Service::AccessoryInformation();
      new Characteristic::Identify();
      new Characteristic::Name("Switch#1");
    new SWITCH(19);

  new SpanAccessory();
    new Service::AccessoryInformation();
      new Characteristic::Identify();
      new Characteristic::Name("Light");
    new LIGHT(16);

  new SpanAccessory();
    new Service::AccessoryInformation();
      new Characteristic::Identify();
      new Characteristic::Name("Fan");
    new FAN(15);

  new SpanAccessory();
    new Service::AccessoryInformation();
      new Characteristic::Identify();
      new Characteristic::Name("Switch#2");
    new SWITCH(5);

}

void loop() {
  homeSpan.poll();

}

void init () {

  homeSpan.enableWebLog(50,"pool.ntp.org","UTC+5:30","myLog");

  // status LED (builtin LED)
  homeSpan.setStatusPin (2);

  // push button which allows End-User to communicate with this board 
  homeSpan.setControlPin (13);

  // allows to upload new sketch Overt-The-Air
  homeSpan.enableOTA(false);

  // if existing credentials are not available
  // custom access point to get WiFi credentials
  homeSpan.setApSSID ("smart device-setup");
  homeSpan.setApPassword ("CONNECTING@THINGS");

  // start access point if Wifi Credentials are not available
  homeSpan.enableAutoStartAP ();
}
