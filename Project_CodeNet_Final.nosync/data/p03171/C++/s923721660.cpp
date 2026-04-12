///=======================///
/// coder: Andy - Tohrumi ///
///=======================///

#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define fastio ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0);
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
#define rep(i, a, b) for(__typeof(b) i = a; i < b; i++)
#define Rep(i, a, b) for(__typeof(a) i = a; i > b; i--)

using namespace std;

typedef pair<ll, ll> pll;	typedef pair<int, int> ii;
typedef vector<pll> vll;	typedef vector<string> vs;		typedef vector<ii> vii;
typedef vector<int> vi; 	typedef vector<ll> vl;

///====code start here====///

ll dp[3005][3005];

signed main() {
	fastio;
	int n; cin >> n;
	ll a[n];
	rep(i, 0, n) cin >> a[i];
	Rep(l, n - 1, -1) {
		rep(r, l, n) {
			if(l == r) dp[l][r] = a[l];
			else {
				dp[l][r] = max(a[l] - dp[l + 1][r], a[r] - dp[l][r - 1]);
			}
		}
	}
	cout << dp[0][n - 1] << endl;
	return 0;
}
