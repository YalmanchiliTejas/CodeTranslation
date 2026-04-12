#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(long long i=0; i<(n); i++)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

vector<ll> g(51), h(51);

ll solve(ll n, ll x){
    if(n==0){
        return x;
    }
    if(x==0) return 0;
    if(x == g[n]) return h[n];
    if(x <= g[n-1]+1){
        return solve(n-1, x-1);
    }
    return 1 + h[n-1] + solve(n-1, x-2-g[n-1]);
}


int main(){
    ll n,x; cin>>n>>x;
    g[0]=1; h[0]=1;
    for(ll i=1; i<=50; i++) g[i]=2*g[i-1]+3;
    for(ll i=1; i<=50; i++) h[i]=2*h[i-1]+1;

    cout << solve(n, x) << endl;
    return 0;
}