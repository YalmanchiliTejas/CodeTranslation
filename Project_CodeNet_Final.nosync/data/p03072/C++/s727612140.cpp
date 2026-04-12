///*
#include<iostream>
using namespace std;

int main() {

	int arrayNumber;
	int *ary;
	int max = 0, counter = 0;

	cin >> arrayNumber;
	ary = new int[++arrayNumber];

	ary[0] = 0;

	for (int count = 1; count != arrayNumber; count++) {
		cin >> ary[count];
	}

	for (int count = 1; count != arrayNumber; count++) {
		if (max <= ary[count]) {
			counter++;
			max = ary[count];
		}
	}

	cout << counter << endl;
	delete[] ary;

	return 0;
}
//*/