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
const ll MOD = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);

	string k;
	ll d;
	cin >> k >> d;

	vector<vvl> dp;
	dp.assign(sz(k), vvl(d, vl(2, 0)));
	ll curr = ll(k[0] - '0');
	FOR(n,0,curr) {
		dp[0][(n)%d][0] += 1;
	}
	dp[0][curr%d][1] += 1;

	FOR(i,1,sz(k)) {
		FOR(j,0,d) {
			FOR(x,0,2) {
				curr = ll(k[i] - '0');
				if (x == 0) {
					// x = 0: alles fine
					FOR(n,0,10) {
						dp[i][(j+n)%d][0] += dp[i-1][j][0];
						dp[i][(j+n)%d][0] %= MOD;
					}
				} else {
					// x = 1: nix fine
					FOR(n,0,curr) {
						dp[i][(j+n)%d][0] += dp[i-1][j][1];
						dp[i][(j+n)%d][0] %= MOD;
					}
					dp[i][(j+curr)%d][1] += dp[i-1][j][1];
					dp[i][(j+curr)%d][1] %= MOD;
				}
			}
		}
	}

	cout << (dp[sz(k)-1][0][0] + dp[sz(k)-1][0][1] - 1 + MOD) %MOD << endl;

	return 0;
}
