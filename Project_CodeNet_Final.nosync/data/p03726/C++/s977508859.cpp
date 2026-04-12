#include <bits/stdc++.h>
using namespace std;
int n,x,y;vector<int>e[100005];
int dfs(int x,int fa)
{
	int tot=0;
	for(int i=0;i<e[x].size();i++) if(e[x][i]!=fa) tot+=dfs(e[x][i],x);
	if(tot>=2) return tot;else return tot^1;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++) scanf("%d%d",&x,&y),e[x].push_back(y),e[y].push_back(x);
	puts(dfs(1,0)?"First":"Second");
}