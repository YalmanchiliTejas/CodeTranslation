#include <bits/stdc++.h>
using namespace std;
template <class T> inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T> inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return 1;
    }
    return 0;
}
using ll = long long;

#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
#define endl "\n"
const double EPS = 1e-7;
const int INF = 1 << 30;
const ll LLINF = 1LL << 60;
const double PI = acos(-1);
constexpr int MOD = 1000000007;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

//-------------------------------------

template <int mod> struct ModInt {
    int x;

    ModInt() : x(0) {}

    ModInt(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}

    ModInt &operator+=(const ModInt &p) {
        if((x += p.x) >= mod)
            x -= mod;
        return *this;
    }

    ModInt &operator-=(const ModInt &p) {
        if((x += mod - p.x) >= mod)
            x -= mod;
        return *this;
    }

    ModInt &operator*=(const ModInt &p) {
        x = (int)(1LL * x * p.x % mod);
        return *this;
    }

    ModInt &operator/=(const ModInt &p) {
        *this *= p.inverse();
        return *this;
    }

    ModInt operator-() const { return ModInt(-x); }

    ModInt operator+(const ModInt &p) const { return ModInt(*this) += p; }

    ModInt operator-(const ModInt &p) const { return ModInt(*this) -= p; }

    ModInt operator*(const ModInt &p) const { return ModInt(*this) *= p; }

    ModInt operator/(const ModInt &p) const { return ModInt(*this) /= p; }

    bool operator==(const ModInt &p) const { return x == p.x; }

    bool operator!=(const ModInt &p) const { return x != p.x; }

    ModInt inverse() const {
        int a = x, b = mod, u = 1, v = 0, t;
        while(b > 0) {
            t = a / b;
            swap(a -= t * b, b);
            swap(u -= t * v, v);
        }
        return ModInt(u);
    }

    ModInt pow(int64_t n) const {
        ModInt ret(1), mul(x);
        while(n > 0) {
            if(n & 1)
                ret *= mul;
            mul *= mul;
            n >>= 1;
        }
        return ret;
    }

    friend ostream &operator<<(ostream &os, const ModInt &p) {
        return os << p.x;
    }

    friend istream &operator>>(istream &is, ModInt &a) {
        int64_t t;
        is >> t;
        a = ModInt<mod>(t);
        return (is);
    }

    static int get_mod() { return mod; }
};

using mint = ModInt<MOD>;

struct Combination {
    vector<mint> fac, finv, inv;
    int MAX;
    Combination(int _MAX) : MAX(_MAX), fac(_MAX), finv(_MAX), inv(_MAX) {
        init();
    }
    void init() {
        fac[0] = fac[1] = finv[0] = finv[1] = 1;
        inv[0] = mint(0).inverse();
        inv[1] = mint(1).inverse();
        for(int i = 2; i < MAX; i++) {
            fac[i] = fac[i - 1] * mint(i);
            inv[i] = mint(i).inverse();
            finv[i] = finv[i - 1] * mint(i).inverse();
        }
    }
    mint COM(int n, int k) {
        if(n < k || n < 0 || k < 0) {
            return 0;
        }
        return fac[n] * finv[k] * finv[n - k];
    }
    mint factorial(int n) { return fac[n]; }
    mint facinv(int n) { return finv[n]; }
    mint inverse(int n) { return inv[n]; }
};

Combination comb(200200);

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m, k;
    cin >> n >> m >> k;
    mint ans = 0;
    for(int i = 0; i < n; i++) {
        ans += mint(i) * mint(n - i) * mint(m).pow(2);
    }
    for(int i = 0; i < m; i++) {
        ans += mint(i) * mint(m - i) * mint(n).pow(2);
    }
    ans *= comb.COM(n * m - 2, k - 2);
    cout << ans << endl;
}