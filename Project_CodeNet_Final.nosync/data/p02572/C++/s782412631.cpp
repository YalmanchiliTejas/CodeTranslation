#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int llu;
typedef long double ld;
#define vi vector<int>
#define vl vector<ll>
#define vp vector<pair<int,int>>
#define pb push_back
#define pf push_front
#define mp map<ll,ll>
#define INF 1000000000000000000
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
ll gcd(ll a,ll b)
{
    if(a==0)
    {
        return b;
    }
    else
    {
        return gcd(b%a,a);   
    }
}
ll lcm(ll a,ll b)
{
    return a*b/gcd(a,b);
}
int f(char c)
{
    return (int)c-48;
}
/**********************************************************************
***********************************************************************
*********************ACTUAL CODE BEGINS HERE***************************/
int main()
{   
    fast;
    ll n;
    cin>>n;
    ll a[200005];
    ll sum=0,sum1=0,mod=1e9+7;
    ll s[200005];
    s[0]=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        s[i]=s[i-1]+a[i];
    }
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        ans=(ans+(((s[n]-s[i])%mod)*a[i])%mod)%mod;
    }
    if(ans<0)
    {
        cout<<ans+mod;
    }
    else
    {
        cout<<ans;
    }
    return 0;
}