#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < n; ++i)
typedef long long ll;
using namespace std;
const int INF = 1e9;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    sort(a.rbegin(), a.rend());

    ll ans = 0;
    if (n % 2 == 0) {
        for (int i = 0; i < n / 2; ++i)
            ans += a[i] * 2;

        for (int i = n / 2; i < n; ++i)
            ans -= a[i] * 2;

        ans -= a[n / 2 - 1];
        ans += a[n / 2];
    } else {
        ll ans1 = 0, ans2 = 0;
        for (int i = 0; i < n / 2; ++i)
            ans1 += a[i] * 2;

        ans1 -= a[n / 2];
        ans1 -= a[n / 2 + 1];
        for (int i = n / 2 + 2; i < n; ++i)
            ans1 -= a[i] * 2;

        for (int i = 0; i < n / 2 - 1; ++i)
            ans2 += a[i] * 2;
        ans2 += a[n / 2 - 1];
        ans2 += a[n / 2];
        for (int i = n / 2 + 1; i < n; ++i)
            ans2 -= a[i] * 2;

        ans = max(ans1, ans2);
    }

    cout << ans << endl;

    return 0;
}