//Since this is all Arduino Code, and I have yet to configure an Arduino Library for VSC
//The Code here is a .ino file, which can be copied into the arduino IDE

//This testing code was modified based on code published by groundFungus on an arduino forum
//link to post: https://forum.arduino.cc/t/ir-remote-error/695087/2 

//The following code requires the IRremote.h Library (version 4.5.0) to be installed 
//and the Serial Monitor to be at 115200 baud to work properly


//Code:
#include <IRremote.h>   //must install the library for this to work

const byte IR_RECEIVE_PIN = 13;

void setup()
{
    //setup the serial monitor to display results
   Serial.begin(115200);
   Serial.println("Begin Testing");
   //start testing
   IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
}

void loop()
{
   if (IrReceiver.decode())
   {
      Serial.println(IrReceiver.decodedIRData.command, HEX);
      delay(100);       //small pause so data can be read from monitor
      IrReceiver.resume();
   }
}
