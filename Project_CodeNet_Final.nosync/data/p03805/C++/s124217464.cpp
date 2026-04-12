#include "stdio.h"
int v[10][10],ch[10],c=1,n;
long long int ans=0;
void dfs(int now,int k[10],int cou)
{
    if(cou>=n) {ans++;return;}
    for(int i=1;i<=n;i++)
    {
        if(v[now][i]==1&&k[i]==0)
        {
            int temp[10];
             for(int j=1;j<=n;j++) temp[j]=k[j];
            temp[i]=1;
            dfs(i,temp,cou+1);
        }
    }
    return ;
}
main()
{
    int m,a,b;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%d %d",&a,&b);
        v[a][b]=1; v[b][a]=1;
    }
    ch[1]=1;
    dfs(1,ch,c);
    printf("%d",ans);
}
