#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define forn(i, a, n) for (int i = a; i < n; ++i)
#define ford(i, a, n) for (int i = n - 1; i >= a; --i)
#define fore(i, a, n) for (int i = a; i <= n; ++i)
#define all(a) (a).begin(), (a).end()
#define fs first
#define sn second
#define trace(a)\
    for (auto i : a) cerr << i << ' ';\
    cerr << '\n'
#define eb emplace_back

#ifndef M_PI
const ld M_PI = acos(-1.0);
#endif

const ld eps = 1e-9;
const int INF = 2000000000;
const ll LINF = 1ll * INF * INF;
const ll MOD = 1000000007;

const int N = 1e5 + 100;
int pr[N];

int get(int i) {
    if (pr[i] == i) return i;
    return pr[i] = get(pr[i]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    vector<tuple<int, int, int>> e;
    forn(i, 0, n) cin >> x[i] >> y[i];
    vector<int> a(n);
    forn(i, 0, n) a[i] = i;
    sort(all(a), [&](int i, int j) {
            return x[i] < x[j];
            });
    forn(i, 0, n - 1) {
        e.eb(x[a[i + 1]] - x[a[i]], a[i], a[i + 1]);
    }
    sort(all(a), [&](int i, int j) {
            return y[i] < y[j];
            });
    forn(i, 0, n - 1) {
        e.eb(y[a[i + 1]] - y[a[i]], a[i], a[i + 1]);
    }
    sort(all(e));
    ll ans = 0;
    forn(i, 0, n) pr[i] = i;
    for (auto p : e) {
        int w, u, v;
        tie(w, u, v) = p;
        //cerr << u << ' ' << v << ' ' << w << '\n';
        u = get(u);
        v = get(v);
        if (u == v) continue;
        ans += w;
        pr[u] = v;
    }
    cout << ans << '\n';
}
