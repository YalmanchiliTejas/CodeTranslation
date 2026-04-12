#include <iostream>
#include<math.h>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include <algorithm>
#include<string.h>
#define ll long long
#define ull unsigned long long
using namespace std;
struct edge{
	int to, nxt;
}e[70];
int head[10], tot = 1;
void add(int v, int u)
{
	e[tot].to = u, e[tot].nxt = head[v], head[v] = tot++;
}
int gt[10], used[10], n, m;
set<int> st; 
void dfs(int x, int dep)
{
	if (dep == n - 1)
	{
		int ans = 0;
		for (int i = 0; i < dep; i++)
			ans = ans * 10 + gt[i];
		st.insert(ans);
		return;
	}
	for (int u = head[x]; u; u = e[u].nxt)
	{
		int v = e[u].to;
		if (!used[v])
		{
			gt[dep] = v;
			used[v] = 1;
			dfs(v, dep + 1);
			used[v] = 0;
		}
	}
}
signed main() 
{
	used[1] = 1;
	while (~scanf("%d%d", &n, &m))
	{
		memset(head, 0, sizeof(head));
		st.clear();
		for (int i = 0; i < m; i++)
		{
			int a, b;
			scanf("%d%d", &a, &b);
			add(a, b), add(b, a);
		}
		dfs(1, 0);
		printf("%d\n", st.size());
	}
}
