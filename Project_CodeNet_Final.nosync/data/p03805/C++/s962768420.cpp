#include <bits/stdc++.h>
#define mp make_pair
#define eb emplace_back
#define fi first
#define se second
using namespace std;
using cd = complex <double>;
 
typedef pair <int, int> pii;
const int N = 3e3 + 5;
const long long INF = 1e18;
const int mod = 1e9 + 123;//786433;//998244353;
const double Pi = acos(-1);
const int p = 510200;
 
void Fastio()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int n, m;
vector <int> Adj[9];
int cnt = 0;

bool Vis[9];

void DFS(int node, int l = 0)
{
	if(l == n - 1)
	{
		cnt++;
		return;
	}
	Vis[node] = true;
	for(auto x : Adj[node])
	{
		if(!Vis[x])
		{
			DFS(x, l + 1);
		}
	}
	Vis[node] = false;
}

signed main()
{
	Fastio();
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		Vis[i] = false;
	}
	for(int i = 1; i <= m; i++)
	{
		int u, v;
		cin >> u >> v;
		Adj[u].eb(v);
		Adj[v].eb(u);
	}
	DFS(1);
	cout << cnt;
}
