#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ll long long
#define an size()
#define S second
#define F first

using namespace std;
const ll maxn=1002;
ll mod=1e9+7;
ll b,kk,c,d;
ll entekh[1011][1011];
ll fuc[maxn+100][maxn+100];
ll fcc[maxn+100][maxn+100];
ll ans=0;

ll dp[maxn][maxn];
bool viz[maxn][maxn];
vector<pair<ll,ll> > vaz;
ll f(ll n,ll a )
{
    if (viz[n][a])
    {
        return dp[n][a];
    }
    if (n==0)
    {
        return 1;
    }
    if (a>b)
    {
        return 0;
    }

    ll v=0;
    ll j=1;
    for(ll i=c; i<=d  && i*a<=n; i++)
    {
        j=(((entekh[a*i][n]*((fuc[a*i][1]*fcc[a][i])%mod))%mod)*fcc[i][1])%mod;
        j*=f(n-a*i,a+1);
        j%=mod;
        v+=j;
        v%=mod;
    }
    v+=f(n,a+1);
    v%=mod;
    dp[n][a]=v;
   // cout<<n<<' '<<a<<':'<<v<<endl;
    viz[n][a]=1;
    return v;
}
ll tav(ll a,ll b)
{
    ll v;
    if (b==1)
    {
        return a;
    }
    if (b&1)
    {
        v=tav(a,b/2);
        return(((v*v)%mod)*a)%mod;
    }
    else
    {
        v=tav(a,b/2);
        return(v*v)%mod;
    }
}

int main()
{
    ll n,a;
    cin>>n>>a>>b>>c>>d;
    kk=n;
    if (c==0)
    {
        c=1;
    }
    for (ll i=0; i<maxn; i++)
    {
        entekh[0][i]=1;
    }
    for (ll i=0; i<maxn; i++)
    {
        entekh[i][i]=1;
    }
    for (ll j=1; j<maxn; j++)
    {
        for (ll i=1; i<=j; i++)
        {

            entekh[i][j]=(entekh[i-1][j-1]+entekh[i][j-1])%mod;
        }
    }

    fuc[0][1]=1;
    for (ll i=1; i<maxn; i++)
    {
        fuc[i][1]=(fuc[i-1][1]*i)%mod;
        fcc[i][1]=tav(fuc[i][1],mod-2);
    }

    for (ll i=1; i<maxn; i++)
    {
        for (ll j=2; j<maxn; j++)
        {
            fuc[i][j]=(fuc[i][j-1]*fuc[i][1])%mod;
            fcc[i][j]=tav(fuc[i][j],mod-2);
        }
    }
    cout<<f(n,a);

}
