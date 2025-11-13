#define IN1 7                      
#define IN2 6                      
#define IN3 5                      
#define IN4 4

// Definindo pinos para o controle de velocidade dos motores
// #define ENA 10                       
// #define ENB 11  

//mudar pinos depois conforme esta no carrinho

/*
IN1 = primeiro motor esquerdo  
IN2 = segundo motor esquerdo
IN3 = primeiro motor direito 
IN4 = segundo motor direito
*/

void setup()
{

  Serial.begin(9600);

  //Definindo moto
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

char cha;

void loop()
{
  if (Serial.available() > 0) {
    cha = Serial.read();
    delay(2);
  }

  if (cha == 'F') {
    moverFrente();
    Serial.println("Movendo para Frente");
  }

  if (cha == 'B') {
    moverTras();
    Serial.println("Movendo para Tras");
  }

  if (cha == 'R') {
    moverDireito();
    Serial.println("Movendo para Direita");
  }
  if (cha == 'L') {
    moverEsquerda();
    Serial.println("Movendo para Esquerda");
  }

  if ( cha == '0') {
    semMovimento();
    Serial.println("O carrinho esta parado");
  }

}

void loop() {
  // put your main code here, to run repeatedly:

}


//VERIFICAR DEPOIS A LOGICA DE MOTORES DA PLACA SHIELD
void frearMotores(){

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);

}

void moverFrente(){
  digitalWrite(IN1, HIGH); 
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, HIGH);
}

void moverTras(){
  digitalWrite(IN1, LOW); 
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void moverEsquerda(){
  digitalWrite(IN1, LOW); 
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, HIGH);

  /*
  IN1 = primeiro motor esquerdo  
  IN2 = segundo motor esquerdo
  IN3 = primeiro motor direito 
  IN4 = segundo motor direito
*/

}

void moverDireito(){
  digitalWrite(IN1, HIGH); // tem que ser o mesmo sentido os dois motores
  digitalWrite(IN2, HIGH); // tem que ser o mesmo sentido os dois motores
  digitalWrite(IN3, LOW); /*desligados ou movimentar sentido contrario dos outros motores*/
  digitalWrite(IN4, LOW);

}

void semMovimento(){
  digitalWrite(IN1, LOW); 
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
