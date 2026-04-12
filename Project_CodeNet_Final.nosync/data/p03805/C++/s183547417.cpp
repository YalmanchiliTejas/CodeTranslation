#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int a[9][30];
int book[10],ans,n,m;
int dfs(int c,int step)
{
    if(step==n) { ans++; return 0;}
    for(int i=1;i<=n;i++)
    {
        if(a[c][i]==1&&book[i]==0)
        {
            book[i]=1;
            dfs(i,step+1);
            book[i]=0;

        }
    }
    return 0;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        a[x][y]=a[y][x]=1;
    }
    book[1]=1;
    dfs(1,1);
    printf("%d\n",ans);

    return 0;
}
