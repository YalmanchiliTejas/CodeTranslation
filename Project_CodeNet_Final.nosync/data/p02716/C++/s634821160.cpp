#include <bits/stdc++.h>
#include <iterator>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <math.h>
#define vi vector<int>
#define vl vector<long long>
#define vpi vector<pair<int,int> >
#define ll long long 
#define vpl vector<pair<long long,long long> > 
#define F first
#define S second
#define mp make_pair
#define ld long double
#define pb push_back
#define pii pair<int,int>
#define pll pair<long long,long long>
#define pci pair<char,int>
#define un unsigned
# define M_PI           3.14159265358979323846  /* pi */
// #define mod 998244353
#define mod 1000000007
#define MAXN  1000001
using namespace std; 
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)


/*
//------------------------------------------DSU--------------------------------------------------------//
int parent[1000001];
int ssize[1000001];


int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void make_set(int v) {
    parent[v] = v;
    ssize[v] = 1;
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (ssize[a] < ssize[b])
            swap(a, b);
        parent[b] = a;
        ssize[a] += ssize[b];
    }
}
*/

//-----------------------------Sieve Of Eratosthenes--------------------------------------//

/*
v<int> primes;
void SieveOfEratosthenes(int n) 
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
          primes.pb(p); 
}

*/

//----------------DFS------------------------
/*
int n;
vi adj[100001];
int p[100001];
int d[100001];
bool visited[100001];


void dfs(int start)
{
    visited[start] = true;
    for(auto u : adj[start])
    {
        if(!visited[u])
        {
            // visited[u] = start;
            p[u] = start;
            d[u] = d[start]+1;
            dfs(u);
        }
    }
}
*/
//----------------------------------------------

//----------------BFS------------------------
/*
int n;
vi adj[100001];
int p[100001];
int d[100001];
bool visited[100001];


void bfs(int start)
{
    visited[start] = true;
    queue<int> q;
    q.push(start);
    d[start] = 0;
    p[start] = -1;
    while(!q.empty())
    {
        int v = q.front();
        q.pop();
        for(auto u : adj[v])
        {
            if(!visited[u])
            {
                visited[u] = true;
                parent[u] = v;
                d[u] = d[v]+1;
            }
        }
    }
}
*/
//----------------------------------------------



void solve()
{
    int n;
    cin>>n;
    vl a(n+1,0);
    for(int i = 1 ; i <= n ; i++)
    cin>>a[i];
    ll dp[n+1][2];
    dp[1][0] = 0;
    dp[1][1] = 0;
    dp[2][0] = a[1];
    dp[2][1] = a[2];
    if(n >= 3)
    {
        dp[3][1] = a[3];
        dp[3][0] = max(a[1],a[2]);   
    }
    for(int i = 4 ; i <= n ; i++)
    {
        if(i%2 == 1)
        {
            dp[i][1] = a[i] + max(dp[i-2][0],dp[i-2][1]);
            dp[i][0] = max(dp[i-1][1],dp[i-1][0]); 
        }
        else
        {
            dp[i][1] = a[i] + max(max(dp[i-1][0],dp[i-2][1]),dp[i-2][0]);
            dp[i][0] = a[i-1]+dp[i-2][0]; 
        }
    }
    cout<<max(dp[n][0],dp[n][1])<<endl;
    
}



int main()
{
    fast;
    int t;
    // cin>>t;
    t = 1;
    while(t--)
    solve();
    return 0;
}