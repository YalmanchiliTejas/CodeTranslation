#include<iostream>
using namespace std;

int main() {
	int X, Y, Z;
	cin >> X >> Y >> Z;

	int answer = X / (Z + Y);
	if (X % (Z + Y) < Z) cout << answer - 1 << endl;
	else cout << answer << endl;
}