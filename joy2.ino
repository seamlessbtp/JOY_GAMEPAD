#include <Arduino.h>
#include <BleGamepad.h>
BleGamepad bleGamepad("PENTIUM Respawn", "RAJ MALI CO.", 100);
void setup() {
  // put your setup code here, to run once:
    Serial.begin(115200);
    pinMode(23,INPUT_PULLUP);
    pinMode(12,INPUT_PULLUP);
    pinMode(33,INPUT_PULLUP);
    pinMode(25,INPUT_PULLUP);
    pinMode(16,INPUT_PULLUP);
    pinMode(17,INPUT_PULLUP);
    pinMode(5,INPUT_PULLUP);
    pinMode(18,INPUT_PULLUP);
    Serial.println("Starting BLE work!");
    
    BleGamepadConfiguration bleGamepadConfig;
    
    bleGamepad.begin();
    bleGamepad.setHat1(HAT_CENTERED);
}
int buttonstate[8];
int pot[4];
void loop() {
  // put your main code here, to run repeatedly:
 if (bleGamepad.isConnected())
    { 
       buttonstate[0]=digitalRead(23);
       
       if(buttonstate[0]==0)bleGamepad.press(BUTTON_1);
       else bleGamepad.release(BUTTON_1);
       buttonstate[1]=digitalRead(12);
       if(buttonstate[1]==0)bleGamepad.press(BUTTON_2);
       else bleGamepad.release(BUTTON_2);
       buttonstate[2]=digitalRead(33);
       if(buttonstate[2]==0)bleGamepad.press(BUTTON_3);
       else bleGamepad.release(BUTTON_3);
       buttonstate[3]=digitalRead(25);
       if(buttonstate[3]==0)bleGamepad.press(BUTTON_4);
       else bleGamepad.release(BUTTON_4);
       buttonstate[4]=digitalRead(16);
       if(buttonstate[4]==0)bleGamepad.press(BUTTON_10);
       else bleGamepad.release(BUTTON_10);
       buttonstate[5]=digitalRead(17);
       if(buttonstate[5]==0)bleGamepad.press(BUTTON_11);
       else bleGamepad.release(BUTTON_11);
       buttonstate[6]=digitalRead(5);
       if(buttonstate[6]==0)bleGamepad.press(BUTTON_12);
       else bleGamepad.release(BUTTON_12);
       buttonstate[7]=digitalRead(18);
       if(buttonstate[7]==0)bleGamepad.press(BUTTON_13);
       else bleGamepad.release(BUTTON_13);
       
       pot[0]=analogRead(26);
       pot[0]=map(pot[0],0,4095,0,22);
       pot[1]=analogRead(27);
       pot[1]=map(pot[1],0,4095,0,22);
       pot[2]=analogRead(15);
       pot[2]=map(pot[2],0,4095,0,22);
       pot[3]=analogRead(2);
       pot[3]=map(pot[3],0,3960,0,28);
       for(int k=0;k<4;k++){
        if(pot[k]>20)pot[k]=20;
        
        }
        pot[0]=map(pot[0],0,20,32767,0);
        pot[1]=map(pot[1],0,20,32767,0);
        pot[2]=map(pot[2],0,20,32767,0);
        pot[3]=map(pot[3],0,20,0,32767);
        Serial.print(pot[0]);
        Serial.print(" ");
        Serial.print(pot[1]);
         Serial.print(" ");
        Serial.print(pot[2]);
         Serial.print(" ");
        Serial.println(pot[3]);
        
       // bleGamepad.setAxes(pot[3],pot[2],0,pot[1],pot[0],0,0,0);
       bleGamepad.setRightThumb(pot[3],pot[2]); 
       bleGamepad.setLeftThumb(pot[1],pot[0]);
        // All axes, sliders, hats etc can also be set independently. 
        

          
      
     
       

    }
}

