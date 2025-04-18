#include <SoftwareSerial.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>



LiquidCrystal_I2C lcd(0x27, 16, 2);  // Change the HEX address
Servo myservo1;

int IR1 = 8;
int IR2 = 9;
int Slot = 3;  // Enter Total number of parking Slots

int flag1 = 0;
int flag2 = 0;

SoftwareSerial nodemcu(2, 3);

int parking1_slot1_ir_s = 5; // parking slot1 infrared sensor connected with pin number 5 of Arduino
int parking1_slot2_ir_s = 6; // parking slot2 infrared sensor connected with pin number 6 of Arduino
int parking1_slot3_ir_s = 7; // parking slot3 infrared sensor connected with pin number 7 of Arduino

String sensor1;
String sensor2;
String sensor3;

String cdata = "";  // Complete data, consisting of sensor values

void setup() {
  delay(2000);
  lcd.begin(16, 2);  // Initialize the LCD with 16 columns and 2 rows
  lcd.backlight();
  
  pinMode(IR1, INPUT);
  pinMode(IR2, INPUT);
  
  myservo1.attach(10);
  myservo1.write(100);

  lcd.setCursor(0, 0);
  lcd.print("     PARKEASE    ");
  lcd.setCursor(0, 1);
  lcd.print(" PARKING CENTER ");
  delay(3000);
  lcd.clear();

  Serial.begin(9600);
  nodemcu.begin(9600);

  pinMode(parking1_slot1_ir_s, INPUT);
  pinMode(parking1_slot2_ir_s, INPUT);
  pinMode(parking1_slot3_ir_s, INPUT);
}

void loop() {
  // Car enters
  if (digitalRead(IR1) == LOW && flag1 == 0) {
    if (Slot > 0) {
      flag1 = 1;
      if (flag2 == 0) {
        myservo1.write(0);
        Slot = Slot - 1;
      }
    } else {
      lcd.setCursor(0, 0);
      lcd.print("    SORRY :(    ");
      lcd.setCursor(0, 1);
      lcd.print("  Parking Full  ");
      delay(3000);
      lcd.clear();
    }
  }

  // Car exits
  if (digitalRead(IR2) == LOW && flag2 == 0) {
    flag2 = 1;
    if (flag1 == 0) {
      myservo1.write(0);
      Slot = Slot + 1;
    }
  }

  // Reset flags and close gate
  if (flag1 == 1 && flag2 == 1) {
    delay(1000);
    myservo1.write(100);
    flag1 = 0;
    flag2 = 0;
  }

  // Display available slots
  lcd.setCursor(0, 0);
  lcd.print("    WELCOME!    ");
  lcd.setCursor(0, 1);
  lcd.print("Slot Left: ");
  lcd.print(Slot);

  // Check parking slots status
  p1slot1();
  p1slot2();
  p1slot3();

  // Send data to NodeMCU
  cdata = sensor1 + "," + sensor2 + "," + sensor3;
  Serial.println(cdata);
  nodemcu.println(cdata);

  delay(3000);
  cdata = "";  // Reset data for next loop

  digitalWrite(parking1_slot1_ir_s, HIGH);
  digitalWrite(parking1_slot2_ir_s, HIGH);
  digitalWrite(parking1_slot3_ir_s, HIGH);
}

void p1slot1() {  // Parking slot 1
  if (digitalRead(parking1_slot1_ir_s) == LOW) {
    sensor1 = "255";  // Slot occupied
    delay(200);
  }
  if (digitalRead(parking1_slot1_ir_s) == HIGH) {
    sensor1 = "0";  // Slot free
    delay(200);
  }
}

void p1slot2() {  // Parking slot 2
  if (digitalRead(parking1_slot2_ir_s) == LOW) {
    sensor2 = "255";  // Slot occupied
    delay(200);
  }
  if (digitalRead(parking1_slot2_ir_s) == HIGH) {
    sensor2 = "0";  // Slot free
    delay(200);
  }
}

void p1slot3() {  // Parking slot 3
  if (digitalRead(parking1_slot3_ir_s) == LOW) {
    sensor3 = "255";  // Slot occupied
    delay(200);
  }
  if (digitalRead(parking1_slot3_ir_s) == HIGH) {
    sensor3 = "0";  // Slot free
    delay(200);
  }
}
