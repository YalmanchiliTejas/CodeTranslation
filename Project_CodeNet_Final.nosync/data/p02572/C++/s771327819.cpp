#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    int ans = 0;
    int sum = 0;
    rep(i, n) {
        int row = ((ll)a[i] * sum) % MOD;
        ans += row;
        ans %= MOD;
        sum += a[i];
        sum %= MOD;
    }
    cout << ans << endl;
    return 0;
}