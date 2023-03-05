#define C2  65
#define C3  131
#define GH2 104
#define GH3 208
#define AH2 116
#define AH3 233 
#define C4  262
#define DH3 155
#define DH4 311
#define AH4 466
#define C5  523
#define GH4 416
#define DH5 622 
#define AH5 932 
#define C6 1046
#define G4  392
#define G5 792
#define FH4 370
#define FH5 740
#define GH5 832
#define F4  344
#define F5 688
#define A4  440
#define A5 880
#define D4  288
#define D5  576
#define G3 198
#define E4 329
#define REST 0
#define B4 494
#define CH4 277
#define CH5 554
#define E5 659


int piezo = 8; 
int led = 7; 

volatile int beatlength = 150; 
float beatseparationconstant = 0.1;


// 2= 0.7sc


int chorus_and_verse_beggin[] = {
  B4,8, E5,4, D5,4,REST,8, E5,6, REST,16, D5,8, E5,8, B4,-16, D5,4, CH5,4, REST,8, CH5,8, D5,8, E5, 8, D5,8, CH5,8, CH5,4, CH5,4, D5,4, CH5,4,
  REST,-4, B4,8, E5,4, D5,4, REST,8, E5,6,REST,16, D5,8, E5,8, B4,-16, D5,4, CH5,4,REST,8, CH5,8, D5,8, E5, 8, D5,8, CH5,8, CH5,4, CH5,4, D5,4, CH5,4,

  
  B4,8, B4,8, B4,-8, E5,16, REST,-16,D5,8, D5,4, G4,8, G4,8, G4,8, B4,16, E5,16, 
  REST, -16, D5,8, D5,4,G4,8, G4,8, G4,8, B4,16, E5,16, REST, -16, D5,8, D5,8, D5,8, CH5,4, CH5,4, CH5, 8, D5,8, D5,8,
  B4,8, B4,8, B4,8, B4,-8, E5,16, REST,8, D5,8, D5,4, G4,8,G4,8, G4,8, B4,16, E5,16, REST, 16, D5,8, D5,4,
  G4,8, G4,8, G4,8, B4,16, E5,16,REST,16, D5,8, D5,8, D5,8, CH5,4, CH5,4, CH5,8, D5,8, D5,8, B4,8,

   
};

int notes = sizeof(chorus_and_verse_beggin) / sizeof(chorus_and_verse_beggin[0]) / 2;

int wholenote = (70000 * 4) / beatlength;

int divider = 0, noteDuration = 0;

void setup() {
  for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {

    divider = chorus_and_verse_beggin[thisNote + 1];
    if (divider > 0) {
      noteDuration = (wholenote) / divider;
    } else if (divider < 0) {
      noteDuration = (wholenote) / abs(divider);
      noteDuration *= 1.5; 
    }

    tone(piezo, chorus_and_verse_beggin[thisNote], noteDuration*0.9);

    delay(noteDuration);
    
    
    noTone(piezo);
  }
}

void loop() {
  
}
