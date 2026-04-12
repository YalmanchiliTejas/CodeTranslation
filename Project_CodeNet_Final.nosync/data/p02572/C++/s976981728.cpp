#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

ll MOD = 1e9+ 7;

int main() {
    int n;
    cin >> n;
    vector<ll>a(n);
    rep(i, n) cin >> a[i];
    ll sum = 0;
    rep(i, n) {
        sum += a[i];
        sum %= MOD;
    }
    ll ans = 0;
    rep(i, n - 1) {
        sum -= a[i];
        sum %= MOD;
        if (sum < 0) sum += MOD;
        ans += sum * a[i] % MOD;
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}
