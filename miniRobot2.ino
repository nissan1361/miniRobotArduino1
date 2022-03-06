#include <NewPing.h>

#define SPEED_1      5 
#define DIR_1        4
 
#define SPEED_2      6
#define DIR_2        7
 
#define TRIGGER_PIN  10
#define ECHO_PIN     11
#define MAX_DISTANCE 400
 
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
 
void setup() {
  Serial.begin(9600);
    for (int i = 4; i < 8; i++) {     
    pinMode(i, OUTPUT);
  }
}
 
void loop() {
  delay(50);
  Serial.print("Ping: ");
  Serial.print(sonar.ping_cm());
  Serial.println("cm");

  if (sonar.ping_cm() <= 30){
      // устанавливаем направление мотора «M1» в одну сторону
      digitalWrite(DIR_1, HIGH);
        // устанавливаем направление мотора «M2» в другую сторону
      digitalWrite(DIR_2, HIGH);
      // включаем мотор на максимальной скорости
      analogWrite(SPEED_1, 110);
      analogWrite(SPEED_2, 110);
      
      // ждём
      delay(125);
      analogWrite(SPEED_1, 0);
      analogWrite(SPEED_2, 0);
      
  } else if (sonar.ping_cm() > 30){
     // устанавливаем направление мотора «M1» в одну сторону
     digitalWrite(DIR_1, HIGH);
     // включаем мотор на максимальной скорости
     analogWrite(SPEED_1, 110);

     // устанавливаем направление мотора «M2» в одну сторону
     digitalWrite(DIR_2, LOW);
     // включаем второй мотор на максимальной скорости
     analogWrite(SPEED_2, 110);
     // ждём
     delay(400);
  } else {
        analogWrite(SPEED_1, 0);
      analogWrite(SPEED_2, 0);
    }
  
}
