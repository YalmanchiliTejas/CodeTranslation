#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<=n;i++)
typedef long long ll;

ll dp[200005][4];
ll INF = 1e+18;

int main(){
	ll n;
	cin >> n;
	vector<ll> a(n);
	rep(i,n) cin >> a[i];
	ll k = 1 + n % 2 ;
	rep(i,n+1)rep(j,k+1) dp[i][j] = -INF;
	dp[0][0] = 0;
	rep(i,n){
		rep(j,k+1){
			dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j]);
			ll now = dp[i][j];
			if((i+j)%2 == 0) now += a[i];
			dp[i+1][j] = max(dp[i+1][j], now);
		}
	}
	ll ans = dp[n][k];
	cout << ans << endl;
	return 0;
}