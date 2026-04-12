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

ll divide(ll x, ll y) {
    return multiply(x, modpower(y, mod - 2));
}

ll frac[1000000];
ll invfrac[1000000];

void fracinvfrac(ll n) {
    frac[0] = 1;
    for (int i = 1; i <= n; i++) {
        frac[i] = multiply(frac[i - 1], i);
    }
    invfrac[n] = divide(1, frac[n]);
    for (int i = n - 1; i >= 0; i--) {
        invfrac[i] = multiply(invfrac[i + 1], i + 1);
    }
}

ll modcombi(ll x, ll y) {
    if (x < y || y < 0) {
        return 0;
    } else if (y == 0) {
        return 1;
    } else {
        return multiply(multiply(frac[x], invfrac[x - y]), invfrac[y]);
    }
}

ll dp[1010][1010];
ll modco[1010][1010];

int main() {
    ll N, A, B, C, D;
    cin >> N >> A >> B >> C >> D;
    fracinvfrac(5000);
    REP(i, 0, 1010) {
        REP(j, 0, 1010) {
            modco[i][j] = modcombi(i, j);
        }
    }
    REP(i, 0, 1010) {
        fill(dp[i], dp[i] + 1010, 0);
    }
    dp[0][0] = 1;
    REP(i, 0, 1000) {
        if (A <= i + 1 && i + 1 <= B) {
            REP(j, 0, 1001) {
                dp[i + 1][j] = modadd(dp[i + 1][j], dp[i][j]);
                ll ctod = C;
                ll dif = (i + 1) * ctod;
                // ll mult = 1;
                // if (j + dif <= N) {
                //     REP(k, 0, C) {
                //         mult = multiply(mult, modco[N - j - (i + 1) * k][i + 1]);
                //         mult = divide(mult, (k + 1));
                //     }
                // }
                while(j + dif <= N && ctod <= D) {
                    ll multnum = multiply(multiply(modco[N - j][dif], frac[dif]),
                                          multiply(invfrac[ctod], modpower(invfrac[i + 1], ctod)));
                    dp[i + 1][j + dif] = modadd(dp[i + 1][j + dif],
                                                multiply(dp[i][j], multnum));
                    // mult = multiply(mult, modco[N - j - (i + 1) * ctod][i + 1]);
                    // mult = divide(mult, (ctod + 1));
                    ctod++;
                    dif = (i + 1) * ctod;
                }
            }
        } else {
            REP(j, 0, 1001) {
                dp[i + 1][j] = dp[i][j];
            }
        }
    }
    // REP(i, 0, N + 1) {
    //     REP(j, 0, N + 1) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    ll ans = dp[1000][N];
    cout << ans << endl;
}
