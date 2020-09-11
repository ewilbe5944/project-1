//Emily Wilber
//CPSC 1071: 003
//September 11, 2020


#include <iostream>
#include <cmath>
#include <cstdio>
#include <stdlib.h>
#include <time.h>
#include <limits>

#define MAX_DAILY_RATE 15

using namespace std;

//calculates the charge depending on the number of hours a car has been parked
double calculateCharge(double hours) {
	double sum = 0;
	if (hours < 0) {
		printf("This is not a valid input.");
		return 0; 
	}
	else if (hours < .5) {
		return 0;
	}
	else if (hours < 1) {
		return 2;
	}
	else if (hours < 24) {
		sum = 2 + trunc(hours);
		if (sum > MAX_DAILY_RATE) {
			sum = MAX_DAILY_RATE;
		}
		return (sum);
	}
	else {
		return MAX_DAILY_RATE;
	}
}

// prints cars, times, and charges, as well as the sum of the hours in a table
void calculateCharges(double carTimes[]) {
	printf("Car	Hours	Charge ($)\r\n");
	double totalHours = 0;
	double totalCharge = 0;
	int i = 0;
	while (carTimes[i] != -999) {
		totalHours += carTimes[i];
		totalCharge += calculateCharge(carTimes[i]);
		printf("%d	%0.1f	%0.2f\r\n", i, carTimes[i], calculateCharge(carTimes[i]));
		i++;
	}	
	printf("Total:	%0.1f	%0.2f\r\n\r\n", totalHours, totalCharge);
	
}

//takes in 10 doubles (with user validation) to turn into an array
void putCarInfo(void) {
	double carTimes[11]; 
	carTimes[10] = -999; //end flag
	printf("Enter 10 customers' times...\r\n");
	for (int i = 0; i < 10; i++) {
		cout << (i+1) << ": ";		
		cin >>	carTimes[i]; 
		//user validation checks if the input is a positive double
		//gives error if not positive double or end flag (-999)
		while(1) {
			if(cin.fail()) {	
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(),'\n');
				cout << "This input is invalid. Try again.\r\n"<< (i+1) << ": ";
				cin >> carTimes[i]; 
			}	
			if(!cin.fail()) {
				if ( (carTimes[i] == -999) || (carTimes[i] > 0)) {
					break;
				}
				else {
					cout << "This input is invalid. Try again.\r\n"<< (i+1) << ": ";
					cin >> carTimes[i]; 
				}
			}

		}	
	
		if (carTimes[i] == -999) {
			break;
		}
	} 

	calculateCharges(carTimes);
}

//randomly returns either 0 or 1
int flip(void) {
	int num =rand() % 2;
	return num;
}

//prints Heads if it is passed 0 and Tails if it is passed 1
void printCoinToss(int i) {
	if (i == 0) {
		printf("Heads");
	} 
	else if (i == 1)  {
		printf("Tails");
	}
	else {
		printf("This should never print %d.", i);
	}
}

//prints randomly heads or tails num number of times
void runCoinToss(int num) {
	srand(time(NULL));
	for (int i = num; i > 0; i--) {
		printCoinToss(flip());
		printf ("\r\n");
	}
}

int main() {
	putCarInfo();
	runCoinToss(5);
	return 0;

}
