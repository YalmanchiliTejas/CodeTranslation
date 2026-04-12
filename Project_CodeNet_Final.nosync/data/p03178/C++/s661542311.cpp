#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;
const int MOD = 1e9 + 7;
int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string K;
	int D, N, **dp, p[10001];
	cin >> K >> D;
	N = K.size();
	dp = new int*[N];
	for(int k = 0; k < N; ++k) {
		dp[k] = new int[D];
		memset(dp[k], 0, D * sizeof(int));
	}
	p[0] = K[0] - '0';
	for(int k = 1; k < N; ++k) 
		p[k] = (p[k - 1] + K[k] - '0') % D;
	for(int k = 0; k <= K[0] - '0'; ++k) 
		++dp[0][k % D];
	for(int k = 1; k < N; ++k) {
		int d = K[k] - '0';
		for(int i = 0; i <= 9; ++i)
			for(int j = 0; j < D; ++j)
				dp[k][(i + j) % D] = (dp[k][(i + j) % D] + dp[k - 1][j]) % MOD;
		for(int i = d + 1; i <= 9; ++i)
			dp[k][(i + p[k - 1]) % D] = (MOD - 1LL + dp[k][(i + p[k - 1]) % D]) % MOD; 
	}
	cout << (dp[N - 1][0] + MOD - 1) % MOD << '\n';
	return 0;
}