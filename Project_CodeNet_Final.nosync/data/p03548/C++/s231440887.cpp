#include <iostream>
using namespace std;

int main() {
	int X = 0;
	int Y = 0;
	int Z = 0;
	cin >> X >> Y >> Z;
	int n = (X - Z) / (Y + Z);
	cout << n << endl;
}