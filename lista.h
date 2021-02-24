/*
 * lista.h
 *
 *  Created on: 12 dic. 2020
 *      Author: usuario
 */
#include <iostream>
#ifndef LISTA_H_
#define LISTA_H_
#include "nodo.h"


template <class T> class Lista{
	private:
		void mirarResto();
		Nodo<T>* primero;
		int tamanio;
	public:
		Lista();
		Lista(const Lista<T>*&);
		Lista(const Lista<T>&);
		void agregarPrimero(T elemento);
		void agregarElemento(T elemento, int posicion);
		void agregarAlFinal(T elemento);
		bool estaIncluida(Lista<T>* lista);
		Lista<T>* interseccionLista(Lista<T>* lista);
		Lista<T>* unirListas(Lista<T>* lista);
		Lista<T>* restoListas(Lista<T>* lista);
		bool listasIguales(Lista<T>* lista);
		int devolverLongitud();
		void concatenarLista(Lista<T>* lista);
		T obtenerPrimero();
		T obtenerUltimo();
		T obtenerElemento(int posicion);
		int obtenerTamanio();
		bool elementoRepetido(T elemento);
		void eliminarElemento(int posicion);
		void eliminarPrimero();
		void eliminarUltimo();
		void eliminarPrimeraAparicion(T elemento);
		void imprimirLista();
		bool listaPalindroma();
		void listaInvertida();
		bool listaVacia();
		~Lista();
};

template <class T> Lista<T>::Lista(){
	this->primero = 0;
	this->tamanio = 0;
}

template <class T> Lista<T>::Lista(const Lista*& objeto){
	this->primero = objeto->primero;
	this->tamanio = objeto->tamanio;
}

template <class T> Lista<T>::Lista(const Lista& objeto){
	this->primero = objeto.primero;
	this->tamanio = objeto.tamanio;
}
template <class T> bool Lista<T>::estaIncluida(Lista<T>* lista){
	bool incluida = true;
	Nodo<T>* punteroAux = this->primero;
	Nodo<T>* punteroAux2 = lista->primero;
	while((punteroAux->obtenerSiguiente())&&(punteroAux2->obtenerSiguiente())){
	if (punteroAux->obtenerDato() != punteroAux2->obtenerDato()){
			incluida = false;
		}
		punteroAux = punteroAux->obtenerSiguiente();
		punteroAux2 = punteroAux2->obtenerSiguiente();
	}
	return incluida;
}

template <class T> Lista<T>* Lista<T>::interseccionLista(Lista* lista){
	Lista<T>* interseccion = new Lista<T>();
	Nodo<T>* punteroAux = this->primero;
	while((punteroAux)){
		bool encontro = false;
		Nodo<T>* punteroAux2 = lista->primero;
		while((punteroAux2) && (encontro == false)){
			if(punteroAux->obtenerDato() == punteroAux2->obtenerDato()){
				interseccion->agregarAlFinal(punteroAux->obtenerDato());
				encontro = true;
			}
			punteroAux2 = punteroAux2->obtenerSiguiente();
	}
		punteroAux = punteroAux->obtenerSiguiente();
	}
	return interseccion;
}

template <class T> Lista<T>* Lista<T>::unirListas(Lista<T>* lista){
	Lista<T>* unionListas = new Lista;
	Nodo<T>* punteroAux = primero;
	Nodo<T>* punteroAux2 = lista->primero;
	while(punteroAux2){
		unionListas->agregarAlFinal(punteroAux2->obtenerDato());
		punteroAux2 = punteroAux2->obtenerSiguiente();
	}
	while(punteroAux){
		unionListas->agregarAlFinal(punteroAux->obtenerDato());
		punteroAux = punteroAux->obtenerSiguiente();
	}
	return unionListas;
}

template <class T> Lista<T>* Lista<T>::restoListas(Lista* lista){
	Lista* resto = new Lista;
	Nodo<T>* punteroAux = primero;
	while((punteroAux)){
		bool encontro = false;
		Nodo<T>* punteroAux2 = lista->primero;
		while((punteroAux2) && (encontro == false)){
			encontro = (punteroAux->obtenerDato() == punteroAux2->obtenerDato());
			punteroAux2 = punteroAux2->obtenerSiguiente();
	}
		if (encontro == false){
			resto->agregarAlFinal(punteroAux->obtenerDato());
		}
		punteroAux = punteroAux->obtenerSiguiente();
	}
	punteroAux = lista->primero;
	while((punteroAux)){
		bool encontro = false;
		Nodo<T>* punteroAux2 = primero;
		while((punteroAux2) && (encontro == false)){
			encontro = (punteroAux->obtenerDato() == punteroAux2->obtenerDato());
			punteroAux2 = punteroAux2->obtenerSiguiente();
	}
		if (encontro == false){
			resto->agregarAlFinal(punteroAux->obtenerDato());
		}
		punteroAux = punteroAux->obtenerSiguiente();
	}
	return resto;
}

