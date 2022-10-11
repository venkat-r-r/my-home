#include "extras/PwmPin.h"

struct LIGHT : Service::LightBulb {
  int pin;
  SpanCharacteristic *power;

  LIGHT(int pin): Service::LightBulb(){
    
    power=new Characteristic::On();

    this->pin = pin;
    pinMode (pin, OUTPUT);

    digitalWrite (pin, power->getVal());
    
  }

  boolean update() {

    digitalWrite (pin, power->getNewVal());

    return(true);
  }
};

struct FAN : Service::Fan {
  LedPin *pin;
  SpanCharacteristic *power;
  SpanCharacteristic *speed;
  
  FAN(int pin): Service::Fan(){
    power = new Characteristic::Active();
    speed = new Characteristic::RotationSpeed(25);
    speed->setRange (0, 100, 25);

    this->pin = new LedPin (pin);

    this->pin->set (power->getVal()*speed->getVal());
    
  }

  boolean update(){
    pin->set (power->getNewVal()*speed->getNewVal());

    return(true);
  }
  
};

struct SWITCH : Service::Switch {
  int pin;
  
  SpanCharacteristic *power;

  SWITCH(int pin): Service::Switch(){

    power=new Characteristic::On();

    this->pin = pin;
    pinMode (pin, OUTPUT);

    digitalWrite (pin, power->getVal());
  }

  boolean update() {

    digitalWrite (pin, power->getNewVal());

    return(true);
  }
};
