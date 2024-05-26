const int anoda[] = { 9, 4, 17, 6, 10, 16, 11, 14 };
const int katoda[] = { 5, 12, 13, 8, 15, 7, 3, 2 };
const int pole[8][8] =
{
{0, 1, 0, 1, 0, 1, 1, 1},
{0, 1, 1, 1, 0, 1, 1, 1}, 
{0, 1, 0, 1, 0, 1, 1, 1}, 
{0, 1, 1, 1, 0, 1, 1, 1}, 
{0, 1, 0, 1, 0, 1, 1, 1}, 
{0, 1, 1, 1, 0, 1, 1, 1}, 
{0, 1, 0, 1, 0, 1, 1, 1},
{0, 1, 1, 1, 0, 1, 1, 1}
};

const int velikostPole = 28;
int pozice = 0;

const int napis[8][velikostPole] = {
  { 0, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 0, 0 },
  { 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0 },
  { 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0 },
  { 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
};


void setup() {
  for (int i = 0; i < 8; i++) {
    pinMode(anoda[i], OUTPUT);
    pinMode(katoda[i], OUTPUT);
    digitalWrite(anoda[i], LOW);
    digitalWrite(katoda[i], HIGH);
  }
}
void loop(){
  for(int i = 0; i < 70; i++)
  vykresleni();
  pozice++;
}
void vykresleni() {
  for( int j = 0; j < 8; j++)
  {
    digitalWrite(katoda[j], LOW);
    for (int i = 0; i < 8;i++)
    {
      digitalWrite(anoda[i], napis[i][( j + pozice) - abs((j+pozice)/ velikostPole) * velikostPole]);
      //delay(150);
    }
        for (int i = 0; i < 8;i++)
    {
      digitalWrite(anoda[i], LOW);
      //delay(150);
    }
    digitalWrite(katoda[j], HIGH);
  }
  /*
  digitalWrite(anoda[0], HIGH); 
  digitalWrite(anoda[1], HIGH);
  digitalWrite(anoda[2], HIGH);
  digitalWrite(anoda[3], HIGH);
  digitalWrite(anoda[4], HIGH);
  digitalWrite(anoda[5], HIGH);
  digitalWrite(anoda[6], HIGH);
  digitalWrite(anoda[7], HIGH);
  
  //1.SLOUPEC
  digitalWrite(katoda[0], LOW);

  digitalWrite(anoda[1], HIGH);
  digitalWrite(anoda[3], HIGH);
  digitalWrite(anoda[5], HIGH);

  digitalWrite(katoda[0], HIGH);

  digitalWrite(anoda[1], LOW);
  digitalWrite(anoda[3], LOW);
  digitalWrite(anoda[5], LOW);

  //2.SLOUPEC
  digitalWrite(katoda[1], LOW);

  digitalWrite(anoda[0], HIGH);
  digitalWrite(anoda[2], HIGH);
  digitalWrite(anoda[4], HIGH);

  digitalWrite(katoda[1], HIGH);

  digitalWrite(anoda[0], LOW);
  digitalWrite(anoda[2], LOW);
  digitalWrite(anoda[4], LOW);
  */
}
