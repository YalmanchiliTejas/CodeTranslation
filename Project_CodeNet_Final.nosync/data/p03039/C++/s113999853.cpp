#include"bits/stdc++.h"
using namespace std;
using ll = int64_t;

constexpr ll MOD = 1e9 + 7;

ll MODpow(ll n, ll m) {
    ll result = 1;
    while (m) {
        if (m % 2 == 1) {
            result *= n;
            result %= MOD;
        }

        m /= 2;
        n *= n;
        n %= MOD;
    }

    return result;
}

class Combination {
public:
    Combination(ll max_num, ll mod) {
        fact_.resize(max_num + 1, 1);
        inv_fact_.resize(max_num + 1, 1);
        mod_ = mod;
        for (ll i = 2; i <= max_num; i++) {
            fact_[i] = i * fact_[i - 1] % mod_;
            inv_fact_[i] = MODpow(fact_[i], mod_ - 2);
            assert(fact_[i] * inv_fact_[i] % mod_ == 1);
        }
    }
    ll operator()(ll n, ll m) const {
        if (m < 0 || m > n) return 0;
        return fact_[n] * inv_fact_[n - m] % mod_ * inv_fact_[m] % mod_;
    }
private:


    vector<ll> fact_, inv_fact_;
    ll mod_;
};

int main() {
    ll N, M, K;
    cin >> N >> M >> K;

    ll ans = 0;
    for (ll i = 0; i < N; i++) {
        ll tmp = 0;
        ll x = 0;
        (x += i * (i + 1) / 2 % MOD) %= MOD;
        (x += (N - i - 1) * (N - i) / 2 % MOD) % MOD;
        ll sum = M * (M - 1) / 2 % MOD;
        ll sum_u = ((sum + M - 1) + (sum + i * (M - 1))) * i / 2 % MOD;
        ll sum_d = (sum + (sum + (N - i - 1) * (M - 1))) * (N - i) / 2 % MOD;
        (x += sum_u) %= MOD;
        (x += sum_d) %= MOD;

        (tmp += M * x % MOD) %= MOD;

        ll pow2 = (M - 1) * M * (2 * M - 1) / 6 % MOD;
        (tmp += N * pow2 % MOD) %= MOD;

        ll sub = (M - 1) * (M - 1) * M / 2 % MOD * N % MOD;
        tmp = (tmp + MOD - sub) % MOD;

        (ans += tmp) %= MOD;
    }
    (ans *= MODpow(2, MOD - 2)) %= MOD;

    for (ll i = 0; i < K - 2; i++) {
        (ans *= N * M - 2 - i) %= MOD;
    }
    for (ll i = 1; i <= K - 2; i++) {
        (ans *= MODpow(i, MOD - 2)) %= MOD;
    }

    cout << ans << endl;
}