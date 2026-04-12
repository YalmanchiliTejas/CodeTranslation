#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e5 + 10;

struct Node
{
	int to, next;
}edge[maxN * 2 + 1];

int n;
int tot, head[maxN + 1];
int f[maxN + 1][2];

inline int read()
{
	int num = 0, f = 1;
	char ch = getchar();
	while( !isdigit( ch ) ) { if(ch == '-') f = -1; ch = getchar(); }
	while( isdigit( ch ) ) num = (num << 3) + (num << 1) + (ch ^ 48), ch = getchar();
	return num * f;
}

inline void add(int x, int y)
{
	tot ++;
	edge[tot].to = y;
	edge[tot].next = head[x];
	head[x] = tot;
}

inline void dfs(int u, int pa)
{
	f[u][1] = 1;
	for(int i = head[u]; i; i = edge[i].next)
	{
		int v = edge[i].to;
		if(v == pa) continue;
		dfs(v, u);
		f[u][0] += max(f[v][0], f[v][1]);
		f[u][1] += f[v][0];
	}
}

int main()
{
	n = read();
	for(int i = 1; i < n; i++)
	{
		int x = read(), y = read();
		add(x, y); add(y, x);
	}

	dfs(1, 0);

	int ans = max(f[1][0], f[1][1]);
	if(2 * ans == n) puts("Second");
	else puts("First");
	return 0;
}
