#include <algorithm>
#include <iostream>
#include <vector>
#include <math.h>
#include <set>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <iomanip>
#include <numeric>
#include <tuple>
#include <bitset>
#include <complex>
#include <unistd.h>
#include <cassert>
#include <cctype>
#include <random>
#include <time.h>
#define _USE_MATH_DEFINES
#define _GLIBCXX_DEBUG
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> plglg;
typedef pair<double, ll> pdlg;
typedef tuple<int, int, int> tiii;
typedef tuple<ll, ll, ll> tlglglg;
typedef tuple<double, double, double> tddd;
typedef complex<double> xy_t;
typedef vector<ll> vll;
typedef vector< vector<ll> > matrix;
#define REP(i, x, y) for(ll i = (ll)x; i < (ll)y; i++)
#define DREP(i, x, y, d) for(ll i = (ll)x; i < (ll)y; i += (ll)d)
#define PER(i, x, y) for(ll i = (ll)x; i > (ll)y; i--)
#define DPER(i, x, y, d) for(ll i = (ll)x; i > (ll)y; i -= (ll)d)
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
double pi = 3.141592653589793;
ll mod = 1000000007;
int intmax = 2147483647;
int intmin = -2147483648;
ll llmax = 9223372036854775807;
ll llmin = -9223372036854775807;
int iinf = intmax / 8;
ll inf = llmax / 8;
double eps = 1e-12;

ll modadd(ll x, ll y) {
    return ((x + y) % mod + mod) % mod;
}

ll modminus(ll x, ll y) {
    return (x - y + mod) % mod;
}

ll dp[2][10010][110];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string K;
    ll D;
    cin >> K >> D;
    ll len = K.size();
    dp[0][0][0] = 1;
    REP(i, 0, len) {
        ll dig = (ll)K[i] - (ll)'0';
        REP(j, 0, D) {
            REP(k, 0, 10) {
                dp[1][i + 1][(j + k) % D] = modadd(dp[1][i + 1][(j + k) % D], dp[1][i][j]);
            }
            dp[0][i + 1][(j + dig) % D] = modadd(dp[0][i + 1][(j + dig) % D], dp[0][i][j]);
            REP(k, 0, dig) {
                dp[1][i + 1][(j + k) % D] = modadd(dp[1][i + 1][(j + k) % D], dp[0][i][j]);
            }
        }
    }
    // REP(i, 0, len + 1) {
    //     REP(j, 0, D) {
    //         cout << dp[0][i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // REP(i, 0, len + 1) {
    //     REP(j, 0, D) {
    //         cout << dp[1][i][j] << " ";
    //     }
    //     cout << endl;
    // }
    ll ans = modminus(modadd(dp[0][len][0], dp[1][len][0]), 1);
    cout << ans << endl;
}
