#pragma once
#ifndef garage_h
#define garage_h
#include<iostream>
#include<fstream>
#include "Stack.h"
using namespace std;
class Garage {
public:
	Stack lane1;
	Stack lane2;
	Stack Street;
	void readCars();
};
class Car {
public:
	int numOfMoves = 0;
	string op;
	string name;
};
#endif
