#include <bits/stdc++.h>
using namespace std;

template<typename T>
T pow(T a, long long n, T e = 1) {
    T ret = e;
    while (n) {
        if (n & 1) ret *= a;
        a *= a;
        n >>= 1;
    }
    return ret;
}

template<int mod>
struct ModInt {
    int x;
    ModInt() : x(0) {}
    ModInt(long long x_) { if ((x = x_ % mod + mod) >= mod) x -= mod; }
    ModInt& operator+=(ModInt rhs) { if ((x += rhs.x) >= mod) x -= mod; return *this; }
    ModInt& operator-=(ModInt rhs) { if ((x -= rhs.x) < 0) x += mod; return *this; }
    ModInt& operator*=(ModInt rhs) { x = (unsigned long long) x * rhs.x % mod; return *this; }
    ModInt& operator/=(ModInt rhs) { x = (unsigned long long) x * rhs.inv().x % mod; return *this; }

    ModInt operator-() const { return -x < 0 ? mod - x : -x; }
    ModInt operator+(ModInt rhs) const { return ModInt(*this) += rhs; }
    ModInt operator-(ModInt rhs) const { return ModInt(*this) -= rhs; }
    ModInt operator*(ModInt rhs) const { return ModInt(*this) *= rhs; }
    ModInt operator/(ModInt rhs) const { return ModInt(*this) /= rhs; }
    bool operator==(ModInt rhs) const { return x == rhs.x; }
    bool operator!=(ModInt rhs) const { return x != rhs.x; }
    ModInt inv() const { return pow(*this, mod - 2); }

    friend ostream& operator<<(ostream& s, ModInt<mod> a) { s << a.x; return s; }
    friend istream& operator>>(istream& s, ModInt<mod>& a) { s >> a.x; return s; }
};

using mint = ModInt<1000000007>;

mint fact[202020];
mint factinv[202020];

void init() {
    fact[0] = 1;
    for (int i = 1; i < 202020; i++) {
        fact[i] = fact[i - 1] * i;
    }
    factinv[202020 - 1] = fact[202020 - 1].inv();
    for (int i = 202020 - 2; i >= 0; i--) {
        factinv[i] = factinv[i + 1] * (i + 1);
    }
    assert(factinv[0] == 1);
}

mint ncr(int n, int r) {
    return fact[n] * factinv[r] * factinv[n - r];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    init();
    int n, m, k;
    cin >> n >> m >> k;
    mint ans = ncr(n * m - 2, k - 2);

    mint coe = 0;
    for (int i = 1; i < n; i++) {
        coe += 1ll * i * m * m * (n - i);
    }
    for (int i = 1; i < m; i++) {
        coe += 1ll * i * n * n * (m - i);
    }
    cout << ans * coe << endl;
}