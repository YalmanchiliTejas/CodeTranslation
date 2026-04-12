#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long mod = 998244353;

// 入力
long long X, Y;
string A;
string B;

// その他
long long fact[1 << 18], factinv[1 << 18], inv[1 << 18];
long long fact2[1 << 18];
long long dp[5009][10009];

long long modpow(long long a, long long b, long long m) {
	long long p = 1, q = a;
	for (int i = 0; i < 32; i++) {
		if ((b / (1LL << i)) % 2 == 1) { p *= q; p %= m; }
		q *= q; q %= m;
	}
	return p;
}

long long Div(long long a, long long b, long long m) {
	return (a * modpow(b, m - 2, m)) % m;
}

void init(int maxlim) {
	fact[0] = 1;
	for (int i = 1; i <= maxlim * 4; i++) fact[i] = (1LL * i * fact[i - 1]) % mod;
	for (int i = 0; i <= maxlim * 4; i++) factinv[i] = Div(1, fact[i], mod);
	for (int i = 1; i <= maxlim * 4; i++) inv[i] = Div(1, i, mod);
	for (int i = 0; i <= maxlim * 4; i++) fact2[i] = fact[i] * fact[i] % mod;

	dp[0][0] = 1;
	for (int i = 1; i <= maxlim * 2; i++) dp[1][i] = 1;
	for (int i = 2; i <= maxlim; i++) {
		for (int j = i; j <= maxlim * 2; j++) {
			dp[i][j] = 1LL * i * (dp[i][j - 1] + 1LL * (i + j - 1LL) * dp[i - 1][j - 1]);
			dp[i][j] %= mod;
		}
	}
}

long long ncr(int n, int r) {
	if (n < r || r < 0) return 0;
	return (fact[n] * factinv[r] % mod) * factinv[n - r] % mod;
}

long long product(vector<long long> t) {
	long long s = 1;
	for (int i = 0; i < t.size(); i++) { s *= t[i]; s %= mod; }
	return s;
}

long long solve(int pos) {
	long long ret = 0;
	for (int i = pos; i <= X; i++) {
		long long v = ncr(Y, pos);
		long long r1 = (dp[pos][i] * fact[i] % mod) * fact[pos] % mod;
		long long r2 = (fact[X + Y] * factinv[Y - pos] % mod) * (factinv[X - i] * factinv[pos + i] % mod) % mod;
		long long r3 = (v * v % mod) * fact2[Y - pos] % mod;
		long long r4 = ncr(X, i) * fact2[X - i] % mod;
		ret += (r1 * r2 % mod) * (r3 * r4 % mod);
		ret %= mod;
	}
	return ret;
}

int main() {
	init(5000);
	cin >> A >> B;
	for (int i = 0; i < A.size(); i++) {
		if (A[i] == '1' && B[i] == '1') X += 1;
		if (A[i] == '1' && B[i] == '0') Y += 1;
	}

	long long Answer = 0;
	for (int i = 0; i <= min(X, Y); i++) Answer += solve(i);
	cout << Answer % mod << endl;
	return 0;
}