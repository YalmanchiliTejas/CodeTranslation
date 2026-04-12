#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(long long i = 0; i < n; i++)
#define all(v) v.begin(), v.end()
#define pq priority_queue
#define bcnt(n) __builtin_popcountll(n)

using ll = long long;  // long longをllだけにした
using vll = vector<ll>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;
using mll = map<long long, long long>;
using pll = pair<long long, long long>;
using sll = set<long long>;
using vpll = vector<pair<long long, long long>>;
using mlv = map<long long, vector<long long>>;

int main() {
	ll const mod = 1e9 + 7;
	string p;
	ll d;
	cin >> p >> d;
	ll n = p.size();
	vll k(n);
	rep(i, n) k[i] = p[i] - '0';
	vvvll dp(n + 1, vvll(d, vll(2, 0)));  //[][][1]は未満フラグtrue
	dp[0][0][0] = 1;
	// cout << "#" << endl;
	rep(i, n) {
		rep(j, d) {
			ll w = (j + k[i]) % d;
			dp[i + 1][w][0] += dp[i][j][0];
			dp[i + 1][w][0] %= mod;
			rep(r, k[i]) {
				ll l = (j + r) % d;
				dp[i + 1][l][1] += dp[i][j][0];
				dp[i + 1][l][1] %= mod;
			}
			rep(r, 10) {
				ll l = (j + r) % d;
				dp[i + 1][l][1] += dp[i][j][1];
				dp[i + 1][l][1] %= mod;
			}
		}
	}
	ll res = (dp[n][0][0] + dp[n][0][1] - 1 + mod) % mod;
	cout << res << endl;
}
