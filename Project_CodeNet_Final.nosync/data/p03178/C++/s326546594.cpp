#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int inf_int = 1e9 + 100;
const ll inf_ll = 1e15;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double dbl;
#define pb push_back
const double pi = 3.1415926535898;
#define dout if(debug) cout
#define fi first
#define se second
#define sp setprecision
#define sz(a) (int(a.size()))
#define all(a) a.begin(),a.end()
bool debug = 0;
const int MAXN = 2e5 + 100;
const int LOG = 20;
const int mod = 1e9 + 7;
const int MX = 1e6 + 100;
typedef long long li;
const li MOD = 1000000000949747713ll;

struct Fenwick_tree {
    ll t[MAXN];

    Fenwick_tree() {
        memset(t, 0, sizeof t);
    }

    void upd(int pos, ll val) {
        for (; pos < MAXN; pos = (pos | (pos + 1))) {
            t[pos] = max(t[pos], val);
        }
    }

    ll get(int r) {
        ll res = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1) {
            res = max(res, t[r]);
        }
        return res;
    }
};

typedef vector<vector<ll> > matrix;

ll SQR = 1ll * mod * mod;

void add_sqr(ll &a, ll val) {
    a += val;
    if (a >= SQR)
        a -= SQR;
}

matrix mult(matrix &a, matrix &b) {
    int n = sz(a);
    int m = sz(b[0]);
    int k = sz(a[0]);
    assert(sz(a[0]) == sz(b));
    matrix res(n, vector<ll>(m));
    for (int i = 0; i < n; ++i) {
        for (int e = 0; e < m; ++e) {
            ll val = 0;
            for (int j = 0; j < k; ++j) {
                add_sqr(val, a[i][j] * b[j][e]);
            }
            res[i][e] = val % mod;
        }
    }
    return res;
}

matrix bin_pow(matrix &a, ll n) {
    matrix res(sz(a), vector<ll>(sz(a)));
    for (int i = 0; i < sz(a); ++i) {
        res[i][i] = 1;
    }

    while (n) {
        if (n & 1) {
            res = mult(res, a);
        }
        a = mult(a, a);
        n >>= 1;
    }
    return res;
}


ll dp[10100][100];
ll dp_any[10010][100];
string a;
int k;

ll get_any(int i, int sum) {
    if (i >= sz(a)) {
        if (sum == 0)
            return 1;
        return 0;
    }
    if (dp_any[i][sum] != -1)
        return dp_any[i][sum];

    ll &res = dp_any[i][sum];
    res = 0;
    for (int j = 0; j <= 9; ++j) {
        res += get_any(i + 1, (sum + j) % k);
    }
    res %= mod;
    return res;
}

ll get_dp(int i, int sum) {
    if (i >= sz(a)) {
        if (sum == 0)
            return 1;
        return 0;
    }
    if (dp[i][sum] != -1)
        return dp[i][sum];

    ll &res = dp[i][sum];
    res = 0;
    for (int j = 0; j <= 9; ++j) {
        if (j < a[i]) {
            res += get_any(i + 1, (sum + j) % k);
        } else if (j == a[i]) {
            res += get_dp(i + 1, (sum + j) % k);
        }
    }
    res %= mod;
    return res;
}


void solve() {
    memset(dp,-1, sizeof dp);
    memset(dp_any,-1,sizeof dp_any);
    cin >> a >> k;
    for (char &c:a)
        c -= '0';
    ll res = get_dp(0, 0);
    res = (res + mod - 1)%mod;
    cout << res << "\n";
}

signed main() {
#ifdef zxc
    debug = 1;
    freopen("../input.txt", "r", stdin);
#else

#endif //zxc
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.setf(ios::fixed);
    cout.precision(20);

    int t = 1;

    while (t--)
        solve();
    dout << endl << (1.0 * clock() / CLOCKS_PER_SEC) << endl;
}