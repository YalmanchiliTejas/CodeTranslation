#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;
using vvl = vector<vl>;
using vb = vector<bool>;
const ll oo = 0x3f3f3f3f3f3f3f3fLL;
const double eps = 1e-9;
#define sz(c) ll((c).size())
#define all(c) begin(c),end(c)
#define mp make_pair
#define pb push_back
#define xx first
#define yy second
#define FOR(i,a,b) for (ll i=(a); i<(b); i++)
#define FORD(i,a,b) for (ll i=ll(b)-1; i>=(a); i--)

int main() {
	ios::sync_with_stdio(false);

	ll n; cin >> n;

	vl a(n);

	vvl dp(n, vl(n+1, 0));
	FOR(i,0,n) {
		cin >> a[i];
	}

	FOR(j,1,n+1) {
		FOR(i,0,n) {
			ll x = i;
			ll y = i + j;
			if (y > n) {
				continue;
			}
			if (i+1 >= n) {
				dp[i][j] = a[y-1] - dp[i][j-1];
			} else {
				dp[i][j] = max(a[x] - dp[i+1][j-1], a[y-1] - dp[i][j-1]);
			}
		}
	}

	cout << dp[0][n] << endl;

	return 0;
}
