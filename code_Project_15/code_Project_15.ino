/*
 By:Farkad Adnan
 E-mail: farkad.hpfa95@gmail.com
 https://linktr.ee/farkadadnan
 inst : farkadadnan
 #farkadadnan , #farkad_adnan , فرقد عدنان#
 FaceBook: كتاب عالم الاردوينو
 inst : arduinobook
 #كتاب_عالم_الاردوينو  #كتاب_عالم_الآردوينو 
 */
 
#include <Servo.h>
Servo myServoX;
Servo myServoY;
int ServoXPin = 8;
int ServoYPin = 9;
int ServoXHomePos =103; 
int ServoYHomePos =134; 
int ServoXPos =103; 
int ServoYPos =135;  
int XAxlePin = A0; 
int YAxlePin = A1;  
int XAxleValue = 0;
int YAxleValue = 0;
int Direction = 0;
int range = 12; 
int center = range/2; 
int threshold = range/4;
void setup(){
myServoX.attach(ServoXPin);
myServoY.attach(ServoYPin);
ServoXPos = ServoXHomePos;
ServoYPos = ServoYHomePos;
myServoX.write(ServoXPos);
myServoY.write(ServoYPos);
Serial.begin(9600);
}
void loop(){
XAxleValue = readAxis(XAxlePin);
YAxleValue = readAxis(YAxlePin);

Serial.print(XAxleValue,DEC);
Serial.print(" - ");
Serial.println(YAxleValue,DEC);
if (XAxleValue>0) { ServoXPos++; myServoX.write(ServoXPos); delay(100*(7-XAxleValue)); }
if (XAxleValue<0) { ServoXPos--; myServoX.write(ServoXPos); delay(100*(7+XAxleValue)); }
if (YAxleValue>0) { ServoYPos++; myServoY.write(ServoYPos); delay(100*(7-YAxleValue)); }
if (YAxleValue<0) { ServoYPos--; myServoY.write(ServoYPos); delay(100*(7+YAxleValue)); }

if (ServoXPos>ServoXHomePos+20) { ServoXPos=ServoXHomePos+20; }
if (ServoXPos<ServoXHomePos-20) { ServoXPos= ServoXHomePos-20; }
if (ServoYPos>ServoYHomePos+20) { ServoYPos=ServoYHomePos+20; }
if (ServoYPos<ServoYHomePos-20) { ServoYPos= ServoYHomePos-20; }
delay(10);
}
int readAxis(int thisAxis) {
int reading = analogRead(thisAxis);
reading = map(reading, 0, 1023, 0, range);
int distance = reading - center;
if (abs(distance) < threshold) {
distance = 0;
}
return distance;
}
