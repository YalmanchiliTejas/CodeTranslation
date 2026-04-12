#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	int A, B, C, X, Y;
	long long int ans = 0;
	cin >> A >> B >> C >> X >> Y;
	if (A + B < 2 * C) {
		int t = min(X, Y);
		ans += (A + B) * t;
		X -= t;
		Y -= t;
	}
	else {
		int t = min(X, Y);
		ans += 2 * C * t;
		X -= t;
		Y -= t;
	}
	if (X > 0) {
		int t = min(A, 2 * C);
		ans += t * X;
	}
	if (Y > 0) {
		int t = min(B, 2 * C);
		ans += t * Y;
	}
	cout << ans << endl;
	//system("pause");
}