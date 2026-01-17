// This is "code" for the Arduino, but since I am less practiced in arduino
// code, I figured I may as well write it up as a text file while I wait on parts



//Code:
//note that the timings are purely arbitrary and will be determined via testing

//define pins with descriptive names

#include <IRremote.h>       //requires version 4.5.0 to run smoothly

#define RECIEVER_PIN 13
#define IN1_1 12
#define ENA_1 11
#define ENB_1 10
#define IN2_1 9
#define IN3_1 8
#define IN4_1 7
#define ENA_2 6
#define ENB_2 5
#define IN1_2 4
#define IN2_2 3
#define IN3_2 2
#define IN4_2 1




void setup() {
    //set all used digital pins to output mode

    //IR Reciever 
    pinMode( RECIEVER_PIN , OUTPUT);     //not 100% sure this is an output?
    
    //Motor Driver 1
    pinMode( ENA_1, OUTPUT);
    pinMode ( ENB_1, OUTPUT);
    pinMode ( IN1_1, OUTPUT);
    pinMode (IN2_1, OUTPUT);
    pinMode (IN3_1, OUTPUT);
    pinMode (IN4_1, OUTPUT);

    //Motor Driver 2
    pinMode( ENA_2, OUTPUT);
    pinMode ( ENB_2, OUTPUT);
    pinMode ( IN1_2, OUTPUT);
    pinMode (IN2_2, OUTPUT);
    pinMode (IN3_2, OUTPUT);
    pinMode (IN4_2, OUTPUT);

    //for printing/debugging purposes:
    Serial.begin(9600);      //lets the Serial.Println() function work

}

void loop() {
    // MOSTLY pseudo code here
    //making STOP the priority.... nesting if/elses (whoo! :/ )

    if ("KEY = STOP_Key"){
        //stop the car. just stop it
        STOP();
        Serial.Println("Stopping...");
        delay(1000);
    } else {
        //IF key pressed means "forward", go forward
        if(//KEY = FWD_Key){
            moveFWD();
            Serial.Println("Forward...");
            delay(500);
        } else if (//KEY = BKWD_Key){
            moveBKWD();
            Serial.Println("Backward...");
            delay(500);
        } else if (//KEY = SLeft_Key){
            strafeLeft();
            Serial.Println("Left Strafe...");
            delay(500);
        } else if (//KEY = SRight_Key){
            strafeRight();
            Serial.Println("Right Strafe...");
            delay(500);
        } else if (//KEY = RightTurn_Key){
            turnRight();
            Serial.Println("Turning Right...");
            delay(500);
        } else if (//KEY = LeftTurn_Key){
            turnLeft();
            Serial.Println("Turning Left...");
            delay(500);
        } else if (//KEY = DiaRFWD_Key){
            moveDiagonalRightFWD();
            Serial.Println("Angle Right: Forward...");
            delay(500);
        } else if (//KEY = DiaRBKWD_Key){
            moveDiagonalRightBKWD();
            Serial.Println("Angle Right: Backwards...");
            delay(500);
        } else if (//KEY = DiaLFWD_Key){
            moveDiagonalLeftFWD();
            Serial.Println("Angle Left: Forward...");
            delay(500);
        } else if (//KEY = DiaLBKWD_Key){
            moveDiagonalLeftBKWD();
            Serial.Println("Angle Left: Backwards...");
            delay(500);
        }

        delay(500);
    }

}


//define movement functions (aka the actually hard part)

void moveFWD() {
    //all wheels move forwards
    AL_FWD();
    AR_FWD();
    BL_FWD();
    BR_FWD();
}

void moveBKWD() {
    //all wheels go backwards
    AL_BKWD();
    AR_BKWD();
    BL_BKWD();
    BR_BKWD();
}

void strafeLeft() {
    //all A go backwards
    AL_BKWD();
    AR_BKWD();
    
    //all B go forwards
    BL_FWD();
    BR_FWD();
}

void strafeRight() {
    //all B go backwards
    BL_BKWD();
    BR_BKWD();    

    //all A go forwards
    AL_FWD();
    AR_FWD();
}

void turnRight() {
    //both R go backwards
    AR_BKWD();
    BR_BKWD();

    //both L go forwards
    AL_FWD();
    BL_FWD();
}

void turnLeft() {
    //both R go forwards
    AR_FWD();
    BR_FWD();

    //both L go backwards
    BL_BKWD();
    AL_BKWD();
}

void moveDiagonalRightFWD() {
    //all A go forwards
    AL_FWD();
    AR_FWD();

    //all B stop
    BL_STOP();
    BR_STOP();
}

void moveDiagonalRightBKWD() {
    //all B go backwards
    BL_BKWD();
    BR_BKWD();

    //all A stop
    AL_STOP();
    AR_STOP();
}

void moveDiagonalLeftFWD() {
    //all B go forwards
    BL_FWD();
    BR_FWD();

    //all A stop
    AL_STOP();
    AR_STOP();
}

void moveDiagonalLeftBKWD() {
    //all A go backwards
    AR_BKWD();
    AL_BKWD();

    //all B stop
    BL_STOP();
    BR_STOP();
}

void STOP(){
    //stop all motors
    AL_STOP();
    AR_STOP();
    BL_STOP();
    BR_STOP();
}

//define wheel movement (FWD, BKWD, STOP)

//          AL WHEEL functions

void AL_FWD(){
    //sets the left AA wheel forwards
    digitalWrite(IN1_1, HIGH);
    digitalWrite(IN2_1, LOW);
}

void AL_BKWD(){
    //sets the left AA wheel backwards
    digitalWrite(IN1_1, LOW);
    digitalWrite(IN2_1, HIGH);
}

void AL_STOP(){
    //stops the left AA wheel
    digitalWrite(IN1_1, LOW);
    digitalWrite(IN2_1, LOW);
}

//          BR WHEEL functions

void BR_FWD(){
    //sets the right BB wheel forward
    digitalWrite(IN3_1, HIGH);
    digitalWrite(IN4_1, LOW);
}

void BR_BKWD(){
    //sets the right BB wheel backwards
    digitalWrite(IN3_1, LOW);
    digitalWrite(IN4_1, HIGH);
}

void BR_STOP(){
    //stops the right BB wheel
    digitalWrite(IN3_1, LOW);
    digitalWrite(IN4_1, LOW);
}

//          BL WHEEL functions

void BL_FWD(){
    //sets the left BB wheel forwards
    digitalWrite(IN1_2, HIGH);
    digitalWrite(IN2_2, LOW);
}

void BL_BKWD(){
    //sets the left BB wheel backwards
    digitalWrite(IN1_2, LOW);
    digitalWrite(IN2_2, HIGH);
}

void BL_STOP(){
    //stops the left BB wheel
    digitalWrite(IN1_2, LOW);
    digitalWrite(IN2_2, LOW)
}

//          AR WHEEL functions

void AR_FWD(){
    //sets the right AA wheel forwards
    digitalWrite(IN3_2, HIGH);
    digitalWrite(IN4_2, LOW);
}

void AR_BKWD(){
    //sets the right AA wheel Backwards
    digitalWrite(IN3_2, LOW);
    digitalWrite(IN4_2, HIGH);
}

void AR_STOP(){
    //stops the right AA wheel
    digitalWrite(IN3_2, LOW);
    digitalWrite(IN4_2, LOW);
}