//#pragma GCC optimize ("Ofast")
//#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define pb push_back
#define all(_obj) _obj.begin(),_obj.end()
#define F first
#define S second
#define INF 1e18
#define pll pair<ll, ll> 
#define vll vector<ll>
ll n,m,a,b,c,k,temp,x,y;
const int MAXN=1e5+11,mod=1e9+7;
inline ll max(ll a,ll b) {return ((a>b)?a:b);}
inline ll min(ll a,ll b) {return ((a>b)?b:a);}
inline vll read(int n) {vll v(n);for (int i = 0; i < v.size(); i++)cin>>v[i];return v;}
ll power(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll modInverse(ll a){return power(a,mod-2);}
void sol(void)
{
cin>>n;
vll v(n);
ll sum=0;
for(int i=0;i<n;i++)
{
    cin>>v[i];
    sum+=v[i];
    sum%=mod;
}
ll ans=0;
for(int i=0;i<n;i++)
{
    ans+=((v[i]*(sum-v[i]+mod)%mod)%mod);
    ans%=mod;
}
cout<<(ans*modInverse(2))%mod;
return ;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test=1;
    //cin>>test;
    for(int i=1;i<=test;i++)
    sol();
}
