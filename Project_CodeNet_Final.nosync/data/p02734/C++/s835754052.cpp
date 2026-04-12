#include <bits/stdc++.h>

using namespace std;

using ll = long long;

constexpr char newl = '\n';

// https://noshi91.hatenablog.com/entry/2019/03/31/174006
template <std::uint_fast64_t Modulus>
struct ModInt {
    using u64 = std::uint_fast64_t;

    static constexpr u64 MOD = Modulus;

    u64 val;

    constexpr ModInt(const u64 x = 0) noexcept : val(x % MOD) {}

    constexpr ModInt operator+() const noexcept { return ModInt(*this); }
    constexpr ModInt operator-() const noexcept {
        ModInt res(*this);
        if (res.val != 0) res.val = MOD - res.val;
        return res;
    }

    // prefix increment/decrement
    constexpr ModInt& operator++() noexcept { return *this += ModInt(1); }
    constexpr ModInt& operator--() noexcept { return *this -= ModInt(1); }

    // postfix increment/decrement
    constexpr ModInt& operator++(int) noexcept {
        ModInt tmp(*this);
        ++*this;
        return tmp;
    }
    constexpr ModInt& operator--(int) noexcept {
        ModInt tmp(*this);
        --*this;
        return tmp;
    }

    constexpr ModInt operator+(const ModInt& rhs) const noexcept {
        return ModInt(*this) += rhs;
    }
    constexpr ModInt operator-(const ModInt& rhs) const noexcept {
        return ModInt(*this) -= rhs;
    }
    constexpr ModInt operator*(const ModInt& rhs) const noexcept {
        return ModInt(*this) *= rhs;
    }
    constexpr ModInt operator/(const ModInt& rhs) const noexcept {
        return ModInt(*this) /= rhs;
    }

    constexpr ModInt& operator+=(const ModInt& rhs) noexcept {
        val += rhs.val;
        if (val >= Modulus) val -= MOD;
        return *this;
    }
    constexpr ModInt& operator-=(const ModInt& rhs) noexcept {
        if (val < rhs.val) val += MOD;
        val -= rhs.val;
        return *this;
    }
    constexpr ModInt& operator*=(const ModInt& rhs) noexcept {
        val = val * rhs.val % MOD;
        return *this;
    }

    // prime Modulus only
    constexpr ModInt& operator/=(const ModInt& rhs) noexcept {
        return *this *= rhs.inv();
    }

    // prime Modulus only
    constexpr ModInt inv() const noexcept {
        return pow(*this, MOD - 2);
    }
};

template<std::uint_fast64_t Modulus>
constexpr ModInt<Modulus> pow(ModInt<Modulus> x, std::uint_fast64_t n) {
    ModInt<Modulus> res(1);
    while (n) {
        if (n & 1) res *= x;
        x *= x;
        n >>= 1;
    }
    return res;
}

template<std::uint_fast64_t Modulus>
istream& operator>>(istream& is, ModInt<Modulus>& x) {
    std::uint_fast64_t val;
    is >> val;
    x = ModInt<Modulus>(val);
    return is;
}

template<std::uint_fast64_t Modulus>
ostream& operator<<(ostream& os, const ModInt<Modulus>& x) {
    return os << x.val;
}

using mint = ModInt<998244353>;

mint dp[3005][3005];

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    mint ans = 0;
    dp[0][0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= s; ++j) {
            dp[i + 1][j] = dp[i][j];
            if (j >= a[i]) {
                mint hoge = dp[i][j - a[i]] * (j == a[i] ? i + 1 : 1);
                dp[i + 1][j] += hoge;
                if (j == s) ans += hoge * (n - i);
            }
        }
    }
    cout << ans << newl;

    return 0;
}
