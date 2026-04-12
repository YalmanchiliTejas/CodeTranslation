#include <bits/stdc++.h>
#define ll  long long
#define ull unsigned long long  
using namespace std;
#define  inf 1e18+18
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define mod 1000000007
#define  f1(i,n) for(i=1;i<=n;i++)
#define f0(i,n)  for(i=0;i<n;i++)
#define w(x)   while(x--)
const int maxn=1000001;
#define  pq priority_queue
#define  ff first
#define  ss second 
#define pb  push_back
#define lb lower_bound
string s;
ll dp[10001][100][2],k;
ll solve(ll pos,ll mo,ll st)
{
    if(pos==s.size())
    {
      return (mo==0);

    }
    if(dp[pos][mo][st]!=-1)
      return dp[pos][mo][st];
    ll lim=s[pos]-'0';
    if(st==0)
      lim=9;
    ll ans=0;
    for(int i=0;i<=lim;i++)
    {
      int str=st;
      if(i<lim)
        str=0;
      ans=(ans+solve(pos+1,(mo+i)%k,str))%mod;
    }
    dp[pos][mo][st]=ans;
    return ans;
}
int main()
{
   
   fastio;
   int t;
   ll n,i,j,l;
   cin>>s>>k;
    memset(dp,-1,sizeof(dp));
    j=(solve(0,0,1)-1+mod)%mod;
   cout<<j;
   
}