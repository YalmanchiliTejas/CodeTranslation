#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, b) for (int i = a; i < (int)(b); i++)
#define all(v) v.begin(), v.end()
const int MOD = 1e9 + 7;
const int INF = 1e9;
//'A' = 65, 'Z' = 90, 'a' = 97, 'z' = 122

int main() {
    int n;
    cin >> n;
    ll a[n];
    rep(i, 0, n) {
        cin >> a[i];
    }
    ll sum[n + 1] = {};
    rep(i, 0, n) {
        sum[i + 1] = sum[i] + a[i];
    }
    ll ans = 0;
    rep(i, 0, n - 1) {
        ans += (a[i] * ((sum[n] - sum[i + 1]) % MOD)) % MOD;
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}
