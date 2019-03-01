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
 * LinkedList data structure. This class is a list of elements connected by
 * pointing each element to the next one in the list. 
 */
template <class DT> 
class LinkedList {
	protected:
		DT* _info;
		LinkedList<DT>* _next;
	public:
		LinkedList();
		LinkedList(DT& info, LinkedList<DT>* next);
		LinkedList(const LinkedList<DT>& obj);
		virtual ~LinkedList();
		LinkedList<DT> operator=(const LinkedList<DT>& obj);
		LinkedList<DT> operator[](int index);
		LinkedList<DT>* next();
		DT& info();
		int size();
		void add(LinkedList<DT>& obj);
		void remove();
		void insert(int index);
};

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
	virtual ~Term();
	int getCoefficient();
	int getExponent();
	Term add(Term t);
	Term multiply(Term t);
	int getVal(int xVal);
	void display();
};

/* Default constructor - sets variables to NULL. */
template <class DT>
LinkedList<DT>::LinkedList() {
	_info = NULL;
	_next = NULL;
}

/* Non-default constructor - initializes variables to the given arguments. */
template <class DT>
LinkedList<DT>::LinkedList(DT& info, LinkedList<DT>* next) {
	_info = info;
	_next = next;
}

/* Copy constructor - creates a copy of the given LinkedList. */
template <class DT>
LinkedList<DT>::LinkedList(const LinkedList<DT>& obj) {
	LinkedList<DT>* temp = new LinkedList(_info, _next);
	_info = obj.info();
	_next = temp;
}

/* Destructor - makes sure info isn't NULL and then deletes it and next. */
template <class DT>
LinkedList<DT>::~LinkedList() {
	if (_info == NULL) return;
	delete _info;
	delete _next;
}

// operator=

// operator[]

template <class DT>
LinkedList<DT>* LinkedList<DT>::next() {
	return _next;
}

template <class DT>
DT& LinkedList<DT>::info() {
	return *_info;
}

template <class DT>
int LinkedList<DT>::size() {
	if (_info = NULL) return 0;
	return 1 + next->size();
}

template <class DT>
void LinkedList<DT>::add(LinkedList<DT>& obj) {
	LinkedList<DT>* temp = new LinkedList(_info, _next);
	_info = obj.info();
	_next = temp;
}


/* Default constructor - sets coefficent and exponent to 0. */
Term::Term() {
	coefficient = 0;
	exponent = 0;
}

/* Non-default Constructor - sets coefficient to c and exponent to e. */
Term::Term(int c, int e) {
	coefficient = c;
	exponent = e;
}

/* Destructor. */
Term::~Term() {}

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
	return Term(coefficient * t.getCoefficient(), exponent + t.getExponent());
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

int main() {
	Term* t1 = new Term(2, 4);
	Term* t2 = new Term(11, 4);
	Term* t3 = new Term(3, 6);
	Term temp;

	cout << "First term: ";
	t1->display();
	cout << endl;

	cout << "Second term: ";
	t2->display();
	cout << endl;

	cout << "Third term: ";
	t3->display();
	cout << endl << endl;
	
	cout << "First term added with second term:" << endl;
	temp = t1->add(*t2);
	temp.display();
	cout << endl << endl;

	cout << "First term multiplied with third term:" << endl;
	temp = t1->multiply(*t3);
	temp.display();
	cout << endl << endl;

	cout << "All three terms multiplied:" << endl;
	temp = temp.multiply(*t2);
	temp.display();
	cout << endl << endl;

	system("pause");
	return 0;
}

// what is virtual
// whats the point in overloading = operator?
// are we allowed to have previous in LinkedList class