#include "Garage.h"
#include "Stack.h"
void Garage::readCars()
{
	ifstream read;
	Stack lane1;
	Stack lane2;
	Stack street;
	Car carData; // stores operation and license plate
	int lane1Count = 0, lane2Count = 0;
	int tempCar; // used to see if a car is already in garage
	int index = 0;
	string temp; // used for putting cars back into the lanes after being put into the street
	read.open("ParkingGarage.txt");
	if (!read.is_open()) {
		cout << "Error opening file make sure it is the exact name and it is in the correct folder " << endl;
		return;
	}
	while (!read.eof()) {
		read >> carData.op >> carData.name;
		cout << "New Car: " << endl;
		cout << "Read in " << carData.op << " and " << carData.name << endl;
		if (carData.op == "A") { // if a car wants to enter the garage
			if (lane1Count != 10) { // if lane 1 is not full
				tempCar = lane1.search(carData.name); // search if the car is already in lane 1
				if (tempCar == 0) { // if car is already in lane 1
					cout << "Car is already in garage: lane 1" << endl;
				}
				else { // if car is not in the garage
					lane1.push(carData.name);
					lane1Count++;
					cout << "Pushed " << carData.name << endl << endl;
				}
			}
			else if (lane2Count != 10) { // if lane 2 is not full
				tempCar = lane2.search(carData.name); // search if the car is already in lane 2
				if (tempCar == 0) { // if car is already in lane 2
					cout << "Car is already in garage: lane 2" << endl;
				}
				else {
					lane2.push(carData.name);
					lane2Count++;
					cout << "Pushed " << carData.name << endl << endl;
				}
			}
			else { // if both lanes are full
				cout << "Both lanes full " << carData.name << " is leaving" << endl << endl;
			}
		}
		else { // carData.op == 'D'
			tempCar = lane1.search(carData.name); // searching if car is not in lane 1
			if (tempCar == -1) {
				//cout << "Car is not in the lane 1 checking lane 2 " << endl;
				tempCar = lane2.search(carData.name); // searching if car is in lane 2
				if (tempCar == -1) { // if car is not in garage
					cout << "Car is not in lane 1 or 2, the car is not in the garage" << endl << endl;
				}
				else { // if car is found in lane 2
					index = lane2.searchv2(carData.name); // return how many cars are blocking it
					for (int i = 0; i <= index; i++) { // pop each car blocking it and the car we are trying to remove
						temp = lane2.pop(carData.name);
						if (temp != carData.name && temp != "0") { // push cars to the street that isn't the car we are trying to remove
							Street.push(temp);
						}

						//cout << "temp = " << temp << endl;
					}
					carData.numOfMoves++;
					for (int i = 0; i < index; i++) { // pushing cars back into lane 
						temp = Street.pop(carData.name); // pop cars from street return the car that got popped
						lane2.push(temp); // push into lane 2
					}
					lane2Count--;
					cout << carData.name << " removed from lane 2 and was moved " << carData.numOfMoves << " Times" << endl << endl;
				}
			}
			else { // if car is found in lane 1 same process
				index = lane1.searchv2(carData.name);
				for (int i = 0; i <= index; i++) {
					temp = lane1.pop(carData.name);
					if (temp != carData.name && temp != "0") {
						Street.push(temp);
					}
					//cout << "temp = " << temp << endl;
				}
				carData.numOfMoves++;
				for (int i = 0; i < index; i++) {
					temp = Street.pop(carData.name);
					lane1.push(temp);
				}
				lane1Count--;
				cout << carData.name << " removed from lane 1 and was moved " << carData.numOfMoves << " Times" << endl << endl;
			}
		}

	}
	cout << "\nNo more cars here are the final results " << endl;
	cout << "Lane 1: "; lane1.display();
	cout << "Lane 2: "; lane2.display();
	cout << "Street: "; Street.display();
	return;
}