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
void toposort(vector<int>& order, int v, int visited[], vector<int>adj[])
{
    visited[v]=1;
    int i;
    for(i=0;i<adj[v].size();i++)
    {
        if(!visited[adj[v][i]])
        {
            toposort(order,adj[v][i],visited,adj);
        }
    }
    order.push_back(v);
}
ll segtree[4*200000+1];
void build(ll A[], ll tl, ll tr, ll v)
{
    if(tl==tr)
    segtree[v]=A[tl];
    else
    {
        ll tm=(tl+tr)/2;
        build(A,tl,tm,v*2);
        build(A,tm+1,tr,2*v+1);
        segtree[v]=max(segtree[2*v],segtree[2*v+1]);
    }
}
ll maxival(ll v, ll tl, ll tr, ll l, ll r)
{
    if(l>r)
    return 0;
    if(l==tl && r==tr)
    return segtree[v];
    ll tm=(tl+tr)/2;
    return max(maxival(2*v,tl,tm,l,min(r,tm)), maxival(2*v+1,tm+1,tr,max(l,tm+1),r));
}
void updateval(ll v, ll tl, ll tr, ll pos, ll newval)
{
    if(tl==tr)
    segtree[v]=newval;
    else
    {
        ll tm=(tl+tr)/2;
        if(pos<=tm)
        updateval(2*v,tl,tm,pos,newval);
        else
        updateval(2*v+1,tm+1,tr,pos,newval);
        segtree[v]=max(segtree[2*v],segtree[2*v+1]);
        
    }
    
}
 ll dp[10000+2][100+1][2];
long long calcdp(string& k, ll d, ll pos, ll rem, ll index)
{
    ll i;
    if(index==k.size())
    {
        if(rem==0)
        return 1ll;
        return 0ll;
    }
    if(dp[index][rem][pos]!=-1)
    return dp[index][rem][pos];
    dp[index][rem][pos]=0ll;
    if(pos==0)
    {
        for(i=0;i<k[index]-'0';i++)
        {
            dp[index][rem][pos]=add(dp[index][rem][pos],calcdp(k,d,1,(rem+i)%d,index+1));
            
        }
        dp[index][rem][pos]=add(dp[index][rem][pos],calcdp(k,d,0,(rem+i)%d,index+1));
    }
    else 
    {
        for(i=0;i<=9;i++)
        dp[index][rem][pos]=add(dp[index][rem][pos],calcdp(k,d,1,(rem+i)%d,index+1));
    }
    return dp[index][rem][pos];
}
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
       string k;
       long long d;
       cin>>k>>d;
       memset(dp,-1ll,sizeof(dp));
       cout<<(calcdp(k,d,0,0,0)+mod-1)%mod;
       
    }
    return 0;
} 