#pragma GCC optimize ("-O3")
#include <bits/stdc++.h>
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 998244353;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
// #define INF 1e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

void solve()
{
    ll n,s;
    cin>>n>>s;
    v64 val(n);
    forn(i, n)
    {
        cin>>val[i];
    }
    ll dp[3030][3030];
    forn(i, n)
    {
        forsn(j, 1, s+1)
        {
            
            dp[i][j] = 0;
            if(i > 0) dp[i][j] += dp[i-1][j];
            dp[i][j] %= MOD;
            if(j-val[i] > 0)
            {
                if(i > 0) dp[i][j] += dp[i-1][j-val[i]];
                dp[i][j] %= MOD;
            }
            if(j-val[i] == 0) dp[i][j] += i+1;
            dp[i][j] %= MOD;
        }
    }
    ll ans = 0;
    ans += ((dp[0][s]*n)%MOD);
    ans %= MOD;
    forsn(i, 1, n)
    {
        ll tp = dp[i][s]-dp[i-1][s];
        tp %= MOD;
        if(tp < 0) tp += MOD;
        ans += ((tp*(n-i))%MOD);
        ans %= MOD;
        if(ans < 0) ans += MOD;
    }
    cout<<ans<<ln;
}
 
int main() {
    fast_cin();
    ll t=1;
    // cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}
// BITMASK:
// 1)When some constraint is of the order of 15-20, think of bitmask DP.
// 2)When some constraint is around 40, try out meet in the middle
// 3) See Strings,palindromes,prefix,suffix etc -> KMP,Z algo