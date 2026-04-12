#include <bits/stdc++.h>
using namespace std;
//#include "testlib.h"
#define ff first
#define ss second
#define all(v) v.begin(),v.end()
#define int long long
#define ll long long
#define M 1000000007
#define MM 998244353
#define inputarr(a,n) for(int i=0;i<n;++i) cin>>a[i]
#define GCD(m,n) __gcd(m,n)
#define LCM(m,n) m*(n/GCD(m,n))
#define mii  map<ll ,ll >
#define sz(a) (int)a.size()
#define msi  map<string,ll >
#define rep(a,b)    for(ll i=a;i<b;i++)
#define rep0(n)    for(ll i=0;i<n;i++)
#define repi(i,a,b) for(ll i=a;i<b;i++)
#define pb push_back
#define vi vector<ll>
#define vs vector<string>
#define ppb pop_back
#define endl '\n'
#define asdf ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define r0 return 0;
#define FORD(i, a, b) for (int i = (int) (a); i >= (int) (b); --i)
#define inputoutput freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#define Set(a, s) (a, s, sizeof (a))
#define FOR repi
#define pii pair<int,int>
#define REVERSE(v) reverse(all(v))
#define trav(a, x) for(auto& a : x)
#define display(x) trav(a,x) cout<<a<<" ";cout<<endl
#define debug cerr<<"bhau"<<endl
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    std::cerr << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');std::cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
template<typename T, typename U> static inline void amin(T &x, U y) 
{ 
    if (y < x) 
        x = y; 
}
template<typename T, typename U> static inline void amax(T &x, U y) 
{ 
    if (x < y) 
        x = y; 
}
 
ll max(ll a, ll b) { return (a > b)? a : b;}
int min(int a, int b) { return (a < b)? a : b;} 


int solve(){

    string s;cin>>s;
    map<char,int> m;
    for(auto i:s) m[i]++;
    if(m.size()>=2) cout<<"Yes";
else cout<<"No";


    return 0;
}
signed main(){
    asdf
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
