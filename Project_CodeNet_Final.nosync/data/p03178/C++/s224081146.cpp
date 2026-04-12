#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

template<typename H> bool chmin(H& v1, const H v2) { if (v1 > v2) { v1 = v2; return true; } return false; }
template<typename H> bool chmax(H& v1, const H v2) { if (v1 < v2) { v1 = v2; return true; } return false; }
template<typename H> void read(H& head) { cin >> head; }
template<typename H, typename ...T> void read(H& head, T& ...tail) { cin >> head; read(tail...); }
template<typename H> void write(H head) { cout << head << '\n'; }
template<typename H, typename ...T> void write(H head, T ...tail) { cout << head << " "; write(tail...); }
template<typename ...T> void die(T ...tok) { write(tok...); exit(0); }

ll dp[10005][2][105];
const ll mod = 1000000007ll;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	string s; int d;
	read(s, d);

	int n = sz(s);
	s = ' ' + s;

	dp[0][1][0] = 1;
	rep(i, 1, n + 1) {
		// tight ->
		int tb = s[i] - '0'; // tight bound
		rep(j, 0, d) if (dp[i - 1][1][j]) {
			rep(k, 0, tb) {
				(dp[i][0][(j + k) % d] += dp[i - 1][1][j]) %= mod;
				//printf("TN %d %d %d -> %d %d %d with %d: %lld\n", i - 1, 1, j, i, 0, (j + k) % d, k, dp[i - 1][1][j]);
			}
			(dp[i][1][(j + tb) % d] += dp[i - 1][1][j]) %= mod;
			//printf("TT %d %d %d -> %d %d %d with %d: %lld\n", i - 1, 1, j, i, 1, (j + tb) % d, tb, dp[i - 1][1][j]);
		}
		// non-tight ->
		rep(j, 0, d) if (dp[i - 1][0][j]) {
			rep(k, 0, 10) {
				(dp[i][0][(j + k) % d] += dp[i - 1][0][j]) %= mod;
				//printf("NN %d %d %d -> %d %d %d with %d: %lld\n", i - 1, 0, j, i, 0, (j + k) % d, k, dp[i - 1][0][j]);
			}
		}
	}

	ll ans = (dp[n][0][0] + dp[n][1][0] + mod - 1) % mod;
	write(ans % mod);
}
