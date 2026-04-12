// be name khoda \\

// #define stream_enable
#define long_enable
#define debug_enable

#include <iostream>
#include <map>
#include <iomanip>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>
#include <sstream>
#include <queue>
#include <stack>
#include <limits.h>
#include <fstream>
#include <cstring>

using namespace std;

#ifdef stream_enable
#define cin sss
#endif

#ifdef long_enable
typedef long long int ll;
#else
typedef int ll;
#endif
typedef long double dbl;

typedef pair<ll, ll> pii;
typedef vector<ll> vi;
typedef pair<ll, pii> pip;
typedef pair<pii, ll> ppi;
typedef pair<pii, pii> ppp;
typedef vector<vi> vii;
typedef vector<vii> viii;
typedef vector<bool> vb;
typedef vector<vb> vbb;
typedef vector<pii> vpii;
typedef vector<pip> vpip;

const ll MOD = 1000000007;

const long long BIG = 1446803456761533460LL;
const int Big = 336860180;

#ifdef long_enable
const ll INF = LONG_LONG_MAX;
#else
const ll INF = INT_MAX;
#endif

const ll adj4[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
const ll adj8[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {-1, -1}, {1, -1}, {-1, 1}, {1, 1}};

#define mp make_pair
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define pb push_back

#define print(x) cout << (x) << '\n'
#define print2(x, y) cout << (x) << ' ' << (y) << '\n'
#define print3(x, y, z) cout << (x) << ' ' << (y) << ' ' << (z) << '\n'
#define print4(x, y, z, t) cout << (x) << ' ' << (y) << ' ' << (z) << ' ' << (t) << '\n'
#define printv(x) fori (j12345, (x).size()) { cout << (x)[j12345] << ' '; } cout << '\n'
#define printvv(x) fori (i123456, (x).size()) { fori (j123456, (x)[i123456].size()) { cout << (x)[i123456][j123456] << ' '; } cout << '\n'; }
#define printp(x) cout << "(" << x.ff << ", " << x.ss << ")" << '\n'
#define printvp(x) fori (i1234567, (x).size()) { cout << "(" << x[i1234567].ff << ", " << x[i1234567].ss << ")" << '\n'; }
#define printa(x, n) fori (ja12345, n) { cout << (x)[ja12345] << ' '; } cout << '\n'
#define printap(x, n) fori (ia1234567, n) { cout << "(" << x[ia1234567].ff << ", " << x[ia1234567].ss << ")" << '\n'; }
#define printaa(x, n, m) fori (iaa123456, n) { fori (jaa123456, m) { cout << (x)[iaa123456][jaa123456] << ' '; } cout << '\n'; }
#define printav(x, n) fori (iaa123477, n) { printv(x[iaa123477]); }
#define printia(x, n) fori (ja212345, n) { cout << ja212345 << " : " << (x)[ja212345] << '\n'; }

#ifdef debug_enable
#define debug(x) cout << #x << " -> "; print(x)
#define debug2(x, y) cout << #x << ' ' << #y << " -> "; print2(x, y)
#define debug3(x, y, z) cout << #x << ' ' << #y << ' ' << #z << " -> "; print3(x, y, z)
#define debug4(x, y, z, t) cout << #x << ' ' << #y << ' ' << #z << ' ' << #t << " -> "; print4(x, y, z, t)
#define debugv(x) cout << #x << " -> "; printv(x)
#define debugvv(x) cout << #x << " ->\n"; printvv(x)
#define debugp(x) cout << #x << " -> "; printp(x)
#define debugvp(x) cout << #x << " ->\n"; printvp(x)
#define debuga(x, n) cout << #x << " -> "; printa(x, n)
#define debugap(x, n) cout << #x << " ->\n"; printap(x, n)
#define debugaa(x, n, m) cout << #x << " ->\n"; printaa(x, n, m)
#define debugav(x, n) cout << #x << " ->\n"; printav(x, n)
#define debugia(x, n) cout << #x << " ->\n"; printia(x, n)
ll clk_ar[10];
#define clk_s(i) clk_ar[i] = clock();
#define clk_e(i) cout << "Clock " << i << " : " << (double) (clock() - clk_ar[i]) / CLOCKS_PER_SEC << " sec\n";
#else
#define debug(x)
#define debug2(x, y)
#define debug3(x, y, z)
#define debug4(x, y, z, t)
#define debugv(x)
#define debugvv(x)
#define debugp(x)
#define debugvp(x)
#define debuga(x, n)
#define debugap(x, n)
#define debugaa(x, n, m)
#define debugav(x, n, m)
#define debugia(x, n)
#define clk_s(i)
#define clk_e(i)
#endif

#define fori(i, n) for(ll i = 0; i < (n); ++i)
#define forir(i, n) for(ll i = (n) - 1; i >= 0; --i)
#define forifrom(i, f, n) for(ll i = (f); i < (n); ++i)
#define forirto(i, n, f) for(ll i = (n) - 1; i >= (f); --i)

#define smin(a, b) a = min(a, (b))
#define smax(a, b) a = max(a, (b))

#define inp(x) ll x; cin >> x
#define inp2(x, y) ll x, y; cin >> x >> y
#define inp3(x, y, z) ll x, y, z; cin >> x >> y >> z
#define inp4(x, y, z, w) ll x, y, z, w; cin >> x >> y >> z >> w

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

ll powMod(ll a, ll b) {
    ll n = 1;
    ll p = a;
    while (b > 0) {
        if (b % 2 == 1) {
            n *= p;
            n %= MOD;
        }
        p *= p;
        p %= MOD;
        b /= 2;
    }
    return n;
}

ll modularInverse(ll a) {
    return powMod(a, MOD - 2);
}

stringstream sss;

// -----------------------------------------------------------------------

const ll maxn = 3010;

ll dp[maxn][maxn];
ll ar[maxn];

void MAIN() {

    inp(n);
    fori (i, n) {
        cin >> ar[i];
    }

    forifrom (len, 1, n + 1) {
        fori (i, n - len + 1) {
            ll j = i + len - 1;
            if ((n - len) % 2 == 0) {
                dp[i][j] = max(dp[i + 1][j] + ar[i], dp[i][j - 1] + ar[j]);
            } else {
                dp[i][j] = min(dp[i + 1][j] - ar[i], dp[i][j - 1] - ar[j]);
            }
        }
    }
    print(dp[0][n - 1]);

}

// -----------------------------------------------------------------------

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(10);
    sss << R"(
3
10 100 10

4
10 80 90 30

    )";
    MAIN();
    return 0;
}
