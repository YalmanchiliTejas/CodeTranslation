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
ll mod=1000000007;
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
     ll n;
     cin>>n;
     vector<ll> v(n+1);
     ll i;
     ll s=0;
     for(i=1;i<=n;i++)
     {
          cin>>v[i];
          s=(s%mod+v[i]%mod)%mod;
     }
     ll ans =0;
     for(i=1;i<=n;i++)
     {
          s=(s%mod - v[i]%mod + mod)%mod;
          ans = (ans%mod + ((s%mod)*(v[i]%mod))%mod)%mod;
     }
     cout<<ans;
}

     
     


int main()
{
    ios;
    ll t;
//    cin>>t;
     t=1;
     while(t--)
     {
          solve();
     }
}