template <class T> bool Lista<T>::listasIguales(Lista<T>* lista){
	Nodo<T>* punteroAux = this->primero;
	bool mismaLista = true;
	while((punteroAux) && (mismaLista == true)){
		Nodo<T>* punteroAux2 = lista->primero;
		bool encontro = false;
		while((punteroAux2) && (encontro == false)){
			encontro = (punteroAux2->obtenerDato() == punteroAux->obtenerDato());
			punteroAux2 = punteroAux2->obtenerSiguiente();
		}
		if (encontro == false){
			mismaLista = false;
		}
		punteroAux = punteroAux->obtenerSiguiente();
	}
	return mismaLista;
}

template <class T> void Lista<T>::agregarPrimero(T elemento){
	Nodo<T>* punteroNodo = new Nodo<T>(elemento);
	if (this->listaVacia()){
		this->primero = punteroNodo;
	}
	else{
		Nodo<T>* punteroAuxiliar = punteroNodo;
		punteroAuxiliar->modificarSiguiente((this->primero));
		this->primero = punteroNodo;
	}
	this->tamanio++;
}

template <class T> void Lista<T>::agregarElemento(T elemento, int posicion){
	Nodo<T>* punteroAuxiliar = this->primero;
	Nodo<T>* punteroNodo = new Nodo<T>(elemento);
	if (this->listaVacia()){
		primero = punteroNodo;
	}
	else{
		int i = 1;
		while(i < (posicion-1)){
			punteroAuxiliar = punteroAuxiliar->obtenerSiguiente();
			i++;
		}
		punteroNodo->modificarSiguiente(punteroAuxiliar->obtenerSiguiente());
		punteroAuxiliar->modificarSiguiente(punteroNodo);
		this->tamanio++;}
}

template <class T> void Lista<T>::agregarAlFinal(T elemento){
	Nodo<T>* punteroAuxiliar = this->primero;
	Nodo<T>* punteroNodo = new Nodo<T>(elemento);

	if (this-> listaVacia()){
		this->primero = punteroNodo;
	}
	else{
			while (punteroAuxiliar->obtenerSiguiente()){
				punteroAuxiliar = punteroAuxiliar->obtenerSiguiente();
			}
			punteroAuxiliar->modificarSiguiente(punteroNodo);
		}
	this->tamanio++;
}
template <class T> bool Lista<T>::listaVacia(){
	return (this->primero == 0);
}

template <class T> T Lista<T>::obtenerPrimero(){
	return (this->primero)->obtenerDato();
}

template <class T> T Lista<T>::obtenerUltimo(){
	Nodo<T>* punteroAux = primero;
	while(punteroAux->obtenerSiguiente()){
		punteroAux = punteroAux->obtenerSiguiente();
	}

	return punteroAux->obtenerDato();

}

template <class T> T Lista<T>::obtenerElemento(int posicion)
{
 Nodo<T>* punteroAuxiliar = this->primero;
 unsigned int i = 1;
 while (i < posicion && punteroAuxiliar->obtenerSiguiente())
 {
	 punteroAuxiliar = punteroAuxiliar->obtenerSiguiente();
	 i++;
 }
 return punteroAuxiliar->obtenerDato();
}


template <class T> Lista<T>::~Lista()
{
 while (!(this->listaVacia()))
 this->eliminarElemento(1);
}

template <class T> void Lista<T>::eliminarElemento(int posicion)
{
 Nodo<T>* punteroAuxiliar = this->primero;
 if (posicion == 1 || !(this->primero->obtenerSiguiente()))
 {
	 this->primero = punteroAuxiliar->obtenerSiguiente();
 }
 else
 {
 unsigned i = 1;
 	 Nodo<T>* punteroAnterior;
 while (i < posicion && punteroAuxiliar->obtenerSiguiente())
 {
	 punteroAnterior = punteroAuxiliar;
	 punteroAuxiliar = punteroAuxiliar->obtenerSiguiente();
	 i++;
 }
 punteroAnterior->modificarSiguiente(punteroAuxiliar->obtenerSiguiente());
 }
 this->tamanio--;
}

template <class T> void Lista<T>::eliminarPrimero(){
	this->primero = this->primero->obtenerSiguiente();
	this->tamanio--;
}

