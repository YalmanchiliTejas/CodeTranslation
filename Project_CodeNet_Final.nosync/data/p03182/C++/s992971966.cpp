//#pragma GCC target ("avx2,sse2")
//#pragma GCC optimization ("Ofast")
//#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree <pair <ll, int>, null_type, less <pair <ll, int> >, rb_tree_tag, tree_order_statistics_node_update>
#define ll long long
#define ull unsigned long long
#define db double
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define fi first
#define se second
#define mp make_pair
#define up_b upper_bound
#define low_b lower_bound
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define endl "\n"

#define left fsdsdfoisf
#define sum dpsdfioppsf
#define assign xcvjlkdjfio
#define trie fksdfkjkfnjuiv
#define next sidlfjsfkl
#define merge sdfksdkfsldf

#define int long long

using namespace std;

void dout() {
    cerr << endl;
}
template <typename Head, typename... Tail>
void dout(Head H, Tail... T) {
    cerr << H << ' ';
    dout(T...);
}

//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef pair <int, int> pii;

const int N = 2e5 + 7, inf = 1e18;
int n, m, dp[N], sum, t[N * 4], add[N * 4];
vector <pii> v[N];

void push(int v, int tl, int tr) {
    if (add[v]) {
        int tm = tl + tr >> 1;
        t[v << 1] += add[v];
        t[v << 1 | 1] += add[v];
        add[v << 1] += add[v];
        add[v << 1 | 1] += add[v];
        add[v] = 0;
    }
}

void build(int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = -inf;
        return;
    }
    int tm = tl + tr >> 1;
    build(v << 1, tl, tm);
    build(v << 1 | 1, tm + 1, tr);
    t[v] = max(t[v << 1], t[v << 1 | 1]);
}

void update(int v, int tl, int tr, int l, int r, int x) {
    if (tl > r || tr < l) {
        return;
    }
    if (tl >= l && tr <= r) {
        t[v] += x;
        add[v] += x;
        return;
    }
    int tm = tl + tr >> 1;
    push(v, tl, tr);
    update(v << 1, tl, tm, l, r, x);
    update(v << 1 | 1, tm + 1, tr, l, r, x);
    t[v] = max(t[v << 1], t[v << 1 | 1]);
}

int getmax(int v, int tl, int tr, int l, int r) {
    if (tl > r || tr < l) {
        return -inf;
    }
    if (tl >= l && tr <= r) {
        return t[v];
    }
    int tm = tl + tr >> 1;
    push(v, tl, tr);
    return max(getmax(v << 1, tl, tm, l, r), getmax(v << 1 | 1, tm + 1, tr, l, r));
}

void upd(int x, int y) {
    int val = getmax(1, 1, n, x, x);
    update(1, 1, n, x, x, y - val);
}

void solve(int tc) {
    // check for (int i = 0; i < n; j++)
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int l, r, a;
        cin >> l >> r >> a;
        v[r].pb({l, a});
        sum += a;
    }
    dp[1] = sum;
    build(1, 1, n);
    upd(1, dp[1]);
    int cur = 0;
    for (int i = 2; i <= n + 1; i++) {
        for (auto j : v[i - 1]) {
            int l = j.fi, a = j.se;
            if (l > 1) {
                update(1, 1, n, 1, l - 1, -a);
            }
            cur += a;
        }
        dp[i] = getmax(1, 1, n, 1, i - 1);
        dp[i] = max(dp[i], sum - cur);
        if (i <= n) {
            upd(i, dp[i]);
        }
    }
    cout << dp[n + 1];
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    int tc = 1;
//    cin >> tc;
    for (int i = 0; i < tc; i++) {
        solve(i);
//        cleanup();
    }
}
