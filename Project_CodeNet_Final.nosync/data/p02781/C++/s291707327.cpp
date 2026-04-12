#include<bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
typedef vector<ll> vec; 
#define inf LLONG_MAX
#define bp __builtin_popcountll
#define pb push_back
#define ff first
#define ss second
#define P pair<ll,ll>
#define N (ll)(1<<20)
#define M 20
#define mod 1000000007
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

ll n,k;
string s;
ll dp[105][2][5];

ll solve(ll ind,ll tight,ll cc)
{
      if(cc>k)
            return 0;    
      if(ind==n)
            return (cc==k);
            
      ll &ans=dp[ind][tight][cc];
      
      if(ans!=-1)
            return ans;
      
      ans=0;
      
      ll r=9;
      if(tight)
            r=s[ind]-'0';
            
      for(int i=0;i<=r;i++)
      {
            ll newtight=tight;
            if(i!=r)
                  newtight=0;
                  
            ans+=solve(ind+1,newtight,cc+(i!=0));
      }
      
      return ans;
            
      
}

int32_t main()
{
      FAST;
      
      cin>>s>>k;
      n=s.size();
      
      memset(dp,-1,sizeof(dp));
      // solve(0,1,0);
      
      cout<<solve(0,1,0);
      
}