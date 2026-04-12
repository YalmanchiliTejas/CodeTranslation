#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <stack>
#include <algorithm>
#include <string>
#include <map>
#include <iterator>
#include <set>
#include <queue>
#include <bitset>
#include <cassert>

using namespace std;

const int MOD = 1000000007;

template<int MOD>
struct MINT {
    long long val;

    constexpr MINT(long long v = 0) noexcept: val(v % MOD) {
        if (val < 0) val += MOD;
    }

    constexpr int getmod() { return MOD; }

    constexpr MINT operator-() const noexcept {
        return val ? MOD - val : 0;
    }

    constexpr MINT operator+(const MINT &r) const noexcept { return MINT(*this) += r; }

    constexpr MINT operator-(const MINT &r) const noexcept { return MINT(*this) -= r; }

    constexpr MINT operator*(const MINT &r) const noexcept { return MINT(*this) *= r; }

    constexpr MINT operator/(const MINT &r) const noexcept { return MINT(*this) /= r; }

    constexpr MINT &operator+=(const MINT &r) noexcept {
        val += r.val;
        if (val >= MOD) val -= MOD;
        return *this;
    }

    constexpr MINT &operator-=(const MINT &r) noexcept {
        val -= r.val;
        if (val < 0) val += MOD;
        return *this;
    }

    constexpr MINT &operator*=(const MINT &r) noexcept {
        val = val * r.val % MOD;
        return *this;
    }

    constexpr MINT &operator/=(const MINT &r) noexcept {
        long long a = r.val, b = MOD, u = 1, v = 0;
        while (b) {
            long long t = a / b;
            a -= t * b;
            swap(a, b);
            u -= t * v;
            swap(u, v);
        }
        val = val * u % MOD;
        if (val < 0) val += MOD;
        return *this;
    }

    constexpr bool operator==(const MINT &r) const noexcept {
        return this->val == r.val;
    }

    constexpr bool operator!=(const MINT &r) const noexcept {
        return this->val != r.val;
    }

    friend constexpr ostream &operator<<(ostream &os, const MINT<MOD> &x) noexcept {
        return os << x.val;
    }

    friend constexpr MINT<MOD> modpow(const MINT<MOD> &a, long long n) noexcept {
        if (n == 0) return 1;
        auto t = modpow(a, n / 2);
        t = t * t;
        if (n & 1) t = t * a;
        return t;
    }
};


int main() {
    int N;
    cin >> N;

    using mint = MINT<MOD>;

    mint res = 0;
    vector<mint> vs;
    mint AA = 0;
    for (int i = 0; i < N; ++i) {
        int A;
        cin >> A;
        mint m = A;
        vs.push_back(m);
        AA = AA + A;
    }

    for (int i = 0; i < N - 1; ++i) {

        AA = AA - vs[i];
        mint tmp = vs[i] * AA;
        res = res + tmp;
    }
    cout << res << endl;
}
