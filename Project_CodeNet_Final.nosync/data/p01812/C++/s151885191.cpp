#include <bits/stdc++.h>
using namespace std;
#define FOR(i,k,n) for(int i = (int)(k); i < (int)(n); i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(a) a.begin(), a.end()
#define MS(m,v) memset(m,v,sizeof(m))
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pii;
const int MOD = 1e9 + 7;
template<class T> T &chmin(T &a, const T &b) { return a = min(a, b); }
template<class T> T &chmax(T &a, const T &b) { return a = max(a, b); }
template<class T>
istream& operator >> (istream& is, vector<T>& v)
{
	for (auto &i : v) is >> i;
	return is;
}
template<class T>
ostream& operator<<(ostream& os, vector<T>& v)
{
	const string delimiter = "\n";
	REP(i, v.size())
	{
		os << v[i];
		if (i != v.size() - 1) os << delimiter;
	}
	return os;
}
/*--------------------template--------------------*/

typedef int Weight;
struct Edge
{
	int from, to; Weight cost;
	bool operator < (const Edge& e) const { return cost < e.cost; }
	bool operator > (const Edge& e) const { return cost > e.cost; }
};
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;
typedef vector<Weight> Array;
typedef vector<Array> Matrix;
void add_edge(Graph &g, int from, int to, Weight cost)
{
	g[from].push_back(Edge{ from, to, cost });
}
const int INF = 1e9;
void dijkstra(Graph &g, int s, Array &d)
{
	d.assign(g.size(), INF);
	d[s] = 0;
	typedef pair<Weight, int> P;
	priority_queue<P, vector<P>, greater<P>> que;
	que.push(P(0, s));
	while (!que.empty())
	{
		Weight dist = que.top().first;
		int v = que.top().second;
		que.pop();
		if (d[v] < dist) continue;
		REP(i, g[v].size())
		{
			Edge e = g[v][i];
			if (d[e.to] > d[v] + e.cost)
			{
				d[e.to] = d[v] + e.cost;
				que.push(P(d[e.to], e.to));
			}
		}
	}
}


int main()
{
	cin.sync_with_stdio(false); cout << fixed << setprecision(10);
	int n, m, k;
	cin >> n >> m >> k;
	vi dark, id(n, -1);
	REP(i, m)
	{
		int a; cin >> a;
		a--;
		dark.push_back(a);
		id[a] = i;
	}
	Graph g(n);
	REP(i, n)REP(j, k)
	{
		int a; cin >> a; a--;
		add_edge(g, i, a, 0);
	}
	Graph h(1 << m);
	REP(bit, 1 << m)
	{
		vi v;
		REP(i, m)
		{
			if ((bit >> i) & 1) v.push_back(dark[i]);
		}
		REP(i, k)
		{
			int nex = 0;
			REP(j, v.size())
			{
				int u = g[v[j]][i].to;
				if (id[u] == -1) continue;
				nex |= (1 << id[u]);
			}
			add_edge(h, bit, nex, 1);
		}
	}
	Array dist;
	dijkstra(h, (1 << m) - 1, dist);
	cout << dist[0] << endl;
	return 0;
}
