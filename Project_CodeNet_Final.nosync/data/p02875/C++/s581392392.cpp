#include <iostream>
using namespace std;

int modpow(int a, int b, long long m) {
	long long p = 1, q = a;
	for (int i = 0; i < 30; i++) {
		if ((b & (1 << i)) != 0) { p *= q; p %= m; }
		q *= q; q %= m;
	}
	return p;
}

int Div(int a, int b, long long m) {
	return (1LL * a * modpow(b, m - 2, m)) % m;
}

long long mod = 998244353;
long long dp1[10000007];
long long dp2[10000007];

int main() {
	long long N; cin >> N;

	// dp1 の計算
	dp1[0] = 1; dp1[1] = -2; dp1[2] = 0; dp1[3] = 16;
	long long val1 = 20, val2 = 2, p1 = 14, p2 = 2;
	for (int i = 4; i <= (N >> 1); i++) {
		dp1[i] = dp1[i - 1] * Div(val1 % mod, val2 % mod, mod);
		dp1[i] %= mod;
		p1 += 8; p2++;
		val1 += p1; val2 += p2;
	}

	// dp2 の計算
	dp2[0] = 1;
	for (int i = 1; i <= (N >> 1); i++) {
		dp2[i] = 9LL * dp2[i - 1] + dp1[i];
		dp2[i] = (dp2[i] + mod) % mod;
	}

	cout << dp2[N / 2] << endl;
	return 0;
}