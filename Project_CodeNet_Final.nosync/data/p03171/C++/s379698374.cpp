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

    vvl dp(n+1, vl(n+1));  // dp[L][R] : a[L],…,a[R-1]の状態からはじめて2人が最適に行動したときのX-Yの値
    exrep(len, 1, n) {  // 区間の長さ
        for(ll L = 0; L + len <= n; L++) {  // 区間[L,R)の左
            ll R = L + len;  // 区間[L,R)の右
            if(len%2 == n%2) {  // 区間の長さともとの数列の長さの偶奇が等しいなら先手のターン
                dp[L][R] = max(dp[L+1][R] + a[L], dp[L][R-1] + a[R-1]);  // 先頭要素を取るか末尾要素を取るかの選択でより得点の大きい方を選ぶ
            }
            else {  // そうでなければ後手のターン
                dp[L][R] = min(dp[L+1][R] - a[L], dp[L][R-1] - a[R-1]);  // 先頭要素を取るか末尾要素を取るかの選択でより得点の小さい方を選ぶ
            }
        }
    }
    
    out(dp[0][n]);
    re0;
}