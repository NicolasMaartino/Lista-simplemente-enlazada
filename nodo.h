/*
 * nodo.h
 *
 *  Created on: 12 dic. 2020
 *      Author: usuario
 */

#ifndef NODO_H_
#define NODO_H_

template <class T> class Nodo{
	private:
		T dato;
		Nodo<T>* punteroSiguiente;
	public:
		/* Pre:
		 * Post:
		 */
		Nodo(T dato);
		/* Pre:
		 * Post
		 */
		T obtenerDato();
		/*Pre:-
		 * Post:
		 */
		Nodo<T>* obtenerSiguiente();
		/*Pre:
		 * Post:
		 */
		void modificarSiguiente(Nodo<T>* punteroNuevo);

		/* Pre:-
		 * Post:
		 */
		void modificarDato(T dato);
		/* Pre:
		 * Post:Libera la memoria pedida
		 */
		~Nodo();
};

template <class T> Nodo<T>::Nodo(T dato){
	this-> dato = dato;
	this->punteroSiguiente = 0;
}

template <class T> T Nodo<T>::obtenerDato(){
	return (this-> dato);
}

template <class T> Nodo<T>* Nodo<T>::obtenerSiguiente(){
	return (this-> punteroSiguiente);
}

template <class T> void Nodo<T>::modificarSiguiente(Nodo<T>* punteroNuevo){
	this->punteroSiguiente = punteroNuevo;
}

template <class T> void Nodo<T>::modificarDato(T dato){
	this-> dato = dato;
}

template <class T> Nodo<T>::~Nodo(){
	delete (this->punteroSiguiente);
}



#endif /* NODO_H_ */
