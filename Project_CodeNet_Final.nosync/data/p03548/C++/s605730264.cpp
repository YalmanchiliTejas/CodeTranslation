#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	int X, Y, Z;
	cin >> X >> Y >> Z;

	int count = 0;
	X -= 2 * Z;

	while (X >= Y) {
		X -= Y;
		count++;
		X -= Z;
	}

	cout << count << endl;



	return 0;
}