#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define F first
#define S second
#define bitcnt(v) __builtin_popcount(v)
#define all(v) v.begin(), v.end()

vector<ll> a;
int n; 

void solution(){
	cin >> n;
	a = vector<ll>(n); for(auto& x : a) cin >> x;
	// Game Theory DP
	// dp[i][j] - max value of X - Y for a[i]...a[j]
	// X - who moves first in that move
	// Y - second player in that move
	ll dp[n][n];
	memset(dp,-1e9,sizeof(dp));
	for(int i = 0; i < n; i++) dp[i][i] = a[i];
	for(int x = 1; x < n; x++){
		for(int y = 0; y+x < n; y++){
			int i = y, j = y+x;
			dp[i][j] = max(a[i] - dp[i+1][j], a[j] - dp[i][j-1]);
		}
	}
	cout << dp[0][n-1] << endl;
}	


int main(){ 

	fio;
	int t;
	t = 1;
	// cin >> t;
	for(int i = 1; i <= t; i++){
		// cout << "Case #" << i << ": ";
		solution();
	} 
	return 0;
}
