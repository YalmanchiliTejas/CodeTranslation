#include "bits/stdc++.h"

#define REP(i,n) for(ll i=0;i<ll(n);++i)
#define RREP(i,n) for(ll i=ll(n)-1;i>=0;--i)
#define FOR(i,m,n) for(ll i=m;i<ll(n);++i)
#define RFOR(i,m,n) for(ll i=ll(n)-1;i>=ll(m);--i)
#define ALL(v) (v).begin(),(v).end()
#define UNIQUE(v) v.erase(unique(ALL(v)),v.end());
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

struct Edge { int from; int to; ll weight; bool operator < (const Edge & b) const { return this->weight > b.weight; } };
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;
typedef pair<ll, int> P;

struct UnionFind {
	vector<int> par;
	vector<int> sizes;

	UnionFind(int n) {
		par.resize(n);
		sizes.resize(n);
		REP(i, n) {
			par[i] = i;
			sizes[i] = 1;
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
		if (sizes[x] < sizes[y]) swap(x, y);

		par[y] = x;
		sizes[x] += sizes[y];
	}
	int size(int x) {
		return sizes[root(x)];
	}
};
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<pair<pii,int>> v(n);
	REP(i, n)cin >> v[i].first.first >> v[i].first.second;
	REP(i, n)v[i].second = i;
	sort(ALL(v));
	priority_queue<Edge> q;
	REP(i, n - 1) {
		q.push({ v[i].second,v[i + 1].second,v[i + 1].first.first - v[i].first.first });
	}
	REP(i, n)swap(v[i].first.first, v[i].first.second);
	sort(ALL(v));
	REP(i, n - 1) {
		q.push({ v[i].second,v[i + 1].second,v[i + 1].first.first - v[i].first.first });
	}
	UnionFind uf(n);
	ll ans = 0;
	while (!q.empty()) {
		Edge e = q.top(); q.pop();
		if (!uf.same(e.from, e.to)) {
			uf.unite(e.from, e.to);
			ans += e.weight;
		}
	}
	cout << ans << endl;
}