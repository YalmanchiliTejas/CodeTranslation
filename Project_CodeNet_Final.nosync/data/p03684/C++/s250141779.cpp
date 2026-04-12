#define _CRT_SECURE_NO_WARNINGS
#include"bits/stdc++.h"
#ifdef _DEBUG
#define DBG(n) n
#else
#define DBG(n)
#endif
#define INF         1e9
#define INFLL       1e18
#define EPS         1e-9
#define REP(i,n)    for(ll i=0,i##_len=(n);i<i##_len;++i)
#define REP1(i,n)   for(ll i=1,i##_len=(n);i<=i##_len;++i)
#define REPR(i,n)   for(ll i=(n)-1;i>=0;--i)
#define REPR1(i,n)  for(ll i=(n);i>0;--i)
#define REPC(i,obj) for(auto i:obj)
#define ALL(obj)    (obj).begin(),(obj).end()
#define SETP(n)     cout << fixed << setprecision(n)
using namespace std;
using ll = long long;
template<typename T = ll>inline T in() { T ret; cin >> ret; return ret; }

struct UF {
	vector<ll> par, sz, rank;
	UF(ll n) : par(n), sz(n), rank(n) {
		REP(i, n) {
			par[i] = i;
			sz[i] = 1;
			rank[i] = 0;
		}
	}
	ll find(ll x) {
		return par[x] == x ? x : par[x] = find(par[x]);
	}
	void unite(ll x, ll y) {
		x = find(x);
		y = find(y);
		if (x != y) {
			if (rank[x] < rank[y]) {
				par[x] = y;
				sz[y] += sz[x];
			} else {
				par[y] = x;
				sz[x] += sz[y];
				if (rank[x] == rank[y]) {
					rank[x]++;
				}
			}
		}
	}
	bool same(ll x, ll y) {
		return find(x) == find(y);
	}
	ll size(ll n) {
		return sz[find(n)];
	}
};

using cood = pair<ll, ll>;
using coid = pair<cood, ll>;
using edge = pair<coid, coid>;
ll cost(const edge&e) {
	cood beg = e.first.first, end = e.second.first;
	return min(abs(beg.first - end.first), abs(beg.second - end.second));
}
signed main() {
	ll n = in();
	vector<coid>c(n);
	REP(i, n) {
		ll x = in(), y = in();
		c[i] = make_pair(make_pair(x, y), i);
	}
	vector<edge>e(2 * (n - 1));
	sort(ALL(c), [](const coid&c1, const coid&c2) {return c1.first.first < c2.first.first; });
	REP(i, n - 1)e[i] = make_pair(c[i], c[i + 1]);
	sort(ALL(c), [](const coid&c1, const coid&c2) {return c1.first.second < c2.first.second; });
	REP(i, n - 1)e[i + n - 1] = make_pair(c[i], c[i + 1]);
	sort(ALL(e), [](const edge&e1, const edge&e2) {return  cost(e1) < cost(e2); });
	ll ans = 0;
	UF uf(n);
	REPC(i, e) {
		ll idx_b = i.first.second, idx_e = i.second.second;
		if (!uf.same(idx_b, idx_e)) {
			ans += cost(i);
			uf.unite(idx_b, idx_e);
		}
	}
	cout << ans << endl;
}