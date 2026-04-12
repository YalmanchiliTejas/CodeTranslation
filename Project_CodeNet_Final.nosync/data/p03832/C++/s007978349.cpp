#include "bits/stdc++.h"
using namespace std;

long long MOD = 1000000007;
vector<long long> F, RF, R;

void init(long long N) {
	F.resize(N + 1), RF.resize(N + 1), R.resize(N + 1);
	F[0] = F[1] = RF[0] = RF[1] = R[0] = R[1] = 1;
	for (int i = 2; i <= N; i++) {
		F[i] = (F[i - 1] * i) % MOD;
		R[i] = MOD - (R[MOD % i] * (MOD / i)) % MOD;
		RF[i] = (RF[i - 1] * R[i]) % MOD;
	}
	return;
}

long long Comb(long long A, long long B) {
	if (B < 0 || A < B) return 0;
	return (F[A] * ((RF[A - B] * RF[B]) % MOD)) % MOD;
}

int main() {
	long long N, A, B, C, D;
	cin >> N >> A >> B >> C >> D;
	init(N);
	vector<vector<long long> > DP(N + 1, vector<long long>(B + 1, 0));
	DP[0][A - 1] = 1;
	for (int i = A - 1; i < B; i++) {
		vector<long long> X(D + 1);
		X[0] = 1;
		for (int j = 1; j <= D && j * (i + 1) - 1 <= N; j++) {
			X[j] = (X[j - 1] * Comb(j * (i + 1) - 1, i)) % MOD;
		}
		for (int j = 0; j <= N; j++) {
			DP[j][i + 1] += DP[j][i];
			DP[j][i + 1] %= MOD;
			for (int k = C; k <= D && k * (i + 1) + j <= N; k++) {
				DP[j + k * (i + 1)][i + 1] += (DP[j][i] * ((Comb(N - j, k * (i + 1)) * X[k]) % MOD)) % MOD;
				DP[j + k * (i + 1)][i + 1] %= MOD;
			}
		}
	}
	cout << DP[N][B] << endl;
	return 0;
}