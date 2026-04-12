#include <iostream>
using namespace std;

int main() {
	int X, Y, Z;
	int Ans;

	cin >> X >> Y >> Z;

	Ans = X / (Y + Z);
	if (X % (Y + Z) < Z ) Ans -= 1;

	cout << Ans;


	return 0;
}