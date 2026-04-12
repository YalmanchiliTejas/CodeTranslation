#include <cstdlib>
#include <cstring>
#include <cstdio>
int lst[100005], to[200005], pre[200005], tot; 
bool rem[100005]; 
inline void add_edge(int u, int v)
{
	to[tot] = v; 
	pre[tot] = lst[u]; 
	lst[u] = tot++; 
}
void dfs(int u, int fa = -1)
{
	rem[u] = true; 
	for (int i = lst[u]; ~i; i = pre[i])
	{
		if (to[i] == fa)
			continue; 
		dfs(to[i], u); 
		if (rem[to[i]])
		{
			if (rem[u])
			{
				rem[to[i]] = false; 
				rem[u] = false; 
			}
			else
			{
				puts("First"); 
				exit(0); 
			}
		}
	}
}
int main()
{
	// freopen("AGC014-D.in", "r", stdin); 
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
	puts(rem[0] ? "First" : "Second"); 
	return 0; 
}
