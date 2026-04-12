#include <iostream>
#include <vector>

template <int MOD>
class ModInt {
    using lint = long long;

public:
    int val;

    // constructor
    ModInt(lint v = 0) : val(v % MOD) {
        if (val < 0) val += MOD;
    };

    // assignment
    ModInt& operator=(const ModInt& x) {
        if (this != &x) { this->val = x.val; }
        return *this;
    }

    // unary operator
    ModInt operator+() const { return ModInt(val); }
    ModInt operator-() const { return ModInt(MOD - val); }
    ModInt operator~() const { return *this ^ (MOD - 2); }

    // increment / decrement
    ModInt& operator++() { return *this += 1; }
    ModInt& operator--() { return *this -= 1; }
    ModInt operator++(int) {
        ModInt before = *this;
        ++(*this);
        return before;
    }
    ModInt operator--(int) {
        ModInt before = *this;
        --(*this);
        return before;
    }

    // arithmetic
    ModInt operator+(const ModInt& x) const { return ModInt(*this) += x; }
    ModInt operator-(const ModInt& x) const { return ModInt(*this) -= x; }
    ModInt operator*(const ModInt& x) const { return ModInt(*this) *= x; }
    ModInt operator%(const ModInt& x) const { return ModInt(*this) %= x; }
    ModInt operator/(const ModInt& x) const { return ModInt(*this) /= x; }
    ModInt operator^(const ModInt& x) const { return ModInt(*this) ^= x; }

    // compound assignment
    ModInt& operator+=(const ModInt& x) {
        if ((val += x.val) >= MOD) val -= MOD;
        return *this;
    }
    ModInt& operator-=(const ModInt& x) {
        if ((val -= x.val) < 0) val += MOD;
        return *this;
    }
    ModInt& operator*=(const ModInt& x) {
        val = lint(val) * x.val % MOD;
        return *this;
    }
    ModInt& operator%=(const ModInt& x) {
        val %= x.val;
        return *this;
    }
    ModInt& operator/=(const ModInt& x) { return *this *= ~x; }
    ModInt& operator^=(const ModInt& x) {
        int n = x.val;
        ModInt b = *this;
        if (n < 0) n = -n, b = ~b;

        *this = 1;
        while (n > 0) {
            if (n & 1) *this *= b;
            n >>= 1;
            b *= b;
        }
        return *this;
    }

    // compare
    bool operator==(const ModInt& b) const { return val == b.val; }
    bool operator!=(const ModInt& b) const { return val != b.val; }
    bool operator<(const ModInt& b) const { return val < b.val; }
    bool operator<=(const ModInt& b) const { return val <= b.val; }
    bool operator>(const ModInt& b) const { return val > b.val; }
    bool operator>=(const ModInt& b) const { return val >= b.val; }

    // I/O
    friend std::ostream& operator<<(std::ostream& os, const ModInt& x) noexcept { return os << x.val; }
    friend std::istream& operator>>(std::istream& is, ModInt& x) noexcept { return is >> x.val; }
};

template <int MOD>
class Combination {
    using mint = ModInt<MOD>;

private:
    int MAX_V;
    std::vector<mint> f, invf;

public:
    explicit Combination(int N)
        : MAX_V(N), f(MAX_V + 1), invf(MAX_V + 1) {
        f[0] = 1;
        for (int i = 1; i <= MAX_V; ++i) {
            f[i] = f[i - 1] * i;
        }

        invf[MAX_V] = ~f[MAX_V];
        for (int i = MAX_V - 1; i >= 0; --i) {
            invf[i] = invf[i + 1] * (i + 1);
        }
    }

    mint fact(int n) const { return f[n]; }
    mint invfact(int n) const { return invf[n]; }
    mint perm(int a, int b) const {
        return a < b ? mint(0) : f[a] * invf[a - b];
    }
    mint comb(int a, int b) const {
        return a < b ? mint(0) : f[a] * invf[a - b] * invf[b];
    }
};

using namespace std;

constexpr int MOD = 1000000007;
using mint = ModInt<MOD>;
Combination<MOD> C(200010);

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    mint ans = 0;
    for (int d = 1; d < N; ++d) {
        ans += mint(d) * M * M * (N - d);
    }
    for (int d = 1; d < M; ++d) {
        ans += mint(d) * N * N * (M - d);
    }

    cout << ans * C.comb(N * M - 2, K - 2) << endl;
    return 0;
}
