#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
const int N=6005;
int all,dp[N][N],g[N],mx,f[N][N],gg[N],mm;
int n,a[N];
void update(int i,int j,int v)
{
    dp[i][j]=dp[j][i]=max(dp[i][j],v);
    g[i]=max(g[i],v);
    g[j]=max(g[j],v);
    mx=max(mx,v);
}
void init(int x,int y,int z)
{
    f[x][x]=dp[x][x];
    f[y][y]=dp[y][y];
    f[z][z]=dp[z][z];
    mm=mx;
    for(int i=1;i<=n;i++)
    {
        gg[i]=g[i];
        f[x][i]=f[i][x]=dp[x][i];
        f[y][i]=f[i][y]=dp[y][i];
        f[z][i]=f[i][z]=dp[z][i];
    }
}
void update1(int x,int y,int z)
{
    update(y,z,f[x][x]+1);
}
void update2(int x,int y,int z)
{
    if(x!=y) return;
    for(int i=1;i<=n;i++)
        update(i,z,f[i][x]+1);
}
void update3(int x,int y,int z)
{
    update(x,y,mm);update(y,z,mm);update(x,z,mm);
}
void update4(int x,int y,int z)
{
    update(x,x,gg[x]),update(y,y,gg[y]),update(z,z,gg[z]);
}
void update5(int x,int y,int z)
{
    for(int i=1;i<=n;i++)
        update(i,x,gg[i]),update(i,y,gg[i]),update(i,z,gg[i]);
}
int main()
{
    memset(dp,-inf,sizeof(dp));
    memset(g,-inf,sizeof(g));
    scanf("%d",&n);
    for(int i=1;i<=3*n;i++)
        scanf("%d",&a[i]);
    update(a[1],a[2],0);
    for(int i=3;i<=3*n;i+=3)
    {
        if(i==3*n)
            update(a[i],a[i],dp[a[i]][a[i]]+1);
        else if(a[i]==a[i+1]&&a[i+1]==a[i+2])
           all++;
        else
        {
            init(a[i],a[i+1],a[i+2]);
            update1(a[i],a[i+1],a[i+2]);
            update1(a[i+1],a[i],a[i+2]);
            update1(a[i+2],a[i],a[i+1]);
            update2(a[i],a[i+1],a[i+2]);
            update2(a[i],a[i+2],a[i+1]);
            update2(a[i+1],a[i+2],a[i]);
            update3(a[i],a[i+1],a[i+2]);
            update4(a[i],a[i+1],a[i+2]);
            update5(a[i],a[i+1],a[i+2]);
        }
    }
    printf("%d\n",mx+all);
}
