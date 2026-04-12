#include<bits/stdc++.h>
#include<bitset>
#include<string>
using namespace std;
#include <numeric> 
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using pi=pair<long long,long long>;
#define pii 3.1415926536
#define binary
#define mod 1000000007
typedef long long ll;
typedef long double ld;
bool sortbysec(const pair<long long,long long> &a, 
              const pair<long long,long long> &b) 
{ 
    return (a.first < b.first); 
}
bool compare(const pair<pair<ll,ll>,ll> &a,const pair<pair<ll,ll>,ll>&b)
{
    if(a.first.first==b.first.first)return (a.first.second<b.first.second);
    return (a.first.first < b.first.first); 
}
 int lcm(int a, int b)  
 {  
    return (a*b)/__gcd(a, b);  
 }  
 int Kad(ll dp[],ll n)
{
  ll curr_max=0,maxx=INT_MIN;
  for(int i=0;i<n;i++)
  {
    curr_max=curr_max+dp[i];
    if(curr_max>maxx)
      maxx=curr_max;

    if(curr_max<0)
      curr_max=0;
   
  }

  return maxx;
}

/*void dfs(int u)
{
    vis[u]=true;
    //cout<<u<<" ";
    std::vector<ll> ::iterator i;
     for (i = g[u].begin(); i != g[u].end(); ++i) 
        if (!vis[*i]) 
            dfs(*i); 
    for(int i=1;i<g[u].size();i++)
    {
        if(!vis[g[u][i]])
        {
            dfs(i);
        }
    }
}*/
/*void build_tree(ll tree[],ll a[],ll start,ll end,ll node)
{
    if(start==end)
    {
        tree[node]=a[start];
        return;
    }
    int mid=(start+end)/2;
    build_tree(tree,a,start,mid,2*node);
    build_tree(tree,a,mid+1,end,2*node+1);
    tree[node]=min(tree[2*node],tree[2*node+1]);
}
ll query_tree(ll tree[],ll a[],ll qs,ll qe,ll start,ll end,ll node)
{
    if(start>=qs && end<=qe)
    {
        return tree[node];
    }
    if(start>qe || end<qs)
        return INT_MAX;
    int mid=(start+end)/2;
    int left_tree=query_tree(tree,a,qs,qe,start,mid,2*node);
    int right_tree=query_tree(tree,a,qs,qe,mid+1,end,2*node+1);

    return min(left_tree,right_tree);
}*/


int main()
{

 #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("error.txt", "w", stderr);
  #endif  
  IOS;
 ll n;
 cin>>n;
 ll a[n];
 ll sum=0;
 for (int i = 0; i < n; ++i)
 {
     cin>>a[i];
     sum=(((sum+mod)%mod)+((a[i]+mod)%mod))%mod;
 }
 ll ans=0;
 for(int i=0;i<n;i++)
 {
    sum=(((sum+mod)%mod)-((a[i]+mod)%mod))%mod;
    ans=(((ans+mod)%mod)+((((a[i]+mod)%mod)*((sum+mod)%mod))%mod))%mod;
 }
 cout<<((ans+mod)%mod)<<endl;

}
                                  
   

  