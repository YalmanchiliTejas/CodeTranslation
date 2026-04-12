#include <iostream>

using namespace std;

long long int X, Y, Z;

int main() {
	cin >> X >> Y >> Z;
	if (X - (Y + Z)*(X / (Y + Z)) < Z) {
		cout << X / (Y + Z) - 1 << endl;
	}
	else {
		cout << X / (Y + Z) << endl;
	}
	return 0;
}