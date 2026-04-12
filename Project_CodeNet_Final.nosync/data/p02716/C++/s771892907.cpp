#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll MOD = 1e9+7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i = (m); i <= (n); i++)
#define zep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define printa(x,m,n) for(ll i = (m); i <= n; i++){cout << (x[i]) << " ";} cout<<endl;

int main(){
	cin.tie(0); ios::sync_with_stdio(false);
	
	ll n; cin >> n;
	ll a[n+1]; rep(i, 1, n){cin >> a[i];}
	
	if(n%2 == 0){
		ll dp[n+1][2];
		rep(i, 1, n){
			rep(j, 0, 1){
				dp[i][j] = -INF;
			}
		}
		dp[1][0] = a[1];
		dp[2][1] = a[2];
		
		rep(i, 1, n){
			if(i-2 > 0){
				dp[i][0] = max(dp[i][0], dp[i-2][0]+a[i]);
				dp[i][1] = max(dp[i][1], dp[i-2][1]+a[i]);
			}
			if(i-3 > 0){
				dp[i][1] = max(dp[i][1], dp[i-3][0]+a[i]);
			}
		}
		print(max(dp[n-1][0], dp[n][1]))
	}
	else{
		ll dp[n+1][3];
		rep(i, 1, n){
			rep(j, 0, 2){
				dp[i][j] = -INF;
			}
		}
		dp[1][0] = a[1];
		dp[2][1] = a[2];
		dp[3][2] = a[3];
		
		rep(i, 1, n){
			if(i-2 > 0){
				dp[i][0] = max(dp[i][0], dp[i-2][0]+a[i]);
				dp[i][1] = max(dp[i][1], dp[i-2][1]+a[i]);
				dp[i][2] = max(dp[i][2], dp[i-2][2]+a[i]);
			}
			if(i-3 > 0){
				dp[i][1] = max(dp[i][1], dp[i-3][0]+a[i]);
				dp[i][2] = max(dp[i][2], dp[i-3][1]+a[i]);
			}
			if(i-4 > 0){
				dp[i][2] = max(dp[i][2], dp[i-4][0]+a[i]);
			}
			//cout << dp[i][0] << " " << dp[i][1] << " " << dp[i][2] << endl;
		}
		print(max(dp[n-2][0], max(dp[n-1][1], dp[n][2])))
	}
	return 0;
}