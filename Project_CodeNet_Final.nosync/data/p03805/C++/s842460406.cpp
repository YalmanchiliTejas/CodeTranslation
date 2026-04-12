#include <cstdio>
int mp[9][9],ans,flag[9],N;
void dfs(int x)
{
    int cnt=0;
    flag[x]=1;
    for(int i=1;i<=N;i++)
        cnt+=flag[i];
    if(cnt==N)
    {
        flag[x]=0;
        ans++;
        return;
    }
    for(int i=1;i<=N;i++)
        if(mp[x][i]==1&&flag[i]==0)
            dfs(i);
    flag[x]=0;
    return;
}
int main()
{
    int M,a,b;
    scanf("%d%d",&N,&M);
    for(int i=0;i<M;i++)
    {
        scanf("%d%d",&a,&b);
        mp[a][b]=1;
        mp[b][a]=1;
    }
    dfs(1);
    printf("%d\n",ans);
    return 0;
}
