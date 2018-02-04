// MAIN.cpp

//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** Listing 4-4. */

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

#include "LinkedBag.h"
#include "bagInterface.h"
#include "Node.h"
#include "Polinomio.h"

int main()
{
	LinkedBag<Polinomio> polinomio1;

	Polinomio aPolinomio, aPolinomio2, aPolinomio3;

	cout << "Entre los valores del Polinomio 1 : (Cuantos monomios y sus coefficientes y exponentes)" << endl;
	cin >> aPolinomio;

	polinomio1.add(aPolinomio);

	cout << "\n\n";

	cout << "Entre los valores del Polinomio 2 : (Cuantos monomios y sus coefficientes y exponentes" << endl;
	cin >> aPolinomio2;

	polinomio1.add(aPolinomio2);

	aPolinomio3 = aPolinomio + aPolinomio2; // I commented this one because it closed again. it's here 

	// cin.get();
	// polinomio1.add(aPolinomio);

	cout << aPolinomio << endl;
	cout << aPolinomio2 << endl;

	system("pause");
	cout << "\n";
	
	cout << aPolinomio + aPolinomio2;

	// aPolinomio.evaluate();
	system("pause");

	return 0;



} // end main. 21 de noviembre de 2017 - 

