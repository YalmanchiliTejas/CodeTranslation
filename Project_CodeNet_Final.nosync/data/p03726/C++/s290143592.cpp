#include <bits/stdc++.h>
using namespace std;
vector<int> v[100005];
bool del[100005];
int deg[100005],dep[100005],ord[100005],par[100005];
void dfs(int node,int p)
{
	dep[node]=dep[p]+1;
	par[node]=p;
	for (int u:v[node])
	{
		if (u!=p)
		dfs(u,node);
	}
}
bool cmp(int a,int b)
{
	return dep[a]>dep[b];
}
int main()
{
	int n;
	scanf("%d",&n);
	if (n%2)
	{
		printf("First");
		return 0;
	}
	for (int i=1;i<n;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
		deg[a]++;
		deg[b]++;
	}
	dfs(1,0);
	for (int i=1;i<=n;i++)
	ord[i]=i;
	sort(ord+1,ord+n+1,cmp);
	for (int i=1;i<=n;i++)
	{
		if (del[ord[i]])
		continue;
		if (deg[par[ord[i]]]>2)
		{
			printf("First");
			return 0;
		}
		del[par[ord[i]]]=1;
		deg[par[par[ord[i]]]]--;
	}
	printf("Second");
}