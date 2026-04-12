#include <iostream>
using namespace std;

int main() {
	int A, B, C, X, Y, ans = 0;
	cin >> A >> B >> C >> X >> Y;
	while (X || Y) {
		if (X && Y) {
			if (A + B < 2 * C) ans += A + B;
			else ans += 2 * C;
			X--;
			Y--;
		}
		else if (X) {
			if (A < 2 * C) ans += A;
			else ans += 2 * C;
			X--;
		}
		else {
			if (B < 2 * C) ans += B;
			else ans += 2 * C;
			Y--;
		}
	}
	cout << ans;
}