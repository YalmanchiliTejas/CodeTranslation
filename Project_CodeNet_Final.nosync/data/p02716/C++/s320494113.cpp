#include <bits/stdc++.h>
using namespace std;
using  ll = long long;

int main() {
	int N; cin >> N;
	vector<ll> A(N);
	for(int i=0;i<N;i++) {
		cin >> A[i];
	}

	vector<vector<vector<ll>>> dp(N+1, vector<vector<ll>>(2, vector<ll>(3, -1LL<<60)));

	// dp[i][j][k]: i番目, i要素目を取らないならj = 1, k: これまで連続で選ばなかった箇所の個数
	dp[0][1][0] = 0;
	for(int i=0;i<N;i++) {
		// 取らない
		for(int k=0;k<2;k++)
			dp[i+1][1][k+1] = max(dp[i+1][1][k+1], dp[i][1][k]);
		for(int k=0;k<3;k++)
			dp[i+1][1][k] = max(dp[i+1][1][k], dp[i][0][k]);

		// 取る
		for(int k=0;k<3;k++)
			dp[i+1][0][k] = max(dp[i+1][0][k], dp[i][1][k] + A[i]);
	}
	if(N % 2 == 0) cout << max(dp[N][0][1], dp[N][1][0]) << endl;
	else cout << max(dp[N][0][2], dp[N][1][1]) << endl;
}