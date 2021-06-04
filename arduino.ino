#include <AccelStepper.h>
#include <MultiStepper.h>
#define EN 8

//Direction pin
#define Y_DIR 5
#define X_DIR 6

//Step pin
#define Y_STP 2
#define X_STP 3

//motor interface type
#define motorInterfaceType 1

const int moveSteps = 2000;

AccelStepper stepper1 = AccelStepper(motorInterfaceType, X_STP, X_DIR);
AccelStepper stepper2 = AccelStepper(motorInterfaceType, Y_STP, Y_DIR);

int mchoice;

void setup() {
  Serial.begin(9600);
  Serial.println('f');
  stepper1.disableOutputs();
  stepper2.disableOutputs();
  pinMode(X_DIR, OUTPUT); pinMode(X_STP,OUTPUT);
  pinMode(Y_DIR, OUTPUT); pinMode(Y_STP,OUTPUT);
  pinMode(EN, OUTPUT);
  digitalWrite(EN,LOW);
  
  stepper1.setMaxSpeed(1000);stepper1.setAcceleration(5000);
  stepper2.setMaxSpeed(1000);stepper2.setAcceleration(5000);
}

int num=0,x_flag=1,y_flag=0;
//x_flag 紀錄x軸是否已完全走到需要的總長度，0:以到達總長則x、y軸皆歸零，回到原點，1:尚未到達，但不觸發y軸移動，2:尚未到達但觸發y軸移動
//y_flag 紀錄y軸是否已到達頂點，0:已到原點，要往上走，1:已到頂點，要往下走

void loop() {
  while(Serial.available()>0){

      mchoice = Serial.read();
      switch(mchoice){
        case 1:
          Y_up(2000);
          Serial.println('f');
          break;
        case 2:
          Y_down(2000);
          Serial.println('f');
          break;
        case 3:
          X_right(2000);
          Serial.println('f');
          break;
        case 4:
          X_left(2000);
          Serial.println('f');
          break;
        case 8:
          for(int i=1;i<=4;i++){
            Y_up(2000);
            X_left(400);
            Y_down(2000);
            X_left(400);
          }
        X_right(2000);  
        Serial.println('f');
        break;
        case 9:
          for(int i=1;i<=4;i++){
            X_left(2000);
            Y_up(400);
            X_right(2000);
            Y_up(400);
          }
        Y_down(2000);  
        Serial.println('f');
        break;
      }
  }
}
void X_left(int moveSteps){
  while(stepper2.currentPosition()!=(moveSteps)){
      stepper2.moveTo((moveSteps));
      stepper2.run();   // 1号电机运行
  }
  stepper2.setCurrentPosition(0);
}
void X_right(int moveSteps){
  while(stepper2.currentPosition()!=(-moveSteps)){
      stepper2.moveTo(-moveSteps);
      stepper2.run();   // 1号电机运行
  }
  stepper2.setCurrentPosition(0);
}
void Y_up(int moveSteps){
  while(stepper1.currentPosition()!=(moveSteps)){
      stepper1.moveTo((moveSteps));
      stepper1.run();   // 1号电机运行
  }
  stepper1.setCurrentPosition(0);
}
void Y_down(int moveSteps){
  while(stepper1.currentPosition()!=(-moveSteps)){
      stepper1.moveTo((-moveSteps));
      stepper1.run();   // 1号电机运行
  }
  stepper1.setCurrentPosition(0);
}
void Starting_Point(){
  while(stepper1.currentPosition()!=0){
      stepper1.moveTo(0);
      stepper1.run();   // 1号电机运行
  }
  while(stepper2.currentPosition()!= 0){
      stepper2.moveTo(0);
      stepper2.run();
  }
}