template <class T> void Lista<T>::eliminarUltimo(){
	Nodo<T>* punteroAux = this->primero;
	Nodo<T>* punteroAnterior;
	int i = 0;
	while(i < (this->tamanio-1)){
		punteroAnterior = punteroAux;
		punteroAux = punteroAux->obtenerSiguiente();
		i++;
	}
	punteroAnterior->modificarSiguiente(NULL);
}

template <class T> void Lista<T>::eliminarPrimeraAparicion(T elemento){

	if (this->primero->obtenerDato() == elemento){
		eliminarPrimero();
	}
	else{
		Nodo<T>* punteroAux = (this->primero);
		Nodo<T>* punteroAnterior;

		while ( (punteroAux->obtenerSiguiente()) && (punteroAux->obtenerDato() != elemento)){
			punteroAnterior = punteroAux;
			punteroAux = punteroAux->obtenerSiguiente();
		}
		if (punteroAux->obtenerDato() == elemento && punteroAux->obtenerSiguiente() != NULL){
			punteroAnterior->modificarSiguiente((punteroAux->obtenerSiguiente()));
		}
		else if ((punteroAux->obtenerSiguiente() == NULL ) && (punteroAux->obtenerDato() == elemento)){
			punteroAnterior->modificarSiguiente(NULL);
		}}


	this->tamanio--;


}

template <class T> bool Lista<T>::elementoRepetido(T elemento){
	bool repetido = false;
	Nodo<T>* punteroAux = this->primero;
	while((punteroAux-> obtenerSiguiente()) && repetido == false){
		if (punteroAux->obtenerDato() == elemento){
			std::cout << "El elemento " << elemento << " está repetido y no se agregará a la lista de forma duplicada." << std::endl;
			repetido = true;
		}
		punteroAux = punteroAux->obtenerSiguiente();
	}
	return repetido;
}

template <class T> void Lista<T>::imprimirLista(){
	Nodo<T>* punteroAuxiliar = this->primero;
	int i = 0;
	while(punteroAuxiliar->obtenerSiguiente()){
		i++;
		std::cout << "En la posicion " << i+1 << " hay un valor: " << punteroAuxiliar-> obtenerDato() << std::endl;;
		punteroAuxiliar = punteroAuxiliar->obtenerSiguiente();
	}

}

template <class T> int Lista<T>::devolverLongitud(){
	Nodo<T>* punteroAux = this->primero;
	int longitud = 0;
	while(punteroAux){
		longitud++;
		punteroAux = punteroAux->obtenerSiguiente();
	}
	return longitud;
}

template <class T> void Lista<T>::concatenarLista(Lista<T>* lista){
	Nodo<T>* punteroAux = this->primero;
	Nodo<T>* punteroAux2 = lista->primero;
	while(punteroAux->obtenerSiguiente()){
		punteroAux = punteroAux->obtenerSiguiente();
	}
	punteroAux->modificarSiguiente(punteroAux2);
	this->tamanio+= lista->tamanio;
}

template <class T> bool Lista<T>::listaPalindroma(){
	bool palindroma = true;
	Lista<T> listaCopia;
	Nodo<T>* punteroAux = this->primero;
	while(punteroAux){
		listaCopia.agregarAlFinal(punteroAux->obtenerDato());
		punteroAux = punteroAux->obtenerSiguiente();

	}
	listaCopia.listaInvertida();
	punteroAux = this->primero;
	Nodo<T>* punteroAux2 = listaCopia.primero;
	if (this->tamanio == listaCopia.tamanio){
		while (punteroAux && punteroAux2 && (palindroma == true)){
			if (punteroAux->obtenerDato() != punteroAux2->obtenerDato()){
				palindroma = false;
			}
			punteroAux = punteroAux->obtenerSiguiente();
			punteroAux2 = punteroAux2->obtenerSiguiente();
		}
	}
	else{
		palindroma = false;
	}
	return palindroma;
}


template <class T> void Lista<T>::listaInvertida(){
	Nodo<T>* punteroAux = this->primero;
	Nodo<T>* punteroAnterior = nullptr;
	Nodo<T>* punteroSiguiente = punteroAux;
	while((punteroSiguiente->obtenerSiguiente())){
		punteroSiguiente = punteroSiguiente->obtenerSiguiente();
		punteroAux->modificarSiguiente(punteroAnterior);
		punteroAnterior = punteroAux;
		punteroAux = punteroSiguiente;
	}
	punteroAux->modificarSiguiente(punteroAnterior);
	this->primero = punteroAux;
}

template <class T> int Lista<T>::obtenerTamanio(){
	return (this->tamanio);
}


#endif /* LISTA_H_ */
