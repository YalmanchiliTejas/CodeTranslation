#pragma GCC optimize("Ofast", "unroll-loops")

#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll MOD = 998244353LL;

ll DP[3001][3001][3];
int N, S;

int main() {
	cin >> N >> S;
	for (int i = 0; i <= N; ++i)
		DP[i][0][0] = 1;
	vector<int> A(N);
	for (int i = 0; i < N; ++i)
		cin >> A[i];
	for (int i = 1; i <= N; ++i) {
		int a = A[i - 1];
		for (int s = 0; s <= 3000; ++s) {
			// use & 0 to 1
			if (s >= a) DP[i][s][1] += DP[i - 1][s - a][0];
			// no use & 0 to 1
			DP[i][s][1] += DP[i - 1][s][0];
			// use
			if (s >= a) DP[i][s][1] += DP[i - 1][s - a][1];
			// no use
			DP[i][s][1] += DP[i - 1][s][1];
			// MOD
			DP[i][s][1] %= MOD;
			// 1 to 2
			DP[i][s][2] = (DP[i - 1][s][2] + DP[i][s][1]) % MOD;
		}
	}
	cout << DP[N][S][2] << endl;
	return 0;
}