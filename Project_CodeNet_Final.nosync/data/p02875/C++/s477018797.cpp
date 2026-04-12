#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

struct modint {
    static constexpr int MOD = 998244353;
    ll v;

    bool operator==(const modint& other) const {
        return v == other.v;
    }

    modint& operator+=(const modint& other) {
        v += other.v;
        if (v >= MOD)
            v -= MOD;
        return *this;
    }

    modint& operator-=(const modint& other) {
        v -= other.v;
        if (v < 0)
            v += MOD;
        return *this;
    }

    modint& operator*=(const modint& other) {
        v = v * other.v % MOD;
        return *this;
    }

    modint& operator/=(const modint& other) {
        *this *= other.inv();
        return *this;
    }

    modint operator+(const modint& other) const {
        return modint { v } += other;
    }

    modint operator-(const modint& other) const {
        return modint { v } -= other;
    }

    modint operator*(const modint& other) const {
        return modint { v } *= other;
    }

    modint operator/(const modint& other) const {
        return modint { v } /= other;
    }

    static modint pow(modint b, ll e) {
        modint res { 1 };
        for (ll p = 1; p <= e; p <<= 1) {
            if (p & e)
                res *= b;
            b *= b;
        }

        return res;
    }

    modint pow(ll e) const {
        return pow(*this, e);
    }

    modint inv() const {
        return pow(MOD - 2);
    }

    friend ostream& operator<<(ostream& os, modint m) {
        return os << m.v;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    modint ans = modint::pow(modint { 3 }, n);
    modint cur = { 0 };
    modint term = { 1 };
    modint p = { 2 };
    // n choose k * 2^k for k in range()
    for (int k = n; k > n / 2; --k) {
        cur += term * p;
        // going from n!/k!(n-k)! to n!/(k-1)!(n-k+1)!
        // multiply by k/(n-k+1)
        term /= modint { n - k + 1 };
        term *= modint { k };
        p += p;
    }

    cout << ans - cur << '\n';
 
    return 0;
}
