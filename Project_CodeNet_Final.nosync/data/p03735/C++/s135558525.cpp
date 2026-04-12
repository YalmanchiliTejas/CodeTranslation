#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ll> x(n), y(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        if (x[i] > y[i]) {
            swap(x[i], y[i]);
        }
    }
    ll xa = *max_element(x.begin(), x.end());
    ll xb = *min_element(x.begin(), x.end());
    ll ya = *max_element(y.begin(), y.end());
    ll yb = *min_element(y.begin(), y.end());
    ll ans = (yb - ya) * (xb - xa);
    if (xa < yb || xa == ya || xb == yb) {
        cout << ans << '\n';
        return 0;
    }
    ll mx = xa, mn = yb;
    for (int i = 0; i < n; i++) {
        if (x[i] == xb && y[i] == ya) {
            cout << ans << '\n';
            return 0;
        }
        if (x[i] == xb) {
            mx = max(mx, y[i]);
        }
        if (y[i] == ya) {
            mn = min(mn, x[i]);
        }
    }
    vector<pair<ll, ll>> p;
    for (int i = 0; i < n; i++) {
        if (x[i] < mn && mx < y[i]) {
            p.emplace_back(mn - x[i], y[i] - mx);
        }
    }
    ll dif = 0;
    if (!p.empty()) {
        sort(p.begin(), p.end());
        for (int i = p.size() - 1; i > 0; i--) {
            p[i - 1].second = max(p[i - 1].second, p[i].second);
        }
        dif = min(p.back().first, p[0].second);
        for (int i = 0; i < p.size() - 1; i++) {
            dif = min(dif, p[i].first + p[i + 1].second);
        }
    }
    ans = min(ans, (ya - xb) * (mx - mn + dif));
    cout << ans << '\n';
    return 0;
}
