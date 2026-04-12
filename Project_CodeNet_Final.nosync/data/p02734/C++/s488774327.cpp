#include<bits/stdc++.h>
#define pb push_back
#define ii pair<int,int>
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define INF 100000000000000000
#define modulo 1000000007
#define mod 998244353
#define int long long int
using namespace std;


int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, S, ans = 0;
	cin >> n >> S;
	vector<vector<int> > dp(n + 1, vector<int>(S + 1, 0));

	for(int i = 1; i <= n; i++){
		dp[i] = dp[i - 1];
		int x;
		cin >> x;
		for(int j = x; j <= S; j++){
			dp[i][j] = (dp[i][j] + dp[i - 1][j - x]) % mod;
		}
		if(x <= S) dp[i][x] = (dp[i][x] + i) % mod;
		ans = (ans + dp[i][S]) % mod;
	}
	cout << ans;
}