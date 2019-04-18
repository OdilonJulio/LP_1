#ifndef _CONJUNTO_H_
#define _CONJUNTO_H_

#include <iostream>
#include <vector>
using namespace std;

template<typename T>
class Conjunto{
	private:
		vector<T> elementos;
	public:
		Conjunto();
		void add(T elemento_);
		void add(Conjunto<T> & conjunto_);
		void getElementos();
		int getTamanho();
		bool busca(T elemento_); // Verifica se um dado elemento pertence ou não ao conjunto referência.
		Conjunto<T> operator + (Conjunto<T> & conjunto_); // União de conjuntos.
		Conjunto<T> operator - (Conjunto<T> & conjunto_); // Diferença de conjuntos.
		Conjunto<T> operator * (Conjunto<T> & conjunto_); // Intersecção de conjuntos.
};

template<typename T>
Conjunto<T>::Conjunto(){ 	
}

template<typename T>
void Conjunto<T>::add(T elemento_){
	if( this->busca(elemento_) == false ){
		this->elementos.push_back(elemento_);
	}
}

template<typename T>
void Conjunto<T>::add(Conjunto<T> & conjunto_){
	for (auto &i : conjunto_.elementos){		
		if( (this->busca(conjunto_.elementos[i])) == false ){
			this->elementos.push_back(i);
		}
	}
}

template <typename T>
void Conjunto<T>::getElementos() {
	cout << "Elementos do Conjunto: [ ";
	for(auto &i : this->elementos) {
		cout << i << " ";
	}
	cout << "]" << endl;
}

template <typename T>
int Conjunto<T>::getTamanho(){
	return this->elementos.size();
}

template <typename T>
bool Conjunto<T>::busca(T elemento_){
	for(auto &i : this->elementos) {
		if ( i == elemento_){
			return true;
		}
	}
	return false;
}

/*
=== Implementação da união de conjuntos. ===================
*/
template<typename T>
Conjunto<T> Conjunto<T>::operator + (Conjunto<T> & conjunto_){ 
	Conjunto<int> tmp;
	if ( conjunto_.getTamanho() == 0 ){
		return *this;
	}
	tmp.add(*this);
	for(int i = 0; i < conjunto_.getTamanho(); i++){
		if( this->busca(conjunto_.elementos[i]) == false){
			tmp.add(conjunto_.elementos[i]);
		}
	}
	return tmp;
}

/*
=== Implementação da diferença de conjuntos. ================
*/
template<typename T>
Conjunto<T> Conjunto<T>::operator - (Conjunto<T> & conjunto_){ 
	Conjunto<int> tmp;
	if ( conjunto_.getTamanho() == 0 ){
		return *this;
	}
	for( int i = 0; i < this->getTamanho(); i++ ){
		if( (conjunto_.busca(this->elementos[i])) == false){
			tmp.add(this->elementos[i]);
		}
	}
	return tmp;
}

/*
=== Implementação da intersecção de conjuntos. ================
*/
template<typename T>
Conjunto<T> Conjunto<T>::operator * (Conjunto<T> & conjunto_){ 
	Conjunto<int> tmp;
	for( int i = 0; i < this->getTamanho(); i++ ){
		if( conjunto_.busca(this->elementos[i]) ){
			tmp.add(this->elementos[i]);
		}
	}
	for( int j = 0; j < conjunto_.getTamanho(); j++ ){
		if( this->busca(conjunto_.elementos[j]) ){
			tmp.add(conjunto_.elementos[j]);
		}
	}
	return tmp;
}


#endif //_CONJUNTO_H_