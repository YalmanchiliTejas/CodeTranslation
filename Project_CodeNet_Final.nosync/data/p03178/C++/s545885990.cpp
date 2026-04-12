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
/*ll f[200000]={0};*/
ll mod=1000000007;
/*void ini()
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
ll f1(ll pos,ll dp[][102][2],ll state,ll k,ll sum,string s,ll sz)
{
   //cout<<"calling f1 of "<<pos<<" "<<sum<<" "<<state<<endl;
   
  
    if(sum%k==0 && pos==sz)
    return 1;
   else if(pos==sz)
    return 0;
   else if(dp[pos][sum][state]!=-1)
    return dp[pos][sum][state];
   
   else if(state==0)
   {
      ///ll z=s.at(pos)-'0';
      dp[pos][sum][state]=0;
      for(ll i=0;i<=9;i++)
      {
  //       if(sum+i<=k)
  ll r=(sum+i)%k;
         dp[pos][sum][state]=(dp[pos][sum][state]+f1(pos+1,dp,0,k,r,s,sz))%mod;
      }
      return dp[pos][sum][state]%mod;
   }
   else if(state==1)
   {
      dp[pos][sum][state]=0;
     ll z=s.at(pos)-'0';
     for(ll i=0;i<z;i++)
     {   
       // if(sum+i<=k)
       ll r=(sum+i)%k;
        dp[pos][sum][state]=(dp[pos][sum][state]+f1(pos+1,dp,0,k,r,s,sz))%mod;
     }
   //  if(sum+z<=k)
   ll r=(sum+z)%k;
     dp[pos][sum][state]=(dp[pos][sum][state]+f1(pos+1,dp,1,k,r,s,sz))%mod;
     return dp[pos][sum][state]%mod;

   }
 //  cout<<"returning dp of "<<pos<<" "<<sum<<" "<<state<<" is "<<dp[pos][sum][state]<<endl;
   
   
}
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   string s;
   cin>>s;
   ll sum;
   cin>>sum;
   ll sz=s.size();
   ll dp[sz+1][102][2];
   for(ll i=0;i<=sz;i++)
   {
      for(ll j=0;j<=100;j++)
      {
         for(ll k=0;k<=1;k++)
         dp[i][j][k]=-1;
      }
   }
   cout<<(f1((ll)0,dp,(ll)1,sum,(ll)0,s,sz)-1+mod)%mod<<endl;
  /* for(ll i=0;i<=sz;i++)
   {
      for(ll j=0;j<=sum;j++)
      {
         for(ll m=0;m<2;m++)
         {
            cout<<" pos "<<i<<" sum "<<j<<" and state  "<<m<<" is "<<dp[i][j][m]<<endl;
         }
      }
   }*/
   
   //cout<<endl;
   return 0;
}
