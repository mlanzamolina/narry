#ifndef PLANESTUDIO_H 
#define PLANESTUDIO_H
#include <iostream>
#include "string.h"
#include "cstring"

using namespace std;
struct materia
{
    /* data */
    int codigo;
    char *nombre;
    int uv;
    int cantidadHijos;
    materia ** hijos;
    materia(int _codigo,const char*_nombre,int _uv)
    {
        codigo=_codigo;
        nombre = new char[strlen(_nombre)];
        strcpy(nombre,_nombre);
        uv=_uv;
        cantidadHijos=0;
        hijos=0;
    }
};
class planEstudio
{
private:
    materia*raiz;

public:
    materia*buscarRec(materia*,int);
    planEstudio(/* args */);
    void agregarMateria(int,const char*,int,int);
    materia*buscar(int);
    void imprimir();
    bool estaVacio();
    void imprimirRec(materia*);
  
};





#endif //PLANESTUDIO_H