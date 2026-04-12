#include <bits/stdc++.h>
using namespace std;
long long n,a,b,l,r,i,j,k,mod=round(1e9)+7,c[1001][1001],g[1001][1001],f[1001][1001];
long long lt(long long a,long long b)
{
    if(b==0) return 1;
    long long tg=lt(a,b/2);
    if(b%2==0) return tg*tg%mod;
    return tg*tg%mod*a%mod;
}
int main()
{
    //freopen("ntu.inp","r",stdin);
    //freopen("ntu.out","w",stdout);
    cin>>n>>a>>b>>l>>r;
    for(i=0;i<=n;i++)
        for(j=i;j<=n;j++)
            if(i==0) c[i][j]=1; else c[i][j]=(c[i][j-1]+c[i-1][j-1])%mod;
    for(j=1;j<=n;j++)
    {
        g[0][j]=1;
        for(i=1;i<=n/j;i++) g[i][j]=g[i-1][j]*c[j][i*j]%mod*lt(i,mod-2)%mod;
    }
    for(j=a-1;j<=b;j++) f[0][j]=1;
    for(i=1;i<=n;i++)
        for(j=a;j<=b;j++)
        {
            f[i][j]=f[i][j-1];
            for(k=l;k<=min(r,i/j);k++)
                if(i-j*k>=0) f[i][j]=(f[i][j]+f[i-j*k][j-1]*g[k][j]%mod*c[j*k][i])%mod;
            //cerr<<i<<" "<<j<<" "<<f[i][j]<<'\n';
        }
    cout<<f[n][b];
}
