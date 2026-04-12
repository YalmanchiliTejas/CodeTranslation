#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;
const int MOD = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    ll a[n];
    rep(i, n) cin >> a[i];

    ll ans = 0, sum = 0;
    rep(i, n) sum += a[i];
    sum %= MOD;

    rep(i, n - 1) {
        sum -= a[i];
        if (sum < 0) sum += MOD;
        ans = (ans + a[i] * sum) % MOD;
    }

    cout << ans << endl;
    return 0;
}
