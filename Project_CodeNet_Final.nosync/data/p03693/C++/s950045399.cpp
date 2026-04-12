#include<iostream>
using namespace std;


int main() {
	int r, g, b,n;
	cin >> r >> g >> b;
	n = g * 10 + b;
	if (n % 4 == 0) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}

	return 0;
}