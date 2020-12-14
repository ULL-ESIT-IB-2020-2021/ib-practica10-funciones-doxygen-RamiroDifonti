/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica
  *
  * @file cripto.cc
  * @author Difonti Dome, Ramiro Nicolás
  * @date 7/12/20
  * @brief El programa encripta o desencripta un archivo .txt
  * @bug No hay bugs conocidos
  */
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <bitset>
#include <vector>

std::string texto_usage = "fichero_entrada fichero_salida metodo password operacion\nFichero_entrada: Fichero a codificar\nFichero_salida:  Fichero codificado \nMetodo:          Indica el metodo de encripado\n                   1: Cifrado xor\n                   2: Cifrado de Cesar\nPassword:        Palabra secreta en el caso de metodo 1, valor de K en el metodo 2\nOperación:       Operacion a realizar en el fichero\n                   +: encriptar el fichero\n                   -:desencriptar el fichero\n";
               
void Usage(int argc, char* argv[]){
  if(argc!=6 && argc!=2){
    std::cout<<"Error en la sintaxis del programa, por favor introduzca "<<argv[0]<<" --help"<<std::endl;
    exit(EXIT_SUCCESS);
  }
  std::string parameter = argv[1];
  if(parameter=="--help"&&argc==2){
    std::cout<<"Modo de uso: "<<argv[0]<<" "<<texto_usage;
    exit(EXIT_SUCCESS);
  }

  int numero_metodo = strtol(argv[3],0,10);
  if(numero_metodo!=2 &&numero_metodo!=1){
    std::cout<<"Error en la sintaxis del programa, por favor introduzca "<<argv[0]<<" --help"<<std::endl;
    exit(EXIT_SUCCESS); 
  }
  if(numero_metodo==2){
    unsigned i;
    std::string password = argv[4];
    for(i=0;i!=password.length();i++){
      if(password[i]>57||password[i]<48){
        std::cout<<"Error en la sintaxis del programa, por favor introduzca "<<argv[0]<<" --help"<<std::endl;
        exit(EXIT_SUCCESS);
    }
    }
  }
  std::string char_operacion = argv[5];
  if(char_operacion!="+"&&char_operacion!="-"){
    std::cout<<"Error en la sintaxis del programa, por favor introduzca "<<argv[0]<<" --help"<<std::endl;
    exit(EXIT_SUCCESS);  
  }
}
void Foreword() {
  std::cout << "Este programa encripta o desencripta un archivo de texto.\nPor favor, escriba en el archivo archivo_entrada.txt un mensaje que quiera codificar antes de utilizar el programa.\nTambién puede escribir un mensaje codificado en el archivo archivo_salida.txt, y si tiene su correcta contraseña se descodificará." << std::endl;
  std::cout << "Estos dos archivos se han creado anteriormente con el make, también se crearon los archivos codificado.txt y descodificado.txt que dan los resultados del codificador, dependiendo de lo que elija."<<std::endl;
}
void cripto_funcion(char* argv[]){
  unsigned i,j;
  int metodo= strtol(argv[3],0,10);

//METODO DE CODIFICACION XOR
  if(metodo==1){
    std::string operacion = argv[5],password = argv[4], entrada= argv[1], salida=argv[2], frase;
  
    std::vector<std::string> vector_password(password.length());

    for(i=0;i!=password.length();i++){
      vector_password[i]=password[i];
    }

    std::ofstream archivo_descodificado,archivo_codificado;  //CREACION DEL OFSTREAM Y IFSTREAM PARA LOS ARCHIVOS .TXT
    std::ifstream salida_lectura,entrada_lectura;

    if(operacion=="+"){

      archivo_codificado.open("archivo_codificado.txt");
      entrada_lectura.open(entrada);

      while(std::getline (entrada_lectura, frase)){
        std::vector<std::string> vector_frases(frase.length());

        for(j=0,i=0;i!=frase.length();j++,i++){

          std::string letra = vector_password[j];

          int bit1= letra[0];
          char letra2 = frase[i];
          int bit2= letra2;
          int bit3= bit1^bit2;
          char bit_final = bit3+31; 
          archivo_codificado<< bit_final;

          if(j==vector_password.size()-1){
            j=0;
          }
        }
        archivo_codificado<<"\n";
      }
       archivo_codificado.close();
       entrada_lectura.close();
    }
    if(operacion=="-"){

      archivo_descodificado.open("archivo_descodificado.txt");  //ABRIR ARCHIVOS .TXT
      salida_lectura.open(salida);

      while(std::getline (salida_lectura, frase)){
        std::vector<std::string> vector_frases(frase.length());

        for(j=0,i=0;i!=frase.length();j++,i++){

          std::string letra = vector_password[j];
          int bit1= letra[0];
          char letra2 = frase[i]-31;  //-31 para deshacer el cambio que hice en el codificador
          int bit2= letra2;
          int bit3= bit1^bit2;
          char bit_final = bit3; 
          archivo_descodificado<< bit_final;
          
          if(j==vector_password.size()-1){  // REPETIR LA PALABRA PASSWORD HASTA QUE SE ACABE LA FRASE DEL .TXT
            j=0;
          }
        }
        archivo_descodificado<<"\n";  //SEPARAR CADA FRASE DEL .TXT
      }
       archivo_descodificado.close();
       salida_lectura.close();
    }

//METODO DE CODIFICACION CESAR
    }
  if(metodo==2){
    std::string operacion = argv[5], entrada= argv[1], salida=argv[2], frase;
    int password= strtol(argv[4],0,10);
  
    std::ofstream archivo_descodificado,archivo_codificado;
    std::ifstream salida_lectura,entrada_lectura;

   
    if(operacion=="+"){

      archivo_codificado.open("archivo_codificado.txt");
      entrada_lectura.open(entrada);

      while(std::getline (entrada_lectura, frase)){

        for(i=0;i!=frase.length();i++){
          char letra = frase[i];
          letra = letra + password;
          archivo_codificado<<letra;
        }
        archivo_codificado<<"\n";
      }

    archivo_codificado.close();
    archivo_codificado.close();
    }
    if(operacion=="-"){

      salida_lectura.open(salida);
      archivo_descodificado.open("archivo_descodificado.txt");

      while(std::getline(salida_lectura, frase)){

        for(i=0;i!=frase.length();i++){
          char letra = frase[i];
          letra = letra - password;
          archivo_descodificado<<letra;
        }
        archivo_descodificado<<"\n";
      }
    archivo_descodificado.close();
    salida_lectura.close();
    }
  }
}
