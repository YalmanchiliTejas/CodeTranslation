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
istream& operator >> (istream& is, const vector<T>& v)
{
	for (auto &i : v) is >> i;
	return is;
}
template<class T>
ostream& operator<<(ostream& os, const vector<T>& v)
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

int n, m;
int dp[9][1 << 9];

int solve(int v, int vis, const Graph& g)
{
	if (dp[v][vis] >= 0) return dp[v][vis];
	if (vis == (1 << n) - 1) return 1;
	int res = 0;
	for (auto e : g[v])
	{
		int u = e.to;
		if ((vis >> u) & 1) continue;
		res += solve(u, vis | (1 << u), g);
	}
	return dp[v][vis] = res;
}

int main()
{
	cin.sync_with_stdio(false); cout << fixed << setprecision(10);
	cin >> n >> m;
	Graph g(n);
	REP(i, m)
	{
		int a, b; cin >> a >> b;
		a--; b--;
		add_edge(g, a, b, 0);
		add_edge(g, b, a, 0);
	}
	MS(dp, -1);
	cout << solve(0, 1, g) << endl;
	return 0;
}