#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
#define fi first
#define se second

template<typename A, typename B> inline bool chmax(A &a, B b) { if (a<b) { a=b; return 1; } return 0; }
template<typename A, typename B> inline bool chmin(A &a, B b) { if (a>b) { a=b; return 1; } return 0; }

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, pll> P;
const ll INF = 1ll<<30;
const ll MOD = 1000000007;
const double EPS  = 1e-10;

struct UnionFind {
	vector<int> par;
	vector<int> rank;
	
	UnionFind() {}
	UnionFind(int n) {
		init(n);
	}
	
	int operator[] (int x) {
		return find(x);
	}

	void init(int n) {
		par.resize(n);
		rank.resize(n);
		REP(i, n) {
			par[i] = i;
			rank[i] = 0;
		}
	}

	int find(int x) {
		if (par[x] == x) return x;
		return par[x] = find(par[x]);
	}

	void unite(int x, int y) {
		x = find(x);
		y = find(y);
		if (x == y) return;

		if (rank[x] < rank[y]) {
			par[x] = y;
		} else {
			par[y] = x;
			if (rank[x] == rank[y]) rank[x]++;
		}
	}

	bool same(int x, int y) {
		return find(x) == find(y);
	}
};

int N;
int x[112345], y[112345];

int main() {
	cin >> N;
	REP(i, N) scanf("%d %d", x + i, y + i);
	
	set<pii> ss;
	REP(i, N) ss.insert(pii(x[i], y[i]));
	
	vector<pii> v;
	for (set<pii>::iterator it = ss.begin(); it != ss.end(); ++it)
		v.push_back(*it);
	
	vector<pii> x, y;
	REP(i, v.size()) {
		x.push_back(pii(v[i].fi, i));
		y.push_back(pii(v[i].se, i));
	}
	sort(ALL(x));
	sort(ALL(y));
	
	priority_queue<P, vector<P>, greater<P> > pq;
	REP(i, x.size() - 1) pq.push(P(abs(x[i + 1].fi - x[i].fi), pii(x[i + 1].se, x[i].se)));
	REP(i, y.size() - 1) pq.push(P(abs(y[i + 1].fi - y[i].fi), pii(y[i + 1].se, y[i].se)));
	
	ll ans = 0;
	
	UnionFind uf(N);
	while (!pq.empty()) {
		int p = pq.top().se.fi;
		int q = pq.top().se.se;
		pq.pop();
		
		if (uf.same(p, q)) continue;
		ans += min(abs(v[p].fi - v[q].fi), abs(v[p].se - v[q].se));
		uf.unite(p, q);
	}
	cout << ans << endl;
	
	return 0;
}
