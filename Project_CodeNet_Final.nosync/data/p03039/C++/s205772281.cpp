#include <bits/stdc++.h>
using namespace std;

const int64_t MOD = 1e9 + 7;

// O(log a)
int64_t powmod(int64_t a, int64_t p) {
    int64_t value = 1;
    for (int64_t mul = a; p > 0; p >>= 1, mul = (mul * mul) % MOD) {
        if (p & 1) value = (value * mul) % MOD;
    }
    return value;
}

int64_t invmod(int64_t x) {
    return powmod(x, MOD - 2);
}

struct Factorial {
    vector<int64_t> val;
    vector<int64_t> inv;
};

// O(N)
Factorial GetFact(int N) {
    Factorial fact;
    fact.val = vector<int64_t>(N);
    fact.inv = vector<int64_t>(N);
    fact.val[0] = 1;
    for (int i = 1; i < N; i++) {
        fact.val[i] = int64_t(fact.val[i - 1] * i) % MOD;
    }
    fact.inv[0] = 1;
    fact.inv[N - 1] = powmod(fact.val[N - 1], MOD - 2);
    for (int i = N - 1; i > 0; i--) {
        fact.inv[i - 1] = int64_t(fact.inv[i] * i) % MOD;
    }
    return fact;
}

struct MInt {
    static int64_t mod;
    int64_t v;
    MInt() {}
    MInt(int64_t x) : v(x) {}
    MInt operator+(const MInt &y) { return (v + y.v) % mod; }
    MInt operator-(const MInt &y) { return (v - y.v + mod) % mod; }
    MInt operator*(const MInt &y) { return (v * y.v) % mod; }
    MInt operator/(const MInt &y) { return (v * invmod(y.v)) % mod; }
    void operator+=(const MInt &y) { *this = *this + y; }
    void operator-=(const MInt &y) { *this = *this - y; }
    void operator*=(const MInt &y) { *this = *this * y; }
    void operator/=(const MInt &y) { *this = *this / y; }
    friend istream &operator>>(istream &ist, MInt &m) { return ist >> m.v; }
    friend ostream &operator<<(ostream &ost, MInt &m) { return ost << m.v; }
};
int64_t MInt::mod = MOD;

int64_t Combination(int n, int m, const Factorial &f) {
    if (n < m || m < 0 || n < 0) return 0;
    return ((f.val[n] * f.inv[m] % MOD) * f.inv[n - m]) % MOD;
}
int main() {
    #ifdef DEBUG
    std::ifstream in("/home/share/inputf.in");
    std::cin.rdbuf(in.rdbuf());
    #endif
    int N, M, K;
    cin >> N >> M >> K;
    MInt ans = 0;
    Factorial f = GetFact(N * M + 10);
    for(int i = 0; i < 2; i++) {
        ans += MInt(M) * MInt(M) * MInt(Combination(N + 1, 3, f));
        swap(N, M);
    }
    ans *= MInt(Combination(N * M - 2, K - 2, f));
    cout << ans << endl;
    return 0;
}