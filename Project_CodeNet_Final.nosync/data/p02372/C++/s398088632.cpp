#include <bits/stdc++.h>

#define M_PI       3.14159265358979323846   // pi

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> VI;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> t3;
typedef tuple<ll, ll, char, ll> t4;

#define rep(a,n) for(ll a = 0;a < n;a++)
#define repi(a,b,n) for(ll a = b;a < n;a++)

const ll mod = 1000000007;

static const ll INF = 1e15;

typedef ll Weight;
struct Edge {
	int from, to;
	Weight weight;
	Edge(int src, int dst) :
		from(src), to(dst), weight(0) { }

	Edge(int src, int dst, Weight weight) :
		from(src), to(dst), weight(weight) { }
};
bool operator < (const Edge& e, const Edge& f) {
	return e.weight != f.weight ? e.weight > f.weight :
	e.from != f.from ? e.from < f.from : e.to < f.to;
}

struct UndirectionalCompare {
	bool operator() (const Edge& e, const Edge& f) const {
		if (min(e.from, e.to) != min(f.from, f.to))
			return min(e.from, e.to) < min(f.from, f.to);
		return max(e.from, e.to) < max(f.from, f.to);
	}
};

typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

typedef vector<Weight> Array;
typedef vector<Array> Matrix;
typedef set<Edge, UndirectionalCompare> Edgeset;

struct tree_height {
	Weight visit(const Graph& g, Graph& T, int i, int j) {
		if (T[i][j].weight >= 0) return T[i][j].weight;
		T[i][j].weight = g[i][j].weight;
		int u = T[i][j].to;
		rep(k ,  T[u].size()) {
			if (T[u][k].to == i) continue;
			T[i][j].weight = max(T[i][j].weight, visit(g, T, u, k) + g[i][j].weight);
		}
		return T[i][j].weight;
	}
	vector<Weight> height(const Graph& g) {
		const int n = g.size();
		Graph T(g); // memoise on tree
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < T[i].size(); ++j)
				T[i][j].weight = -1;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < T[i].size(); ++j)
				if (T[i][j].weight < 0)
					T[i][j].weight = visit(g, T, i, j);

		vector<Weight> ht(n); // gather results
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < T[i].size(); ++j)
				ht[i] = max(ht[i], T[i][j].weight);
		return ht;
	}
};

int main(void)
{
	int v;
	cin >> v;
	Graph g(v);
	int e = v - 1;
	rep(i, e) {
		int s, t, w;
		cin >> s >> t >> w;
		g[s].push_back({ s,t,w });
		g[t].push_back({ t,s,w });
	}

	tree_height d;
	auto r = d.height(g);
	for (auto rr : r) {
		cout << rr << endl;
	}
	return 0;
}

