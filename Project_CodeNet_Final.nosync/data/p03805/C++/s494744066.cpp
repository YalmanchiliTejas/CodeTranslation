// think twice code once
// Start:[]
// End  :[]
/*{{{*/
#include <bits/stdc++.h>
using namespace std;

#define rep(i, x, y) for(int i = (x), _ = (y); i <= _; ++ i)
#define per(i, x, y) for(int i = (x), _ = (y); i >= _; -- i)
#define dprintf(...) fprintf(stderr, __VA_ARGS__)
#define disp(x) cout << #x << " = " << x << "; "
#ifdef __linux__
#define getchar getchar_unlocked
#define LLFORMAT "%lld"
#else
#define LLFORMAT "%I64d"
#endif

typedef long long LL;

template <class T> bool chkmin(T& a, T b) { return a > b ? a = b, true : false; }
template <class T> bool chkmax(T& a, T b) { return a < b ? a = b, true : false; }

template <class T> void read(T& a) {
	char c = getchar(); T f = 1; a = 0;
	for(; !isdigit(c); c = getchar()) if(c == '-') f = -1;
	for(; isdigit(c); c = getchar()) a = a * 10 + c - '0';
	a *= f;
}
/*}}}*/

const int maxN = 1050;

struct Edge
{
	int v, next;
}G[maxN];

int st[maxN], e;
int N, M;
int ans;
bool vis[maxN];

void addedge(int u, int v)
{
	G[++e] = (Edge) {v, st[u]};
	st[u] = e;
}

void dfs(int u, int cnt)
{
	if(cnt == N)
	{
		++ ans;
		return;
	}

	for(int e = st[u]; e; e = G[e].next)
	{
		int v = G[e].v;
		if(vis[v])
			continue;
		vis[v] = 1;
		dfs(v, cnt + 1);
		vis[v] = 0;
	}
}

int main()
{
#ifdef Leeson
	freopen("tmp.in", "r", stdin);
	freopen("tmp.out", "w", stdout);
#endif

	read(N); read(M);
	rep(i, 1, M)
	{
		int u, v;
		read(u); read(v);
		addedge(u, v);
		addedge(v, u);
	}

	vis[1] = 1;
	dfs(1, 1);
	cout << ans << endl;

	return 0;
}
