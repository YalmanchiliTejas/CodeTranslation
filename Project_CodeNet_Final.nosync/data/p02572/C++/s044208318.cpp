#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;
ll MOD = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll sum = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }
    for (int i = 0; i < n; i++) {
        sum -= a[i];
        ans += (a[i] * (sum % MOD)) % MOD;
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}