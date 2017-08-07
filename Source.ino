

// variáveis
int gatilho = 13; // pino TRIG do sensor ultrassônico
int echo = 10; // pino ECHO do sensor ultrassônico
float tempo; // para armazenar o tempo de ida e volta do sinal em microsegundos
float distancia_cm; // para armazenar a distância em centímetros

// setup (executado apenas uma vez)
void setup() {
 Serial.begin(9600);
 // configura pino GATILHO como saída
 pinMode(gatilho,OUTPUT);
 // deixa pino em LOW
 digitalWrite(gatilho,LOW);
 delayMicroseconds(10);
 
 // configura pino ECHO como entrada
 pinMode(echo,INPUT);
}

 
// laço principal (executado indefinidamente)
void loop() {
 // disparar pulso ultrassônico
 digitalWrite(gatilho, HIGH);
 delayMicroseconds(1500);
 digitalWrite(gatilho, LOW);

 // medir tempo de ida e volta do pulso ultrassônico
 tempo = pulseIn(echo, HIGH);

 // calcular as distâncias em centímetros e polegadas
 distancia_cm = tempo / 29.4 / 2;

 // apresentar resultados no display LCD

 if(distancia_cm<3000){
 
   Serial.print("Distancia");
   Serial.print(distancia_cm);
   Serial.println(" cm.");

 }

 // aguardar um pouquinho antes de começar tudo de novo
 delayMicroseconds(1500);
}
