#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
const int N=2000+100;
ll pow_m(ll n,ll k)
{
    ll ans=1;
    while(k)
    {
        if(k&1) ans=ans*n%mod;
        n=n*n%mod;
        k>>=1;
    }
    return ans;
}
ll inv[2010];
void init()
{
    inv[0]=inv[1]=1;
    for(int i=2;i<=2000;i++)
    {
        inv[i]=pow_m(i,mod-2);
    }
}
int n,x;
ll d;
ll dp[N][N];
ll f[2][N];

ll C(ll n,ll m)
{
    if(n<m) return 0;
    if(n==m) return 1;
    ll ans=1;
    for(ll i=n;i>=n-m+1;i--)
    {
        ans=(ans*(i%mod))%mod;
    }
    for(int i=1;i<=m;i++)
        ans=(ans*inv[i])%mod;
    //printf("%I64d\n",ans);
    return ans;
}
int main()
{
    init();
    while(scanf("%d%lld%d",&n,&d,&x),n&&d&&x)
    {
        memset(dp,0,sizeof(dp));
        memset(f,0,sizeof(f));
        x--;
        int p=1;
        int mi=(int)min((ll)n,d);
        for(int i=1;i<=n;i++)
        {
            if(i<=x)dp[1][i]=1;
            else dp[1][i]=0;
            f[1][i]=f[1][i-1]+dp[1][i];
        }
        p^=1;
        for(int i=2;i<=mi;i++)
        {
            int tmp=min(n,i*x);
            for(int j=1;j<=tmp;j++)
            {
                if(j-x-1>=0){
                        dp[i][j]=(f[p^1][j-1]-f[p^1][j-x-1])%mod;
                        dp[i][j]=(dp[i][j]+mod)%mod;
                }
                else dp[i][j]=f[p^1][j-1]%mod;
                f[p][j]=(f[p][j-1]+dp[i][j])%mod;
            }
            for(int j=tmp+1;j<=n;j++)
            {
                f[p][j]=f[p][j-1];
            }
            p^=1;
        }
//        for(int i=1;i<=n;i++)
//        {
//            for(int j=1;j<=n;j++)
//            {
//                printf("%d ",dp[i][j]);
//            }printf("\n");
//        }
        ll ans=0;
        for(int i=1;i<=mi;i++)
        {
            ans=(ans+(C(d,i)*dp[i][n])%mod)%mod;
        }
        printf("%lld\n",ans);
    }
    return 0;
}