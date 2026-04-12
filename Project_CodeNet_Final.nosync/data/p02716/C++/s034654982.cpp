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
#include <tuple>
#include <numeric>
#include <functional>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef pair<ll, ll> P;
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
const ll mod = 998244353;
const ll INF = 1e16;
const ll MAX_N = 100010;
 
int main() {
    ll n;
    cin >> n;

    vl a(n);
    rep(i, n) {
        cin >> a[i];
    }

    ll k = 1 + n%2;  // 余分な✖の個数

    vvl dp(n+1, vl(k+2, -INF));  // dp[i+1][j] : a[i]まででj個余分な✖を入れたときの総和の最大値
    dp[0][0] = 0;
    rep(i, n) {
        exrep(j, 0, k) {
            chmax(dp[i+1][j+1], dp[i][j]);
            if((i+j)%2 == 0) {
                chmax(dp[i+1][j], dp[i][j] + a[i]);
            }   
            else {
                chmax(dp[i+1][j], dp[i][j]);
            }  
        }
    }
    
    out(dp[n][k]);
    re0;
}