#include<bits/stdc++.h>
#include<string.h>
 
typedef long long int ll;
#define all(x) (x).begin(), (x).end()
 
using namespace std;

int nxt() {
    int x;
    cin >> x;
    return x;
}

ll nxtl(){
    ll x;
    cin>>x;
    return x;
}
 
void SieveOfEratosthenes(int n,vector <int> &primes) 
{ 
    // Create a boolean array "prime[0..n]" and initialize 
    // all entries it as true. A value in prime[i] will 
    // finally be false if i is Not a prime, else true. 
    bool prime[n+1]; 
    memset(prime, true, sizeof(prime)); 
  
    for (int p=2; p*p<=n; p++) 
    { 
        // If prime[p] is not changed, then it is a prime 
        if (prime[p] == true) 
        { 
            // Update all multiples of p greater than or  
            // equal to the square of it 
            // numbers which are multiple of p and are 
            // less than p^2 are already been marked.  
            for (int i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
  
    // Print all prime numbers 
    for (int p=2; p<=n; p++) 
       if (prime[p]) 
          primes.push_back(p);
} 
 
ll max(ll a,ll b)
{
    if(a>b)
        return a;
    return b;
}
 
ll power(ll x, ll y,ll mod) 
{ 
    ll temp; 
    if( y == 0) 
        return 1; 
    temp = power(x, y/2,mod); 
    if (y%2 == 0) 
        return (temp*temp)%mod; 
    else
        return (((x*temp)%mod)*temp)%mod; 
}

vector <vector <int> > g;
int ans=0;
void dfs(int s,vector <bool> &visited,set <int> &v);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n=nxt(),m=nxt();
    vector <int> row;
    g.resize(n+1,row);
    while(m--)
    {
        int u=nxt(),v=nxt();
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector <bool> visited;
    visited.resize(n+1,0);
    set <int> v;
    for(int i=1;i<=n;i++)
        v.insert(i);
    dfs(1,visited,v);
    cout<<ans<<endl;

    
    return 0;   
}

void dfs(int s,vector <bool> &visited,set <int> &v)
{
    v.erase(s);
    visited[s]=1;
    if(v.size()==0)
        ans++;
    else
    {
        for(auto x:g[s])
        {
            if(!visited[x])
            {
                dfs(x,visited,v);
            }
        }
    }
    visited[s]=0;
    v.insert(s);

}




 
 
