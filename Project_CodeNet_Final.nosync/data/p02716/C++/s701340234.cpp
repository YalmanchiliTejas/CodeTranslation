#include <bits/stdc++.h>
using namespace std;
#define all(V) V.begin(),V.end()
#define ll long long
#define MOD 998244353

ll dp[4][2][200010];

void chmax(ll& a, ll b) {
	a = max(a, b);
}

int main() {
	for (int i = 0;i < 200010;i++) {
		for (int j = 0;j < 4;j++) {
			dp[j][0][i] = dp[j][1][i] = LLONG_MIN / 3;
		}
	}
	int N;
	cin >> N;
	ll A;
	for (int i = 0;i < N;i++) {
		cin >> A;
		if (i == 0) {
			//选 
			dp[3][1][0] = A;
			//不选 
			dp[1][0][0] = 0;
			continue;
		}
		//选 
		chmax(dp[1][1][i], dp[0][0][i - 1] + A);
		chmax(dp[2][1][i], dp[1][0][i - 1] + A);
		chmax(dp[3][1][i], dp[2][0][i - 1] + A);
		//不选 
		chmax(dp[0][0][i], dp[1][0][i - 1]);
		chmax(dp[0][0][i], dp[1][1][i - 1]);
		chmax(dp[1][0][i], dp[2][0][i - 1]);
		chmax(dp[1][0][i], dp[2][1][i - 1]);
		chmax(dp[2][0][i], dp[3][0][i - 1]);
		chmax(dp[2][0][i], dp[3][1][i - 1]);
	}
	
	if (N & 1) {
		cout << max(dp[1][0][N - 1], dp[1][1][N - 1]) << '\n';
	}
	else {
		cout << max(dp[2][0][N - 1], dp[2][1][N - 1]) << '\n';
	}
	
	return 0;
}