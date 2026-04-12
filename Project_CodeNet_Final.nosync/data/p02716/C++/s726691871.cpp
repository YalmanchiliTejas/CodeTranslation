#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(){
	int n;
	cin >> n;
	vector<int> a(n+1);
	for(int i=1;i<=n;++i) cin >> a[i];
	ll dp[n+1][2];
	memset(dp,0,sizeof dp);
	dp[2][1] = a[2];
	dp[2][0] = a[1];
	for(int i=3;i<=n;++i){
		if(i&1){
			ll temp = max({dp[i-3][1],dp[i-3][0],dp[i-2][1],dp[i-2][0]});
			dp[i][1] = a[i]+temp;
			dp[i][0] = max({a[i-1]+dp[i-2][0],a[i-1]+dp[i-3][1],a[i-1]+dp[i-3][0],a[i-2]+dp[i-3][0]});		
		}
		else{
			dp[i][1] = a[i] + max({dp[i-2][1],dp[i-2][0],dp[i-1][0]});
			dp[i][0] = a[i-1]+dp[i-2][0];
		}
	}
	cout << max(dp[n][1], dp[n][0]) << '\n';
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	//cin >> t;
	while(t--){ 
		solve();
	}
	return 0;
}