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

	for(int i=1;i<=N;i++) {
		for(int j=0;j<2;j++) {
			for(int k=0;k<3;k++) {
				// 取らない
				if(k + j < 3) dp[i][1][k+j] = max(dp[i][1][k+j], dp[i-1][j][k]);
				// 取る
				if(j == 1) dp[i][0][k] = max(dp[i][0][k], dp[i-1][j][k] + A[i-1]);
			}
		}
	}
	if(N % 2 == 0) cout << max(dp[N][1][0], dp[N][0][1]) << endl;
	else cout << max(dp[N][0][2], dp[N][1][1]) << endl;
}