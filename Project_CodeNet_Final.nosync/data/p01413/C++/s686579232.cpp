#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
#include<cassert>
#include<complex>
using namespace std;

//#define int long long
typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
const ll mod = 1000000007;
const ll INF = mod * mod;
typedef pair<int, int>P;
typedef pair<int, bool> sP;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef pair<ll, ll> LP;
typedef vector<ll> vec;
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef vector<vector<ll>> mat;
typedef vector<ll> vec;

void solve() {
	int n, m, w, t; cin >> n >> m >> w >> t;
	map<string, int> mp;
	vector<int> v(m), p(m);
	rep(i, m) {
		string s; cin >> s;
		mp[s] = i;
		cin >> v[i] >> p[i];
	}
	vector<int> x(n), y(n);
	vector<vector<int>> r(n), q(n);
	rep(i, n) {
		int sz; cin >> sz;
		cin >> x[i] >> y[i];
		r[i].resize(sz); q[i].resize(sz);
		rep(j, sz) {
			string s; cin >> s;
			r[i][j] = mp[s];
			cin >> q[i][j];
		}
	}
	/*vector<vector<int>> dp(n);
	rep(i, n) {
		dp[i].resize(w + 1, -mod);
		dp[i][0] = 0;
		rep(j, r[i].size()) {
			int id = r[i][j];
			int wei = v[id];
			int bene = p[id]-q[i][j];
			rep(k, w + 1) {
				if (k + wei <= w) {
					dp[i][k + wei] = max(dp[i][k + wei], dp[i][k] + bene);
				}
			}
		}
	}*/
	vector<P> vp;
	rep1(i, (1 << n) - 1) {
		vector<int> dp(w + 1, -mod);
		dp[0] = 0;
		vector<int> bene(m, -mod);
		vector<int> e;
		rep(j, n) {
			if (i&(1 << j)) {
				e.push_back(j);
				rep(k, r[j].size()) {
					bene[r[j][k]] = max(bene[r[j][k]], p[r[j][k]]-q[j][k]);
				}
			}
		}
		rep(j, m) {
			rep(k, w + 1) {
				if (k + v[j] <= w) {
					dp[k + v[j]] = max(dp[k+v[j]], dp[k] + bene[j]);
				}
			}
		}
		int ma = 0;
		rep(j, w + 1)ma = max(ma, dp[j]);
		int cost = mod;
		while (1) {
			int sum = 0;
			sum += abs(x[e[0]]) + abs(y[e[0]]);
			sum += abs(x[e.back()]) + abs(y[e.back()]);
			rep(i, (int)e.size() - 1) {
				int dx = abs(x[e[i]] - x[e[i + 1]]);
				int dy = abs(y[e[i]] - y[e[i + 1]]);
				sum += dx + dy;
			}
			cost = min(cost, sum);
			if (!next_permutation(e.begin(), e.end()))break;
		}
		vp.push_back({ ma,cost });
	}
	vector<ll> dp(t+1, -INF);
	dp[0] = 0;
	rep(i, vp.size()) {
		int wei = vp[i].second;
		ll val = vp[i].first;
		rep(j, t + 1) {
			if (j + wei <= t) {
				dp[j + wei] = max(dp[j + wei], dp[j] + val);
			}
		}
	}
	ll ans = -INF;
	rep(i, t + 1)ans = max(ans, dp[i]);
	cout << ans << endl;
}


signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(7);
	//init();
	solve();
	//stop
	return 0;
}


