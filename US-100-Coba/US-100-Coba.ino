#include <SoftwareSerial.h>

const int US100_TX_Depan = 4;
const int US100_RX_Depan = 5;


SoftwareSerial sensorUS100Depan(US100_RX_Depan, US100_TX_Depan);

unsigned int MSByteDistDepan = 0;
unsigned int LSByteDistDepan = 0;
unsigned int mmDistDepan = 0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  sensorUS100Depan.begin(9600);
}


void sensorDepan(){
    sensorUS100Depan.listen();
    sensorUS100Depan.flush();
    sensorUS100Depan.write(0x55);
        Serial.println(sensorUS100Depan.available());
    if(sensorUS100Depan.available() > 0) {
      Serial.println(sensorUS100Depan.available());
    MSByteDistDepan = sensorUS100Depan.read();
    LSByteDistDepan = sensorUS100Depan.read();
    mmDistDepan = MSByteDistDepan * 256 + LSByteDistDepan;
    if((mmDistDepan > 1) && (mmDistDepan < 10000)) {
        Serial.print("Distance Depan: ");
        Serial.print(mmDistDepan, DEC);
        Serial.println(" mm");
      }
    }
    
    sensorUS100Depan.flush();
    sensorUS100Depan.write(0x50);
  }


   
void loop() {
  // put your main code here, to run repeatedly:
  sensorDepan();

      

  delay(50);
}
