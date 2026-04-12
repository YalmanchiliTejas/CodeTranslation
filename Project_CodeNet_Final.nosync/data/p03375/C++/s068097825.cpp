#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=3010;
int n,mod;
long long f[N][N],c[N][N];
inline long long add(long long x,long long y)
{
    return x+y>=mod?x+y-mod:x+y;
}
inline long long sub(long long x,long long y)
{
    return x-y<0?x-y+mod:x-y;
}
inline long long po(long long x,long long y,int p)
{
    long long u=1ll;
    while(y)
    {
        if(y&1) (u*=x)%=p;
        (x*=x)%=p;
        y>>=1;
    }
    return u;
}
int main()
{
    scanf("%d%d",&n,&mod);
    f[0][0]=1ll;
    for(int k=1;k<=n+1;k++)
        for(int i=1;i<=k;i++)
            f[k][i]=add(f[k-1][i-1],i*f[k-1][i]%mod);
    for(int k=0;k<=n;k++)
    {
        for(int i=0;i<=k;i++)
        {
            if(k==0||i==0) c[k][i]=1ll;
            else c[k][i]=add(c[k-1][i-1],c[k-1][i]);
        }
    }
    long long ans=po(2,po(2,n,mod-1),mod);
    for(int k=1;k<=n;k++)
    {
        long long anss=0ll;
        for(int i=0;i<=k;i++)
            anss=add(anss,f[k+1][i+1]*po(po(2,n-k,mod),i,mod)%mod);
        (anss*=c[n][k]*po(2,po(2,n-k,mod-1),mod)%mod)%=mod;
        if(k&1) ans=sub(ans,anss);
        else ans=add(ans,anss);
    }
    printf("%lld\n",ans);
    return 0;
}
