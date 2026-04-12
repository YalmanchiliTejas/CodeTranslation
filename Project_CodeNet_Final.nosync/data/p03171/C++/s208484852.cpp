#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define pb push_back
#include <ext/pb_ds/assoc_container.hpp> // Common file  
#include <ext/pb_ds/tree_policy.hpp>  
#include <functional> // for less   
using namespace __gnu_pbds;  
using namespace std;  
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> set1;
ll find(ll a,ll p[])
{
   //cout<<"find "<<a<<endl;
   if(a==p[a])
   return a;
   else return p[a]=find(p[a],p);

}
void join(ll a,ll b,ll p[],ll sz[])
{
   a=find(a,p);
   b=find(b,p);
   if(a!=b)
   {
      if(sz[a]<sz[b])
      swap(a,b);
      sz[a]+=sz[b];
      p[b]=a;
   }
}
ll power(ll a,ll b,ll mod)
{
   ll res=1;
   while(b>0)
   {
      if(b&1)
      res=(res*a)%mod;
      b=b/2;
      a=(a*a)%mod;
   }
   return res;
}
ll inverse(ll x, ll p)
{
   return power(x,p-2,p);
}
ll hash1(ll x,ll y)
{
   return x+y+x*y;
}
//ll f[200000]={0};
ll mod=1000000007;
/*void ini()
{
   f[0]=1;
   for(ll i=1;i<=200000;i++)
   f[i]=(i*f[i-1])%mod;
}*/



/*ll ncr(ll n,ll r)
{
   ll res=1;
   ll k=f[n];
   ll v=inverse(f[n-r],mod);
   ll u=inverse(f[r],mod);
   ll x=(u*v)%mod;
   k=(k*x)%mod;
   return k;
}*/
/*struct edge
{
   ll from;
   ll to;
};
void dfs(ll v,ll vis[],ll dp[],vector<ll> adj[])
{
   ll k=adj[v].size();
   for(ll i=0;i<k;i++)
   {
      ll u=adj[v].at(i);
      if(vis[u]==0)
      {
         vis[u]=1;
         dfs(u,vis,dp,adj);
         dp[v]=max(dp[v],dp[u]+1);
      }
      else
      dp[v]=max(dp[v],dp[u]+1);
   }
}*/
ll f1(ll l,ll r,ll dp[][3001],ll a[])
{
  // cout<<l<<" form to "<<r<<endl;
   if(dp[l][r]!=-1)
   return dp[l][r];
   else if(l==r)
   {
      dp[l][r]=a[l];
    //  cout<<"dp["<<l<<"]["<<r<<"]"<<" "<<dp[l][r]<<endl;
      return dp[l][r];
   }
   else if(r-l==1)
   {
      
       dp[l][r]=max(a[r]-a[l],a[l]-a[r]);
    //   cout<<"dp["<<l<<"]["<<r<<"]"<<" "<<dp[l][r]<<endl;
       return dp[l][r];
   }
   else
   { dp[l][r]=max(a[l]+min(-a[r]+f1(l+1,r-1,dp,a),-a[l+1]+f1(l+2,r,dp,a)),a[r]+min(-a[l]+f1(l+1,r-1,dp,a),-a[r-1]+f1(l,r-2,dp,a)));
  // cout<<"dp["<<l<<"]["<<r<<"]"<<" "<<dp[l][r]<<endl;
   return dp[l][r];
   }
}


int main()
{
   ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    ll a[n];
    for(ll i=0;i<n;i++)
    cin>>a[i];
    ll dp[n+1][3001];
    for(ll i=0;i<n;i++)
    {
       for(ll j=0;j<n;j++)
       dp[i][j]=-1;
    }
    
    cout<<f1(0,n-1,dp,a)<<endl;
   /* for(ll i=0;i<n;i++)
    {
       for(ll j=i;j<n;j++)
       cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
    }*/
    return 0;
}