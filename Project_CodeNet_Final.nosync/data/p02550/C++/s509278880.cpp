#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P  = pair<int, int>;

int main() {
    ll n, x, mod, l, r;
    cin >> n >> x >> mod;
    vector<ll> a(100001, 0);
    a[0] = 1;
    a[1] = x;
    map<ll, ll> m;
    m[x] = 1;
    bool type = false;
    for (int i = 2; i <= 100000; ++i) {
        a[i] = a[i - 1] * a[i - 1] % mod;
        if (m[a[i]]) {
            l = m[a[i]];
            r = i;
            break;
        }
        if(!a[i]){
            l = 1;
            r = i;
            type = true;
            break;
        }
        m[a[i]] = i;
    }

    ll sum = 0, psum = 0;
    for (int i = l; i < r; ++i) psum += a[i];
    if (type) return cout << psum, 0;
    for (int i = 1; n > 0 && i < l; ++i, --n) sum += a[i];
    sum += n / (r - l) * psum;
    n %= (r - l);
    for (int i = l; i < r && n > 0; ++i, --n) sum += a[i];
    cout << sum;
}