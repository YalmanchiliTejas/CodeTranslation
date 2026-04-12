//#define _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"

#define rep(i,n) for(ll (i)=0;(i)<(ll)(n);(i)++)
#define all(x) (x).begin(),(x).end()
#define MOD 1000000007LL
#define INF (1LL<<60LL)
#define int long long
typedef long long ll;

using namespace std;

ll n, m;
vector<vector<ll>> g(9, vector<ll>(0));

ll dfs(vector<ll> visits, ll v) {
	for (auto a : visits) {
		if (v == a) return 0;
	}
	visits.emplace_back(v);
	if (visits.size() == n) return 1;
	ll res = 0;
	for (auto a : g[v]) {
		res += dfs(visits, a);
	}
	return res;
}


signed main() {
	cin >> n >> m;
	rep(i, m) {
		ll a, b; cin >> a >> b;
		g[a].emplace_back(b);
		g[b].emplace_back(a);
	}
	vector<ll> visits(0);
	ll ans = dfs(visits, 1);
	cout << ans << endl;
}