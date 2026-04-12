#include <bits/stdc++.h>
using namespace std;

int X, Y, Z;

int main() {
	cin >> X >> Y >> Z;
	X = X - Z;
	cout << X / (Y + Z) << endl;
}
