#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const int N=1e3+10,mod=1e9+7;
ll dp[N],n,a,b,c,d,C[N][N],fact[N],ifact[N],inv[N],p[N][N];

void build()
{
    inv[1]=ifact[0]=ifact[1]=fact[0]=fact[1]=1;
    for (int i=2;i<=n;i++)
    {
        inv[i]=mod-mod/i*inv[mod%i]%mod;
        ifact[i]=ifact[i-1]*inv[i]%mod;
        fact[i]=fact[i-1]*i%mod;
    }
    for (int i=0;i<=n;i++)
    {
        C[0][i]=1;
        for (int j=1;j<=i;j++) C[j][i]=(C[j][i-1]+C[j-1][i-1])%mod;
    }
    for (int i=1;i<=n;i++)
    {
        p[i][0]=1;
        for (int j=1;j<=n;j++) p[i][j]=p[i][j-1]*ifact[i]%mod;
    }
}

ll modpow(ll x,ll h)
{
    ll res=1;
    for (;h;h>>=1)
    {
        if (h&1) res=res*x%mod;
        x=x*x%mod;
    }
    return res;
}

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>a>>b>>c>>d;
    dp[0]=1;
    build();
    for (int i=a;i<=b;i++)
        for (int j=n;j>=0;j--)
            for (int t=c;t<=min(d,(n-j)/i);t++)
                dp[j+t*i]=(dp[j+t*i]+dp[j]*C[t*i][n-j]%mod*fact[t*i]%mod*ifact[t]%mod*p[i][t])%mod;
    cout<<dp[n];
    return 0;
}
