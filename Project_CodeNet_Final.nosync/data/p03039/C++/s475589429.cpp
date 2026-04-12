// Author: Shusuke Ueda
// AtCoder Beginner Contest 127 - Problem C

#include <iostream>

namespace nt {
    template <int_fast64_t mod>
    class ModInt {
        int_fast64_t val;

      public:
        ModInt(): val(0) {}
        ModInt(int_fast64_t init_val): val(init_val >= 0? init_val % mod: mod - (-init_val % mod)) {}

        friend std::istream& operator >> (std::istream& is, ModInt& n) {
            int_fast64_t init_val;
            is >> init_val;
            n = ModInt(init_val);
            return is;
        }
        friend std::ostream& operator << (std::ostream& os, const ModInt n) {
            os << n.val;
            return os;
        }

        ModInt operator -() const {
            return ModInt(-val);
        }
        bool operator !() const {
            return val == 0;
        }
        ModInt& operator ++() {
            val++;
            if (val >= mod) {
                val -= mod;
            }
            return *this;
        }
        ModInt operator ++(int) {
            ModInt tmp = *this;
            val++;
            if (val >= mod) {
                val -= mod;
            }
            return tmp;
        }
        ModInt& operator --() {
            val--;
            if (val < 0) {
                val += mod;
            }
            return *this;
        }
        ModInt operator --(int) {
            ModInt tmp = *this;
            val--;
            if (val < 0) {
                val += mod;
            }
            return tmp;
        }

        ModInt& operator += (const ModInt that) {
            val += that.val;
            if (val >= mod) {
                val -= mod;
            }
            return *this;
        }
        ModInt& operator -= (const ModInt that) {
            val -= that.val;
            if (val < 0) {
                val += mod;
            }
            return *this;
        }
        ModInt& operator *= (const ModInt that) {
            val = val * that.val % mod;
            return *this;
        }
        ModInt& operator /= (const ModInt that) {
            int_fast64_t res = 1, n = that.val, p = mod - 2;
            while (p > 0) {
                if (p % 2 == 1) {
                    res = res * n % mod;
                }
                n = n * n % mod;
                p /= 2;
            }
            val = val * res % mod;
            return *this;
        }

        ModInt operator + (const ModInt that) const {
            return ModInt(*this) += that;
        }
        ModInt operator - (const ModInt that) const {
            return ModInt(*this) -= that;
        }
        ModInt operator * (const ModInt that) const {
            return ModInt(*this) *= that;
        }
        ModInt operator / (const ModInt that) const {
            return ModInt(*this) /= that;
        }
    };

    using mint = ModInt<1000000007>;
}

int main() {
    int_fast64_t m, n, k;
    std::cin >> m >> n >> k;

    nt::mint comb_x = 0;
    for (int i = 1; i < m; i++) {
        comb_x += nt::mint(i) * (m - i);
    }
    comb_x *= n * n;
    nt::mint comb_y = 0;
    for (int i = 1; i < n; i++) {
        comb_y += nt::mint(i) * (n - i);
    }
    comb_y *= m * m;
    nt::mint comb_rest = 1;
    for (int i = 0; i < k - 2; i++) {
        comb_rest = comb_rest * (nt::mint(m) * n - 2 - i) / (i + 1);
    }

    std::cout << (comb_x + comb_y) * comb_rest << std::endl;

    return 0;
}