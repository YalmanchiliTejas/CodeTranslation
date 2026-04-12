#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int inf_int = 1e9 + 100;
const ll inf_ll = 1e18;
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
const int MX = 2e5 + 100;
typedef long long li;
const li MOD = 1000000000949747713ll;


int a[MAXN];
int l[MAXN], r[MAXN];

vector<int> open[MAXN];
vector<int> close[MAXN];

ll t[4*MAXN];
ll add[4*MAXN];
#define left v<<1,tl,tm
#define right v<<1|1,tm+1,tr

void build(int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = -inf_ll;
        add[v] = 0;
    } else {
        int tm = (tl + tr) >> 1;
        build(left);
        build(right);
        t[v] = -inf_ll;
    }
}

inline void push(int v) {
    if (add[v]) {
        add[v << 1] += add[v];
        add[v << 1 | 1] += add[v];
        add[v] = 0;
    }
}

inline void calc(int v) {
    t[v] = max(t[v << 1] + add[v << 1], t[v << 1 | 1] + add[v << 1 | 1]);
}

void add_range(int v, int tl, int tr, int l, int r, int val) {
    if (l > tr || r < tl)
        return;
    if (l <= tl && tr <= r) {
        add[v] += val;
    } else {
        int tm = (tl + tr) >> 1;
        push(v);
        add_range(left, l, r, val);
        add_range(right, l, r, val);
        calc(v);
    }
}

inline void update(int v, int tl, int tr, int pos, ll val) {
    if (tl == tr) {
        t[v] = val;
        add[v] = 0;
    } else {
        int tm = (tl + tr) >> 1;
        push(v);
        if (pos <= tm) {
            update(left, pos, val);
        } else {
            update(right, pos, val);
        }
        calc(v);
    }
}

ll get(int v, int tl, int tr, int l, int r) {
    if (l > tr || r < tl) {
        return -inf_ll;
    }
    if (l <= tl && tr <= r) {
        return t[v] + add[v];
    } else {
        int tm = (tl + tr) >> 1;
        push(v);
        ll val1 = get(left, l, r);
        ll val2 = get(right, l, r);
        calc(v);
        return max(val1, val2);
    }
}

ll dp[MAXN];

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> l[i] >> r[i] >> a[i];
        open[l[i]].pb(i);
        close[r[i] + 1].pb(i);
    }
    build(1, 0, n);
    ll cur_open = 0;

    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int v:close[i]) {
            cur_open -= a[v];
            dout << "clo_range "<<l[v]-1<<" : "<<-a[v]<<endl;
            add_range(1, 0, n, 0, l[v] - 1, -a[v]);
        }
        for (int v:open[i]) {
            cur_open += a[v];
            add_range(1, 0, n, 0, l[v] - 1, a[v]);
            dout << "ope_range "<<l[v]-1<<" : "<<a[v]<<endl;
        }

        dp[i] = cur_open;

        ll get_val = get(1, 0, n, 0, i - 1);

        dout <<  i <<" : " << dp[i]<<" "<<get_val<<endl;
        dp[i] = max(dp[i], get_val);

        update(1, 0, n, i, dp[i]);


        ans = max(ans,dp[i]);
    }

    cout << ans<<"\n";
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
