#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,a,b) for(ll i=a;i <= b;i++)
#define fast_io ios_base::sync_with_stdio(false)
#define pb push_back
#define fir first
#define sec second
#define tr(it,x) for(it = x.begin();it != x.end();it++)
#define mp make_pair
#define sz(x) (ll)x.size()
#define rep(i,n) for(ll i=0;i<n;i++)
#define double long double
#define accuracy ll precision = numeric_limits<double>::digits10
#define pll pair<ll,ll>
#define N 3005

ll n,a[N],dp[N][N][2];

int main() {
	// freopen("input.txt", "r", stdin); 
	// freopen("output.txt", "w", stdout);
	fast_io;	 
	accuracy;
	cin >> n;
	fr(i,1,n) cin >> a[i];
	fr(i,1,n) {
		dp[i][i][0] = a[i];
		dp[i][i][1] = -a[i];
	}
	fr(i,2,n) {
		fr(sta,1,n) {
			ll en = sta + i - 1;
			if(en <= n) {
				dp[sta][en][0] = max(a[sta] + dp[sta+1][en][1],a[en] + dp[sta][en-1][1]);
				dp[sta][en][1] = min(-a[sta] + dp[sta+1][en][0],-a[en] + dp[sta][en-1][0]);
			}
		}
	}
	cout << dp[1][n][0] << endl;
}