#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, k;
    cin >> n >> k;
    ll ans = 0;
    if (k == 0) {
        cout << ll(n) * n;
        return 0;
    }
    for (ll i = 1; i <= n; ++i) {
        ll z = n - n % i;
        ans += max(i - k, 0LL) * z / i;
        ll r = n % i;
        ans += max(0LL, r - k + 1);
    }
    cout << ans;
    return 0;
}