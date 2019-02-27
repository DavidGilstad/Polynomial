/*
 * Data Structures Project 3
 *
 * This project provides classes and a main method for creating and performing
 * operatorions on polynomials, such as addition or multiplication. SDG
 *
 *			author: David Gilstad
 *		   created: 26 February 2019
 */
#include <iostream>
using namespace std;

/*
 * This class represents a single term in a polynomial, such as Cx^e, where C 
 * is the coefficient, x is the variable, and e is the exponent.
 */
class Term {
	protected:
		int coefficient;
		int exponent;
	public:
		Term();
		Term(int c, int e);
		int getCoefficient();
		int getExponent();
		Term add(Term t);
		Term multiply(Term t);
		int getVal(int xVal);
		void display();
};

/* Default constructor - sets coefficent and exponent to 0. */
Term::Term() {
	coefficient = 0;
	exponent = 0;
}

/* Non-default - sets coefficient and exponent to c and e, respectively. */
Term::Term(int c, int e) {
	coefficient = c;
	exponent = e;
}

/* Returns the coefficient. */
int Term::getCoefficient() {
	return coefficient;
}

/* Returns the exponent. */
int Term::getExponent() {
	return exponent;
}

/* Adds this term with t and returns the sum. */
Term Term::add(Term t) {
	return *new Term(coefficient + t.getCoefficient(), exponent);
}

/* Multiplies this term with t and returns the product. */
Term Term::multiply(Term t) {
	return *new Term(coefficient*t.getCoefficient(), exponent+t.getExponent());
}

/* Returns the value of the term for a given value of the variable x. */
int Term::getVal(int xVal) {
	int value = 1;
	for (int i = 0; i < getExponent(); ++i)
		value *= xVal;
	return value;
}

/* Prints the term in the form "(coefficient,exponent)". */
void Term::display() {
	cout << "(" << coefficient << "," << exponent << ")";
}