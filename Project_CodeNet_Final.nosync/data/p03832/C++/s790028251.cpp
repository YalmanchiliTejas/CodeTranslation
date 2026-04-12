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
    ModInt(int x_) { if ((x = x_ % mod + mod) >= mod) x -= mod; }
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

using mint = ModInt<(int) 1e9 + 7>;

// https://blog.knshnb.com/posts/mujin_pc_2018_f/

mint fact[101010];
mint factinv[101010];

void init() {
    fact[0] = 1;
    for (int i = 1; i < 101010; i++) {
        fact[i] = fact[i - 1] * i;
    }
    factinv[101010 - 1] = fact[101010 - 1].inv();
    for (int i = 101010 - 2; i >= 0; i--) {
        factinv[i] = factinv[i + 1] * (i + 1);
    }
    assert(factinv[0] == 1);
}

mint choose(int n, int r) {
    return fact[n] * factinv[r] * factinv[n - r];
}

mint arrange(int n, int m) {
    return fact[n * m] * factinv[n] * pow(factinv[m], n);
}

int main() {
    init();
    int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;

    mint dp[1010][1010] = {};
    dp[a][n] = 1;
    vector<int> ds = {0};
    for (int i = c; i <= d; i++) {
        ds.push_back(i);
    }
    for (int i = a; i <= b; i++) {
        for (int j = 0; j <= n; j++) {
            for (int k : ds) {
                if (j - k * i < 0) break;
                dp[i + 1][j - k * i] += dp[i][j] * choose(j, k * i) * arrange(k, i);
            }
        }
    }
    cout << dp[b + 1][0] << endl;
}
