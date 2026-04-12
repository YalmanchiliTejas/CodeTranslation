#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll a[55], n, ans;

bool gg() {
    for (int i = 0; i < n; ++i) {
        if (a[i] >= n)
            return false;
    }
    return true;
}

void solve() {
    ll cur = 0;
    for (int i = 0; i < n; ++i) {
        cur += a[i] / n;
    }
    for (int i = 0; i < n; ++i) {
        ll cc = a[i] / n;
        a[i] -= cc * n;
        a[i] += cur - cc;
    }
    ans += cur;
}

int main() {
#ifdef LOCAL
    freopen("xxx.in", "r", stdin);
    freopen("xxx.out", "w", stdout);    
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    while (!gg()) {
        solve();
    }
    cout << ans;
    return 0;
}