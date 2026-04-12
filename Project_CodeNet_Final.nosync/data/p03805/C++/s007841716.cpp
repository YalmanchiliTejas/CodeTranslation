#include<bits/stdc++.h>
using namespace std;
int v[10][10],n,ans,vis[10];
void dfs(int s,int cnt)
{
    if(cnt==n)
    {
        ans++;
        return ;
    }
    for(int i=1;i<=n;i++)
    {
        if(!vis[i]&&(v[i][s]||v[s][i]))
        {
            vis[i]=1;
            dfs(i,cnt+1);
            vis[i]=0;
        }
    }
}
int main()
{
    int m,x,y;
    scanf("%d%d",&n,&m);
    memset(v,0,sizeof(v));
    memset(vis,0,sizeof(vis));
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&x,&y);
        v[x][y]=1,v[y][x]=1;
    }
    ans=0;
    vis[1]=1;
    dfs(1,1);
    printf("%d\n",ans);
}
