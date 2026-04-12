#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
// defines
#define rep(i,a,b) for(int i = a; i < b; ++i)
#define invrep(i,b,a) for(int i = b; i >= a; --i)
#define umap unordered_map
#define uset unordered_set
// typedefs
typedef unsigned long long int ull;
typedef long long int ll;
// -------------------------------
int n, s, a[3000];
const ll MOD = 998244353LL;


// intuition:
//   we want to count all distinct tuples (L, seq, R)
//   where seq is a sequence [i1, i2, ..., ik] of indices such that
//      L <= i1 < i2 < ... < ik <= R
//      and a[i1] + a[i2] + ... + a[ik] == s
// dp(i, c, b):
//   number of ways of completing a seu
//



ll memo[3000][3001][2];
ll dp(int i, int c, int b) {
    // base case 1: out of range -> 0 ways
    if (i == n) return 0;
    // base case 2: already solved
    ll& ans = memo[i][c][b];
    if (ans != -1) return ans;
    // general case
    if (b == 0) { // mode 0: looking for 
        ans = (dp(i, c, 1) + dp(i+1, c, 0)) % MOD;
    } else {
        ans = dp(i+1, c, 1);
        if (a[i] < c) ans = (ans + dp(i+1, c - a[i], 1)) % MOD;
        if (a[i] == c) ans = (ans + dp(i+1, 0, 1) + 1) % MOD;
        if (c == 0) ans = (ans + 1) % MOD;
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false); 
    cin.tie(0);
    cin >> n >> s;
    rep(i,0,n) cin >> a[i];
    memset(memo, -1, sizeof memo);
    cout << dp(0,s,0) << '\n';
    return 0;
}