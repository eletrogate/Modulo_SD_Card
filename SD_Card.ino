/*
  SD card read/write

  Esse exemplo mostra como ler e escrever dados no cartão SD
  O circuito:
   cartão SD conectado ao SPI da seguinte maneira:
 ** MOSI - pino 11
 ** MISO - pino 12
 ** CLK - pino 13
 ** SDCS - pino 4

  created   Nov 2010
  by David A. Mellis
  modified 9 Apr 2012
  by Tom Igoe

  This example code is in the public domain.

*/

#include <SPI.h>
#include <SD.h>

File myFile;

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ; // Espera a porta serial conectar
  }


  Serial.print("Inicializando cartão SD...");

  if (!SD.begin(4)) {
    Serial.println("Falha na inicialização!");
    while (1);
  }
  Serial.println("Inicialização feita.");

  // Abre o arquivo. Perceba que apenas um arquivo pode ser aberto nesse momento,
  // portanto você terá que fechar este antes de abrir outro
  myFile = SD.open("test.txt", FILE_WRITE);

  // Se este arquivo abriu corretamente, escreva nele:
  if (myFile) {
    Serial.print("Escrevendo para test.txt...");
    myFile.println("testando 1, 2, 3.");
    // fecha o arquivo:
    myFile.close();
    Serial.println("feito.");
  } else {
    // Se este arquivo não abriu, imprima um erro:
    Serial.println("Erro ao abrir test.txt");
  }

  // Abre novamente o arquivo para leitura:
  myFile = SD.open("test.txt");
  if (myFile) {
    Serial.println("test.txt:");

    // Lê do arquivo até não ter mais nada nele:
    while (myFile.available()) {
      Serial.write(myFile.read());
    }
    // fecha o arquivo:
    myFile.close();
  } else {
    // Se este arquivo não abriu, imprima um erro:
    Serial.println("Erro ao abrir test.txt");
  }
}

void loop() {
  // nada acontece depois do setup
}