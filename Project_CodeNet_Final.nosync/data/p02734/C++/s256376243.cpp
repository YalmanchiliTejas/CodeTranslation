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

const long long MOD = 1e9+7;

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

//from https://github.com/spaghetti-source/algorithm/blob/master/number_theory/modular_arithmetics.cc
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

vector<int> a;

vector<vector<bool>> done(3001, vector<bool>(3001));
vector<vector<ModInt>> memo(3001, vector<ModInt>(3001));

ModInt solve(int r, int x) {
    if (x < 0) return ModInt(0);
    if (x == 0) return ModInt(r + 1);
    if (r == 0) return ModInt(0);
    if (done[r][x]) return memo[r][x];
    
    done[r][x] = true;
    return memo[r][x] = solve(r - 1, x) + solve(r - 1, x - a[r - 1]);
}

int main() {
    int n, s;
    cin >> n >> s;
    a.resize(n);
    cin >> a;
    
    ModInt ans;
    rep(i, n) {
        ModInt res = solve(i + 1, s);
        //cout << res << endl;
        ans += res;
    }
    cout << ans << endl;
}