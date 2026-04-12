/*
    Author: aksayushx
*/
#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
#define all(a) a.begin(),a.end()
#define mp make_pair
#define mod 1000000007
using namespace std;
typedef long long ll;
typedef long double ld;

/*
void compute()
{
	fac[0]=1;
	for(ll i=1;i<=10000;i++)
	fac[i]=(i*fac[i-1])%mod;
}
ll power(ll x, ll y)  
{  
    ll res = 1; 
    x = x % mod;
    while (y > 0)  
    {  
        if (y & 1)  
            res = (res*x) % mod;  
        y = y>>1; 
        x = (x*x) % mod;  
    }  
    return res;  
} 
ll modInverse(ll n) 
{ 
    return power(n, mod-2); 
}
ll nCr(ll n,ll r) 
{ 
    if (r == 0) 
        return 1; 
    return (fac[n] * modInverse(fac[r]) % mod * modInverse(fac[n - r]) % mod) % mod; 
}*/ 
int n;
vector<ll> a;
vector<vector<vector<ll>>> dp;
ll optimal(int lx,int rx,int turn)
{
    if(dp[lx][rx][turn]!=-1)
    return dp[lx][rx][turn];
    if(lx>rx)
    return 0;
    if(lx==rx)
    {
        if(turn)
        return a[lx];
        else
        return -1*a[lx];
    }
    if(turn)
    {
        ll x=a[lx]+optimal(lx+1,rx,false);
        ll y=a[rx]+optimal(lx,rx-1,false);
        dp[lx][rx][1]=max(x,y);
        return dp[lx][rx][1];
    }
    else
    {
        ll x=optimal(lx+1,rx,true)-a[lx];
        ll y=optimal(lx,rx-1,true)-a[rx];
        dp[lx][rx][0]=min(x,y);
        return dp[lx][rx][0];
    }
}
void aksayushx()
{
    cin>>n;
    a.resize(n);
    for(int i=0;i<n;i++)
    cin>>a[i];
    dp.assign(n,vector<vector<ll>>(n,vector<ll>(2,-1)));
    ll score=optimal(0,n-1,1);
    cout<<score;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test=1;
    //cin>>test;
    while(test--)
        aksayushx();
    return 0;
}
