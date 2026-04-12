#include "bits/stdc++.h"
using namespace std;

long long N, M, K, ANS = 0, MOD = 1000000007;
long long F[200010] = {}, RF[200010] = {};

long long Calc(long long A, long long B) {
	if (B == 0) return 1;
	if (B % 2 == 0) {
		long long C = Calc(A, B / 2);
		return (C * C) % MOD;
	}
	return (A * Calc(A, B - 1)) % MOD;
}

void init() {
	F[0] = 1, F[1] = 1, RF[0] = 1, RF[1] = 1;
	for (int i = 2; i <= 200000; i++) {
		F[i] = F[i - 1] * i;
		F[i] = F[i] % MOD;
		RF[i] = Calc(F[i], MOD - 2);
		RF[i] = RF[i] % MOD;
	}
}

long long Comb(long long A, long long B) {
	long long RET = F[A];
	RET = RET * RF[B];
	RET = RET % MOD;
	RET = RET * RF[A - B];
	RET = RET % MOD;
	return RET;
}

int main() {
	cin >> N >> M >> K;
	init();
	for (int i = 0; i <= N; i++) {
		long long COUNT = i;
		COUNT *= Comb(N * M - 2, K - 2);
		COUNT = COUNT % MOD;
		COUNT *= ((N - i) * Calc(M, 2)) % MOD;
		COUNT = COUNT % MOD;
		ANS += COUNT;
		ANS = ANS % MOD;
	}
	for (int i = 0; i <= M; i++) {
		long long COUNT = i;
		COUNT *= Comb(N * M - 2, K - 2);
		COUNT = COUNT % MOD;
		COUNT *= ((M - i) * Calc(N, 2)) % MOD;
		COUNT = COUNT % MOD;
		ANS += COUNT;
		ANS = ANS % MOD;
	}
	cout << ANS << endl;
}