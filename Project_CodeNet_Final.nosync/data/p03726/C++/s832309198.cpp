//waz
#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)((x).size()))

typedef pair<int, int> PII;
typedef vector<int> VI;
typedef long long int64;
typedef unsigned int uint;
typedef unsigned long long uint64;

#define gi(x) ((x) = F())
#define gii(x, y) (gi(x), gi(y))
#define giii(x, y, z) (gii(x, y), gi(z))

int F()
{
	char ch;
	int x, a;
	while (ch = getchar(), (ch < '0' || ch > '9') && ch != '-');
	if (ch == '-') ch = getchar(), a = -1;
	else a = 1;
	x = ch - '0';
	while (ch = getchar(), ch >= '0' && ch <= '9')
		x = (x << 1) + (x << 3) + ch - '0';
	return a * x;
}

const int N = 1e5 + 10; 

int n;

int siz[N];

VI edge[N];

bool ok;

void dfs(int u, int fa)
{
	siz[u] = 1;
	int cnt = 0;
	for (auto v : edge[u])
	{
		if (v == fa) continue;
		dfs(v, u);
		siz[u] += siz[v];
		cnt += (siz[v] & 1);
	}
	cnt += ((n - siz[u]) & 1);
	if (cnt > 1) ok = 1;
}

int main()
{
	gi(n);
	for (int i = 1; i < n; ++i)
	{
		int u, v;
		gii(u, v);
		edge[u].pb(v);
		edge[v].pb(u); 
	}
	dfs(1, 0);
	if (n & 1) ok = 1;
	puts(ok ? "First" : "Second");
	return 0;
}