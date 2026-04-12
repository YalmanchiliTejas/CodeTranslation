#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if(x < y) x = y; }

struct UnionFind {
	vector<int> data;
	void init(int n) { data.assign(n, -1); }
	bool unionSet(int x, int y) {
		x = root(x); y = root(y);
		if(x != y) {
			if(data[y] < data[x]) swap(x, y);
			data[x] += data[y]; data[y] = x;
		}
		return x != y;
	}
	bool findSet(int x, int y) { return root(x) == root(y); }
	int root(int x) { return data[x] < 0 ? x : data[x] = root(data[x]); }
	int size(int x) { return -data[root(x)]; }
};
vector<int> t_parent;
vi t_ord;

template<typename T>
void wtree_getorder(const vector<vector<pair<int, T> > > &gw, int root, vector<T> &t_weight) {
	int n = (int)gw.size();
	t_parent.assign(n, -1);
	t_ord.clear();
	t_weight.assign(n, T());

	vector<int> stk; stk.push_back(root);
	while(!stk.empty()) {
		int i = stk.back(); stk.pop_back();
		t_ord.push_back(i);
		for(int j = (int)gw[i].size() - 1; j >= 0; j --) {
			int c = gw[i][j].first;
			if(t_parent[c] == -1 && c != root) {
				t_parent[c] = i;
				t_weight[c] = gw[i][j].second;
				stk.push_back(c);
			}
		}
	}
}


struct Edge {
	int a, b, c;
	bool operator<(const Edge &that) const {
		return c < that.c;
	}
};

struct Sum {
	int maxC;
	Sum() : maxC(-INF) {}
	explicit Sum(int x) : maxC(x) {}
	Sum &operator+=(const Sum &that) {
		amax(maxC, that.maxC);
		return *this;
	}
};
struct PathCompressionTree {
private:
	vector<int> parent;
	vector<Sum> val, sum;
public:
	void init(int n, const vector<Sum> &initval) {
		parent.assign(n, -1);
		val = initval;
		sum.assign(n, Sum());
	}
	void link(int c, int p) {
		assert(parent[c] == -1 && p != -1);
		parent[c] = p;
		sum[c] = val[c];
	}
	int find(int u) {
		int p = parent[u], g;
		if(p == -1) return u;
		g = parent[u] = find(p);
		sum[u] += sum[p];
		return g;
	}
	Sum get(int u) {
		find(u);
		return sum[u];
	}
};

struct Query {
	int u, v;
	int i;
};

vector<vi> g;
vector<bool> visited;
PathCompressionTree pct;
vector<vector<Query>> queries, lca;
vector<Sum> vals, ans;

void dfs(int i, int p) {
	for(int j : g[i]) if(j != p)
		dfs(j, i);
	visited[i] = true;
	for(const Query &q : queries[i]) {
		if(visited[q.v])
			lca[pct.find(q.v)].push_back(q);
	}
	for(const Query &q : lca[i]) {
		ans[q.i] += pct.get(q.u);
		ans[q.i] += pct.get(q.v);
	}
	if(p != -1)
		pct.link(i, p);
}

int main() {
	int N; int M;
	while(~scanf("%d%d", &N, &M)) {
		vector<Edge> edges(M);
		rep(i, M) {
			int a; int b; int c;
			scanf("%d%d%d", &a, &b, &c), -- a, -- b;
			edges[i] = { a, b, c };
		}
		sort(edges.begin(), edges.end());
		UnionFind uf; uf.init(N);
		g.assign(N, vi());
		vector<vector<pair<int, Sum>>> gw(N);
		ll cost = 0;
		for(auto &&e : edges) {
			if(uf.unionSet(e.a, e.b)) {
				g[e.a].push_back(e.b);
				g[e.b].push_back(e.a);
				gw[e.a].emplace_back(e.b, Sum(e.c));
				gw[e.b].emplace_back(e.a, Sum(e.c));
				cost += e.c;
			}
		}
		wtree_getorder(gw, 0, vals);
		queries.assign(N, vector<Query>());
		int Q;
		scanf("%d", &Q);
		rep(i, Q) {
			int u; int v;
			scanf("%d%d", &u, &v), -- u, -- v;
			queries[u].push_back(Query{ u, v, i });
			queries[v].push_back(Query{ v, u, i });
		}
		lca.assign(N, vector<Query>());
		ans.assign(Q, Sum());
		visited.assign(N, false);
		pct.init(N, vals);
		dfs(0, -1);
		rep(i, Q) {
			ll x = cost - max(0, ans[i].maxC);
			printf("%lld\n", x);
		}
	}
	return 0;
}
