#include <arduino.h>
#include <MsTimer2.h>
#include "define.h"
#include "Controller.h"

Controller Con(&SERIAL_LEONARDO);

bool flag_10ms = false;

void timer_warikomi(){
    Con.update();
    flag_10ms = true;
}

void setup(){
    pinMode(PIN_LED_1,OUTPUT);
    pinMode(PIN_LED_2,OUTPUT);
    pinMode(PIN_LED_3,OUTPUT);
    pinMode(PIN_LED_4,OUTPUT);
    Serial.begin(115200);
    //SERIAL_LEONARDO.begin(115200);
    SERIAL_XBEE.begin(115200);
    //Serial.println("START");
    digitalWrite(PIN_LED_1,HIGH);
    MsTimer2::set(10,timer_warikomi); // 10ms period
    MsTimer2::start();
}

void loop(){
    //Con.update(); //タイマー割込みに移動
    digitalWrite(PIN_LED_2,HIGH);
    if(flag_10ms){
    
    coords refV;
    refV.x = (double)Con.readJoyLX();
    refV.y = (double)Con.readJoyLY();
    refV.z = (double)Con.readJoyRX();

    Serial.print(refV.x);
    Serial.print("\t");
    Serial.print(refV.y);
    Serial.print("\t");
    Serial.println(refV.z);
    flag_10ms = false;
    static int a = 0;
    a++;
    if(a > 100){
        digitalWrite(PIN_LED_3,HIGH);
    }
    else if(a > 200){
        digitalWrite(PIN_LED_3,LOW);
        a = 0;
    }
    }
}