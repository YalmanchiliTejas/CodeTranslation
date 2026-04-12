#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define pb push_back
#define vi vector<long long>
#include <ext/pb_ds/assoc_container.hpp> // Common file  
#include <ext/pb_ds/tree_policy.hpp>  
#include <functional> // for less   
using namespace __gnu_pbds;  
using namespace std;  
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> set1;
ll mod=1000000007;
ll large=1e18;
ll neg=-1e18;
ll N=500000;
ll mod1=998244353;
struct pii
{
   ll x;
   ll y;
};
struct edge
{
   ll from;
   ll to;
   ll w;
   ll id;
};
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
/*ll f[200000]={0};

void ini()
{
   f[0]=1;
   for(ll i=1;i<=200000;i++)
   f[i]=(i*f[i-1])%mod;
}*/
void build(ll tree[],ll v,ll l,ll r,ll dp[])
{
   if(l==r)
      tree[v]=dp[l];
   else
   {
      ll m=(l+r)/2;
      build(tree,2*v,l,m,dp);
      build(tree,2*v+1,m+1,r,dp);
      tree[v]=max(tree[2*v],tree[2*v+1]);
   }
}
ll query(ll tree[],ll v,ll l,ll r,ll tl,ll tr)
{
   if(l==tl && tr==r)
   {
    //  cout<<"max of "<<tl<<" "<<tr<<" "<<tree[v]<<endl;
      return tree[v];
   }
   else
   {
      ll m=(l+r)/2;
      if(tr<=m)
      {
         ll z1= query(tree,2*v,l,m,tl,tr);
     //    cout<<"max of "<<tl<<" "<<tr<<" "<<z1<<endl;
         return z1;
      }
      else if(tl>m)
      {
         ll z2= query(tree,2*v+1,m+1,r,tl,tr);
      //   cout<<"max of "<<tl<<" "<<tr<<" "<<z2<<endl;
         return z2;
      }
      else 
      {
         ll z=query(tree,2*v,l,m,tl,m);
         ll z1=query(tree,2*v+1,m+1,r,m+1,tr);
       //  cout<<"max of "<<tl<<" "<<tr<<" "<<max(z1,z)<<endl;
         return max(z1,z);
      }
      
      
   }
}
void update(ll tree[],ll v,ll l,ll r,ll pos,ll element)
{
   if(l==r && l==pos)
   tree[v]=element;
   else
   {
      ll m=(l+r)/2;
      if(pos<=m)
      update(tree,2*v,l,m,pos,element);
      else
      update(tree,2*v+1,m+1,r,pos,element);
      tree[v]=max(tree[2*v],tree[2*v+1]);
   }
}

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
ll max_n=1e6+100;
ll hash2(ll x,ll y,ll W)
{
   return (x-1)*W+y;
}
pii rev(ll u,ll W)
{
   pii ans;
   if(u%W==0)
   {
      ans.y=W;
      ans.x=(u-W)/W+1;
   }
   return ans;

}
ll MAX_N=200000;
string tobin(ll a,ll sz)
{
   string s;
   ll r=0;
   while(a>0)
   {
      if(a%2==0)
      s.pb('0');
      else
      s.pb('1');
      a/=2;
      r++;
   }
   while(r<sz)
   {
      s.pb('0');
      r++;
   }
   reverse(s.begin(),s.end());
   return s;
}
ll tolong(string s)
{
   ll sz=s.size();
   ll ans=0;
   for(ll i=0;i<sz;i++)
   {
      if(s.at(i)=='1')
      ans+=(ll)pow(2,sz-i-1);
      
   }
   return ans;
}
void printvec(vector<ll> &c)
{
   for(ll i : c)
   cout<<i<<" ";
   cout<<endl;
}
void printarr(ll a[],ll n)
{
   for(ll i=0;i<n;i++)
   cout<<a[i]<<" ";
   cout<<endl;
}

int main()
{
  
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   ll n;ll k;
   cin>>n>>k;
   ll a[n+1];
   for(ll i=0;i<n;i++)
   cin>>a[i+1];

   ll dp[n+1][k+1]={{0}};
   for(ll i=0;i<=n;i++)
   {
      for(ll j=0;j<=k;j++)
      dp[i][j]=0;
   }
  for(ll i=1;i<=n;i++)
  {
     for(ll sum=0;sum<=k;sum++)
     {
        if(sum==a[i])
        dp[i][sum]=i;
        if(sum!=k)
        dp[i][sum]=(dp[i][sum]+dp[i-1][sum])%mod1;;
        if(sum-a[i]>=0)
        dp[i][sum]=(dp[i][sum]+dp[i-1][sum-a[i]])%mod1;
     }
  }
  ll ans=0;
  for(ll i=1;i<=n;i++)
  ans=(ans+(dp[i][k]*(n-i+1))%mod1)%mod1;
  cout<<ans<<endl;
  return 0;
}