#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mpp make_pair
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
ll mod=1000000007;
ll bix(ll a,ll n)
{
    if(n==0)
    {
        return 1;
    }
    if(n&1)
    {
        return (a*bix(a,n-1))%mod;
    }
    ll x=bix(a,n/2);
    return (x*x)%mod;
}
int main()
{
    fast;
    ll n,esq=0,sumsq=0;
    vector<ll>v;
    cin>>n;
    for(ll i=0; i<n; i++)
    {
        ll x;
        cin>>x;
        v.pb(x);
    }
    for(ll i=0; i<n; i++)
    {
        //v[i]=(v[i]+mod)%mod;
        sumsq+=(v[i]);
        sumsq=(sumsq)%mod;
        ll sq=((v[i]*v[i]))%mod;
        esq+=sq;
        esq=(esq)%mod;
    }
    // sumsq=(sumsq+mod)%mod;
    sumsq=((sumsq*sumsq))%mod;
    ll ans=((sumsq-esq+100*mod)%mod);
    ans=ans*bix(2,mod-2);
    cout<<ans%mod<<endl;

}
/*
4
141421356 17320508 22360679 244949
*/
