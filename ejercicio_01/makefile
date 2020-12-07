CXX= g++
CXXFLAGS= -std=c++14 -g -Wall

Generadores ejecutable: cripto.o
	$(CXX) $(CXXFLAGS) cripto.o -o cripto
	touch archivo_codificado.txt
	touch archivo_descodificado.txt
	touch archivo_salida.txt
	touch archivo_entrada.txt
configurador.o: cripto.cc
	$(CC) $(CXXFLAGS) -c cripto.cc
clean:
	rm *.o cripto archivo_codificado.txt archivo_descodificado.txt 
clean_archivos:
	rm archivo_entrada.txt archivo_salida.txt
