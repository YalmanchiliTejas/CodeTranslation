#include <bits/stdc++.h>
#include <boost/range/adaptor/reversed.hpp>
#include <boost/range/algorithm/sort.hpp>

using namespace std;
using boost::sort;
using boost::adaptors::reversed;

struct mint {
    static constexpr long MOD = 1000000007;
    long value;

    constexpr mint(long value = 0) noexcept : value((value % MOD + MOD) % MOD) {}
    constexpr mint operator-() const noexcept {
        return mint(-value);
    }
    constexpr mint& operator+=(const mint& rhs) noexcept {
        if ((value += rhs.value) >= MOD) value -= MOD;
        return *this;
    }
    constexpr mint& operator-=(const mint& rhs) noexcept {
        if ((value += MOD - rhs.value) >= MOD) value -= MOD;
        return *this;
    }
    constexpr mint& operator*=(const mint& rhs) noexcept {
        (value *= rhs.value) %= MOD;
        return *this;
    }
    constexpr mint operator+(const mint& rhs) const noexcept {
        mint res(*this);
        return res += rhs;
    }
    constexpr mint operator-(const mint& rhs) const noexcept {
        mint res(*this);
        return res -= rhs;
    }
    constexpr mint operator*(const mint& rhs) const noexcept {
        mint res(*this);
        return res *= rhs;
    }
    constexpr mint pow(long e) const noexcept {
        if (e == 0) return 1;
        mint a = pow(e >> 1);
        a *= a;
        if (e % 2 == 1) a *= *this;
        return a;
    }
    constexpr mint inv() const noexcept {
        return pow(MOD - 2);
    }
    constexpr mint& operator/=(const mint& rhs) noexcept {
        return *this *= rhs.inv();
    }
    constexpr mint operator/(const mint& rhs) const noexcept {
        mint res(*this);
        return res /= rhs;
    }
    friend constexpr mint pow(const mint& a, const long& b) noexcept {
        return a.pow(b);
    }
    friend ostream& operator<<(ostream& os, const mint& n) noexcept {
        os << n.value;
        return os;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<mint> am(n);
    am[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--) {
        am[i] = am[i + 1] + a[i + 1];
    }
    mint ans = 0;
    for (int i = 0; i < n; i++) {
        ans += am[i] * a[i];
    }
    cout << ans << endl;
}
