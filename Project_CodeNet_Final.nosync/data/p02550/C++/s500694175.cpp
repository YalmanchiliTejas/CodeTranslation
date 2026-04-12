#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;
ll MOD = 1000000000 + 7;

int main() {
    ll n, x, m;
    cin >> n >> x >> m;
    ll x1 = x;
    ll sum = x;
    vector<ll> a(m);
    ll l = 0, r = 0;
    a[0] = x;
    bool roop = false;
    for (ll i = 1; i < n; i++) {
        ll tmp = (x * x) % m;
        x = tmp;
        for (int j = 0; j < i; j++) {
            if (a[j] == tmp) {
                l = j;
                r = i - 1;
                roop = true;
                break;
            }
        }
        if (roop) break;
        a[i] = tmp;
        sum += tmp;
    }
    if (r) {
        ll fsum = 0;
        for (int i = 0; i < l; i++) {
            fsum += a[i];
        }
        ll lsum = 0;
        for (int i = 0; i < ((n - l) % (r - l + 1)); i++) {
            lsum += a[l + i];
        }
        sum += (sum - fsum) * ((n - l + 1) / (r - l + 1) - 1) + lsum;
    }

    if (x1 == ((x1 * x1) % m)) {
        sum = x1 * n;
    }
    cout << sum << endl;
    return 0;
}