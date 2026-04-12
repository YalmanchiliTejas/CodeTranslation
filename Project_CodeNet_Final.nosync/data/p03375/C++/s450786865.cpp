#include"bits/stdc++.h"
using namespace std;
using ll = int64_t;

ll N, M;

ll MODpow(ll n, ll m, ll MOD = M) {
    ll result = 1;
    n %= MOD;
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

vector<vector<ll>> dp;
vector<ll> pow2;
ll ways(ll i) {
    ll result = 0;
    for (ll j = 0; j <= i; j++) {
        (result += dp[i][j] * pow2[(N - i) * j] % M) %= M;
    }
    return result * MODpow(2, MODpow(2, N - i, M - 1)) % M;
}

int main() {
    cin >> N >> M;

    dp.resize(N + 2, vector<ll>(N + 2, 0));
    dp[0][0] = 1;
    for (ll i = 1; i <= N; i++) {
        for (ll j = 0; j <= N; j++) {
            if (j > 0) {
                (dp[i][j] += dp[i - 1][j - 1]) %= M;
            }
            (dp[i][j] += dp[i - 1][j] * (j + 1)) %= M;
        }
    }

    pow2.resize(N * N);
    pow2[0] = 1;
    for (ll i = 1; i < N * N; i++) {
        pow2[i] = pow2[i - 1] * 2 % M;
    }

    Combination comb(N + 1, M);
    ll ans = 0;
    //包除原理
    for (ll i = 0; i <= N; i++) {
        (ans += (i % 2 ? -1 : 1) * comb(N, i) * ways(i) % M + M) %= M;
    }
    cout << ans << endl;
}