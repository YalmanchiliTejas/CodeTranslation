#include <iostream>

using namespace std;

int main() {
	int A, B, C, X, Y;
	int c;
	int total, min;

	cin >> A >> B >> C >> X >> Y;

	min = 3 * 5000 * 100000;
	for (c = 0; c <= (X < Y ? X : Y); c++) {
		total = A * (X - c) + B * (Y - c) + 2 * C * c;
		if (min > total) {
			min = total;
		}
	}
	
	for (; c <= (X < Y ? Y : X); c++) {
		if (X < Y) {
			total = B * (Y - c) + 2 * C * c;
		} else {
			total = A * (X - c) + 2 * C * c;
		}

		if (min > total) {
			min = total;
		}
	}

	cout << min << endl;

	return 0;
}
