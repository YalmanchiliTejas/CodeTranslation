#include <cstdio>

#define maxn 100010
struct Edge
{
	Edge *next;
	int to;
} *last[maxn], e[maxn << 1], *ecnt = e;
inline void link(int a, int b)
{
	*++ecnt = (Edge) {last[a], b}; last[a] = ecnt;
	*++ecnt = (Edge) {last[b], a}; last[b] = ecnt;
}
bool f[maxn], flag;
void dfs(int x, int fa)
{
	int cnt = 0;
	for (Edge *iter = last[x]; iter; iter = iter -> next)
		if (iter -> to != fa)
		{
			dfs(iter -> to, x);
			cnt += f[iter -> to];
		}
	if (cnt > 1) flag = 1;
	f[x] = !cnt;
}
int main()
{
	int n; scanf("%d", &n);
	for (int i = 1; i < n; ++i)
	{
		int a, b; scanf("%d%d", &a, &b);
		link(a, b);
	}
	dfs(1, 0);
	puts(flag || f[1] ? "First" : "Second");
	return 0;
}