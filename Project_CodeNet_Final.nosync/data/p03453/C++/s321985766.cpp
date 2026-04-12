#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pb push_back
 
const int maxn = 2e5 + 20;
const int mod = 1e9 + 7;

int from[maxn] , to[maxn] , w[maxn] , fs[maxn] , fv[maxn];

ll d[2][maxn];

vector<int> adj[maxn] , out[maxn] , in[maxn];

bool cmp(int a , int b)
{
	return d[0][a] < d[0][b];
}

inline void mkay(int &a)
{
	if(a >= mod)
		a -= mod;
	else if(a < 0)
		a += mod;
}

int t2(int x)
{
	return 1LL * x * x % mod;
}

void dij(ll* d , int s)
{
	fill(d , d + maxn , 1e18);
	set<pair<ll , int> > st;
	d[s] = 0;
	st.insert({d[s] , s});

	while(!st.empty())
	{
		int v = st.begin() -> second;
		ll W = st.begin() -> first;
		st.erase(st.begin());

		if(d[v] != W)
			continue;

		for(auto e : adj[v])
		{
			int u = from[e] ^ to[e] ^ v;
			if(d[u] > d[v] + w[e])
			{
				d[u] = d[v] + w[e];
				st.insert({d[u] , u});
			}
		}
	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n , m , s , t;
	cin >> n >> m >> s >> t;
	s-- , t--;

	for(int i = 0; i < m; i++)
	{
		int a , b;
		cin >> a >> b >> w[i];
		a-- , b--;

		adj[a].pb(i);
		adj[b].pb(i);

		from[i] = a , to[i] = b;
	}

	dij(d[0] , s);
	dij(d[1] , t);
	
	vector<int> topol;
	for(int v = 0; v < n; v++)
	{
		topol.pb(v);
		for(auto e : adj[v])
		{
			int u = from[e] ^ to[e] ^ v;
			if(d[0][v] + w[e] + d[1][u] == d[0][t])
				out[v].pb(u) , in[u].pb(v);
		}
	}

	sort(topol.begin() , topol.end() , cmp);
	fs[s] = 1;
	for(int i = 1; i < n; i++)
	{
		int v = topol[i];
		for(auto u : in[v])
			mkay(fs[v] += fs[u]);
	}

	fv[t] = 1;
	for(int i = n - 2; i >= 0; i--)
	{
		int v = topol[i];
		for(auto u : out[v])
			mkay(fv[v] += fv[u]);
	}

	assert(fv[s] == fs[t]);
	int res = 1LL * fv[s] * fv[s] % mod;

	for(int v = 0; v < n; v++)
	{
		if(d[0][v] + d[1][v] == d[0][t] && d[0][v] == d[1][v])
			mkay(res -= t2(1LL * fv[v] * fs[v] % mod));

		for(auto u : out[v])
			if(d[0][v] * 2 < d[0][t] && d[0][t] < d[0][u] * 2)
				mkay(res -= t2(1LL * fs[v] * fv[u] % mod));
	}

	cout << res << endl;
}
















