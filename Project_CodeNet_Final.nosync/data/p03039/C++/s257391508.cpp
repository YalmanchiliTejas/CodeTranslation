#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

const ull MOD = 1000000007;

const ull MAX = 510000;
 
ull fac[MAX], finv[MAX], inv[MAX];

void COMinit() {
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for (int i = 2; i < MAX; i++) {
		fac[i] = fac[i - 1] * i % MOD;
		inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
		finv[i] = finv[i - 1] * inv[i] % MOD;
	}
}

ull COM(ull n, ull k) {
	if (n < k) return 0;
	if (n < 0 || k < 0) return 0;
	return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main() {
	COMinit();
	ull N, M, K;
	cin >> N >> M >> K;

	ull xval = 0;
	for (int ii = 1; ii < M; ++ii){
		xval += ii * (M-ii) % MOD;
	}
	xval *= N*N % MOD;

	ull yval = 0;
	for (int ii = 1; ii < N; ++ii){
		yval += ii * (N-ii) % MOD;
	}
	yval *= M*M % MOD;
	ull ans = (xval + yval) % MOD;

	//combinationを考慮
	ull total = N*M-2;
	ull select = min(K-2, total - (K-2));

	ans = (ans * COM(total, select)) % MOD;

	cout << ans << endl;


	return 0;
}
