#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define exrep(i, a, b) for(ll i = a; i <= b; i++)
#define out(x) cout << x << endl
#define exout(x) printf("%.10f\n", x)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
#define re0 return 0
const ll mod = 1000000007;
const ll INF = 1e16;
const ll MAX_N = 100010;
 
int main() {
    ll n;
    cin >> n;
 
    vl a(n);
    rep(i, n) {
        cin >> a[i];
    }
    
    vvl dp(n+1, vl(n+1));  // dp[l][r] : aの区間[l,r)から始めて二人が最適に行動したときのx-yの値
    exrep(len, 1, n) {
        for(ll l = 0; l + len <= n; l++) {
            ll r = l + len;
            if(n%2 == len%2) {
                dp[l][r] = max(dp[l+1][r] + a[l], dp[l][r-1] + a[r-1]);
            }
            else {
                dp[l][r] = min(dp[l+1][r] - a[l], dp[l][r-1] - a[r-1]);
            }
        }
    }
    
    out(dp[0][n]);
    re0;
}