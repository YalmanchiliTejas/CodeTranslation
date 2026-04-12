#include <iostream>
using namespace std;

int n, pay, cb;

int main() {
	cin >> n;
	pay = n * 800;
	cb = n / 15 * 200;
	cout << pay - cb << endl;
	return 0;
}