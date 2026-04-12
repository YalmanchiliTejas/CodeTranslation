#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=1e9+7;


ll dp[100005][200][5];

ll go(ll index,ll n,const string &s,ll k,ll sum,bool tight)
{
    
 if(index==n)
 {
  if(sum%k==0)
      return 1;
     return 0;
 }
   
    if(dp[index][sum][tight]!=-1)return dp[index][sum][tight];
    
    
    ll ans=0;
    if(tight)
    {
        ll limit=s[index]-'0';
        for(ll i=0;i<limit;i++)
         ans=(ans%mod+go(index+1,n,s,k,(sum+i)%k,false)%mod)%mod;
        
        ans=(ans%mod+go(index+1,n,s,k,(sum+limit)%k,true)%mod)%mod;
    }
    else
    {
       for(ll i=0;i<=9;i++)
          ans=(ans%mod+go(index+1,n,s,k,(sum+i)%k,false)%mod)%mod;  
    }
    dp[index][sum][tight]=ans%mod;
    return dp[index][sum][tight];
}

void solve()
{
  string s;
    cin>>s;
    ll k,n;
    cin>>k;
    n=s.length();
    memset(dp,-1,sizeof(dp));
    ll ans=go(0LL,n,s,k,0LL,true)%mod;
    ans=(ans-1+mod)%mod;
    cout<<ans<<endl;    
}


int main()
{
ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t=1;
   // cin>>t;
    while(t--)
        solve();
}