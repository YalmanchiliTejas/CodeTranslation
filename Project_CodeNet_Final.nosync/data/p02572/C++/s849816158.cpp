// adios amigos!!
#include <bits/stdc++.h>
#include <chrono>
#include <random>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
#define rep(i,n) for(ll i = 0; i < n; ++i)
#define ed end()  
#define bg begin()
# define ld long double
#define ll long long
#define ub(v,a) upper_bound(all(v),a)
#define lb(v,a) lower_bound(all(v),a)
#define sz(a) (int)(a.size())
#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()
#define tr(v,it) for(auto it=v.begin();it!=v.end();it++)
#define present(v,x) (v.find(x)!=v.end()) //set/map etc.
#define vpresent(v,x) (find(all(v),x)!=v.end()) // vector
#define vi vector <int>
#define vs vector <string>
#define vc vector <char>
typedef vector< long long > vll;
typedef vector<pair<ll,ll>> vp;
typedef vector< vll > vvll;
typedef pair< int,int > pi;
const long long max_sz = 1e5 + 1;
const long long mod = 1e9 + 7;
const long long MAXN = 4e18 + 1;
const int N=500023;
#define PI 3.1415926535897932384626
char flip(char k){ if(k=='0') return '1'; return '0'; }
ll sum_digit(ll n){ ll a=0,i; for(i=n;i>0;i=i/10){ a+=(i%10);} return a; }
ll gcd(ll a, ll b){if(b == 0) return a;return gcd(b, a%b);}
bool isPowerOfTwo(int n){if(n==0)return false;return (ceil(log2(n)) == floor(log2(n)));}
//DEBUGGING
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
const int LG = 20;
//__builtin_popcount(n) -> returns number of set bits in n
ll expo(ll a, ll b, ll m); // a^(b) %m
//=======================

//vector<bool> vis;vis.assign(n,false); g.assign(n,{});
//vector<vll> g;
//void ipgraph(ll m){ll  u, v;while(m--){cin>>u>>v; u--, v--;g[u].pb(v);g[v].pb(u);}}
//ll lvl[N], p[N][LG];
//ll lca(ll u,ll v){if(lvl[u]<lvl[v])swap(u,v);ll i,lg; for(lg=0;(1<<lg)<=lvl[u];lg++);lg--;for(i=lg;i>=0;i--){if(lvl[u]-(1<<i)>=lvl[v]){u=p[u][i];}}if(u==v)return v;else{for(i=lg;i>=0;i--){if(p[u][i]!=-1 && p[u][i]!=p[v][i]){u=p[u][i];v=p[v][i];}}}return p[u][0];}

void solve(){
    ll n;cin>>n;
    vll a(n);rep(i,n){cin>>a[i];}
    
    ll jhc=0 ;
    ll sum=a[n-1];
    ll idx=n-2;
    while(idx>=0){
        jhc+=(a[idx]%mod * sum%mod)%mod;
        sum+=a[idx]%mod;
        sum%=mod;
        jhc%=mod;
        idx--;
    }
    
    cout<<jhc<<endl;
}

int main(){
 
   ll t = 1;
  //  cin >> t;
    while(t--) {
      solve();
    }
   return 0;
}


ll expo(ll a, ll b, ll m) 
{ 
    if (b == 0)return 1; 
    ll p = expo(a, b / 2, m) % m; 
    p = (p * p) % m; 
  
    return (b % 2 == 0) ? p : (a * p) % m; 
} 