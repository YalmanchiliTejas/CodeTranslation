#include <bits/stdc++.h>
using namespace std;

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	long N;
	cin >> N;

	long long A, P;
	cin >> A;

	long c[N] = {};
	long cc = 1;
	c[0] = A;
	P = A;

	bool f = false;
	for (long i = 1; i < N; i++) {
		cin >> A;

		if (P >= A && f == false) {
			c[cc] = A;
			cc++;
			P = A;
			continue;
		}

		f = false;

		for (long x = 0; x < cc; x++) {
			if (c[x] < A) {
				c[x] = A;
				f = true;
				break;
			}
		}

		if (f == false) {
			c[cc] = A;
			cc++;
		}
		P = A;
	}

	cout << cc << endl;

	return 0;
}