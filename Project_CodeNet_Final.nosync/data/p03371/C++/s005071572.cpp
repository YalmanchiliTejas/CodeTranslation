#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
	int A, B, C, X, Y;
	cin >> A >> B >> C >> X >> Y;

	int ans = 0;
	if (A + B < C * 2) {
		ans = A * X + B * Y;
	} else {
		if (X < Y) {
			ans = C * 2 * X + min(B, 2 * C) * (Y - X);
		} else {
			ans = C * 2 * Y + min(A, 2 * C) * (X - Y);
		}
	}

	cout << ans << endl;
	return 0;
}
