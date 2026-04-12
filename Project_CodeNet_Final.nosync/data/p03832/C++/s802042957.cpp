#include"bits/stdc++.h"
using namespace std;
using ll = int64_t;

constexpr ll MOD = (ll)1e9 + 7;

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
    ll fact(ll n) const {
        return fact_[n];
    }
private:
    vector<ll> fact_, inv_fact_;
    ll mod_;
};

ll N, A, B, C, D;
vector<vector<ll>> memo;
Combination comb(2001, MOD);

//i人をj人のグループだけを使って分ける方法の数
ll f(ll i, ll j) {
    ll k = i / j;

    return comb.fact(i) * MODpow(MODpow(comb.fact(j), k), MOD - 2) % MOD * MODpow(comb.fact(k), MOD - 2) % MOD;
}

//i人をj人以下のグループだけを使って場合分けする数
ll solve(ll i, ll j) {
    if (i == 0) {
        return 1;
    }
    if (i < 0) {
        return 0;
    }
    if (j == A - 1) {
        return 0;
    }

    if (memo[i][j] != -1) {
        return memo[i][j];
    }

    //j人ちょうどのグループをk個とする
    ll result = solve(i, j - 1);
    for (ll k = C; k <= D; k++) {
        if (j * k > i) {
            break;
        }

        ll tmp = solve(i - j * k, j - 1);

        //i人からj * k人選ぶ方法
        (tmp *= comb(i, j * k)) %= MOD;

        //j * k人をk個のグループに分ける方法
        (tmp *= f(j * k, j)) %= MOD;

        (result += tmp) %= MOD;
    }

    return memo[i][j] = (result % MOD);
}

int main() {
    cin >> N >> A >> B >> C >> D;
    memo.resize(N + 1, vector<ll>(N + 1, -1));
    cout << solve(N, B) << endl;
}