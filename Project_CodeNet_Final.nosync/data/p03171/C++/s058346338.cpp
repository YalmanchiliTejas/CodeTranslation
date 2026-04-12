#include <bits/stdc++.h>
#define ll long long
#define rep(i, a) for(ll i=0; i<a; i++)
#define rep1(i, a, b) for(ll i=a; i<b; i++)
using namespace std;
typedef vector<ll> vi;
typedef vector<vi> vvi;

ll fun(vi &v, ll s, ll e, vvi &dp){
    if(s==e)
        return (dp[s][e] = v[s]);
    if(s==e-1)
        return (dp[s][e] = max(v[s], v[e]));
    if(dp[s][e]==-1)
        dp[s][e] =  max(v[s] + min(fun(v, s+2, e, dp), fun(v, s+1, e-1, dp)), v[e] + min( fun(v, s+1, e-1, dp), fun(v, s, e-2, dp) ));
    return dp[s][e];
}

int main(){
    ll n, s=0;
    cin>>n;
    vi v(n);
    vvi dp(n+1, vi(n+1, -1));
    rep(i, n)
        cin>>v[i], s+=v[i];
    cout<<2*fun(v, 0, n-1, dp)-s;
}

/*

10 80 90 30

0, 3 -> 10 + min((2, 3), (1, 2))
     -> 30 + min((0, 1), (1, 2))







*/