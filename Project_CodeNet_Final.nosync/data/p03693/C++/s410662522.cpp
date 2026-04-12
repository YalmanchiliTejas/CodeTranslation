#include<iostream>
using namespace std;

int main() {
	int r, g, b;
	cin >> r >> g >> b;

	int n = 10 * g + b;

	cout << ((n % 4 == 0) ? "YES" : "NO") << endl;

	return 0;
}