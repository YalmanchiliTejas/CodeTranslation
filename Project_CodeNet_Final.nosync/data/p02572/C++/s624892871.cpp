#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define repr(i, n) for (int i = n-1; i >= 0; i--)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
const int mod = 1e9+7;
const int INF = 2e9;
const int MAX = 1e6;

int main() {
    int n;
    cin >> n;
    vi a(n);
    ll sum = 0;
    rep(i, n) {
        cin >> a[i];
        sum += a[i];
    }
    ll ans = 0;
    rep(i, n-1) {
        sum -= a[i];
        ll r = (ll)a[i] * (sum % mod);
        r %= mod;
        ans += r;
        ans %= mod;
    }
    cout << ans << endl;
}