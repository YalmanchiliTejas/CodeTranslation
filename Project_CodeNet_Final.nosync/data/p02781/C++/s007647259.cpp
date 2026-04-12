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

ll dp[2][110][10];  /* dp[id][i+1][j] : 先頭からi桁目までで0でない数がj個現れるs以下の数の個数。
                                       ただし、id = 0 のとき現時点でsと等しい。
                                       id = 1 のとき現時点でsより小さいことが確定。 */

int main() {
    string s;
    ll k;
    cin >> s >> k;
    ll m = s.size();  // sはm桁とする
    
    dp[0][0][0] = 1;
    rep(id, 2) {
        rep(i, m) {
            rep(j, 4) {
                ll lim = s[i] - '0';  //  先頭からi桁目にはlim以下の数を置ける
                if(id) {
                    lim = 9;
                }
                exrep(x, 0, lim) {  // 先頭からi桁目にxを置くとする
                    dp[id || x < lim][i+1][j + (x != 0)] += dp[id][i][j];
                }
            }
        }
    }
    
    ll ans = (dp[0][m][k] + dp[1][m][k])%mod;
    
    out(ans);
    re0;
}