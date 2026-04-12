#include "bits/stdc++.h"
#define puba push_back
#define ff first
#define ss second
#define bend(_x) begin(_x), end(_x)
#define szof(_x) ((int) (_x).size())
#define TASK_NAME ""

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9 + 7;
const ll INFL = 1e18 + 123;
const double PI = atan2(0, -1);

mt19937 tw(960172);
ll rnd(ll x, ll y) { static uniform_int_distribution<ll> d; return d(tw) % (y - x + 1) + x; }

const ll MOD = 998244353;
const int MAXN = 1e6 + 5;

ll fact[MAXN];

ll mpow(ll a, ll b) {
    if (!b) {
        return 1;
    }
    ll tmp = mpow(a, b / 2);
    tmp = tmp * tmp % MOD;
    if (b & 1) {
        tmp = tmp * a % MOD;
    }
    return tmp;
}

ll inv(ll a) {
    return mpow(a, MOD - 2);
}

ll cnk(int n, int k) {
    return fact[n] * inv(fact[k]) % MOD * inv(fact[n - k]) % MOD;
}

ll buckets(int a, int b) {
    return cnk(a + b - 1, b - 1);
}

char buf[MAXN];
int a[MAXN], b[MAXN];

const int SZ = 10005;
ll d[SZ][SZ];

void add(ll& a, ll b) {
    a += b;
    if (a >= MOD) {
        a -= MOD;
    }
}

int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);
    cerr << fixed << setprecision(15);
    cout << fixed << setprecision(15);
    
    scanf("%s", buf);

    int n = strlen(buf);
    for (int i = 0; i < n; ++i) {
        a[i] = buf[i] - '0';
    }

    scanf("%s", buf);

    for (int i = 0; i < n; ++i) {
        b[i] = buf[i] - '0';
    }

    fact[0] = 1;
    for (int i = 1; i < MAXN; ++i) {
        fact[i] = fact[i - 1] * i % MOD;
    }

    int t[3] = {0, 0, 0};
    int tot = 0;
    for (int i = 0; i < n; ++i) {
        tot += a[i];
        if (a[i] == 1 && b[i] == 1) {
            ++t[0];
        } else if (a[i] == 1 && b[i] == 0) {
            ++t[1];
        } else if (a[i] == 0 && b[i] == 1) {
            ++t[2];
        }
    }

    if (t[1] != t[2]) {
        cout << "0\n";
        return 0;
    }

    ll ans = fact[t[1]];

    d[0][0] = 1;
    for (int i = 0; i <= t[1]; ++i) {
        //for (int j = 0; j <= t[1] && i + j <= t[1]; ++j) {
            for (int k = 0; k <= t[0]; ++k) {
                if (i < t[1]) {
                    add(d[i + 1][k], d[i][k] * (t[1] - i) % MOD);
                }
                if (i > 0 && k < t[0]) {
                    add(d[i][k + 1], d[i][k] * (t[0] - k) % MOD * i % MOD);
                }
            }
        //}
    }

    ll val = 0;
    for (int i = 0; i <= t[0]; ++i) {
        //cerr << cnk(t[0], i) << " " << fact[i] << " " << buckets(i, t[1]) << " " << fact[t[0] - i] << endl;
        //ll sum = 0;
        //cerr << d[t[1]][i] << endl;
        ll now = d[t[1]][i] * cnk(tot, t[1] + i) % MOD * fact[t[0] - i] % MOD * fact[t[0] - i] % MOD;
        //cerr << i << " " << now << endl;
        val = (val + now) % MOD;
    }

    ans = ans * val % MOD;

    cout << ans << "\n";
    
    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}