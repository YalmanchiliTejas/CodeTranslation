#include <bits/stdc++.h>
using namespace std;
 
#define vi vector<int>
#define ll long long
#define ld long double
#define vvi vector<vi>
#define vll vector<ll>
#define vld vector<ld>
#define vvll vector<vll>
#define vvld vector<vld>
#define MOD 1000000007
#define endL << '\n'
#define ii pair<int, int>
#define pll pair<ll, ll>
#define fi first
#define se second
#define mp make_pair
#define endL << '\n'
#define vii vector<ii>
#define pb push_back

/*
ll powmod(ll x, ll y, ll mod){
	ll res = 1;
	while (y > 0){
		if (y%2) res = (res*x) % mod;
		x = (x*x) % mod;
		y /= 2;
	}
	return res;
}
*/

/*const int N = 1000000;
int lp[N+1];
vector<ll> pr;

void sieve(){
	for (int i=2; i<=N; ++i) {
	    if (lp[i] == 0) {
	        lp[i] = i;
	        pr.push_back (i);
	    }
	    for (int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=N; ++j)
	        lp[i * pr[j]] = pr[j];
	}
}*/

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t=1; //cin >> t;
	while(t--){

		int n; cin >> n;
		vll a(n); for (int i = 0; i < n; i++) cin >> a[i];
		vector<vector<pll>> dp(n, vector<pll>(n, mp(-1, -1)));
		for (int i = 0; i < n; i++) dp[i][i] = mp(a[i], 0);
		for (int i = 0; i < n-1; i++) dp[i][i+1] = mp(min(a[i], a[i+1]), max(a[i], a[i+1]));
		int j;
		for (int len = 3; len <= n; len++){
			for (int i = 0; i < n; i++){
				j = i + len - 1;
				if (j >= n) break;
				if (len % 2 == 1){
					if (a[i] + dp[i+1][j].fi > a[j] + dp[i][j-1].fi){
						dp[i][j] = mp(a[i] + dp[i+1][j].fi, dp[i+1][j].se);
					}
					else dp[i][j] = mp(a[j] + dp[i][j-1].fi, dp[i][j-1].se);
				}
				else {
					if (a[i] + dp[i+1][j].se > a[j] + dp[i][j-1].se){
						dp[i][j] = mp(dp[i+1][j].fi, a[i] + dp[i+1][j].se);
					}
					else dp[i][j] = mp(dp[i][j-1].fi, a[j] + dp[i][j-1].se);
				}
			}
		}
		ll ans = dp[0][n-1].fi - dp[0][n-1].se;
		if (n % 2 == 0) ans *= -1;
		cout << ans;
	}
}