#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
constexpr int MOD = 998244353;
constexpr int INF = numeric_limits<int>::max() / 2;
typedef pair<int,int> P;
using Graph = vector<vector<int>>;

int dp[3030][6010][3];


signed main(){
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int N, S;
	cin >> N >> S;
	int A[N];
	rep(i,N) cin >> A[i];
	dp[0][0][0] = 1;
	rep(i,N){
		rep(j,S+1){
			// from 0
			dp[i+1][0][0] = 1;
			dp[i+1][j+A[i]][1] += dp[i][j][0] * (i+1);
			dp[i+1][j+A[i]][2] += dp[i][j][0] * (i+1) * (N-i);

			// from 1
			dp[i+1][j][1] += dp[i][j][1];
			dp[i+1][j+A[i]][1] += dp[i][j][1];
			dp[i+1][j+A[i]][2] += dp[i][j][1] * (N-i);

			// from 2
			dp[i+1][j][2] += dp[i][j][2];

			dp[i+1][j][1] %= MOD;
			dp[i+1][j+A[i]][1] %= MOD;
			dp[i+1][j][2] %= MOD;
			dp[i+1][j+A[i]][2] %= MOD;
		}
	}
	cout << dp[N][S][2] << endl;
 }