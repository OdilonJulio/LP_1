#include <iostream>
#include <algorithm>
#include <vector>

#include "templateConjunto.h"

using namespace std;

int main(){
	/* Instanciando conjuntos. */
	Conjunto<int> conjuntoA;
	Conjunto<int> conjuntoB;
	Conjunto<int> conjuntoC;
	Conjunto<int> conjuntoD;
	
	/* adiciona elementos */
	conjuntoA.add(1);
	conjuntoA.add(3);
	conjuntoA.add(5);
	conjuntoA.add(7);
	conjuntoA.add(9);
	cout << endl << "Conjunto A: " << endl;
	conjuntoA.getElementos();
		
	conjuntoB.add(2);
	conjuntoB.add(3);
	conjuntoB.add(5);
	conjuntoB.add(7);
	conjuntoB.add(11);
	cout << endl << "Conjunto B: " << endl;
	conjuntoB.getElementos();
	
	cout << endl << "União de A e B: " << endl;

	conjuntoC = conjuntoA + conjuntoB;
	conjuntoC.getElementos();
	
	cout << endl << "Conjunto A - B: " << endl;
	conjuntoD = conjuntoA - conjuntoB;
	conjuntoD.getElementos();
	return 0;
}