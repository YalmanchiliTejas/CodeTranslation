#include <iostream>
#include <array>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_set>
#include <cmath>
#include <complex>
#include <deque>
#include <iterator>
#include <numeric>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <limits>
#include <iomanip>
using namespace std;

using ll=long long;
template<class T> using V = vector<T>;
template<class T, class U> using P = pair<T, U>;
using vll = V<ll>;
using vvll = V<vll>;
#define rep(i, k, n) for (ll i=k; i<(ll)n; ++i)
#define REP(i, n) rep(i, 0, n)
#define ALL(v) v.begin(),v.end()
template<class T> inline bool chmax(T& a, T b) {if (a<b) {a=b; return true;} return false;}
template<class T> inline bool chmin(T& a, T b) {if (a>b) {a=b; return true;} return false;}
#define DEBUG_VLL(vec) REP(i, vec.size()) cerr<<vec[i]<<(i==vec.size()-1?'\n':' ');

const ll MOD = 1000000007;
const ll HIGHINF = (ll)1e18;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string k;
    ll d;
    cin >> k >> d;
    V<vvll> dp(k.size()+1, vvll(2, vll(d, 0)));  // i桁目でk=0:ぴったり k=1:以下 のDの倍数
    dp[0][0][0] = 1;
    rep(i, 1, k.size()+1) {
        REP(j, d) {
            dp[i][0][(j+k[i-1]-'0')%d] += dp[i-1][0][j];
            if (dp[i][0][(j+k[i-1]-'0')%d]>=MOD) dp[i][0][(j+k[i-1]-'0')%d]-=MOD;
            REP(dig, 10) {
                if (dig < k[i-1]-'0') {
                    dp[i][1][(j+dig)%d] += dp[i-1][0][j];
                    if (dp[i][1][(j+dig)%d]>=MOD) dp[i][1][(j+dig)%d]-=MOD;
                }
                dp[i][1][(j+dig)%d] += dp[i-1][1][j];
                if (dp[i][1][(j+dig)%d]>=MOD) dp[i][1][(j+dig)%d]-=MOD;
            }
        }
    }
    ll ans = dp[k.size()][0][0] + dp[k.size()][1][0] - 1;
    if (ans < 0) ans += MOD;
    if (ans >= MOD) ans -= MOD;
    cout << ans << '\n';
    return 0;
}
