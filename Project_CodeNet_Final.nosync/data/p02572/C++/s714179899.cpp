#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define f(i,x,y) for(i=x;i<y;i++)
#define vll vector<ll>
#define fast    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
#define mod 1000000007

bool sortbysec(const pair<ll,ll> &a, const pair<ll,ll> &b) 
{ 
    return (a.second < b.second); 
}

void addEdge(vll adj[], ll u, ll v) 
{ 
    adj[u].push_back(v); 
    adj[v].push_back(u); 
}
void DFSE(vll adj[],vector<bool> &visited,ll u)
{
    ll i;
    visited[u] = true;
    cout<<u<<" ";
    f(i,0,adj[u].size())
    {
        if(visited[adj[u][i]]==false)
        {
            DFSE(adj,visited,adj[u][i]);
        }
    }
    
}
void DFS(vll adj[],ll u,ll v)
{
    ll i;
    vector<bool> visited(v,false);
    f(i,0,v)
    {
        if(visited[i]==false)
        {
            DFSE(adj,visited,i);
        }
    }
}
bool isPrime(ll n) 
{ 
    // Corner cases 
    if (n <= 1) 
        return false; 
    if (n <= 3) 
        return true; 
  
    // This is checked so that we can skip 
    // middle five numbers in below loop 
    if (n % 2 == 0 || n % 3 == 0) 
        return false; 
  
    for (ll i = 5; i * i <= n; i = i + 6) 
        if (n % i == 0 || n % (i + 2) == 0) 
            return false; 
  
    return true; 
} 

int main()
{
    fast;
    ll n,i,a;
    cin>>n;
    vll v,s(n,0);
    
    f(i,0,n)
    {
        cin>>a;
        v.pb(a);
    }
    
    s[n-1]=v[n-1];
    
    for(i=n-2;i>=0;i--)
    {
        s[i]=(s[i+1]+v[i])%mod;
    }
    ll ans=0;
    
    f(i,0,n-1)
    {
        ans=(ans+(v[i]*s[i+1])%mod)%mod;
    }
    cout<<ans<<endl;
    return 0;
}