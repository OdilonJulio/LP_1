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
        void add(const T elemento_);
        void add(const Conjunto<T> & conjunto_);
        void getElementos() const;  // marcada como função `const`
        int getTamanho() const;     // marcada como função `const`
        bool busca(T elemento_) const; // Verifica se um dado elemento pertence ou não ao conjunto referência.
        const Conjunto<T> operator + (const Conjunto<T> &conjunto_) const; // União de conjuntos.
        const Conjunto<T> operator - (const Conjunto<T> & conjunto_) const; // Diferença de conjuntos.
        const Conjunto<T> operator * (const Conjunto<T> & conjunto_) const; // Intersecção de conjuntos.
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
void Conjunto<T>::add(const Conjunto<T> & conjunto_){
    for (auto &i : conjunto_.elementos){		
        if( (this->busca(conjunto_.elementos[i])) == false ){
            this->elementos.push_back(i);
        }
    }
}

template <typename T>
void Conjunto<T>::getElementos() const{
    cout << "Elementos do Conjunto: [ ";
    for(auto &i : this->elementos) {
        cout << i << " ";
    }
    cout << "]" << endl;
}

template <typename T>
int Conjunto<T>::getTamanho() const{
    return this->elementos.size();
}

template <typename T>
bool Conjunto<T>::busca(T elemento_) const{
    for(auto &i : this->elementos) {
        if ( i == elemento_){
            return true;
        }
    }
    return false;
}

/*
   === implementação da união de conjuntos. ===================
   */
template<typename t>
const Conjunto<t> Conjunto<t>::operator+ (const Conjunto<t> & conjunto_) const{ 
    Conjunto<t> tmp;
    if ( conjunto_.getTamanho() == 0 ){ // garantimos que .getTamanho() é const
        return *this;   // garantimos que retornará um objeto const
    }
    tmp.add(*this);     // garantimos que o add() não mexe no this (que é const)
    for(int i = 0; i < conjunto_.getTamanho(); i++){    // getTamanho() é const
        if( this->busca(conjunto_.elementos[i]) == false){  // garantimos que o busca() também é const
            tmp.add(conjunto_.elementos[i]);    // add não mexe no elemento
        }
    }
    return tmp; // tmp será convertido para const no retorno (automaticamente)
    // conversão de não const -> const é trivial para o c++
    // o contrário não
}

/*
   === Implementação da diferença de conjuntos. ================
   */
template<typename T>
const Conjunto<T> Conjunto<T>::operator- (const Conjunto<T> & conjunto_) const{ 
    Conjunto<T> tmp;
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
const Conjunto<T> Conjunto<T>::operator * (const Conjunto<T> & conjunto_) const{ 
    Conjunto<T> tmp;
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
