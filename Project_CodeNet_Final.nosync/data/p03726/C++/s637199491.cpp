#include <bits/stdc++.h>

using namespace std;

#define DEBUG(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define fst first
#define snd second
#define SZ(u) ((int) (u).size())
#define ALL(u) (u).begin(), (u).end()

inline void proc_status()
{
	ifstream t("/proc/self/status");
	cerr << string(istreambuf_iterator<char>(t), istreambuf_iterator<char>()) << endl;
}

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
template<typename T> inline T read()
{
	register T sum(0), fg(1);
	register char ch(getchar());
	for(; !isdigit(ch); ch = getchar()) if(ch == '-') fg = -1;
	for(;  isdigit(ch); ch = getchar()) sum = sum * 10 - '0' + ch;
	return sum * fg;
}

typedef long long LL;
typedef pair<int, int> pii;

const int MAXN = (int) 1e5;

int n;

vector<int> adj[MAXN + 5];

inline void input()
{
	n = read<int>();
	for(int i = 1; i < n; ++i)
	{
		int u = read<int>(), v = read<int>();
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
}

int cut[MAXN + 5];

inline void dfs(int u, int fa)
{
	for(auto v : adj[u]) if(v != fa)
		dfs(v, u);
	if(fa && !cut[u] && !cut[fa]) cut[u] = cut[fa] = 1;
}

inline void solve()
{
	dfs(1, 0);

	for(int i = 1; i <= n; ++i) if(!cut[i]) { puts("First"); return; }
	puts("Second");
}

int main()
{
	input();
	solve();

	return 0;
}

