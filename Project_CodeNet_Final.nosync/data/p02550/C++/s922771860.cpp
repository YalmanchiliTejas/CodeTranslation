#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
#include <math.h>
#include <string>
#include <sstream>
#define ll long long
#define F first
#define S second
#define pb push_back
#define ld long double
#define pll pair<long long,long long>
#define pld pair<long double,long double>
#define ios     ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;
ll mod=998244353;
ll INF=1e18;
ll gcd (ll a,ll b)
{
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}
ll fastexp(ll x ,ll n)
{
    ll result =1;
    while(n>0)
    {
        if(n%2==1)
            result*=x;
        x*=x;
        n=n/2;
    }
    return result;
}

ll modularExp(ll x,ll n,ll mod)
{
    ll result=1;
    while(n>0)
    {
        if(n%2==1)
            result=(result*x)%mod;
        x=((x%mod)*(x%mod))%mod;
        n=n/2;
    }
    return (result)%mod;
}
bool isPrime(ll n)
{
    for(ll i=2;i*i<=n;i++)
        if(n%i==0)
            return false;
    return true;
}
bool mycomp(pll &a,pll &b)
{
    if(a.F!=b.F)
        return a.F < b.F;
    else
        return a.S < b.S;
}
void solve()
{
     ll n,x,k;
     cin>>n>>x>>k;
     ll i;
     vector<ll> v;
     map<ll,ll> mp;
     v.pb(x);
     mp[x]=0;
     ll len=1;
     ll prev=x;
     while(1)
     {
          ll curr = (prev*prev)%k;
          // cout<<curr<<"#\n";
          if(mp.find(curr)==mp.end())
          {
               v.pb(curr);
               mp[curr]=len;
               prev=curr;
               len++;
          }
          else 
          {
               prev=curr;
               break;
          }
     }
     ll loopstart = mp[prev];
     ll looplen = (len-loopstart);
     ll ans=0;
     
     // cout<<loopstart<<" "<<looplen<<"!!\n";
     if(n<loopstart)
     {
          for(i=0;i<n;i++)
               ans+=v[i];
          cout<<ans;
          return ;
     }
     for(i=0;i<loopstart;i++)
          ans+=v[i];
     ll sum=0;
     for(i=loopstart;i<len;i++)
          sum+=v[i];
     ll times = (n-loopstart)/looplen;
     ll rem =   (n-loopstart)%looplen;
     ans+= sum*times;
     for(i=0;i<rem;i++)
          ans+=v[loopstart+i];
     cout<<ans;

     
     
}

int main()
{
    ios;
    ll t;
     // cin>>t;
     t=1;
     while(t--)
     {
          solve();
     }
}
