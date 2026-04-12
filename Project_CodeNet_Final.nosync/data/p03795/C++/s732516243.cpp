#include <iostream>
using namespace std;

int main() {

	int n;
	int money;

	do {
		cin >> n;

	} while (n < 1 || n > 100);

	money = 800 * n;

	for (int i = n; i >= 15; i -= 15) {
		money -= 200;
	}

	cout << money << endl;
}