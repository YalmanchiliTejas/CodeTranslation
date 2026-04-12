#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int n;
vector<int> E[maxn];
bool dfs(int x, int fa)
{
	int ret = 0;
	for(auto v : E[x])
		if(v != fa)
			ret += dfs(v, x);
	if(ret > 1) 
	{
		puts("First");
		exit(0);
	}
	return !ret;
}
int main()
{
	scanf("%d", &n);
	for(int i = 1; i < n; ++i)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		E[u].push_back(v);
		E[v].push_back(u);
	}
	if(dfs(1, 0)) puts("First");
	else puts("Second");
	return 0;
}