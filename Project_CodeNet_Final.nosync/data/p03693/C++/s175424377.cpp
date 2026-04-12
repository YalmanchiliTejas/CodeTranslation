#include<iostream>
using namespace std;

int main() {
	int r, g, b, sum;
	cin >> r >> g >> b;

	r = 100 * r;
	g = 10 * g;
	sum = r + g + b;
	
	if (sum % 4 == 0) {
		cout << "YES"<< endl;
	}
	else {
		cout << "NO" << endl;
	}
	return 0;
}