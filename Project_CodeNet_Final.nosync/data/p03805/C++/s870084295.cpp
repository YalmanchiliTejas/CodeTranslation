#include<stdio.h>
#include<string.h>
int s1[10][10];
int vis[10];
int judge[10][10];
int n,m;
int sum,all;
void dfs(int num)
{
    int a,b;
    if(sum==n)
    {
        all++;
        return;
    }
    for(a=1;a<=n;a++)
    {
        if(s1[num][a]==1&&vis[a]==0)
        {
            vis[a]=1;sum++;
            dfs(a);
            vis[a]=0;sum--;
        }
    }
    return;
}
int main()
{
    int a,b,x,y;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        sum=0;all=0;
        memset(s1,0,sizeof(s1));
        memset(vis,0,sizeof(vis));
        for(a=1;a<=m;a++)
        {
            scanf("%d%d",&x,&y);
            s1[x][y]=s1[y][x]=1;
        }
        vis[1]=1;sum++;
        dfs(1);
        printf("%d\n",all);
    }
    return 0;
}
