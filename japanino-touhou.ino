// Japanino Touhou by hiromichinomata
// based on Japanino POV by Musashinodenpa, doremi by Tom Igoe

#include "pitches.h"

#define LEDPIN 7     // どのピンからLEDをつなぐか
#define SWPIN 6      // スイッチをつなぐピン

// 音程
int melody[] = {
 NOTE_F4, NOTE_DF4, NOTE_E4, NOTE_C4, NOTE_G4, NOTE_E4, NOTE_EF4, NOTE_GF4,
 NOTE_F4, NOTE_DF4, NOTE_E4, NOTE_C4, NOTE_G4, NOTE_E4, NOTE_EF4,
 NOTE_F4, NOTE_DF4, NOTE_E4, NOTE_C4, NOTE_G4, NOTE_E4, NOTE_EF4, NOTE_GF4,
 NOTE_F4, NOTE_DF4, NOTE_E4, NOTE_C4, NOTE_G4, NOTE_E4, NOTE_EF4,
 NOTE_BF3, NOTE_F4, NOTE_C4, NOTE_F4, NOTE_DF4, NOTE_EF4, NOTE_F4, NOTE_EF4, NOTE_G4,
 NOTE_BF4, NOTE_F4, NOTE_C5, NOTE_DF5, NOTE_C5, NOTE_DF5, NOTE_C5, NOTE_BF4, NOTE_AF4,
 NOTE_F4, NOTE_AF4, NOTE_EF4, NOTE_F4, NOTE_DF4,
 NOTE_BF3, NOTE_F4, NOTE_C4, NOTE_F4, NOTE_DF4, NOTE_EF4, NOTE_F4, NOTE_EF4, NOTE_G4,
 NOTE_BF4, NOTE_F4, NOTE_C5, NOTE_DF5, NOTE_C5, NOTE_DF5, NOTE_C5, NOTE_BF4, NOTE_AF4,
 NOTE_BF4
};

// 音の長さ 4→四分音符、8→八分音符）
int noteDurations[] = {
 4,4,4,4,4,4,4,4,
 4,4,4,4,4,4,2, // 15
 4,4,4,4,4,4,4,4,
 4,4,4,4,4,4,2, // 15
 4,4,4,4,4,8,8,4,4,
 8,8,8,8,8,16,16,8,8,
 8,8,8,8,2, // 23
 4,4,4,4,4,8,8,4,4,
 8,8,8,8,8,16,16,8,8,
 1 // 19
};

// ビットマップ(画像)を定義
byte bitmap[] = {
0b00000001,
0b00000010,
0b00000101,
0b00000010,
0b00001101,
0b00000010,
0b00011101,
0b00000010,
0b00111101,
0b00000010,
0b00000101,
0b00000010,
0b00011101,
0b00000010,
0b00001101,
0b00000010,
0b00000101,
0b00000010,
0b00000001,
0b10000000   // 最後の行は0b10000000(つまり目印)
};


unsigned char pos = 0;  // 現在のビットマップ中の位置
unsigned char i = 0;


void setup() {
// LEDが接続されたピンを出力に設定します
for(char pin = LEDPIN; pin < LEDPIN + 7; pin++) {
  pinMode(pin, OUTPUT);
}
pinMode(SWPIN, INPUT);      // スイッチのピンを入力に
digitalWrite(SWPIN, HIGH);  // 内蔵プルアップ有効
}

void loop() {
 // メロディの音程を順番に奏でる。
 for (int thisNote = 0; thisNote < 72; thisNote++) {
   // 音の長さを計算する。
   // 1秒＝1000を、音の長さの数値で割る。
   // 四分音符なら1000/4、八分音符なら1000/8
   int noteDuration = 1500/noteDurations[thisNote];
   tone(14, melody[thisNote], noteDuration);

   // 音と音の間に無音の時間を設ける。
   // 音の長さの30%増しくらいがちょうどいい。
   int pauseBetweenNotes = noteDuration * 1.30;
   delay(pauseBetweenNotes);
 }
 delay(1000);  // メロディが終わったら1秒待って繰り返す。
}

//void loop() {
//
//if(digitalRead(SWPIN) == LOW) {  // スイッチがオンならば1回描画
//
//  delay(6);  // すぐ始めると詰まって見えるのでちょっと待つ
//  pos = 0;
//
//  while(bitmap[++pos] != 0b10000000) {  // ビットマップの端まで繰り返し
//    for(i = 0; i < 7; i++) {  // ビットマップの高さの分だけ繰り返し
//      // ビットマップデータから1ビットを取り出してピンの状態に反映
//      digitalWrite(LEDPIN + 6 - i, (bitmap[pos] >> i) & 0b00000001);
//    }
//    delay(1);  // LEDが光っている時間
//  }
//
//  for(i = LEDPIN; i < LEDPIN + 7; i++) {  // 全ドット、消灯
//    digitalWrite(i, LOW);
//  }
// }
//}
