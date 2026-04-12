#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
long long d[2000][2000], N, A, B, C, D, mod = 1000000007, fact[2000], dp[2000][2000], DV[2000];
long long ncr(long long n, long long r) {
	return d[n - r][r];
}
long long modpow(long long a, long long b, long long m) {
	long long p = 1, q = a;
	for (int i = 0; i < 62; i++) {
		if ((b / (1LL << i)) % 2 == 1) { p *= q; p %= m; }q *= q; q %= m;
	}
	return p;
}
long long Div(long long a, long long b, long long m) {
	return (a*modpow(b, m - 2, m)) % m;
}
long long Div2(long long a, long long b, long long m) {
	return (a*DV[b]) % m;
}
int main() {
	fact[1] = 1; for (int i = 2; i < 1999; i++) { fact[i] = fact[i - 1] * i; fact[i] %= mod; }
	for (int i = 0; i < 1999; i++) {
		for (int j = 0; j < 1999; j++) {
			if (i == 0 || j == 0)d[i][j] = 1;
			else d[i][j] = d[i - 1][j] + d[i][j - 1];
			d[i][j] %= mod;
		}
	}
	for (int i = 1; i <= 1999; i++)DV[i] = Div(1, i, mod);
	cin >> N >> A >> B >> C >> D; dp[A - 1][0] = 1;
	for (int i = A; i <= B; i++) {
		for (int j = 0; j <= N; j++) {
			//dp[i-1][j],dp[i-1][j-k],dp[i-1][j-k*2]...
			long long ret = 1, cnt = 0;
			for (int k = j; k >= 0; k -= i) {
				if (k == j)ret = 1;
				else { cnt++; ret *= ncr(k + i, i); ret %= mod; ret = Div2(ret, cnt, mod); }
				if (cnt != 0 && (cnt < C || cnt > D))continue;
				dp[i][j] += ret*dp[i - 1][k]; dp[i][j] %= mod;
			}
		}
	}
	cout << dp[B][N] << endl;
	return 0;
}