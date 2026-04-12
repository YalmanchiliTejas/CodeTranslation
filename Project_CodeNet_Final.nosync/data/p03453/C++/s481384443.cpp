#include <bits/stdc++.h>
/*#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>*/
 
#define pb push_back
#define mp make_pair
#define sz(s) ((int)(s.size()))
#define all(s) s.begin(), s.end()
#define rep(i, a, n) for (int i = a; i <= n; ++i)
#define per(i, n, a) for (int i = n; i >= a; --i)
#define onlycin ios_base::sync_with_stdio(false); cin.tie(0) 
using namespace std;
// using namespace __gnu_pbds;
typedef long long ll;
typedef unsigned long long ull;
/*typedef tree<
pair < int, int >,
null_type,
less< pair < int, int > >,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;*/
// find_by_order() order_of_key()
const int MAXN = (int)5e5+228;
const char nxtl = '\n';
const int mod = (int)1e9+7;
const double eps = (double)1e-7;
template<typename T> inline bool updmin(T &a, const T &b) {return a > b ? a = b, 1 : 0;}
template<typename T> inline bool updmax(T &a, const T &b) {return a < b ? a = b, 1 : 0;}
#define int long long
int n, m, cnt[2][MAXN];
ll dp[2][MAXN];
vector < pair < int, int > > g[MAXN];

void go(int type, int x) {
	set < pair < int, int > > S;
	rep(i, 0, n) dp[type][i] = (ll)1e15;
	dp[type][x] = 0;
	cnt[type][x] = 1;
	S.insert(mp(0, x));
	while(!S.empty()) {
		int v = S.begin()->second; S.erase(S.begin());
		for(auto &it : g[v]) {
			int to = it.first; ll D = dp[type][v] + it.second;
			if(D < dp[type][to]) {
				S.erase(mp(dp[type][to], to));
				dp[type][to] = D;
				cnt[type][to] = cnt[type][v];
				S.insert(mp(dp[type][to], to));
			} else if(D == dp[type][to]) {
				(cnt[type][to] += cnt[type][v]) %= mod;
			}
		}
	}
}
int get(int x) {
	return x *1ll * x % mod;
}

signed main() {
	#ifdef accepted
		freopen(".in", "r", stdin);
		freopen(".out", "w", stdout);
	#endif
	onlycin;
	cin >> n >> m;
	int x, y; cin >> x >> y;
	rep(i, 1, m) {
		int from, to, w; cin >> from >> to >> w;
		g[from].pb(mp(to, w));
		g[to].pb(mp(from, w));
	}
	go(0, x); go(1, y);
	int res = get(cnt[0][y]);
	cerr << res << nxtl;
	rep(i, 1, n) {
		if(dp[0][i] * 2 == dp[0][y] && dp[1][i] * 2 == dp[0][y]) {
			res = (res - (get(cnt[1][i] * 1ll * cnt[0][i] % mod) % mod) + mod) % mod;
			// cerr << get(cnt[1][i] * 1ll * cnt[0][i] % mod) << nxtl;
			// continue;
	 	}
		rep(j, 0, sz(g[i]) - 1) {
			// if(g[i][j].first == y || g[i][j].first == x) continue;
			int to = g[i][j].first, ww = g[i][j].second;
			if(dp[0][i] + dp[1][to] + ww == dp[0][y] && dp[0][i] *2 < dp[0][y] && dp[1][to] *2 < dp[0][y])
				res = (res - get(cnt[0][i] * 1ll * cnt[1][to] % mod) + mod) % mod;
		}
	}
	cout << res % mod << nxtl;
	return 0;
}