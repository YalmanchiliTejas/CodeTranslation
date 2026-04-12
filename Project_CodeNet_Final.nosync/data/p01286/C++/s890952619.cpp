#include <bits/stdc++.h>
using namespace std;
#define FOR(i,k,n) for(int i = (k); i < (n); i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(a) a.begin(), a.end()
#define MS(m,v) memset(m,v,sizeof(m))
#define D10 fixed<<setprecision(10)
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pii;
const int MOD = 1000000007;
const int INF = MOD + 1;
const ld EPS = 1e-12;
template<class T> T &chmin(T &a, const T &b) { return a = min(a, b); }
template<class T> T &chmax(T &a, const T &b) { return a = max(a, b); }

/*--------------------template--------------------*/
typedef int Weight;
typedef int Flow;
struct Edge {
	int src, dest, rev;
	Flow cap;
	Weight cost;
	bool operator < (const Edge &rhs) const
	{
		return cost > rhs.cost;
	}
	Edge(int s, int d) : src(s), dest(d) { ; }
	Edge(int s, int d, int c) : src(s), dest(d), cost(c) { ; }
	Edge(int s, int d, int r, Flow cp, Weight cst) : src(s), dest(d), rev(r), cap(cp), cost(cst) { ; }
};
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;
typedef vector<Weight> Array;
typedef vector<Array> Matrix;
void add_edge(Graph &g, int src, int dest, Flow cap)
{
	g[src].push_back(Edge{ src, dest, (int)g[dest].size(), cap, 0 });
	g[dest].push_back(Edge{ dest, src, (int)g[src].size() - 1, 0, 0 });
}

void add_edge(Graph &g, int from, int to, Flow cap, Weight cost)
{
	g[from].push_back(Edge(from, to, (int)g[to].size(), cap, cost));
	g[to].push_back(Edge(to, from, (int)g[from].size() - 1, 0, -cost));
}

Flow dfs(Graph &g, vector<bool> &used, int v, int t, Flow f)
{
	if (v == t) return f;
	used[v] = true;
	for (Edge& e : g[v])
	{
		if (!used[e.dest] && e.cap > 0)
		{
			Flow d = dfs(g, used, e.dest, t, min(f, e.cap));
			if (d > 0)
			{
				e.cap -= d;
				g[e.dest][e.rev].cap += d;
				return d;
			}
		}
	}
	return 0;
}

Flow ford_fulkerson(Graph &g, int s, int t)
{
	Flow flow = 0;
	for (;;)
	{
		vector<bool> used(g.size(), false);
		Flow f = dfs(g, used, s, t, INF);
		if (f == 0) return flow;
		flow += f;
	}
}

int main()
{
	int h, w, c, m, nw, nc, nm;
	while (cin >> h >> w >> c >> m >> nw >> nc >> nm, h != -1)
	{
		int p = h + w*2 + c*2 + m;
		Graph g(p + 8);
		REP(i, h)
		{
			add_edge(g, p + 6, i, 1);
		}
		REP(i, w)
		{
			int n; cin >> n;
			REP(j, n)
			{
				int t; cin >> t; t--;
				add_edge(g, t, h + i, 1);
			}
		}
		REP(i, w) add_edge(g, h + i, h + w + i, 1);
		REP(i, c)
		{
			int n; cin >> n;
			REP(j, n)
			{
				int t; cin >> t; t--;
				add_edge(g, h + w + t, h + w*2 + i, 1);
			}
		}
		REP(i, c) add_edge(g, h + w * 2 + i, h + w * 2 + c + i, 1);
		REP(i, m)
		{
			int n; cin >> n;
			REP(j, n)
			{
				int t; cin >> t; t--;
				add_edge(g, h + w * 2 + c + t, h + w * 2 + c * 2 + i, 1);
			}
		}
		REP(i, m) add_edge(g, h + w*2 + c*2 + i, p + 7, 1);
		REP(i, h) add_edge(g, i, p, 1);
		add_edge(g, p, p + 1, nw);

		REP(i, w) add_edge(g, h + w + i, p + 2, 1);
		add_edge(g, p+2, p + 3, nc);

		REP(i, c) add_edge(g, h + w * 2 + c + i, p + 4, 1);
		add_edge(g, p+4, p + 5, nm);

		REP(i, c) add_edge(g, p + 1, h + w*2 + i, 1);
		REP(i, m) add_edge(g, p + 3, h + w*2 + c*2 + i, 1);
		add_edge(g, p + 5, p + 7, nm);
		
		cout << ford_fulkerson(g, p + 6, p + 7) << endl;
	}
	return 0;
}