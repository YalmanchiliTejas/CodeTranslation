#include<iostream>

using namespace std;

int main() {
	int r, g, b;
	cin >> r >> g >> b;

	int Q = r * 100 + g * 10 + b;
	if (Q % 4 == 0) {
		cout << "YES" << endl;
	}
	else cout << "NO" << endl;

	return 0;
}