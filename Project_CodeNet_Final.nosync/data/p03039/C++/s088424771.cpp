#include <iostream>
#include <vector>
#include <cassert>

using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;
vector<ll> fact;

void init_fact(int n) {
    fact = vector<ll>(n);
    fact[0] = 1;
    for (int i = 1; i < n; i++) fact[i] = fact[i - 1] * i % MOD;
}

ll calc_pow(ll x, ll pow) {
    if (pow == 0) return 1;
    ll a = calc_pow(x, pow / 2);
    a = a * a % MOD;
    if (pow % 2 == 1) a *= x;
    return a % MOD;
}

ll calc_div(ll a, ll b) {
    a %= MOD, b %= MOD;
    return a * calc_pow(b, MOD - 2) % MOD;
}

ll calc_comb(ll n, ll r) {
    if (n < r)return 0;
    return calc_div(fact[n], fact[r] * fact[n - r] % MOD);
}

int main() {
    init_fact(300000);

    ll n, m, k;
    cin >> n >> m >> k;

    ll ret = calc_div(m * (n - 1) * (n + 1), 3 * n * m - 3) + calc_div(n * (m - 1) * (m + 1), 3 * n * m - 3);
    ret *= calc_comb(k, 2), ret %= MOD;
    ret *= calc_comb(n * m, k), ret %= MOD;

    cout << ret << endl;
    return 0;
}