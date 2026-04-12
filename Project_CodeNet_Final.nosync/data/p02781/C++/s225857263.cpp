//Author ::  ABHINAV3010 ::

#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define fast ios_base::sync_with_stdio(false)
typedef long long ll;
typedef pair<ll,ll> p;
ll mod=1000000007;
ll gcd(ll a,ll b)
{
    return (b==0)?a:gcd(b,a%b);
}
ll power(ll x, ll y, ll p=mod)
{ll res = 1;x = x % p;while (y > 0){if (y & 1){res = (res*x) % p;}y = y>>1;x = (x*x) % p;}return res;}
ll fun(ll n,vector<ll>&v,ll k,ll i,ll j,bool allow,vector< vector< vector<ll> > > &dp)
{
    if(i==n&&j==k)
    {
        return 1;
    }

    if(i==n)
    {
        return 0;
    }
    if(j>k)
    {
        return 0;
    }
    //cout<<i<<" "<<j<<" "<<allow<<endl;
    if(dp[i][j][allow]!=-1)
    {
        return dp[i][j][allow];
    }
    ll ans=0;

    if(allow==true)
    {
        for(ll x=0;x<=v[i];x++)
        {
            if(x==v[i])
            {
                if(v[i]!=0)
                {

                ans+=fun(n,v,k,i+1,j+1,true,dp);
                }else
                {
                    ans+=fun(n,v,k,i+1,j,true,dp);
                }

            }else if(x==0)
            {
                 ans+=fun(n,v,k,i+1,j,false,dp);
            }else
            {
                ans+=fun(n,v,k,i+1,j+1,false,dp);
            }
        }
    }else
    {
        for(ll x=0;x<=9;x++)
        {
            if(x==0)
            {
                ans+=fun(n,v,k,i+1,j,false,dp);
            }else
            {
                ans+=fun(n,v,k,i+1,j+1,false,dp);
            }
        }
    }
    //cout<<i<<" "<<j<<" "<<ans<<endl;
    return dp[i][j][allow]=ans;
}
int main()
{
fast;
string s;
cin>>s;
ll k;
cin>>k;
vector<ll>v;
for(ll i=0;i<s.size();i++)
{
    v.pb(s[i]-48);
}
ll n=s.size();
vector< vector< vector<ll> > > dp(n+1,vector< vector<ll> >(k+1,vector< ll>(3,-1)));
ll ans=fun(n,v,k,0,0,true,dp);
cout<<ans<<endl;
return 0;
}
