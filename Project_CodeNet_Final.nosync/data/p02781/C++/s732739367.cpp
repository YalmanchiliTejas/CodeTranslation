#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
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


int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);


	string N, S;
	cin >> S;
	int keta = S.size();
	int amari = 100 - keta;
	rep(i, amari) N += '0';
	N += S;
	int K;
	cin >> K;

	ll dp[101][4][2] = {};
	dp[0][0][0] = 1;
	
	rep(i, 100) {
		rep(j, K) {
			if (N[i] == '0') dp[i + 1][j][0] += dp[i][j][0];
			else {
				dp[i + 1][j + 1][0] += dp[i][j][0];
				dp[i + 1][j + 1][1] += dp[i][j][0] * (N[i] - '0' - 1);
				dp[i + 1][j][1] += dp[i][j][0];
			}
			dp[i + 1][j + 1][1] += dp[i][j][1] * 9;
			dp[i + 1][j][1] += dp[i][j][1];
		}
		if (N[i] == '0') dp[i + 1][K][0] += dp[i][K][0];
		else dp[i + 1][K][1] += dp[i][K][0];
		dp[i + 1][K][1] += dp[i][K][1];
	}

	co(dp[100][K][0] + dp[100][K][1]);





	Would you please return 0;
}