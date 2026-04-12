#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    sort(a.rbegin(), a.rend());

    vector<ll> coef(n, 0);
    for (int i = 0; i < n - 1; i++) {
        if (i & 1) {
            coef[i]++;
            coef[i + 1]--;
        } else {
            coef[i]--;
            coef[i + 1]++;
        }
    }
    sort(coef.rbegin(), coef.rend());
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += coef[i] * a[i];
    }
    ll tmp = 0;
    for (int i = 0; i < n; i++) {
        tmp += -coef[n - 1 - i] * a[i];
    }
    cout << max(ans, tmp) << endl;
}