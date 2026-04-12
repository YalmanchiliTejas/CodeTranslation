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
 
typedef pair<long long,long long> pll;
typedef pair<int,int> pii;

#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define ld long double
#define int long long
#define pb push_back
#define bs binary_search
#define up upper_bound
#define f first 
#define s second 
#define ff first.first
#define fs first.second
#define sf second.first
#define ss second.second
#define mp make_pair    
#define endl "\n"
 
#define fore(i,a,b) for(ll i = a; i < b; i++)
#define rfore(i, a, b) for(ll i = b - 1; i >= a; i--)
#define forev(a,b) fore(i,0,b)cout<<a[i]<<" "; 
#define ing(g,u,v)  g[u].pb(v); g[v].pb(u);
#define ingp(g,u,v,c) (g[u].pb({v,c});g[v].pb({u,c});)
#define mm(a,b) memset(a , b , sizeof a) 
#define trans(a,b) trasform(a.begin(),a.end(),a.begin(),b)
#define ALL(a) a.begin(),a.end() 
#define SZ(n) ((ll) (n).size())
#define sfind(s,t) (s.find(t) != string::npos)
 
#define infll (ll)1e15
#define infi  (int)(1e9+1)
#define PI 3.14159265359 
#define mod (ll)(1e9+7)
#define eps  1e-10

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b,a%b); } 
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }

int n,d;
string s;
int dp[100001][101][2];

int solve(int i, int re,int e){
    if(i == n)return (re == 0);
    int &r = dp[i][re][e];
    if(~r)return r;
    r=0;
    if(e){
        fore(j,0,s[i]-'0'+1){
            r = (r+ solve(i+1,(re+j)%d,(j == s[i]-'0')))%mod;
        }
    }else{
        fore(j,0,10){
            r = (r + solve(i+1,(re+j)%d,0))%mod;
        }  
    }
    return r;
}

int32_t main(int32_t argc, char const *argv[]){
    FIN;
    cin>>s>>d;
    n=SZ(s);
    mm(dp,-1);
    cout<<(solve(0,0,1)+mod-1)%mod;

    return 0;
}





































































































































































































































































































































































//formulas 
//cero = r/k  -(l/k + (l%k!=0)) +1; cantidad de numeros divisibles por k en el intervalo [l r]
//upper_bound primer elemento mayot estricto
//lower_bound primer elemento mayo o igual
//al hacer bfs con distancia recordar simpre antes de visitar preguntar si ya llegue antes co
//un peso menor
//setprecision(15)




//PROGRAMADO POR xXLucarioXx    
