#include <IRremote.h>   //must install the library for this to work

const byte IR_RECEIVE_PIN = 13;

//Define all keys
#define keyOne 45
#define keyTwo 46
#define keyThree 47
#define keyFour 44
#define keyFive 40
#define keySix 43
#define keySeven 7
#define keyEight 15
#define keyNine 9
#define keyStar 16
#define keyZero 19
#define keyPound "D"
#define keyUpArrow 18
#define keyLeftArrow 8
#define keyOK 1C
#define keyRightArrow 5A
#define keyDownArrow 52


void setup()
{
    //setup the serial monitor to display results
   Serial.begin(115200);
   //start testing
   IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
}

void loop()
{
  if (IrReceiver.decode()) {
    int command = IrReceiver.decodedIRData.command;
    switch(command) {
      case keyOne : {
        Serial.println("ONE");
        break;
      }
    }
  }
}


//Currently does nothing still, but im done for today