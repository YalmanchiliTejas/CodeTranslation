#include<iostream>
#include<math.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
const long MAX = 10000002;
const long MOD = 998244353;
long long fac[MAX], finv[MAX], inv[MAX];
long long P[MAX];

// テーブルを作る前処理
void COMinit() {
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for (int i = 2; i < MAX; i++) {
		fac[i] = fac[i - 1] * i % MOD;
		inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
		finv[i] = finv[i - 1] * inv[i] % MOD;
	}
}

// 二項係数計算
long long COM(int n, int k) {
	if (n < k) return 0;
	if (n < 0 || k < 0) return 0;
	return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

void Pinit() {
	P[0] = 1;
	for (int i = 1; i < MAX; i++) {
		P[i] = P[i - 1] * 2 % MOD;
	}
}

int main() {
	long long N;
	long long L[18];
	long long ans;
	
	cin >> N;
	COMinit();
	Pinit();

	ans = 0;
	long long t = 0;
	for (int i = N / 2; i <= N; i += 1) {
		long long m = P[i] - t;
		if (m < 0) {
			m += MOD;
		}
		ans = (ans + COM(N, i) * m) % MOD;
		t = (t * 2 + COM(i, i - N / 2)) % MOD;
	}

	cout << ans << endl;
}