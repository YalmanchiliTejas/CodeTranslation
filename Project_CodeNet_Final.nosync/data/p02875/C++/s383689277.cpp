#include <iostream>
#include <vector>

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

vector<ll> fact;

void init_fact(int n) {
    fact = vector<ll>(n);
    fact[0] = 1;
    for (int i = 1; i < n; i++) fact[i] = fact[i - 1] * i % MOD;
}

ll calc_comb(ll n, ll r) {
    if (n < r)return 0;
    return calc_div(fact[n], fact[r] * fact[n - r] % MOD);
}

int main() {
    init_fact(1e7 + 1);

    int n;
    cin >> n;
    ll ret = calc_pow(3, n);
    for (int i = n; i > n / 2; i--) {
        ll now = 2 * calc_comb(n, i) % MOD;
        now *= calc_pow(2, n - i), now %= MOD;
        ret += MOD - now, ret %= MOD;
    }
    cout << ret << endl;
    return 0;
}