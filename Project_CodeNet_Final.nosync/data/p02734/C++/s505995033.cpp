#include "bits/stdc++.h"
using namespace std;

constexpr long long MOD = 998244353;

int main() {
	int N, S;
	cin >> N >> S;
	vector<long long> A(N);
	for (int i = 0; i < N; i++) cin >> A[i];
	vector<vector<long long> > DP(N + 1, vector<long long>(S + 1, 0));
	for (int i = 0; i < N; i++) {
		for (int j = 1; j < S; j++) {
			DP[i + 1][j] = (DP[i + 1][j] + DP[i][j]) % MOD;
			if (j + A[i] <= S) DP[i + 1][j + A[i]] = (DP[i + 1][j + A[i]] + DP[i][j]) % MOD;
		}
		if (A[i] <= S) DP[i + 1][A[i]] = (DP[i + 1][A[i]] + i + 1) % MOD;
	}
	long long ANS = 0;
	for (int i = 0; i <= N; i++) {
		ANS = (ANS + DP[i][S] * (N - i + 1)) % MOD;
	}
	cout << ANS << endl;
}