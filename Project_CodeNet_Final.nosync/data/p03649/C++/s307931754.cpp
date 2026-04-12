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
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll ans = 1e18;
    for (int i = 0; i < n; i++) {
        ll lo = 0, hi = 1e17;
        while (hi - lo > 1) {
            ll md = (hi + lo) / 2;
            ll mid = md * n + i;
            ll mx = n - 1 - mid;
            ll cnt = 0;
            for (int i = 0; i < n; i++) {
                cnt += (a[i] - mx + n) / (n + 1);
            }
            if (cnt >= mid) {
                lo = md;
            } else {
                hi = md;
            }
        }
        ans = min(ans, lo * n + i - 1);
    }
    cout << ans << '\n';
    return 0;
}
