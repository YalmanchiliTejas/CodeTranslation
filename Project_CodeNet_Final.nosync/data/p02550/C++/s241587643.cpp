// #pragma GCC optimize ("Ofast")
// #pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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
ll psum[200000];
void sol(void)
{
cin>>n;
ll sum=0;
ll cnt=0;
map<ll,ll> vis;
cin>>x>>m;
vis[x]=1;
sum+=x;
if(n<=MAXN)
{
    n--;
    while(n--)
    {
    x=(x*x)%m;
    sum+=x;
    }
    cout<<sum;
    return ;
}
psum[1]=x;
for(int i=2;i<=MAXN;i++)
{
  x=(x*x)%m;
  if(vis[x])
  {
    cnt=i-vis[x];
    ll calc=psum[i-1]-psum[vis[x]-1];
    n-=(i-1);
    int rem=n%cnt;
    sum+=(calc*(n/cnt))-psum[vis[x]-1]+psum[vis[x]-1+rem];
    break;
  }
  else
  {
      sum+=x;
      psum[i]+=psum[i-1]+x;
      vis[x]=i;
  }
}
cout<<sum;
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
