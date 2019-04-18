#include <iostream>
#include <algorithm>
#include <vector>

#include "templateConjunto.h"

using namespace std;

int main(){
	/* Instanciando conjuntos. */
	Conjunto<int> conjuntoA;
	Conjunto<int> conjuntoB;
	Conjunto<int> conjuntoUniao;
	Conjunto<int> conjuntoDif;
	Conjunto<int> conjuntoInter;
	
	/* adiciona elementos */
	conjuntoA.add(1);
	conjuntoA.add(3);
	conjuntoA.add(5);
	conjuntoA.add(7);
	conjuntoA.add(9);
	cout << endl << "Conjunto dos Ímpares (cinco primeiros): " << endl;
	conjuntoA.getElementos();
		
	conjuntoB.add(2);
	conjuntoB.add(3);
	conjuntoB.add(5);
	conjuntoB.add(7);
	conjuntoB.add(11);
	cout << endl << "Conjunto Primos (cinco primeiros): " << endl;
	conjuntoB.getElementos();
	
	cout << endl << "União dos Ímpares e Primos " << endl;

	conjuntoUniao = conjuntoA + conjuntoB;
	conjuntoUniao.getElementos();
	
	cout << endl << "Diferença entre Ímpares e Primos: " << endl;
	conjuntoDif = conjuntoA - conjuntoB;
	conjuntoDif.getElementos();
	
	cout << endl << "Intersecção entre Ímpares e Primos: " << endl;
	conjuntoInter = conjuntoA * conjuntoB;
	conjuntoInter.getElementos();

	return 0;
}