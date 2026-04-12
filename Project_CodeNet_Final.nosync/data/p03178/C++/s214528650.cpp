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
 
ll dp[2][10005][105];  /* dp[id][i+1][j] : 先頭からi桁目(iは0-index)までで各桁の数字の総和をdで割った余りがjとなる0以上の数の個数
                                           ただし、id = 0 のとき現時点でsと等しい。
                                           id = 1 のとき現時点でsより小さいことが確定。 */
int main() {
    string s;
    ll d;
    cin >> s >> d;
    ll n = s.size();
 
    dp[0][0][0] = 1;
    rep(id, 2) {
        rep(i, n) {
            rep(j, d) {
                ll lim = s[i] - '0';  //  先頭からi桁目にはlim以下の数を置ける
                if(id) {
                    lim = 9;
                }
                exrep(x, 0, lim) {  // 先頭からi桁目にxを置くとする
                    dp[id || x < lim][i+1][(j + x)%d] += dp[id][i][j];
                    dp[id || x < lim][i+1][(j + x)%d] %= mod;
                }
            }
        }
    }
 
    dp[1][n][0] = (dp[1][n][0] + mod -1)%mod;  // 0を余計にカウントしているので除く
    
    ll ans = 0;
    rep(id, 2) {
        ans += dp[id][n][0];
        ans %= mod;
    }
    
    out(ans);
    re0;
}