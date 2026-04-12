#include<bits/stdc++.h>
using namespace std;
vector<int>g[100005];
int n;
inline int dfs(int x, int fa)
{
    int l1=g[x].size();
    int res=0;
    for(int i=0;i<l1;i++) 
	{
        int v=g[x][i];
        if(v!=fa)
            res+=dfs(v,x);
    }
    if(res>=2) 
	{
        printf("First\n");
        exit(0);
    }
    if(res==0) 
		return 1;
    return 0;
}
int main() 
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
    if(dfs(1,-1)) 
        printf("First\n");
    else
        printf("Second\n");
	return 0;
}