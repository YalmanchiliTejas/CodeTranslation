#include <bits/stdc++.h>
#define rep(i, a, n) for(int i = a; i < n; i++)
#define REP(i, n) rep(i, 0, n)
#define int long long
using namespace std;
typedef pair<int, int> P;
const int mod = 1000000007;
const int INF = 1e18;

int dp[110][5][2];

signed main(){
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	string s;
	int kk;
	cin >> s >> kk;
	int n = s.size();
	dp[0][0][0] = 1;
	rep(i, 0, n){
		rep(j, 0, kk + 1){
			if(s[i] == '0') dp[i + 1][j][0] += dp[i][j][0];
			else dp[i + 1][j][1] += dp[i][j][0];
			dp[i + 1][j][1] += dp[i][j][1];
			rep(k, 1, 10){
				if(s[i] == '0' + k) dp[i + 1][j + 1][0] += dp[i][j][0];
				else if(s[i] > '0' + k) dp[i + 1][j + 1][1] += dp[i][j][0];
				dp[i + 1][j + 1][1] += dp[i][j][1];
			}
		}
	}
	cout << dp[n][kk][0] + dp[n][kk][1] << endl;
}