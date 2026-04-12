#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define mod 1000000007
#define fi first
#define se second
#define pb push_back
#define IOS ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);

using namespace std;

ll power(ll a, ll n)
{
    ll ans=1;
    while(n)
    {
        if(n%2) ans=(ans*a)%mod;
        a=(a*a)%mod;
        n>>=1;
    }
    return ans;
}

int main()
{
    IOS;
    ll n,m,k;
    cin>>n>>m>>k;
    ll ans=0;
    ll fac[300001];
    fac[0]=1;
    for(int i=1;i<300001;i++)
    {
        fac[i]=(fac[i-1]*i)%mod;
    }
    ll num=fac[n*m-2];
    ll den=(fac[n*m-k]*fac[k-2])%mod;
    ll val=(num*power(den,mod-2))%mod;
    //cout<<num<<" "<<den<<" "<<val<<endl;
    for(int i=1;i<n;i++)
    {
        ans=(ans+((i*(n-i))%mod*(m*m)%mod)%mod)%mod;
    }
    for(int i=1;i<m;i++)
    {
        ans=(ans+((i*(m-i))%mod*(n*n)%mod)%mod)%mod;
    }
    ans=(ans*val)%mod;
    cout<<ans<<endl;
    return 0;
}