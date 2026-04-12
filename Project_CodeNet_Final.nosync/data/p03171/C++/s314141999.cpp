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
double eps = 1e-11;

ll dp[3010][3010];

int main() {
    ll N;
    cin >> N;
    ll a[N];
    REP(i, 0, N) {
        cin >> a[i];
    }
    REP(i, 0, N + 1) {
        dp[0][i] = 0;
    }
    REP(i, 1, N + 1) {
        REP(j, 0, N + 1 - i) {
            if ((N - i) % 2 == 0) {
                dp[i][j] = max(dp[i - 1][j + 1] + a[j], dp[i - 1][j] + a[j + i - 1]);
            } else {
                dp[i][j] = min(dp[i - 1][j + 1] - a[j], dp[i - 1][j] - a[j + i - 1]);
            }
        }
    }
    // REP(i, 0, N + 1) {
    //     REP(j, 0, N + 1) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    ll ans = dp[N][0];
    cout << ans << endl;
}
