#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;


int main(void) {
	int X;
	string str = "No";

	cin >> X;

	if (X >= 30) {
		str = "Yes";
	}

	cout << str << endl;


	return 0;
}
