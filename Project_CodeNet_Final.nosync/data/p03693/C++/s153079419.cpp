#include<iostream>
#include<string>

using namespace std;

int main(void) {
	int r, g, b;
	int p ;
	cin >> r >> g >> b;
	p = g * 10 + b;
	if (p % 4 == 0) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}

	return 0;
}
