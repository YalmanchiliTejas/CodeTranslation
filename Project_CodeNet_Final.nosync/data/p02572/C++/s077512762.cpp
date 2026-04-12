#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

#define MOD 1000000007
int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    ll sum = 0;
    rep(i, n) {
        cin >> a[i];
        sum += a[i];
        sum %= MOD;
    }
    ll ans = 0;
    rep(i, n - 1) {
        sum -= a[i];
        if (sum < 0) {
            sum += MOD;
        }
        ans += a[i] * sum;
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}
