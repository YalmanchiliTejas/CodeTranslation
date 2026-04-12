#include <iostream>
#include <vector>

template <class T>
std::vector<T> vec(int len, T elem) { return std::vector<T>(len, elem); }

template <int MOD>
struct ModInt {
    using lint = long long;
    int val;

    // constructor
    ModInt(lint v = 0) : val(v % MOD) {
        if (val < 0) val += MOD;
    };

    // unary operator
    ModInt operator+() const { return ModInt(val); }
    ModInt operator-() const { return ModInt(MOD - val); }
    ModInt inv() const { return this->pow(MOD - 2); }

    // arithmetic
    ModInt operator+(const ModInt& x) const { return ModInt(*this) += x; }
    ModInt operator-(const ModInt& x) const { return ModInt(*this) -= x; }
    ModInt operator*(const ModInt& x) const { return ModInt(*this) *= x; }
    ModInt operator/(const ModInt& x) const { return ModInt(*this) /= x; }
    ModInt pow(lint n) const {
        auto x = ModInt(1);
        auto b = *this;
        while (n > 0) {
            if (n & 1) x *= b;
            n >>= 1;
            b *= b;
        }
        return x;
    }

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
    ModInt& operator/=(const ModInt& x) { return *this *= x.inv(); }

    // compare
    bool operator==(const ModInt& b) const { return val == b.val; }
    bool operator!=(const ModInt& b) const { return val != b.val; }
    bool operator<(const ModInt& b) const { return val < b.val; }
    bool operator<=(const ModInt& b) const { return val <= b.val; }
    bool operator>(const ModInt& b) const { return val > b.val; }
    bool operator>=(const ModInt& b) const { return val >= b.val; }

    // I/O
    friend std::istream& operator>>(std::istream& is, ModInt& x) noexcept {
        lint v;
        is >> v;
        x = v;
        return is;
    }
    friend std::ostream& operator<<(std::ostream& os, const ModInt& x) noexcept { return os << x.val; }
};

constexpr int MOD = 1000000007;
using mint = ModInt<MOD>;

using lint = long long;

mint binom(lint n, lint m) {
    mint ret = 1;
    for (int i = 1; i <= m; ++i) {
        ret *= n - i + 1;
        ret /= i;
    }
    return ret;
}

bool solve() {
    int n, m;
    lint d;
    std::cin >> n >> d >> m;
    if (n == 0) return false;

    std::vector<mint> dp(n + 1, 0);
    dp[0] = 1;
    std::vector<mint> sum(n + 1, 0);

    mint ans = 0;
    for (int i = 1; i <= n; ++i) {
        sum[0] = 0;
        for (int j = 0; j < n; ++j) {
            sum[j + 1] = sum[j] + dp[j];
        }

        dp[0] = 0;
        for (int j = 1; j <= n; ++j) {
            dp[j] = sum[j] - sum[std::max(0, j - m + 1)];
        }

        ans += dp[n] * binom(d, i);
    }

    std::cout << ans << "\n";
    return true;
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    while (solve()) {}

    return 0;
}

