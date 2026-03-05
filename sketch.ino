const int PINO_SENSOR_UMIDADE =  4;
const int PINO_LED_SECO = 2;

const int PINO_LED_MOLHADO = 15;

const int LIMIAR_SECO = 2000;


void setup() {
  Serial.begin(115200);
  
  pinMode(PINO_LED_SECO, OUTPUT);
  pinMode(PINO_LED_MOLHADO, OUTPUT);
}

void loop() {
  int valor_umidade = analogRead(PINO_SENSOR_UMIDADE);

  Serial.print("Valor sensor: ");
  Serial.println(valor_umidade);

  if (valor_umidade > LIMIAR_SECO) {
    Serial.println("ALERTA: solo seco! É hora de regar");
    digitalWrite(PINO_LED_SECO, HIGH);
    digitalWrite(PINO_LED_MOLHADO, LOW);
  } else {
    Serial.println("Solo úmido. Tudo Certo!");
    digitalWrite(PINO_LED_SECO, LOW);
    digitalWrite(PINO_LED_MOLHADO, HIGH);
  }

  delay(5000);
}
