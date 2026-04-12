//#pragma GCC optimize ("O3")
//#pragma GCC target ("avx")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rep1(i, n) for(int i = 1; i <= (n); i++)
#define co(x) cout << (x) << "\n"
#define cosp(x) cout << (x) << " "
#define ce(x) cerr << (x) << "\n"
#define cesp(x) cerr << (x) << " "
#define pb push_back
#define mp make_pair
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
#define Would
#define you
#define please


ll dp[200001][3][2];
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);


	int N;
	cin >> N;
	int A[200000];
	rep(i, N) cin >> A[i];

	rep(i, N + 1) rep(j, 3) rep(k, 2) dp[i][j][k] = -1e18;
	dp[0][0][0] = 0;
	rep(i, N) {
		int a = A[i];
		chmax(dp[i + 1][1][0], dp[i][0][0]);
		chmax(dp[i + 1][0][1], dp[i][0][0] + a);

		chmax(dp[i + 1][0][0], dp[i][0][1]);

		chmax(dp[i + 1][2][0], dp[i][1][0]);
		chmax(dp[i + 1][1][1], dp[i][1][0] + a);

		chmax(dp[i + 1][1][0], dp[i][1][1]);

		chmax(dp[i + 1][2][1], dp[i][2][0] + a);

		chmax(dp[i + 1][2][0], dp[i][2][1]);
	}

	if (N % 2) {
		ll kotae = dp[N][1][0];
		chmax(kotae, dp[N][2][1]);
		co(kotae);
	}
	else {
		co(max(dp[N][0][0], dp[N][1][1]));
	}

	Would you please return 0;
}