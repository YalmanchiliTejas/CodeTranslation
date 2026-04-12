#include <iostream>

using namespace std;


int main () {
	int r, g, b;
	cin >> r >> g >> b;

	int val;
	val = r * 100 + g * 10 + b;

	if (val % 4) {
		cout << "NO" << endl;
	}
	else {
		cout << "YES" << endl;
	}

	return 0;
}