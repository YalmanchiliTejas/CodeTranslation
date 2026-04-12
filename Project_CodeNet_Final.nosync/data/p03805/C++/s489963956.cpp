#include <bits/stdc++.h>
const long long MOD = 1000000007;
const int INF = INT_MAX / 2;
const long double PI = 3.1415926;
using namespace std;
#define FOR(i, r, n) for(int i=(ll)(r); i<(ll)(n); i++) 
#define REP(i, n) FOR(i, (0), n)
#define ALL(r) r.begin(), r.end()
#define ll long long int
typedef vector<ll> vc;
typedef vector<string> vcs;
typedef vector<pair<ll, ll>> vcp;
typedef vector<tuple<ll, ll, ll>> vct;
//vector<vector<ll>> vv(n, vector<ll>(n));

typedef int Weight;
struct Edge
{
	int from, to; Weight cost;
	bool operator < (const Edge& e) const { return cost < e.cost; }
	bool operator >(const Edge& e) const { return cost > e.cost; }
};
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;
void add_edge(Graph &g, int from, int to, Weight cost)
{
	g[from].push_back(Edge{ from, to, cost });
}

int n, m,ans=0;
Graph g;

void dfs(bitset<8> b, int vert, int dep)
{
	if (dep == n-1) {
		ans++;
	}
	else {
		for (auto e : g[vert]) {
			if (!b[e.to]) {
				bitset<8> tmp=b;
				tmp[e.to] = 1;
				dfs(tmp, e.to, dep + 1);
			}
		}
	}
}

int main()
{
	cin >> n >> m;
	g.resize(n);
	REP(i, m)
	{
		ll a, b;
		cin >> a >> b;
		a--; b--;
		add_edge(g, a, b, 1);
		add_edge(g, b, a, 1);
	}
	bitset<8> init;
	init[0] = 1;
	dfs(init, 0, 0);
	cout << ans << endl;
}