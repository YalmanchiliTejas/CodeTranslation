#include <bits/stdc++.h>
using namespace std;

#define INF_LL (int64)1e18
#define INF (int32)1e9
#define REP(i, n) for(int i = 0;i < (n);i++)
#define FOR(i, a, b) for(int i = (a);i < (b);i++)
#define all(x) x.begin(),x.end()
#define fs first
#define sc second

using int32 = int_fast32_t;
using uint32 = uint_fast32_t;
using int64 = int_fast64_t;
using uint64 = uint_fast64_t;
using PII = pair<int32, int32>;
using PLL = pair<int64, int64>;

const double eps = 1e-6;

template<typename A, typename B>inline void chmin(A &a, B b){if(a > b) a = b;}
template<typename A, typename B>inline void chmax(A &a, B b){if(a < b) a = b;}

class Union_find{
private:
	vector<int32> par;
	int32 n;

public:
	Union_find(int32 n):n(n){
		par.resize(n, -1);
	}

	int32 find(int32 x){
		return par[x] < 0 ? x : par[x] = find(par[x]);
	}

	int32 size(int32 x){
		return -par[find(x)];
	}

	void unite(int32 x, int32 y){
		x = find(x);
		y = find(y);
		if(x == y) return;
		if(size(x) < size(y)) swap(x, y);
		par[x] += par[y];
		par[y] = x;
	}

	bool same(int32 x, int32 y){
		return find(x) == find(y);
	}
};

const int64 mod = 1e9+7;

using Edge = tuple<int64, int64, int64>;
int64 N, M, Q;
int64 sum = 0;
vector<Edge> e;
vector<PLL> G[4040];
vector<int64> d;
int64 table[13][4040], maxi[13][4040];

void init(){
	d.resize(N);
	memset(table, -1, sizeof table);
	memset(maxi, -1, sizeof maxi);
	function<void(int32, int32, int32)> idfs = [&](int32 v, int32 p, int32 dep){
		d[v] = dep;
		table[0][v] = p;
		REP(i, G[v].size()){
			if(G[v][i].sc == p) continue;
			maxi[0][G[v][i].sc] = G[v][i].fs;
			idfs(G[v][i].sc, v, dep+1);
		}
	};
	idfs(0, -1, 0);
	REP(i, 12){
		REP(j, N){
			if(table[i][j] != -1){
				table[i+1][j] = table[i][table[i][j]];
				maxi[i+1][j] = max(maxi[i][j], maxi[i][table[i][j]]);
			}
		}
	}
}

int64 lca(int32 u, int32 v){
	if(d[u] < d[v]) swap(u, v);
	int64 res = 0;
	for(int32 i = 12;i >= 0;i--){
		if((d[u]-d[v]) >> i & 1){
			res = max(res, maxi[i][u]);
			u = table[i][u];
		}
	}
	if(u == v) return res;
	for(int32 i = 12;i >= 0;i--){
		if(table[i][u] != table[i][v]){
			res = max({res, maxi[i][u], maxi[i][v]});
			u = table[i][u];
			v = table[i][v];
		}
	}
	res = max({res, maxi[0][u], maxi[0][v]});
	return res;
}

int main(void){
	cin >> N >> M;
	REP(i, M){
		int64 a, b, c;
		cin >> a >> b >> c; a--; b--;
		e.push_back(Edge(c, a, b));
	}
	Union_find uf(N);
	sort(all(e));
	REP(i, e.size()){
		int64 u, v, c;
		tie(c, u, v) = e[i];
		if(uf.same(u, v)) continue;
		uf.unite(u, v);
		sum += c;
		G[u].push_back({c, v});
		G[v].push_back({c, u});
	}
	init();
	cin >> Q;
	REP(i, Q){
		int32 u, v;
		cin >> u >> v; u--; v--;
		int64 res = lca(u, v);
		cout << sum-res << endl;
	}
}