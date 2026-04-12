#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <set>
#include <algorithm>
#include <iostream>
using namespace std;

typedef double LD;
typedef long long LL;
typedef pair<int, int> PII;
#define MP make_pair
#define PB push_back
#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define RFOR(i,b,a) for(int i = (b) - 1; i >= (a); --i)
#define REP(i, t) FOR(i,0,t)
#define ALL(a) a.begin(), a.end()
#define SZ(a) (int)((a).size())

const int MOD = 1000000007;
const int INF = 1000000007;
const LL LINF = 1LL * INF * INF;
const int MAXN = 100007;
const LD EPS = 1e-12;

int n;
vector <PII> g[MAXN];
LL Ds[MAXN], Dt[MAXN], Cs[MAXN], Ct[MAXN];

void dijkstra(int s, LL *D, LL *C)
{
	set <pair <LL, int> > S;
	REP(i, n)
		D[i] = LINF;
	D[s] = 0;
	C[s] = 1;
	REP(i, n)
		S.insert(MP(D[i], i));
	REP(i, n)
	{
		int v = S.begin()->second;
		S.erase(S.begin());
		REP(i, SZ(g[v]))
		{
			int to = g[v][i].first;
			if (D[v] + g[v][i].second < D[to])
			{
				S.erase(MP(D[to], to));
				D[to] = D[v] + g[v][i].second;
				S.insert(MP(D[to], to));
			}
			if (D[to] + g[v][i].second == D[v])
			{
				C[v] += C[to];
				C[v] %= MOD;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	int m, s, t, ans;
	cin >> n >> m >> s >> t;
	--s; --t;
	REP(i, m)
	{
		int u, v, d;
		cin >> u >> v >> d;
		--u; --v;
		g[u].push_back(MP(v, d));
		g[v].push_back(MP(u, d));
	}
	dijkstra(s, Ds, Cs);
	dijkstra(t, Dt, Ct);
	ans = (Cs[t] * Cs[t]) % MOD;
	REP(u, n)
	{
		REP(i, SZ(g[u]))
		{
			int v = g[u][i].first, d = g[u][i].second;
			if (Ds[u] + d + Dt[v] == Ds[t] && Dt[v] - Ds[u] + d > 0 && Dt[v] - Ds[u] < d)
			{
				ans -= (((Cs[u] * Ct[v]) % MOD) * ((Cs[u] * Ct[v]) % MOD)) % MOD;
				ans %= MOD;
			}
		}
		if (Ds[u] == Dt[u] && 2 * Ds[u] == Ds[t])
		{
			ans -= (((Cs[u] * Ct[u]) % MOD) * ((Cs[u] * Ct[u]) % MOD)) % MOD;
			ans %= MOD;
		}
	}
	if (ans < 0)
		ans += MOD;
	cout << ans;
	//cout << endl; system("pause");
	return 0;
}