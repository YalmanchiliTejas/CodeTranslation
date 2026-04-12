#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <numeric>

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

    // I/O
    friend std::istream& operator>>(std::istream& is, ModInt& x) noexcept { return is >> x.val; }
    friend std::ostream& operator<<(std::ostream& os, const ModInt& x) noexcept { return os << x.val; }
};

constexpr int MOD = 1e9 + 7;
using mint = ModInt<MOD>;

template <class T>
std::vector<T> vec(int len, T elem) { return std::vector<T>(len, elem); }

void solve() {
    std::string s;
    int k;
    std::cin >> s >> k;
    std::reverse(s.begin(), s.end());

    auto lo = vec(k + 1, vec(10, mint(0))),
         ti = vec(k + 1, vec(10, mint(0)));
    lo[0][0] = 1, ti[0][0] = 1;

    for (char c : s) {
        int dc = c - '0';
        auto nlo = vec(k + 1, vec(10, mint(0))),
             nti = vec(k + 1, vec(10, mint(0)));

        for (int i = 0; i <= k; ++i) {
            for (int e = 0; e <= 9; ++e) {
                for (int d = 0; d <= 9; ++d) {
                    int ni = i + (d != 0);
                    if (ni > k) continue;
                    nlo[ni][d] += lo[i][e];
                }
                for (int d = 0; d < dc; ++d) {
                    int ni = i + (d != 0);
                    if (ni > k) continue;
                    nti[ni][d] += lo[i][e];
                }
                int ni = i + (dc != 0);
                if (ni > k) continue;
                nti[ni][dc] += ti[i][e];
            }
        }
        std::swap(nlo, lo);
        std::swap(nti, ti);
    }

    std::cout << std::accumulate(ti[k].begin(), ti[k].end(), mint(0))
              << std::endl;
}

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}
