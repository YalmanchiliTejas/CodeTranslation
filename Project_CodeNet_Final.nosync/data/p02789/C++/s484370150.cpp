#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define ld long double
#define vin ll n; cin>>n; vector<ll>x(n); for(ll i=0; i<n; i++) cin>>x[i]
#define vout for(ll i=0; i<n; i++) cout<<x[i]<<" "
#define T ll t = 1; cin>>t; while(t--)
#define ain ll n,i; cin>>n; ll a[n]; for( i=0; i<n; i++) cin>>a[i]
#define aout for(ll i=0; i<n; i++) cout<<a[i]<<" "
#define matin ll m,n; cin>>m>>n; ll a[m][n]; for(ll i=0;i<m;i++) for(ll j=0;j<n;j++) cin>>a[i][j];
#define matout for(ll i=0;i<m;i++){for(ll j=0;j<n;j++) cout<<a[i][j]<<" "; cout<<"\n";}
#define F first
#define S second
#define I insert
#define sin set<ll>s; ll n; cin>>n; ll tmp; for(ll i=0;i<n;i++){cin>>tmp; s.I(tmp);}
#define sout for(auto it=s.begin();it!=s.end();++it) cout<<*it<<" "
#define AISORT sort(a,a+n)
#define ADSORT sort(a,a+n,greater<ll>())
#define VISORT sort(x.begin(),x.end())
#define VDSORT sort(x.begin(),x.end(),greater<ll>())
#define pb push_back
#define ppb pop_back
#define N_ cout<<"\n"
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) ((a)*1ll * (b)) / gcd(a, b)
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
 
const ll maxs = 1e6+3;
const ll maxs1 = 1e3+4;
const ll mod = 1e9+7;
//MODULO OPEARTIONS
inline ll add(ll a, ll b) { return (mod + a + b) % mod; }
inline ll sub(ll a, ll b) { return (a - b + mod) % mod; }
inline ll mul(ll a, ll b) { return (1ll * a * b) % mod; }
//POWER
ll fastpow(ll x,ll y)
{ll res = 1;x = x % mod;while (y > 0){ if (y & 1)res = (res * x) % mod; y = y >> 1 ; x = (x * x) % mod; } return res;}
//MODULAR INVERSE
ll inv(ll x){ return pow(x , mod - 2);}

ll fact[maxs];
ll fib[maxs];
ll ncr[maxs1][maxs1];
bool vis[maxs];
vector<ll>graph[maxs];

//FACTORIAL
void FACT()
{fact[0]=1;for(ll i=1; i<maxs; i++)fact[i] = (i % mod * fact[i-1] % mod) % mod;}
//FIBONACCI
void FIB()
{ fib[0]=0; fib[1]=1; for(ll i=2; i<maxs; i++)fib[i] = (fib[i-1] % mod + fib[i-2] % mod)% mod;}
//NCR
void NCR()
{ll i,j;ncr[1][0] = 1;ncr[1][1] = 1;for(i=2; i<maxs1; i++){for(j=0; j<=i; j++) { if(j==0)ncr[i][j]=1;else ncr[i][j] = (ncr[i-1][j] + ncr[i-1][j-1] ) % mod;} }}
//PRIME CHECK
bool soe(ll n)
{ bool prime[maxs+1];memset(prime, true, sizeof(prime));for (ll p=2; p*p<=maxs; p++) { if (prime[p] == true){ for (ll i=p*p; i<=maxs; i += p) prime[i] = false; } }
 if(prime[n]) return true;else return false;}    
//BFS
void bfs(ll s,ll n)
{
    queue<ll>PATH;
    PATH.push(s);
    vis[s] = true;
    while(!PATH.empty())
    {
        s = PATH.front();
        PATH.pop();
        vis[s] = true;
        for(auto it = graph[s].begin();it != graph[s].end(); ++it)
        {
            if(vis[*it] == false)
            {
                vis[*it] = true;
                PATH.push(*it);
            }
        }
    }
}
//DFS
void dfs(ll s)
{
    vis[s] = true;          
    for(ll i = 0;i < graph[s].size(); ++i)  
    {
        if(vis[graph[s][i]] == false)           
            dfs(graph[s][i]);
    }
}

//


//
int main()
{
    // FACT();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll m,n;
    cin >> m >> n;
    if(m <= n)
        cout << "Yes";
    else    
        cout << "No";
     
}
