// queue::push/pop
#include "Mascota.h"
#include "Evaluador.h"
#include <iostream>
#include <list>
#include <fstream>
using namespace std;

//Escribe los datos del objeto mascota dado en un archivo binario con el nombre dado en la posicion dada
//Nota: Se deben poder agregar varias mascotas en un solo archivo
void escribir(string nombre_archivo, Mascota*mascota, int posicion)
{
    nombre_archivo+=".txt";
    ofstream out(nombre_archivo.c_str(), ios::app);
    out.seekp(posicion*14,ios::beg);
    out.write(mascota->nombre.c_str(), 10);
    out.write((char*)&mascota->edad, 4);
    out.close();
}

//Devuelve una mascota previamente escrita (con la funcion escribir()) en un archivo binario con nombre dado en la posicion dada
//Nota: Se deben poder leer varias mascotas de un solo archivo
Mascota* leer(string nombre_archivo, int posicion)
{
    nombre_archivo+=".txt";
    ifstream in(nombre_archivo.c_str());
    in.seekg(posicion*14, ios::beg);
    char* nombre = new char[10];
    in.read(nombre, 10);
    string n = nombre;
    int edad;
    in.read((char*)&edad, 4);
    Mascota *m = new Mascota(edad, n);
    in.close();
    return m;
}

//Devuelve un vector que contenga todas las mascotas previamente escritas (con la funcion escribir()) en un archivo binario con nombre dado
//Nota: El vector debe contener las mascotas ordenadas de acuerdo a la posicion en la que se escribieron
vector<Mascota*> leerTodos(string nombre_archivo)
{
    vector<Mascota*>respuesta;
    return respuesta;
}

int main ()
{
    //Funcion evaluadora
    evaluar();
    return 0;
}
