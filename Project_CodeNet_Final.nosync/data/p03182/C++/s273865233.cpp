#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

#define FASTIO
#define ALL(v) (v).begin(), (v).end()
#define rep(i, l, r) for (int i = (l); i < (r); ++i)

#ifdef FASTIO
#define scanf abacaba
#define printf abacaba
#endif

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;

const int MX = 200 * 1000 + 7;
const ll INF = 1e18;

ll t[4 * MX];
ll mod[4 * MX];

ll getv(int v) {
    return t[v] + mod[v];
}

void push(int v) {
    mod[v + v] += mod[v];
    mod[v + v + 1] += mod[v];
    mod[v] = 0;
}

void ad(int v, int tl, int tr, int l, int r, ll x) {
    if (r < tl || l > tr) {
        return;
    }
    if (tl >= l && tr <= r) {
        mod[v] += x;
        return;
    }
    push(v);
    int tm = (tl + tr) >> 1;
    ad(v + v, tl, tm, l, r, x);
    ad(v + v + 1, tm + 1, tr, l, r, x);
    t[v] = max(getv(v + v), getv(v + v + 1));
}

ll gt(int v, int tl, int tr, int l, int r) {
    if (r < tl || l > tr) {
        return -INF;
    }
    if (tl >= l && tr <= r) {
        return getv(v);
    }
    push(v);
    int tm = (tl + tr) >> 1;
    ll ans =max(gt(v + v, tl, tm, l, r), gt(v + v + 1, tm + 1, tr, l, r));
    t[v] = max(getv(v + v), getv(v + v + 1));
    return ans;
}
vector<pair<int, int>> add[MX], rm[MX];
ll f[MX];
int main() {
#ifdef FASTIO
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int l, r, x;
        cin >> l >> r >> x;
        add[l].emplace_back(l - 1, x);
        rm[r].emplace_back(l - 1, x);
    }

    for (int i = 1; i <= n; i++) {
        for (const auto& q : add[i]) {
            ad(1, 0, n, 0, q.first, q.second);
        }
        f[i] = gt(1, 0, n, 0, i - 1);
        ad(1, 0, n, i, i, f[i]);
        for (const auto& q : rm[i]) {
            ad(1, 0, n, 0, q.first, -q.second);
        }
    }

    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, f[i]);
    }

    cout << ans << "\n";
    return 0;
}

