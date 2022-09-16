#pragma once
#ifndef stack_h
#define stack_h
#include<iostream>
#include<fstream>
using namespace std;
class Node {
public:
	string data;
	Node* next;
	Node* prev;
	Node(string d) { data = d; next = NULL; }
};
class Stack {
public:
	//bool append(string d);
	void push(string name); // pushes cars to lanes
	int search(string name); // searches if the car is in any of the lanes
	int searchv2(string name); // different from the first search returns an index of how far the car that wants to leave is
	string pop(string name); // pops car from lane
	void display(); // displays a lane of cars
	Node* head = NULL;
	Node* tail = NULL;	
};
#endif