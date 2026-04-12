#include <iostream>
using namespace std;

int max(int a, int b) {
	if (a>=b) {
		return a;
	}
	else {
		return b;
	}
}

int main() {
	int A, B, C, X, Y;
	cin >> A >> B >> C >> X >> Y;
	int S = 0;
	int min = A*X + Y * B;
	for (int i = 1; i <= 100000; i++) {
		S = i * 2 * C + max(0, X - i) * A + max(0, Y - i) * B;
		if (S < min) {
			min = S;
		}
	}
	cout << min << endl;
}