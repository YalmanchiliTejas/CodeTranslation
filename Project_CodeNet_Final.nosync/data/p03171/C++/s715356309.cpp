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

pair<long long,long long> dp[3000][3000]; 

void solve()
{
    int n;
    cin>>n;
    vl a(n,0);
    vl pre_sum(n+1,0);
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        dp[i][j] = mp(0,0);
    }
    for(int i = 0 ; i < n ; i++)
    {
        cin>>a[i];
        pre_sum[i+1] = pre_sum[i-1]+a[i];    
        dp[i][i] = mp(a[i],0);
    }
    for(int j = 1 ; j < n ; j++)
    {
        for(int i = 0 ; j+i < n ; i++)
        {
            pll temp1 = mp(a[i]+dp[i+1][j+i].S,dp[i+1][j+i].F);
            pll temp2 = mp(a[i+j]+dp[i][i+j-1].S,dp[i][i+j-1].F);
            if(temp1.F > temp2.F)
            dp[i][i+j] = temp1;
            else
            {
                dp[i][i+j] = temp2;
            }
            

        }
    }
    cout<<dp[0][n-1].F-dp[0][n-1].S<<endl;
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