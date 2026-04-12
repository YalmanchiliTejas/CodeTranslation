#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
	ll n; cin >> n;
	vector<ll> a(n); for(auto &b : a) cin >> b;
	vector<vector<ll> > dp(n, vector<ll>(n));
	for(ll i = 0; i < n; i++) dp[i][i] = a[i];
	for(ll len = 2; len <= n; len++) for(ll lb = 0; lb < n; lb++){
		ll rb = lb + len - 1;
		if(rb >= n) continue;
		dp[lb][rb] = max(a[lb] - dp[lb+1][rb], a[rb] - dp[lb][rb-1]);
	}
	cout << dp[0][n-1] << endl;
}