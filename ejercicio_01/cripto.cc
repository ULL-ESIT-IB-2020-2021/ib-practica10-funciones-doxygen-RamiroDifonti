/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica
  *
  * @file fibonacci_main.cc
  * @author F. de Sande fsande@ull.es
  * @date 23 Jun 2020
  * @brief El programa encripta o desencripta un archivo .txt
  * @bug No hay bugs conocidos
  * @see https://www.cs.cmu.edu/~410/doc/doxygen.html
  */
#include <iostream>
#include "funciones_cripto.h"

int main(int argc, char* argv[]){
  Usage(argc, argv);
  Foreword();
  cripto_funcion(argv);


}