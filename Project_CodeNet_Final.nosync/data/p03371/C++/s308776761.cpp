#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pint = pair<int, int>;

int main() {
	int A, B, C, X, Y;
	cin >> A >> B >> C >> X >> Y;

	int ans = 0;
	if (A + B > C * 2) {
		if (X > Y) {
			ans += Y * C * 2;
			int div = X - Y;
			ans += min(div * A, C * 2 * div);
		}
		else {
			ans += X * C * 2;
			int div = Y - X;
			ans += min(div * B, C * 2 * div);
		}
	}
	else {
		if (X > Y) {
			ans += Y * A;
			ans += Y * B;
			int div = X - Y;
			ans += min(div * A, C * 2 * div);
		}
		else {
			ans += X * A;
			ans += X * B;
			int div = Y - X;
			ans += min(div * B, C * 2 * div);
		}
	}
	cout << ans << endl;
	return 0;
}
