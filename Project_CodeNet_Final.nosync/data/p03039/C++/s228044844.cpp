#include <bits/stdc++.h>
#define ll long long
#define BUF 1e5
#define INF 1 << 30
constexpr ll mod = 1e9 + 7;
using namespace std;
ll A, B, C, D, G, H, N, M, L, K, P, Q, R, W, X, Y, Z;
string S, T;
ll ans = 0;

template <ll mod>
class Fp {
public:
    ll val;

private:
    inline void calc_mod(ll &v) {
        if (v >= mod)
            v -= mod;
    }

public:
    Fp() {}
    Fp(ll v) : val(v % mod) {
        if (val < 0)
            val += mod;
    }
    Fp operator+=(const Fp &in) {
        val += in.val;
        calc_mod(val);
        return *this;
    }
    Fp operator+(const Fp &in) const {
        return Fp(*this) += in;
    }
    Fp &operator-=(const Fp &in) {
        val -= in.val;
        calc_mod(val);
        if (val < 0)
            val += mod;
        return *this;
    }
    Fp operator-(const Fp &in) const {
        return Fp(*this) -= in;
    }
    Fp &operator*=(const Fp &in) {
        val = val * in.val % mod;
        return *this;
    }
    Fp operator*(const Fp &in) const {
        return Fp(*this) *= in;
    }
    Fp &operator/=(const Fp &in) {
        *this *= modpow(in, mod - 2);
        return *this;
    }
    Fp operator/(const Fp &in) const {
        return Fp(*this) /= in;
    }
    bool operator==(const Fp &in) const {
        return val == in.val;
    }
    bool operator!=(const Fp &in) const {
        return val != in.val;
    }
    friend Fp modpow(const Fp &in, ll n) {
        if (n == 0)
            return 1;
        if (n & 1) {
            return in * modpow(in * in, n / 2);
        } else {
            return modpow(in * in, n / 2);
        }
    }
};
using modll = Fp<mod>;
class Factorial {
public:
    vector<modll> fact, finv;
    Factorial(ll n) : fact(n + 1, modll(1)), finv(n + 1, modll(1)) {
        for (int i = 2; i <= n; i++) {
            modll tmp(i);
            fact[i] = fact[i - 1] * tmp;
            finv[i] = finv[i - 1] / tmp;
        }
    }
    modll com(const ll &n, const ll &k) {
        if (n < k || n < 0 || k < 0)
            return modll(0);
        return fact[n] * finv[k] * finv[n - k];
    }
};

int main() {
    cin >> N >> M >> K;
    vector<modll> dp(M + 1);
    dp[0] = 0;
    dp[1] = 0;
    modll diff = 0;
    modll tmp = N * (N + 1) / 2;
    for (int i = 1; i <= N; i++) {
        dp[1] += i * (N - i);
        diff += tmp;
        tmp -= N - 2 * i;
    }
    for (int i = 2; i <= M; i++) {
        dp[i] = dp[i - 1] * 2 + diff - dp[i - 2];
        diff += N * N;
    }
    Factorial f(N * M);
    dp[M] *= f.com(N * M - 2, K - 2);
    cout << dp[M].val << endl;
}