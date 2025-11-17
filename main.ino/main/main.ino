#include <AFMotor_R4.h>


//motores utilizado no arduino
AF_DCMotor  motor1(1);
AF_DCMotor  motor2(2);
AF_DCMotor  motor3(3);
AF_DCMotor  motor4(4);


// Definindo pinos para o controle de velocidade dos motores
// #define ENA 10
// #define ENB 11

//modulo HC-06
//senha: 1234

//mudar pinos depois conforme esta no carrinho

/*
MOTOR 1 É O PRIMEIRO MOTOR ESQUERDO
MOTOR 2 É O SEGUNDO MOTOR ESQUERDO
MOTOR 3 É O PRIMEIRO MOTOR DIREITO
MOTOR 4 É O SEGUNDO MOTOR DIREITO
*/
int velocidade = 80;
int parar = 0;

void frente() {
  motor1.setSpeed(velocidade);
  motor2.setSpeed(velocidade);
  motor3.setSpeed(velocidade);
  motor4.setSpeed(velocidade);

  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);

}

void tras() {
  motor1.setSpeed(velocidade);
  motor2.setSpeed(velocidade);
  motor3.setSpeed(velocidade);
  motor4.setSpeed(velocidade);

  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);

}

void esquerda() {
  motor3.setSpeed(velocidade);
  motor4.setSpeed(velocidade);

  motor3.run(FORWARD);
  motor4.run(FORWARD);
}

void direita(){
  motor1.setSpeed(velocidade);
  motor2.setSpeed(velocidade);

  motor1.run(FORWARD);
  motor2.run(FORWARD);

}

void parado() {
  motor1.setSpeed(parar);
  motor2.setSpeed(parar);
  motor3.setSpeed(parar);
  motor4.setSpeed(parar);

  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}


void setup() {
  Serial.begin(9600);

  motor1.setSpeed(0);
  motor2.setSpeed(0);
  motor3.setSpeed(0);
  motor4.setSpeed(0);
}



char cha = ' ';

void loop() {

  if (Serial.available() > 0) {
    cha = Serial.read();
    delay(2);
  }

  if (cha == 'F') {
    frente();   
    Serial.println("Movendo para Frente");
  }

  if (cha == 'T') {
    tras();   
    Serial.println("Movendo para Tras");
  }

  if (cha == 'E') {
    esquerda();
    Serial.println("Movendo para Esquerda");
  }

  if (cha == 'D') {
    direita();   
    Serial.println("Movendo para Direita");
  }


  if (cha == 'P' || cha == 'p') {
    parado();        
    Serial.println("O carrinho esta parado");
  }
}

