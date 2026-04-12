#include "bits/stdc++.h"
using namespace std;

int main() {
	string S;
	static long long D, DP[10010][100][10] = {}, MOD = 1000000007;
	cin >> S >> D;
	DP[0][0][0] = 1;
	for (int i = 1; i <= S.size(); i++) {
		for (int j = 0; j < D; j++) {
			for (int k = 0; k < 10; k++) {
				for (int l = 0; l < 10; l++) {
					DP[i][(j + l) % D][l] += DP[i - 1][j][k];
					DP[i][(j + l) % D][l] %= MOD;
				}
			}
		}
	}
	long long NOW = 0, ANS = 0;
	for (int i = 0; i < S.size(); i++) {
		for (int j = 0; j < S[i] - '0'; j++) {
			ANS += DP[S.size() - i][NOW][j];
			ANS %= MOD;
		}
		NOW = (NOW - (S[i] - '0') % D + D) % D;
	}
	if (NOW != 0) ANS = (ANS - 1 + MOD) % MOD;
	cout << ANS << endl;
}