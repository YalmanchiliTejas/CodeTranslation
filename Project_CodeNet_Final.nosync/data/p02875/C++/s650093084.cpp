#include <iostream>

using namespace std;
typedef long long ll;

constexpr ll MOD = 998244353;

ll calc_pow(ll x, ll pow) {
    if (pow == 0) return 1;
    ll a = calc_pow(x, pow / 2);
    a = a * a % MOD;
    if (pow % 2 == 1) a *= x;
    return a % MOD;
}

ll calc_div(ll a, ll b) {
    return (a % MOD) * calc_pow(b, MOD - 2) % MOD;
}

int main() {
    int n;
    cin >> n;
    ll ret = calc_pow(3, n), comb = 1;
    for (int i = n; i > n / 2; i--) {
        if (i < n)comb = calc_div(comb * (i + 1), n - i);
        ll now = 2 * comb % MOD;
        now *= calc_pow(2, n - i), now %= MOD;
        ret += MOD - now, ret %= MOD;
    }
    cout << ret << endl;
    return 0;
}