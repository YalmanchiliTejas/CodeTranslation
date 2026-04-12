#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int add(int x, int y) {
	return (x += y) >= mod ? x - mod : x;
}

template<class... T>
int add(int x, T... y) {
	return add(x, add(y...));
}

int mul(int x, int y) {
	return 1LL * x * y % mod;
}

template<class... T>
int mul(int x, T... y) {
	return mul(x, mul(y...));
}

void upd(int &x, int y) {
	if ((x += y) >= mod) x -= mod;
}

int main() {
	int n, a, b, c, d;
	cin >> n >> a >> b >> c >> d;

	static int inv[1000001];

	inv[1] = 1;
	for (int i = 2; i <= 1000; i++) {
		inv[i] = mul(inv[mod % i], mod - mod / i);
	}

	static int F[1000001];
	static int invF[1000001];
	F[0] = 1;
	invF[0] = 1;
	for (int i = 1; i <= 1000000; i++) {
		F[i] = mul(F[i - 1], i);
		invF[i] = mul(invF[i - 1], inv[i]);
	}

	auto C = [&](int n, int r) {
		if (n < 0 || r < 0 || n < r) return 0;
		return mul(F[n], invF[r], invF[n - r]);
	};

	static int dp0[1001];
	static int dp1[1001];
	dp0[0] = 1;

	for (int i = a; i <= b; i++) {
		memcpy(dp1, dp0, sizeof(dp1));

		for (int j = 0; j < n; j++) {
			int f = 1;
			for (int k = 0; k <= d && j + i * k <= n; k++) {
				// j + i * k <= n
				if (k >= c) {
					upd(dp0[j + i * k], mul(dp1[j], C(n - j, i * k), F[i * k], f, invF[k]));
				}
				f = mul(f, invF[i]);
			}
		}
	}

	cout << dp0[n] << endl;
}
