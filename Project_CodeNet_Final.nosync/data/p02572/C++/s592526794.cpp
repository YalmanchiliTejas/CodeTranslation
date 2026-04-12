#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;

ll calc_pow(ll x, ll pow) {
    if (pow == 0) return 1;
    ll a = calc_pow(x, pow / 2);
    a = a * a % MOD;
    if (pow % 2 == 1) a *= x;
    return a % MOD;
}

ll calc_div(ll a, ll b) {
    return a * calc_pow(b, MOD - 2) % MOD;
}

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    ll sum = 0;
    for (int i = 0; i < n; i++)cin >> a[i], sum += a[i], sum %= MOD;

    ll ret = sum * sum % MOD;
    for (int i = 0; i < n; i++) {
        ret -= (a[i] * a[i]) % MOD;
        if (ret < 0)ret += MOD;
    }

    cout << calc_div(ret, 2) << endl;
    return 0;
}