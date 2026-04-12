#include <iostream>
#include <vector>

template <class T>
std::vector<T> vec(int len, T elem) { return std::vector<T>(len, elem); }

struct ModInt {
    static int MOD;
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

    // I/O
    friend std::istream& operator>>(std::istream& is, ModInt& x) noexcept { return is >> x.val; }
    friend std::ostream& operator<<(std::ostream& os, const ModInt& x) noexcept { return os << x.val; }
};

int ModInt::MOD;
using mint = ModInt;

void solve() {
    int n;
    std::cin >> n >> ModInt::MOD;

    auto comb = vec(n + 1, vec(n + 1, mint(0)));
    comb[0][0] = 1;
    for (int x = 0; x < n; ++x) {
        for (int y = 0; y <= x; ++y) {
            comb[x + 1][y] += comb[x][y];
            comb[x + 1][y + 1] += comb[x][y];
        }
    }

    auto dp = vec(n + 1, vec(n + 1, mint(0)));
    for (int k = 0; k <= n; ++k) {
        for (int l = 0; l <= k; ++l) {
            if (l == 0) {
                dp[k][l] = 1;
            } else if (k == 0) {
                dp[k][l] = 0;
            } else {
                dp[k][l] = dp[k - 1][l - 1] + dp[k - 1][l] * (l + 1);
            }
        }
    }

    mint ans = 0;
    for (int k = 0; k <= n; ++k) {
        mint c = 0;
        for (int l = 0; l <= k; ++l) {
            c += dp[k][l] * mint(2).pow((n - k) * l);
        }

        int e = 1;
        for (int i = 0; i < n - k; ++i) {
            (e *= 2) %= (ModInt::MOD - 1);
        }
        c *= mint(2).pow(e);

        ans += comb[n][k] * c * mint(k % 2 == 0 ? 1 : -1);
    }

    std::cout << ans << std::endl;
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}
