#include <algorithm>
#include <cmath>
#include <complex>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
#include <functional>
#include <cstring>
#include <regex>
#include <random>
#include <cassert>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repr(i, s, n) for (int i = (s); i < (int)(n); i++)
#define revrep(i, n) for (int i = (n) - 1; i >= 0; i--)
#define revrepr(i, s, n) for (int i = (n) - 1; i >= s; i--)
#define debug(x) cerr << #x << ": " << x << "\n"
#define popcnt(x) __builtin_popcount(x)

using ll = long long;
using P = pair<int, int>;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

template<class T>
vector<T> make_vec(size_t a){
    return vector<T>(a);
}
template<class T, class... Ts>
auto make_vec(size_t a, Ts... ts){
    return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}

template<class T>
istream& operator >>(istream &is, vector<T> &v) {
    for (int i = 0; i < (int)v.size(); i++) cin >> v.at(i);
    return is;
}

template<class T, class U>
ostream& operator <<(ostream &os, pair<T, U> p) {
    cout << '(' << p.first << ", " << p.second << ')';
    return os;
}

template<class T>
void print(const vector<T> &v, const string &delimiter) { rep(i, v.size()) cout << (0 < i ? delimiter : "") << v.at(i); cout << endl; }

template<class T>
void print(const vector<vector<T>> &vv, const string &delimiter) { for (const auto &v: vv) print(v, delimiter); }

struct ModInt {
    static ll mod;
    ll val;
    ModInt(ll v = 0) : val(v % mod) {}
    ModInt operator-() const { return ModInt(val ? mod - val : val); }
    ModInt &operator+=(ModInt a) {
        if ((val += a.val) >= mod) val -= mod;
        return *this;
    }
    ModInt &operator-=(ModInt a) {
        if ((val -= a.val) < 0) val += mod;
        return *this;
    }
    ModInt &operator*=(ModInt a) {
        val = (__uint128_t(val) * a.val) % mod;
        return *this;
    }
    ModInt &operator/=(ModInt a) {
        ll u = 1, v = a.val, s = 0, t = mod;
        while (v) {
            ll q = t / v;
            swap(s -= u * q, u);
            swap(t -= v * q, v);
        }
        a.val = (s < 0 ? s + mod : s);
        val /= t;
        return (*this) *= a;
    }
    ModInt inv() const { return ModInt(1) /= (*this); }
    bool operator<(ModInt x) const { return val < x.val; }
};
ll ModInt::mod = 998244353;

ostream &operator<<(ostream &os, ModInt a) {
    os << a.val;
    return os;
}
ModInt operator+(ModInt a, ModInt b) { return a += b; }
ModInt operator-(ModInt a, ModInt b) { return a -= b; }
ModInt operator*(ModInt a, ModInt b) { return a *= b; }
ModInt operator/(ModInt a, ModInt b) { return a /= b; }
ModInt pow(ModInt a, ll e) {
    ModInt x(1);
    for (; e > 0; e /= 2) {
        if (e % 2 == 1) x *= a;
        a *= a;
    }
    return x;
}

ModInt comb(int n, int k) {
    ModInt x = 1, y = 1;
    rep(i, k) {
        x *= n - i;
        y *= i + 1;
    }
    return x / y;
}

ModInt dp[3001][3001][3];

int main() {
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    cin >> a;

    dp[0][0][0] = 1;
    rep(i, n) rep(x, s + 1) {
        rep(t, 3) dp[i + 1][x][t] += dp[i][x][t];
        rep(t, 2) dp[i + 1][x][t + 1] += dp[i][x][t];
        dp[i + 1][x][2] += dp[i][x][0];
        if (x + a[i] <= s) {
            rep(t, 2) dp[i + 1][x + a[i]][t + 1] += dp[i][x][t];
            dp[i + 1][x + a[i]][1] += dp[i][x][1];
            dp[i + 1][x + a[i]][2] += dp[i][x][0];
        }
    }
    cout << dp[n][s][2] << endl;
}