
#include<bits/stdc++.h>
#define ll          long long
#define pb          push_back
#define eb          emplace_back
#define c(P)        cout<<P<<"\n"
#define pii         pair<ll,ll>
#define mi          map<ll,ll>
#define mii         map<pii,ll>
#define F           first
#define S           second
#define mp(x,y)     make_pair(x,y) 
#define exit(x)     cout<<x<<"\n",return
#define mem(a,val)  memset(a,val,sizeof(a))
#define fr(i,a,n)   for(ll i=a;i<n;i++)
#define frr(i,a,n)  for(ll i=n-1;i>=a;i--)


const ll N   =  500005;
const ll mod = 1e9 + 7;
using namespace std;


ll dp[10001][101][2];
ll dv;
// TO SEE STATES SEE SOLVE FUNC
string s;
ll solve(int pos,int mo,int tight)
{
    if(pos==s.size())
        {
          
          if(mo==0)
          {
            return 1;
          }                         
          return 0;
        }
    if(dp[pos][mo][tight]!=-1)
    {
      return dp[pos][mo][tight];
    }
    int d = s[pos] - '0';
    ll sum=0;
    for (int i = 0; i < 10; ++i)
    {
      if(!tight and i>d) break;     
       sum =(sum + solve(pos + 1,(mo + i)%dv,tight | (i<d) ))%mod;
    }
  
       return dp[pos][mo][tight] = sum;

}


signed main(){
  
      ios_base::sync_with_stdio(false);   
      cin.tie(NULL);
      
      cin>>s>>dv;
      memset(dp,-1,sizeof(dp));
    
      ll ans1=solve(0,0,0);
      ans1=(ans1 -1 + mod)%mod;
      cout<<ans1<<endl;
      
      return 0;
    }
