#include <bits/stdc++.h>
#include <iostream>
#include <numeric> 
#define ll long long
#define mod 1000000007
#define mod1 998244353 
using namespace std;
//vector<int>adj[200000+1];
int cnt=0;
vector<int>cand;
bool prime[100006]; 
  void SieveOfEratosthenes(int n) 
{ 
   
    memset(prime, true, sizeof(prime)); 
  
    for (int p=2; p*p<=n; p++) 
    { 
        if (prime[p] == true) 
        { 
            for (int i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
    
} 
int prob=0;
void dfs(vector<int>adj[],int v, bool visited[],stack<int>&s,bool visited2[])
{
    
    visited[v]=true;
    int i;
    int c=1;
    bool f=true;
    for(i=0;i<adj[v].size();i++)
    {
        if(!visited[adj[v][i]])
        {    
            f=false;
            dfs(adj,adj[v][i],visited,s, visited2);    
        }
    }
    if(adj[v].size()==1)
   { s.push(v); visited2[v]=true;}
}
long long power(long long x, long long  y )
{  
    long long res = 1;     
    x = x % mod; 
    if (x == 0) return 0; 
    while (y > 0)  
    {  
        if (y & 1)  
            res = (res*x) % mod;  
        y = y>>1; 
        x = (x*x) % mod;  
    }  
    return res;  
}  
long long add(long long x, long long y)
{
    x += y;
    while(x >= mod) x -= mod;
    while(x < 0) x += mod;
    return x;
}
 
long long mul(long long x, long long y)
{
    return (x * 1ll * y) % mod;
}
 
long long binpow(long long x, long long y)
{
    long long z = 1;
    while(y)
    {
        if(y & 1) z = mul(z, x);
        x = mul(x, x);
        y >>= 1;
    }
    return z;
}
 
long long inv(long long x)
{
    return binpow(x, mod - 2);
}
 
long long divide(long long x, long long y)
{
    return mul(x, inv(y));
}
 
long long fact[100005];
 
void precalc()
{
    fact[0] = 1;
    for(long long i = 1; i < 100005; i++)
        fact[i] = mul(fact[i - 1], i);
}
 
long long C(long long n, long long k)
{
    if(n==0)
    return 1;
    return divide(fact[n], mul(fact[k], fact[n - k]));
}
int dfs(bool visited[], vector<int> adj[], int v)
{
    int c=1;
    visited[v]=true;
    for(int i=0;i<adj[v].size();i++)
    {
        if(!visited[adj[v][i]])
        {
            c+=dfs(visited,adj,adj[v][i]);
        }
    }
    return c;
}
struct comp
{
    bool operator()(const pair<int,int>& p1, const pair<int,int>&p2)
    {
        if(p1.first==p2.first)
        {
            return p1.second<p2.second;
        }
        else 
        return p1.first>p2.first;
    }
};
long long sub(long long A,long long B)
{
    return (A-B+mod)%mod;
}
bool topflag=true;
void toposort(string& order, int v, int visited[], vector<int>adj[])
{
    visited[v]=1;
    int i;
    for(i=0;i<adj[v].size();i++)
    {
        if(!visited[adj[v][i]])
        {
            toposort(order,adj[v][i],visited,adj);
        }
        else 
        if(visited[adj[v][i]]==1)
        {
           // cout<<(char)(v+97)<<"\n";
            topflag=false;
        }
    }
    order+=(v+97);
    visited[v]=2;
}
 ll dp[101][100001];
int main()
{
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout<<fixed<<setprecision(10);
    cerr<<fixed<<setprecision(5);
    int t=1;
    //SieveOfEratosthenes(100005);
    //precalc();
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //cin>>t;
   
    while(t--)
    {
      ll n;
      cin>>n;
      ll i,j;
      ll A[n];
      for(i=0;i<n;i++)
      cin>>A[i];
      ll dp[n+1][n+1];
      memset(dp,0ll,sizeof(dp));
      for(i=0;i<n;i++)
      {
          dp[i][i]=A[i];
          for(j=i-1;j>=0;j--)
          {
              dp[i][j]=max(A[j]-dp[i][j+1],A[i]-dp[i-1][j]);
          }
      }
      cout<<dp[n-1][0]<<"\n";
      
    }

    return 0;
} 