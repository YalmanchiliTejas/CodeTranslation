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
const int MOD = 1000000007;
const int INF = MOD + 1;
const ld EPS = 1e-12;
template<class T> T &chmin(T &a, const T &b) { return a = min(a, b); }
template<class T> T &chmax(T &a, const T &b) { return a = max(a, b); }

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

ll pow(ll x, ll n, ll mod)
{
	ll res = 1;
	while (n > 0)
	{
		if (n & 1) res = res * x % mod;
		x = x*x%mod;
		n >>= 1;
	}
	return res;
}


int main()
{
	cin.sync_with_stdio(false); cout << fixed << setprecision(10);
	int n, m;
	while (cin >> n >> m, n)
	{
		Graph g(n);
		REP(i, m)
		{
			int a, b; cin >> a >> b;
			a--; b--;
			add_edge(g, a, b, 0);
			add_edge(g, b, a, 0);
		}
		vector<bool> vis(n);
		ll cnt = 0;
		REP(i, n)
		{
			if (vis[i]) continue;
			vis[i] = true;
			cnt++;
			queue<int> que;
			que.push(i);
			while (!que.empty())
			{
				int t = que.front();
				que.pop();
				for (auto j : g[t])
				{
					int u = j.to;
					if (vis[u]) continue;
					vis[u] = true;
					que.push(u);
				}
			}
		}
		ll ans = pow(2, cnt, MOD);
		if (cnt != n) ans++;
		cout << ans % MOD << endl;
	}
	return 0;
}