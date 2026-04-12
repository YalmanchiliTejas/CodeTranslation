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

ll N, M;
ll dp[200010][2];

ll solve(ll num) {
    dp[0][0] = 1;
    REP(i, 0, num) {
        dp[i + 1][0] = modadd(dp[i + 1][0], dp[i][0]);
        dp[i + 1][0] = modadd(dp[i + 1][0], dp[i][1]);
        dp[i + 1][1] = modadd(dp[i + 1][1], dp[i][0]);
    }
    return (dp[num - 1][0] + dp[num - 1][1] + dp[num - 2][0]) % mod;
}

ll dpb[200010][2];

ll solveb(ll num, ll len) {
    // cout << num << " " << len << endl;
    ll p = num / 2;
    ll q = len / 2;
    dpb[0][0] = 1;
    dpb[0][1] = 1;
    // ll sum = 0;
    REP(i, 0, p) {
        dpb[i + 1][0] = modadd(dpb[i + 1][0], dpb[i][1]);
        if (i - (q + 1) >= 0) {
            dpb[i + 1][0] = modminus(dpb[i + 1][0], dpb[i - (q + 1)][1]);
        }
        // dpb[i + 1][0] = modadd(dpb[i + 1][0], dpb[i][1]);
        dpb[i + 1][1] = modadd(modadd(dpb[i + 1][1], dpb[i + 1][0]), dpb[i][1]);
        // sum = modadd(sum, dpb[i + 1][1]);
        // if (i >= q) {
        //     sum = modminus(sum, dpb[i + 1 - q][0]);
        // }
        // if (i == 0) {
        //     sum--;
        // }
    }
    // dpb[0][0] = 1;
    // dpb[0][1] = 1;
    // REP(i, 0, num) {
    //     dpb[i + 1][0] = modadd(dpb[i + 1][0], dpb[i][0]);
    //     dpb[i + 1][0] = modadd(dpb[i + 1][0], dpb[i][1]);
    //     dpb[i + 1][1] = modadd(dpb[i + 1][1], dpb[i][0]);
    // }
    // dp[0][0] = 1;
    // REP(i, 0, num) {
    //     dp[i + 1][0] = modadd(dp[i + 1][0], dp[i][0]);
    //     dp[i + 1][0] = modadd(dp[i + 1][0], dp[i][1]);
    //     dp[i + 1][1] = modadd(dp[i + 1][1], dp[i][0]);
    // }
    // REP(i, 0, p) {
    //     cout << dpb[i][0] << " " << dpb[i][1] << endl;
    // }
    ll ans = 0;
    REP(i, 0, q + 1) {
        if (p - 1 - i >= 0) {
            ll val = multiply((i + 1) * 2, dpb[p - 1 - i][0]);
            // cout << val << endl;
            ans = modadd(ans, val);
        }
    }
    return ans;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    string S;
    cin >> S;
    if (N & 1) {
        bool ok = true;
        char c = S[0];
        REP(i, 0, M) {
            if (S[i] != c) {
                ok = false;
            }
        }
        if (ok) {
            cout << solve(N) << endl;
        } else {
            cout << 0 << endl;
        }
        return 0;
    } else {
        ll len = 0;
        char c = S[0];
        ll num = 0;
        while (num < M && S[num] == c) {
            num++;
        }
        len = num;
        if (len == M) {
            cout << solve(N) << endl;
            return 0;
        }
        if (!(len & 1)) {
            len++;
        }
        ll tmp = 0;
        num++;
        while (num < M) {
            if (S[num] == c) {
                tmp++;
            } else {
                if (tmp & 1) {
                    len = min(len, tmp);
                }
                tmp = 0;
            }
            num++;
        }
        // cout << len << endl;
        cout << solveb(N, len) << endl;
    }
}
