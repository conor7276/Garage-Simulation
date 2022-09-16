#include "Stack.h"
#include "Garage.h"
void Stack::push(string name)
{
	Node* newNode = new Node(name);
	if (!newNode)
		return;
	// list is empty
	if (head == NULL) {
		head = newNode;
		tail = newNode;
	}
	else {// list is not empty
		newNode->next = head;
		head = newNode;
	}
	return;
}
void Stack::display() {
	if (head == NULL) {//list is empty
		cout << "List is empty" << endl;
		return;
	}
	//list is not empty
	Node* temp = head;
	while (temp != NULL) {
		cout << temp->data << ' ';
		temp = temp->next;
	}
	cout << endl;
}
int Stack::search(string carName)
{
	Node* temp = head;
	int index = 0;
	if (head == NULL) {
		return -1;
	}
	while (temp != NULL) {
		if (temp->data == carName) {
			return 0;
		}
		temp = temp->next;
		index++;
	}
	return -1; // not found
}
string Stack::pop(string carName)
{
	int counter = 0;
	Stack Street;
	//list is empty
	if (head == NULL) {
		return "0";
	}
	// only 1 node in the list
	if (head->next == NULL && head->data == carName) {
		delete head;
		head = NULL;
		tail = NULL;
		return "0";
	}
	//more then 1 node
	Node* temp;
	string save;
	save = head->data;
	temp = head;
	head = head->next;
	delete temp;
	return save;

}
int Stack::searchv2(string carName) {
	Node* temp = head;
	int index = 0;
	if (head == NULL) {
		return -1;
	}
	while (temp != NULL) {
		if (temp->data == carName) {
			return index;
		}
		temp = temp->next;
		index++;
	}
	return -1; // not found
}