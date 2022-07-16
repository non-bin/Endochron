// #include "RTClib.h"

// RTC_DS1307 rtc;

const int anode = 8;
//                   A,B,C,D,E, F,G,DP
const int segs[8] = {2,3,7,5,10,1,0,8};

// DP,G,F,E,D,C,B,A
const unsigned char segChars[16] = {
  0b00111111, // 0
  0b00000110, // 1
  0b01011011, // 2
  0b01001111, // 3
  0b01100110, // 4
  0b01101101, // 5
  0b01111101, // 6
  0b00000111, // 7
  0b01111111, // 8
  0b01100111, // 9
  0b01110111, // A
  0b01111100, // B
  0b00111001, // C
  0b01011110, // D
  0b01111001, // E
  0b01110001  // F
};

void display(char c) {
  for (char i=0; i<8; i++) {
    digitalWrite(segs[i], (c & (1<<i)) ? LOW : HIGH);
  }
}

void flash(char c) {
  display(c);
  delay(300);
  display(0);
  delay(200);
}

void sleep() {
  while(1);
}

// the setup routine runs once when you press reset:
void setup() {
  pinMode(anode, OUTPUT);
  digitalWrite(anode, HIGH);

  for (char i=0; i<8; i++) {
    pinMode(segs[i], OUTPUT);
    digitalWrite(segs[i], HIGH);
  }

  // if (! rtc.begin()) {
  //   flash(segChars[0xE]);
  //   flash(segChars[0xE]);
  //   flash(segChars[0xE]);
  //   sleep();
  // }

  // if (! rtc.isrunning()) {
  //   // Serial.println("RTC is NOT running, let's set the time!");
  //   // When time needs to be set on a new device, or after a power loss, the
  //   // following line sets the RTC to the date & time this sketch was compiled
  //   rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  //   flash(0b10000000);
  // }

  // DateTime now = rtc.now();
  // flash(segChars[now.hour()/10]);
  // flash(segChars[now.hour()%10]);
  // flash(segChars[now.minute()/10]);
  // flash(segChars[now.minute()%10]);

  flash(segChars[0xB]);
  flash(segChars[0xE]);
  flash(segChars[0xE]);
  flash(0b01110011);

  sleep();
}

void loop() {}
