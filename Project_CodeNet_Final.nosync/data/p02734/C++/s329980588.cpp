#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;
const int maxN = 4000;
const ll MOD = 998244353;
ll dp[maxN][maxN] = {{0}};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, s;
	cin>>n>>s;
	ll ans = 0;
	vector<ll> a(n);
	for (int i = 0; i < n; i++) {
		cin>>a[i];
		for (int j = 0; j <= s; j++) {
			dp[i+1][j] = dp[i][j];
		}
		for (int j = a[i]; j <= s; j++) {
			dp[i+1][j] += dp[i][j-a[i]];
			dp[i+1][j] %= MOD;
			// cout<<dp[i+1][j]<<' ';
		}
		dp[i+1][a[i]] += i+1;
		dp[i+1][a[i]] %= MOD;
		for (int j = 0; j <= s; j++){
			// cout<<dp[i+1][j]<<' ';
		}
		// cout<<'\n';
	}
	for (int i = 1; i <= n; i++) {
		ans += dp[i][s];
		ans %= MOD;
	}
	cout<<ans<<'\n';
	return 0;
}