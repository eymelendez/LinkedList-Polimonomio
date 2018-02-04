#pragma once

// Monomio.h

#include<iostream>
#include<cstdio>

using namespace::std;

class Monomio
{
public:
	Monomio(); // Constructor
	Monomio(int a, int n); // Parameter Constructor
	Monomio(const Monomio & tempMonomio); // Copy Constructor
	~Monomio(); // Destructor

				// Setters
	void setCoefficient(int a);
	void setExponent(int n);

	// Getters
	int getCoefficient() const;
	int getExponent() const;

	// Eval function
	int eval(int x) const;

	// Operators

	Monomio &operator = (const Monomio &); // Assign Operator

	bool operator == (const Monomio &aMonomio) const; // overloading operator

	Monomio operator ^ (int exp); // ^ operator

	Monomio operator + (const Monomio & tempMonomio); // Sum Operator
	Monomio operator - (const Monomio & tempMonomio); // Substract Operator
	Monomio operator * (const Monomio & tempMonomio); // Multiplication Operator

	friend ostream &operator << (ostream &, const Monomio &); // Prints
	friend istream &operator >> (istream &, Monomio &); // Inputs


private:

	int coefficient;
	int exponent;

};

// Monomio.cpp

#include<iostream>
#include<cstdio>
#include<cmath>

using namespace::std;

#include"Monomio.h"

// Constructor
Monomio::Monomio()
{
	coefficient = 1;
	exponent = 1;
}

// Parameter Constructor
Monomio::Monomio(int a, int n)
{
	setCoefficient(a);
	setExponent(n);

}

// Copy Constructor
Monomio::Monomio(const Monomio & tempMonomio)
{
	setCoefficient(tempMonomio.getCoefficient());
	setExponent(tempMonomio.getExponent());
}

// Destructor
Monomio::~Monomio()
{
	// cout << "Destroying objects... << endl;
}

// Setters
void Monomio::setCoefficient(int a)
{
	coefficient = a;
}

void Monomio::setExponent(int n)
{
	if (n > 0)
	{

		exponent = n;

	}
	else
	{
		cout << "Entre un numero mayor de cero. ";

	}

}

// Getters
int Monomio::getCoefficient() const
{
	return coefficient;
}

int Monomio::getExponent() const
{
	return exponent;
}

// Function to evalute the polinomio using a value of x.
int Monomio::eval(int x) const
{
	int result;

	result = getCoefficient() * pow(x, getExponent());

	return result;
}

// Assign Operator
Monomio & Monomio::operator = (const Monomio & tempMonomio)
{
	this->coefficient = tempMonomio.getCoefficient();
	this->exponent = tempMonomio.getExponent();

	return *this;
}



Monomio Monomio::operator ^ (int exp)
{
	exponent = exp;
	return *this;

}

// Sum Operator
Monomio Monomio::operator + (const Monomio & tempMonomio)
{

	int sum;

	if (exponent == tempMonomio.exponent)
	{
		sum = (coefficient + tempMonomio.coefficient);

	}
	else
	{
		cout << "ERROR, for it to be sum, they must be of the same exponent. ";
		exit(1);

	}

	Monomio Sum(sum, exponent);

	return Sum;

}

// Subtract Operator
Monomio Monomio::operator - (const Monomio & tempMonomio)
{

	int subtract;

	if (exponent == tempMonomio.exponent)
	{
		subtract = (coefficient - tempMonomio.coefficient);

	}
	else
	{
		cout << "ERROR, for it to be sum, they must be of the same exponent. ";
		exit(1);

	}

	Monomio Subtract(subtract, exponent);

	return Subtract;


}

// Multiplication Operator
Monomio Monomio::operator * (const Monomio & tempMonomio)
{
	int exp = exponent + tempMonomio.exponent;
	int coe = coefficient * tempMonomio.coefficient;

	Monomio monomio(coe, exp);

	return monomio;


}

// Output operator with if-else conditions for displaying the monomio in the correct way.
ostream & operator << (ostream & output, const Monomio & tempMonomio)
{
	//output << tempMonomio.coefficient << "x^ " << tempMonomio.exponent;

	if (tempMonomio.exponent == 1)
	{
		output << tempMonomio.coefficient << "x";
	}
	else if (tempMonomio.coefficient == 0)
	{
		output << 0;
	}
	else if (tempMonomio.coefficient == 1)
	{
		output << "x^" << tempMonomio.exponent;

	}
	else if (tempMonomio.exponent == 0)
	{
		output << tempMonomio.coefficient;

	}
	else
	{
		output << tempMonomio.coefficient << "x^" << tempMonomio.exponent;
	}

	return output;
}

// User inputs the values of the coeficient and exponent
istream & operator >> (istream & input, Monomio & tempMonomio)
{

	cout << "Enter the coeficient: ";
	input >> tempMonomio.coefficient;

	cout << "Enter the exponent: ";
	input >> tempMonomio.exponent;

	return input;

}

bool Monomio::operator == (const Monomio & aMonomio) const
{
	bool flag = false;

	if (aMonomio.getCoefficient() == getCoefficient() && aMonomio.getExponent() == getExponent()) 
	{
		flag = true;
	}

	return flag;
}