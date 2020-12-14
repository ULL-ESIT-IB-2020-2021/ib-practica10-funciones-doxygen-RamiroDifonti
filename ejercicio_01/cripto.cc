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
#include "funciones_cripto.h"

int main(int argc, char* argv[]){
  Usage(argc, argv);
  Foreword();
  cripto_funcion(argv);


}
