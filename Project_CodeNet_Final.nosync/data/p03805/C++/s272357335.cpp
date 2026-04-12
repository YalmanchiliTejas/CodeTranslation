#include <bits/stdc++.h>
const long long INF = LLONG_MAX / 2;
const long long MOD = 1000000007;
const long double PI = 3.1415926;
#define FOR(i, r, n) for(int i=(ll)(r); i<(ll)(n); i++) 
#define REP(i, n) FOR(i, (0), n)
#define ALL(r) r.begin(), r.end()
#define ll long long int
using namespace std;
string s;
vector<ll> v;
vector<pair<ll, ll>> vp;
vector<vector<ll>> vv(110, vector<ll>(50, 0));
vector<tuple<ll, ll, ll>> vt;
set<ll> st;
map<char, ll> mp;

typedef int Weight;
struct Edge
{
	int from, to; Weight cost;
	bool operator < (const Edge& e) const { return cost < e.cost; }
	bool operator > (const Edge& e) const { return cost > e.cost; }
};
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;
void add_edge(Graph &g, int from, int to, Weight cost)
{
	g[from].push_back(Edge{ from, to, cost });
}

Weight dist[100005];
typedef pair<Weight, Edge> P;

int n, m;
ll ans=0;
bool d[10][10];

void solve(int num,int dep, int b)
{
	if (dep >= n) ans++;
	else
	{
		FOR(i,1,n+1)
		{
			auto visited = [b](int k) {return b + (1 << k); };
			if (i != num&&d[num][i]&&!((b >> i) & 1)) solve(i, dep + 1, visited(i));
		}
	}
}

int main()
{

	cin >> n >> m;
	REP(i,m)
	{
		ll a, b;
		cin >> a >> b;
		d[a][b] = d[b][a] = true;
	}
	solve(1, 1, 2);
	cout << ans << endl;
}