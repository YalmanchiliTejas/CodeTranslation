#include <bits/stdc++.h>
#define ALL(obj) begin(obj), end(obj)
#define debug(x) cerr << #x << ": " << x << '\n'
using namespace std;
template <class T>
vector<T> make_vec(size_t a) {
    return vector<T>(a);
}
template <class T, class... Ts>
auto make_vec(size_t a, Ts... ts) {
    return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}
template <class T>
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}

using ll = long long;
using ull = unsigned long long;
const int INF = 1e9;
// const int MOD = 1e9 + 7;

template <int mod>
struct ModInt {
    int val;
    ModInt() : val(0) {}
    ModInt(long long x) : val(x >= 0 ? x % mod : (mod - (-x) % mod) % mod) {}
    int getmod() { return mod; }
    ModInt &operator+=(const ModInt &p) {
        if ((val += p.val) >= mod) {
            val -= mod;
        }
        return *this;
    }
    ModInt &operator-=(const ModInt &p) {
        if ((val += mod - p.val) >= mod) {
            val -= mod;
        }
        return *this;
    }
    ModInt &operator*=(const ModInt &p) {
        val = (int)(1LL * val * p.val % mod);
        return *this;
    }
    ModInt &operator/=(const ModInt &p) {
        *this *= p.inverse();
        return *this;
    }
    ModInt operator-() const { return ModInt(-val); }
    ModInt operator+(const ModInt &p) const { return ModInt(*this) += p; }
    ModInt operator-(const ModInt &p) const { return ModInt(*this) -= p; }
    ModInt operator*(const ModInt &p) const { return ModInt(*this) *= p; }
    ModInt operator/(const ModInt &p) const { return ModInt(*this) /= p; }
    bool operator==(const ModInt &p) const { return val == p.val; }
    bool operator!=(const ModInt &p) const { return val != p.val; }
    ModInt inverse() const {
        int a = val, b = mod, u = 1, v = 0, t;
        while (b > 0) {
            t = a / b;
            swap(a -= t * b, b);
            swap(u -= t * v, v);
        }
        return ModInt(u);
    }
    ModInt pow(long long n) const {
        ModInt ret(1), mul(val);
        while (n > 0) {
            if (n & 1) ret *= mul;
            mul *= mul;
            n >>= 1;
        }
        return ret;
    }
    friend ostream &operator<<(ostream &os, const ModInt &p) { return os << p.val; }
    friend istream &operator>>(istream &is, ModInt &a) {
        long long t;
        is >> t;
        a = ModInt<mod>(t);
        return (is);
    }
    static int get_mod() { return mod; }
};
const int MOD = 998244353;  // if inv is needed, this shold be prime.
using modint = ModInt<MOD>;

modint dp[3005][6005];
int main() {
    int N, S;
    cin >> N >> S;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A.at(i);
    }

    for (int i = 0; i < N; i++) {
        dp[i][0] += 1;
        for (int s = 0; s <= S; s++) {
            dp[i + 1][s] += dp[i][s];
            dp[i + 1][s + A[i]] += dp[i][s];
        }
    }
    modint ans(0);
    for (int i = 0; i < N; i++) {
        ans += dp[i + 1][S];
    }

    cout << ans << endl;
}
