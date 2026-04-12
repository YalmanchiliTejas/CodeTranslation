#include <bits/stdc++.h>
using namespace std;
#define FASTIO  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define vi vector<ll>
#define all(a) (a).begin(), (a).end()
#define rep(i,a,b)  for(ll i=a;i<b;i++)
#define tr(it, a)   for(auto it=a.begin();it!=a.end();it++)
#define pb push_back
#define endl  "\n"
const ll MAX=1e5+3;
const ll mod=1e9+7;
 vector<ll>v;
 ll  d,x;
 ll dp[MAX][120][2];
 ll fun(ll n,ll sum,bool edge)
 {
     if(n<0 && sum==0)
       {
        return 1;
       }
       if(n<0)
        return 0;
        if(dp[n][sum][edge]!=-1)
            return dp[n][sum][edge];
        ll range=9;
     if(edge)
     {
         range=v[n];
     }
     ll ans=0;
     for(ll j=0;j<=range;j++)
     {
         bool patakaro=(j==v[n] && edge );
            ans=((ans%mod)+(fun(n-1,(sum+j%d)%d,patakaro)%mod))%mod;
     }
     return dp[n][sum][edge]=ans%mod;
 }
int main()
{
   FASTIO
   int t=1;
   //cin>>t;
   while(t--)
  {
    string s;cin>>s;cin>>d;
    ll n=s.size();
    rep(i,0,n)
    v.pb(s[i]-'0');
    reverse(all(v));
    memset(dp,-1,sizeof(dp));
    ll z=(fun(n-1,0,true)%mod-1LL%mod+mod)%mod;
    cout<<z<<"\n";

   }
 return 0;
}
