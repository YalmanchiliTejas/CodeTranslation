#include<iostream>

using namespace std;

int main() {
	int X, Y, Z,number,L;
	cin >> X >> Y >> Z;
	number = 0; L = 0;

	do {
		L = L + Y + Z;
		number = number + 1;
	} while (L <= X - Y - 2*Z);
		cout << number;
}