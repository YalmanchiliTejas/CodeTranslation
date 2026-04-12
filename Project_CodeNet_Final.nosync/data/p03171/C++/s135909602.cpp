#include <bits/stdc++.h>

using namespace std;

//#define PRAGMA 448
#ifdef PRAGMA
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#endif

#ifdef LUCARIO
#define deb(...) fprintf(stderr,__VA_ARGS__)
#define deb1(x) cerr << #x << " = " << x << endl
#else
#define deb(...) 0
#define deb1(x) 0
#endif

typedef int intt;
typedef pair<long long,long long> pll;
typedef pair<int,int> pii;

#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define ld long double
#define int long long
#define pb push_back
#define bs binary_search
#define up upper_bound
#define fs first 
#define sd second 
#define mp make_pair    
#define endl "\n"

#define fore(i,a,b) for(ll i = a; i < b; i++)
#define rfore(i, a, b) for(ll i = a - 1; i >= b; i--)
#define forev(a,b) fore(i,0,b)cout<<a[i]<<" "; 
#define ing(g,u,v)  g[u].pb(v); g[v].pb(u);
#define ingp(g,u,v,c) (g[u].pb({v,c});g[v].pb({u,c});)
#define mm(a,b) memset(a , b , sizeof a) 
#define ALL(a) a.begin(),a.end() 
#define SZ(n) ((ll) (n).size())
#define sfind(s,t) (s.find(t) != string::npos)

#define infll (ll)1e15
#define infi  (int)(1e9+1)
#define PI 3.14159265359 
#define mod (ll)(1e9+7)
#define eps  1e-6

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b,a%b); } 
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }

int n;
int a[3001];
int dp[3001][3001][2];

int solve(int i, int j, bool b){
    if(i == j)return !b ? a[i] : -a[i];
    int &r = dp[i][j][b];
    if(~r)return r;
    
    if(b){
        return r = min(-a[i]+solve(i+1,j,!b),-a[j]+solve(i,j-1,!b));
    }else{
        return r = max(solve(i+1,j,!b)+a[i],solve(i,j-1,!b)+a[j]);
    }
}


int32_t main(int32_t argc, char const *argv[]){
    FIN;
    mm(dp,-1);
    int n; cin>>n;
    fore(i,0,n)cin>>a[i];
    cout<<solve(0,n-1,false)<<endl;


    return 0;
}

















