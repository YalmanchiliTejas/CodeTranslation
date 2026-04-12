#include <bits/stdc++.h>
using namespace std;
typedef long long llong;

int main(void) {
	llong A, B, C, X, Y;
	cin >> A >> B >> C >> X >> Y;

	llong res = 1LL << 30;
	for (int i = 0; i <= 100000; i++) {
		if (i > X && i > Y) break;
		llong price = i * 2 * C + max(0LL, X - i)*A + max(0LL, Y - i) * B;
		res = min(res, price);
	}

	cout << res << endl;
	return 0;
}