#include "bits/stdc++.h"
using namespace std;

long long MOD = 998244353;
vector<long long> F, RF, R;

long long Comb(long long A, long long B) {
	return (F[A] * ((RF[A - B] * RF[B]) % MOD)) % MOD;
}

long long Calc(long long A, long long B) {
	if (B == 0) return 1;
	if (B % 2 == 0) {
		long long C = Calc(A, B / 2);
		return (C * C) % MOD;
	}
	return (A * Calc(A, B - 1)) % MOD;
}

int main() {
	long long N, NG = 0;
	cin >> N;
	F.resize(N + 1), RF.resize(N + 1), R.resize(N + 1);
	F[0] = F[1] = RF[0] = RF[1] = R[0] = R[1] = 1;
	for (int i = 2; i <= N; i++) {
		F[i] = (F[i - 1] * i) % MOD;
		R[i] = MOD - (R[MOD % i] * (MOD / i)) % MOD;
		RF[i] = (RF[i - 1] * R[i]) % MOD;
	}
	long long NOW = 1;
	for (int X = N; X > N / 2; X--) {
		long long COUNT = Comb(N, X);
		COUNT *= NOW;
		COUNT %= MOD;
		NG = (NG + COUNT) % MOD;
		NOW = (NOW * 2) % MOD;
	}
	cout << (Calc(3, N) - NG * 2 + MOD * 2) % MOD << endl;
}