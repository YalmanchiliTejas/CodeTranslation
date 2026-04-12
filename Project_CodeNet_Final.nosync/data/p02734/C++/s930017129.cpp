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
    ll n, S;
    cin >> n >> S;

    // 1-indexで考える
    vl a(n+1);
    exrep(i, 1, n) {
        cin >> a[i];
    }

    // dp1[l][r][s] :「l <= x_1 < … < x_k <= r」かつ「Σa_(x_i) (1 <= i <= k) = s」 をみたす(x_1, …,x_k)の個数
    // とおくと、
    // l = r のとき、 dp1[r][r][s] = １[(s = 0) ∨ (s = a[r])]  (ただし、１[bool] はbool = falseのとき0, bool = trueのとき1となる関数)
    // l < r のとき、 dp1[l][r][s] =  dp1[l][r-1][s] + dp1[l][r-1][s - a[r]]
    // このとき求める値は Σ(Σdp1[l][r][S] (1 <= l <= r)) (1 <= r <= n) なので、
    // dp2[r][s] = Σdp1[l][r][s] (1 <= l <= r) とおくと
    // 求める値は Σdp2[r][S] (1 <= r <= n) となる。
    // dp2[r][s] = Σdp1[l][r][s] (1 <= l <= r) = Σdp1[l][r][s] (1 <= l <= r-1) + dp1[r][r][s]
    //           = Σ(dp1[l][r-1][s] + dp1[l][r-1][s - a[r]]) (1 <= l <= r-1) + １[(s = 0) ∨ (s = a[r])]
    //           = dp2[r-1][s] + dp2[r-1][s - a[r]] + １[(s = 0) ∨ (s = a[r])]
    // となってO(n*S)になる。

    // dp1[l][r][s] :「l <= x_1 < … < x_k <= r」かつ「Σa_(x_i) (1 <= i <= k) = s」をみたす(x_1, …,x_k)の個数
    vvl dp2(n+1, vl(S+1));  // dp2[r][s] : Σdp1[l][r][s] (1 <= l <= r)
    exrep(r, 1, n) {
        exrep(s, 0, S) {
            ll x = 0;
            if(s == 0 || s == a[r]) {
                x = 1;
            }
            if(s >= a[r]) {
                dp2[r][s] = dp2[r-1][s] + dp2[r-1][s - a[r]] + x;
            }
            else {
                dp2[r][s] = dp2[r-1][s] + x;
            }
            dp2[r][s] %= mod;
        }
    }

    ll ans = 0;
    exrep(r, 1, n) {
        ans += dp2[r][S];
        ans %= mod;
    }

    out(ans);
    re0;
}