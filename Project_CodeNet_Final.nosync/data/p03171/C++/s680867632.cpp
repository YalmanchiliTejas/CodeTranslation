#include <bits/stdc++.h>
 
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) FOR(i,0,n)
#define RFOR(i,a,b) for(int i=(a)-1;i>=(b);i--)
#define rrep(i,n) RFOR(i,n,0)
 
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
 
int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
 
	int n;
	cin >> n;
 
	ll a[n];
	rep(i, n) cin >> a[i];
 
	ll dp[n+1][n+1];
	rep(i, n+1) rep(j, n+1) dp[i][j] = 0;
	// dp[i][j] :
	//  ai+1からajでゲームをするときのX-Yの最大値
	//  ただし、手番は「元のゲームを行ってその局面になった時の手番」とする
 
	for(int len = 1; len <= n; len++){
		for(int l = 0; l < n - len + 1; l++){
			int r = l + len;
			if((n - len) % 2 == 0){
				dp[l][r] = max(dp[l+1][r] + a[l], dp[l][r-1] + a[r-1]);
			}else{
				dp[l][r] = min(dp[l+1][r] - a[l], dp[l][r-1] - a[r-1]);
			}
		}
	}
 
	cout << dp[0][n] << endl;
}