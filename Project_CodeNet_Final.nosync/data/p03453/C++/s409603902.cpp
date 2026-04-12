#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100010;

typedef long long ll;
const int mod = 1e9 + 7;
const ll INF = 1e18;

#define X first
#define Y second

struct edge
{
	int u, v, w;
};

vector<edge> E[MAXN];
vector<int> rg[MAXN];
queue<int> Q;
bool vis[MAXN];
ll d1[MAXN], d2[MAXN], cnt1[MAXN], cnt2[MAXN];

ll gao(int x, ll cnt[])
{
	//cout << "gao " << x << " " << rg[x].size() << " " << cnt[x] << endl;
	if (cnt[x] != -1) return cnt[x];
	
	ll &res = cnt[x]; res = 0;
	for (auto y: rg[x])
	{
	//	cout << x << " " << y << endl;
		res = (res + gao(y, cnt)) % mod;
	}
	return res;
}

void SPFA(int S, int n, ll d[], ll cnt[])
{
	Q.push(S); vis[S] = true;
	for (int i = 1; i <= n; ++i) d[i] = INF;
	d[S] = 0;
	
	int x, y, z;
	while (!Q.empty())
	{
		x = Q.front(); Q.pop();
		for (auto e: E[x])
		{
			y = e.v, z = e.w;
			if (d[x] + z < d[y])
			{
				d[y] = d[x] + z;
				if (!vis[y]) 
				{
					vis[y] = true;
					Q.push(y);
				}
			}
		} 
		vis[x] = false;
	}
	
	for (int i = 1; i <= n; ++i) rg[i].clear();
	for (int i = 1; i <= n; ++i)
	{
		for (auto e: E[i])
		{
			if (d[i] + e.w == d[e.v])
				rg[e.v].push_back(i);
		}
	}
	 
	for (int i = 1; i <= n; ++i)
		cnt[i] = -1;
	cnt[S] = 1;
	for (int i = 1; i <= n; ++i)
		gao(i, cnt);
	
} 

ll sqr(ll x){return x * x % mod;}

int main()
{
//	freopen("input", "r", stdin);

	int n, m, S, T, x, y, z;
	scanf("%d %d %d %d", &n, &m, &S, &T);
	
	for (int i = 1; i <= m; ++i)
	{
		scanf("%d %d %d", &x, &y, &z);
		E[x].push_back(edge{x, y, z});
		E[y].push_back(edge{y, x, z});
	}
	SPFA(S, n, d1, cnt1);
	SPFA(T, n, d2, cnt2);
	
	ll ans = cnt1[T] * cnt1[T] % mod;
	
	for (int i = 1; i <= n; ++i)
	{
		if (i == S || i == T) continue;
		if (d1[i] * 2 == d1[T])
			ans -= sqr(cnt1[i] * cnt2[i] % mod);
	}
	ans %= mod;
	
	for (int i = 1; i <= n; ++i)
	{
		//cout << i << " " << d1[i] << " " << cnt1[i] << " " << d2[i] << " " << cnt2[i] << endl;
		for (auto e: E[i])
		{
			x = e.u, y = e.v, z = e.w;
			if (d1[x] + z + d2[y] == d1[T] && d1[x] + z == d1[y] && d2[y] + z == d2[x])
			{
				if (abs(d1[x] - d2[y]) < z)
					ans -= sqr(cnt1[x] * cnt2[y] % mod);
			}
		}
	}
	ans %= mod;
	if (ans < 0) ans += mod; 
	cout << ans << endl;
	
    return 0;
}