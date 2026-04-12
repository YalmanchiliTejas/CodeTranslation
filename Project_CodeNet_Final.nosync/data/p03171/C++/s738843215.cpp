#include "bits/stdc++.h"
using namespace std;

// コンテスト中のみ
//#define int long long

#define ll long long
#define rep(i,n) for(int i = 0; i < (n); i++)
#define P pair<ll,ll>
#define ld long double
ll INF = (1LL << 60);
int MOD = 1000000007;

ll N;
ll a[3010];

ll dp[3100][3100];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N;
	rep(i, N)cin >> a[i];
	for (int len = 1; len <= N; len++) {
		for (int i = 0; i + len <= N; i++) {
			int j = i + len;
			if ((N - len) % 2 == 0) {
				dp[i][j] = max(dp[i + 1][j] + a[i], dp[i][j - 1] + a[j - 1]);
			}
			else {
				dp[i][j] = min(dp[i + 1][j] - a[i], dp[i][j - 1] - a[j - 1]);
			}
		}
	}
	cout << dp[0][N] << endl;

	return 0;
}