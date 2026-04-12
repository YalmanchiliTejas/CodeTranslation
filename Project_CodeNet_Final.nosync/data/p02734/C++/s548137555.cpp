// copied by Nurstan Duisengaliev
// skatal
#include <bits/stdc++.h>
 
#define ll long long
#define all(x) x.begin(), x.end()
#define in insert
#define mp make_pair
#define F first
#define S second
#define ppf pop_front
#define pb push_back
#define ppb pop_back
#define pf push_front
#define pii pair <int, int>
#define boost() ios_base::sync_with_stdio(0), cin.tie(0)
#define sz(x) (int)x.size()
#define int ll 
using namespace std;             
 
const int N = 3005;
const int mod = 998244353; 
const ll INF = (ll)1e18 + 7;
int n, s, a[N];
pair <bool, ll> dp[N];
void solve () {
	dp[0].F = 1;
	dp[0].S = 0;
	cin >> n >> s;
	ll ans = 0;
	for (int i = 1; i <= n; i ++) cin >> a[i];
	for (int i = 1; i <= n; i ++) {
	
		if (s > a[i] && dp[s - a[i]].F == 1) ans += (n - i + 1) * dp[s - a[i]].S;
		if (s == a[i]) ans += ((n - i + 1) * i);
		ans %= mod;
		for (int j = s - 1; j >= 0; j --) {
			if (dp[j].F == 1 && j + a[i] <= s) {
				dp[j + a[i]].F = 1;
				dp[j + a[i]].S += dp[j].S;
				dp[j + a[i]].S %= mod;		
			}
		}
		if (a[i] < s) dp[a[i]].S += i;
		dp[a[i]].S %= mod;		
	}
	cout << ans;
}   	
 
main () {
//	freopen (".in", "r", stdin);
//	freopen (".out", "w", stdout);
	boost ();
	int TT = 1;
//    cin >> TT;
	while (TT --) {
		solve ();
	}
	return 0;	
}