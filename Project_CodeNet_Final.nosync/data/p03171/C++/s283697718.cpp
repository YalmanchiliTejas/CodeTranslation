#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const long long INF = 1e13;
#define fi first
#define sec second 
#define MOD 1000000007
#define pb push_back
#define endl "\n"
#define test cout<<"debuged\n";

#define si 1000000
#define pi pair<ll,ll>

ll dp[3010][3010];
ll vis[3010][3010];
 vector<ll> v(si,0);
ll solve(ll s,ll e,ll n,ll c)
{
  if(s>e)
   return 0;
 if(vis[s][e]==1)
    return dp[s][e];
  if(c==1)
  {
    ll h=(-1*INF);
    ll k= max(solve(s+1,e,n,c*-1)+v[s],solve(s,e-1,n,c*-1)+v[e]);
      vis[s][e]=1;
     dp[s][e]=max(k,h);
    return dp[s][e];
  }
  else
  {
    ll h=(INF);
    ll a= solve(s+1,e,n,c*-1)-v[s];
    ll b= solve(s,e-1,n,c*-1)-v[e];
    a=min(a,h);
      vis[s][e]=1;
    dp[s][e]=min(a,b);
    return dp[s][e];
  }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    ll n,k,s=0;
    cin>>n;
    for(ll i=0;i<n;i++)
      cin>>v[i];
   
    for(ll i=0;i<3010;i++)
      for(ll j=0;j<3010;j++)
        vis[i][j]=0;

    ll p=solve(0,n-1,n,1);  
    cout<<p;
}
