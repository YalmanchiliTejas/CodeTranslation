#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std; 
int lst[100005], to[200005], pre[200005], tot; 
bool ok[100005]; 
inline void add_edge(int u, int v)
{
	to[tot] = v; 
	pre[tot] = lst[u]; 
	lst[u] = tot++; 
}
void dfs(int u, int fa = -1)
{
	for (int i = lst[u]; ~i; i = pre[i])
	{
		if (to[i] == fa)
			continue; 
		dfs(to[i], u); 
		if (!ok[to[i]])
		{
			if (ok[u])
			{
				puts("First"); 
				exit(0);
			}
			ok[to[i]] = true; 
			ok[u] = true; 
		}
	}
}
int main()
{
	memset(lst, -1, sizeof(lst)); 
	int n; 
	scanf("%d", &n); 
	for (int i = 1; i < n; i++)
	{
		int u, v; 
		scanf("%d%d", &u, &v); 
		add_edge(--u, --v); 
		add_edge(v, u); 
	}
	dfs(0); 
	puts(ok[0] ? "Second" : "First"); 
	return 0; 
}
