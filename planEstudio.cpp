#include "planEstudio.h"
planEstudio::planEstudio():raiz(0)
{}

bool planEstudio::estaVacio()
{
    return raiz==0;
}
void planEstudio::agregarMateria(int codigo, const char* nombre,int uv,int codigoPadre)
{
    materia *nuevo=new materia(codigo,nombre,uv);

    if (estaVacio())
    {
        raiz=nuevo;
        return;
    }
    materia * padre=buscar(codigoPadre);
    if (padre==0)
    {
        cout<<"Codigo de clase requisito incorrecto";
        delete nuevo;
        return;
    }
    //crear copia de hijos
    materia ** tmpHijos = new materia * [padre->cantidadHijos + 1];
    for (int i = 0; i < padre->cantidadHijos; i++)
    {
        tmpHijos[i]=padre->hijos[i];
    }
    tmpHijos[padre->cantidadHijos]=nuevo;

    if (padre->cantidadHijos!=0)
    {
        delete padre->hijos;
    }
    padre->cantidadHijos++;

    
    padre->hijos=tmpHijos;
    cout<<"\nmateria ingresada";
}
materia* planEstudio::buscar(int codigoPadre)
{
   return buscarRec(raiz,codigoPadre);
}
materia* planEstudio::buscarRec(materia*raiz,int codigoPadre)
{
    if (raiz==0)
    {
        return 0;
    }

    if(raiz->codigo==codigoPadre)
    {
        return raiz;
    }
    
    for (int i = 0; i < raiz->cantidadHijos; i++)
    {
        materia*tmp=buscarRec(raiz->hijos[i],codigoPadre);
        if (tmp!=0)
        {
            return tmp;
        }
        
    }
    return 0;
    
}
void planEstudio::imprimir()
{
     imprimirRec(raiz);
}
void planEstudio::imprimirRec(materia* raiz)
{
    if (raiz==0)
    {
        /* code */
        return;
    }
    cout<<"materia[ codigo: "<<raiz->codigo<<", nombre: "<<raiz->nombre<<"]\n";

    for (int i = 0; i < raiz->cantidadHijos; i++)
    {
        /* code */
        imprimirRec(raiz->hijos[i]);
    }
    
  
}