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
ll mod = 998244353;
int intmax = 2147483647;
int intmin = -2147483648;
ll llmax = 9223372036854775807;
ll llmin = -9223372036854775807;
int iinf = intmax / 8;
ll inf = llmax / 8;
double eps = 1e-12;
void yesno(bool ok, string yes = "Yes", string no = "No") {
    if (ok) {
        cout << yes << endl;
    } else {
        cout << no << endl;
    }
}

ll modadd(ll x, ll y) {
    return ((x + y) % mod + mod) % mod;
}

ll modminus(ll x, ll y) {
    return (x - y + mod) % mod;
}

ll multiply(ll x, ll y) {
    return (x % mod) * (y % mod) % mod;
}

ll modpower(ll x, ll y) {
    if (y == 0) {
        return 1;
    } else if (y == 1) {
        return x % mod;
    } else if (y % 2 == 0) {
        ll p = modpower(x, y / 2);
        return p * p % mod;
    } else {
        ll p = modpower (x, y / 2);
        return (p * p) % mod * (x % mod) % mod;
    }
}

ll dpl[3010][3010], dpr[3010][3010];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, S;
    cin >> N >> S;
    ll A[N];
    REP(i, 0, N) {
        cin >> A[i];
    }
    dpl[0][0] = 1;
    REP(i, 0, N) {
        dpl[i + 1][0] = 1;
        REP(j, 0, S + 1) {
            dpl[i + 1][j] = modadd(dpl[i + 1][j], dpl[i][j]);
            if (j + A[i] <= S) {
                dpl[i + 1][j + A[i]] = modadd(dpl[i + 1][j + A[i]], dpl[i][j]);
            }
        }
    }
    dpr[N][0] = 1;
    PER(i, N - 1, - 1) {
        REP(j, 0, S + 1) {
            dpr[i][j] = modadd(dpr[i][j], dpr[i + 1][j]);
            if (j + A[i] <= S) {
                dpr[i][j + A[i]] = modadd(dpr[i][j + A[i]], dpr[i + 1][j]);
            }
        }
    }
    // REP(i, 0, N + 1) {
    //     REP(j, 0, S + 1) {
    //         cout << dpl[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // REP(i, 0, N + 1) {
    //     REP(j, 0, S + 1) {
    //         cout << dpr[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    ll ans = 0;
    REP(l, 0, N + 1) {
        ans = modadd(ans, dpl[l][S]);
    }
    cout << ans << endl;
}
