#include "bits/stdc++.h"

#define REP(i,n) for(ll i=0;i<n;++i)
#define RREP(i,n) for(ll i=n-1;i>=0;--i)
#define FOR(i,m,n) for(ll i=m;i<n;++i)
#define RFOR(i,m,n) for(ll i=n-1;i>=m;--i)
#define ALL(v) (v).begin(),(v).end()
#define PB(a) push_back(a)
#define UNIQUE(v) v.erase(unique(ALL(v)),v.end());
#define DUMP(v) REP(aa, (v).size()) { cout << v[aa]; if (aa != v.size() - 1)cout << " "; else cout << endl; }
#define INF 1000000001ll
#define MOD 1000000007ll
#define EPS 1e-9

const int dx[8] = { 1,1,0,-1,-1,-1,0,1 };
const int dy[8] = { 0,1,1,1,0,-1,-1,-1 };


using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll max(ll a, int b) { return max(a, ll(b)); }
ll max(int a, ll b) { return max(ll(a), b); }
ll min(ll a, int b) { return min(a, ll(b)); }
ll min(int a, ll b) { return min(ll(a), b); }
///(´・ω・`)(´・ω・`)(´・ω・`)(´・ω・`)(´・ω・`)(´・ω・`)///
struct E {
	int a, b, c;
	E(int aa, int bb, int cc) {
		a = aa; b = bb; c = cc;
	}
	E() {}
};

bool comp(E i, E j) {
	return i.c < j.c;
}
struct UnionFind {
	vector<int> par;
	vector<int> ran;

	UnionFind(int n) {
		par.resize(n);
		ran.resize(n);
		REP(i, n) {
			par[i] = i;
			ran[i] = 0;
		}
	}

	int root(int a) {
		return par[a] == a ? a : par[a] = root(par[a]);
	}

	bool same(int x, int y) {
		return root(x) == root(y);
	}

	void unite(int x, int y) {
		x = root(x);
		y = root(y);
		if (x == y)return;
		if (ran[x] < ran[y]) {
			par[x] = y;
		}
		else {
			par[y] = x;
			if (ran[x] == ran[y]) ran[x]++;
		}
	}
};
bool c(pair<pii,int> a, pair<pii,int> b) {
	if (a.first.second == b.first.second)return a.first.first < b.first.first;
	return a.first.second < b.first.second;
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<pair<pii,int>> v(n);
	REP(i, n) {
		cin >> v[i].first.first >> v[i].first.second;
		v[i].second = i;
	}
	vector<E> e;
	sort(ALL(v)); 
	REP(i, n) {
		if (i != 0) {
			int a = v[i].second, b = v[i - 1].second, c = min(abs(v[i].first.first - v[i - 1].first.first), abs(v[i].first.second - v[i - 1].first.second));
			e.push_back(E(a, b, c)); e.push_back(E(b, a, c));
		}
		if (i != n - 1) {
			int a = v[i].second, b = v[i + 1].second, c = min(abs(v[i].first.first - v[i + 1].first.first), abs(v[i].first.second - v[i + 1].first.second));
			e.push_back(E(a, b, c)); e.push_back(E(b, a, c));
		}
	}
	sort(ALL(v),c);
	REP(i, n) {
		if (i != 0) {
			int a = v[i].second, b = v[i - 1].second, c = min(abs(v[i].first.first - v[i - 1].first.first), abs(v[i].first.second - v[i - 1].first.second));
			e.push_back(E(a, b, c)); e.push_back(E(b, a, c));
		}
		if (i != n - 1) {
			int a = v[i].second, b = v[i + 1].second, c = min(abs(v[i].first.first - v[i + 1].first.first), abs(v[i].first.second - v[i + 1].first.second));
			e.push_back(E(a, b, c)); e.push_back(E(b, a, c));
		}
	}
	sort(ALL(e), comp);
	UnionFind uf(n);
	ll ans = 0;
	REP(i, e.size()) {
		E f = e[i];
		if (!uf.same(f.a, f.b)) {
			uf.unite(f.a, f.b);
			ans += f.c;
		}
	}
	cout << ans << endl;
}
