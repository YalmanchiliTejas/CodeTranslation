#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int maxn = 100005;

struct Edge
{
	int to, nxt;
} e[maxn << 1];

int first[maxn];

inline void add_edge(int from, int to)
{
	static int cnt = 0;
	e[++cnt].nxt = first[from];
	first[from] = cnt;
	e[cnt].to = to;
	e[++cnt].nxt = first[to];
	first[to] = cnt;
	e[cnt].to = from;
}

bool shan[maxn];
int n;

inline void dfs(int now, int fa)
{
	for(int i = first[now]; i; i = e[i].nxt)
	{
		register int to = e[i].to;
		if(to != fa)
			dfs(to, now);
	}
	if(!shan[now])
	{
		if(shan[fa])
		{
			puts("First");
			exit(0);
		}
		shan[now] = shan[fa] = true;
	}
}

int main()
{
	shan[0] = true;
	scanf("%d", &n);
	for(int i = 1, f, t; i < n; ++i)
	{
		scanf("%d%d", &f, &t);
		add_edge(f, t);
	}
	dfs(1, 0);
	puts("Second");
	return 0;
}