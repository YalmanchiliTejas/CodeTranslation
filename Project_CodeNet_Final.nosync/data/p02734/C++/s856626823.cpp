#include <bits/stdc++.h>
using namespace std;
using Int = int_fast64_t;

constexpr Int mod = 998244353;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	Int n, s; cin >> n >> s;
	vector<Int> a(n);
	for(auto &i:a) cin >> i;
	vector<vector<Int>> dp(n, vector<Int>(s+1, 0));
	Int ans = 0;
	for(Int i=0; i<n; ++i){
		if(i > 0){
			for(Int j=0; j<=s; ++j){
				dp[i][j] += dp[i-1][j];
				dp[i][j] %= mod;
				if(j+a[i] <= s){
					dp[i][j+a[i]] += dp[i-1][j];
					dp[i][j+a[i]] %= mod;
				}
			}
		}
		if(a[i] <= s){
			dp[i][a[i]] += i+1;
			dp[i][a[i]] %= mod;
		}
		ans += dp[i][s];
		ans %= mod;
	}
	cout << ans << "\n";
}