class Display {


  private:
    int A_PIN;
    int B_PIN;
    int C_PIN;
    int D_PIN;
    int E_PIN;
    int F_PIN;
    int G_PIN;
    int D1_PIN;
    int D2_PIN;
    int D3_PIN;
    int D4_PIN;


    void lambaParcalariniYak(int* yakilacaklarParcalar){
      for(int i = 0; i < 7; i++){
          digitalWrite(segmentPininiGetir(i),yakilacaklarParcalar[i] ? HIGH : LOW);
      }
    }

    int segmentPininiGetir(int i){
      switch(i){
        case 0:
          return A_PIN;
        case 1:
          return B_PIN;
        case 2:
          return C_PIN;
        case 3:
          return D_PIN;
        case 4:
          return E_PIN;
        case 5:
          return F_PIN;
        case 6:
          return G_PIN;
      }
    }

    int basamakPininiGetir(int basamakNumarasi){
      switch(basamakNumarasi){
        case 0:
          return D1_PIN;
        case 1:
          return D2_PIN;
        case 2:
          return D3_PIN;
        case 3:
          return D4_PIN;
      }
    }


  public:
      const static int numbersInputs[10][7];
    // Constructor tanımlaması
    Display(int d4, int a, int f, int d3, int d2, int b, int e, int d, int c, int g, int d1)
      : A_PIN(a), B_PIN(b), C_PIN(c), D_PIN(d), E_PIN(e), F_PIN(f), G_PIN(g), D1_PIN(d1), D2_PIN(d2), D3_PIN(d3), D4_PIN(d4) {
        pinMode(a,OUTPUT);
        pinMode(b,OUTPUT);
        pinMode(c,OUTPUT);
        pinMode(d,OUTPUT);
        pinMode(e,OUTPUT);
        pinMode(f,OUTPUT);
        pinMode(g,OUTPUT);
        pinMode(d1,OUTPUT);
        pinMode(d2,OUTPUT);
        pinMode(d3,OUTPUT);
        pinMode(d4,OUTPUT);
        this->turnOffAllNumbers();
    }

    void turnNthLamp(int basamak_numarasi,int number){
      if(number > 9 && number < 0){
        return;
      }
      if(basamak_numarasi < 0 && basamak_numarasi > 3){
        return;
      }
      digitalWrite(basamakPininiGetir(basamak_numarasi),LOW);
      lambaParcalariniYak(numbersInputs[number]);
    }

    void writeNumber(int number){
      int i = 0;
      while(number){
        turnOffAllNumbers();
        turnNthLamp(i, number % 10);
        number /= 10;
        ++i;
      }
    }

        
    void turnOffAllNumbers(){
      for(int i = 0; i < 4 ; i++){
        digitalWrite(segmentPininiGetir(i),LOW);
        digitalWrite(basamakPininiGetir(i),HIGH);
      }
    }
    
};

const int Display::numbersInputs[10][7] = {
    // A,B,C,D,E,F,G
      {1,1,1,1,1,1,0}, // 0
      {0,1,1,0,0,0,0}, // 1
      {1,1,0,1,1,0,1}, // 2
      {1,1,1,1,0,0,1}, // 3
      {0,1,1,0,0,1,1}, // 4
      {1,0,1,1,0,1,1}, // 5
      {1,0,1,1,1,1,1}, // 6
      {1,1,1,0,0,0,0}, // 7
      {1,1,1,1,1,1,1}, // 8
      {1,1,1,1,0,1,1}, // 9
    };




Display display(5,6,7,4,3,8,9,10,11,12,2);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
}
int i = 0;
void loop() {
  // put your main code here, to run repeatedly:
  display.turnOffAllNumbers();

  display.writeNumber(i++);

}
