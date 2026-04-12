#include <iostream>
#include <vector>
#include <cstdint>

template <std::uint_fast64_t Modulus>
class modint {
    using u64 = std::uint_fast64_t;

public:
    u64 a;

    constexpr modint(const u64 x = 0) noexcept : a(x% Modulus) {}
    constexpr u64& value() noexcept { return a; }
    constexpr const u64& value() const noexcept { return a; }
    constexpr modint operator+(const modint rhs) const noexcept {
        return modint(*this) += rhs;
    }
    constexpr modint operator-(const modint rhs) const noexcept {
        return modint(*this) -= rhs;
    }
    constexpr modint operator*(const modint rhs) const noexcept {
        return modint(*this) *= rhs;
    }
    constexpr modint operator/(const modint rhs) const noexcept {
        return modint(*this) /= rhs;
    }
    constexpr modint& operator+=(const modint rhs) noexcept {
        a += rhs.a;
        if (a >= Modulus) {
            a -= Modulus;
        }
        return *this;
    }
    constexpr modint& operator-=(const modint rhs) noexcept {
        if (a < rhs.a) {
            a += Modulus;
        }
        a -= rhs.a;
        return *this;
    }
    constexpr modint& operator*=(const modint rhs) noexcept {
        a = a * rhs.a % Modulus;
        return *this;
    }
    constexpr modint& operator/=(modint rhs) noexcept {
        u64 exp = Modulus - 2;
        while (exp) {
            if (exp % 2) {
                *this *= rhs;
            }
            rhs *= rhs;
            exp /= 2;
        }
        return *this;
    }
};

using Mint = modint<998244353>;

int main() {
    int n, s;
    std::cin >> n >> s;

    std::vector<int> a(n);
    for (auto&& e : a)
        std::cin >> e;

    Mint ans = 0;
    std::vector<Mint> sums(s);
    for (int i = 0; i < n; ++i) {
        sums[0] += 1;
        if (a[i] > s)
            continue;

        ans += sums[s - a[i]] * (n - i);

        for (int j = s - a[i] - 1; j >= 0; --j)
            sums[j + a[i]] += sums[j];
    }

    std::cout << ans.a << std::endl;
}