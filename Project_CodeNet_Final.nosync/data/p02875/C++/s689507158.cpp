#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <class T> using treap = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
using Int = long long;
#define REP(i, n) for (long long i = 0, max_i = (n); i < max_i; i++)
#define REPI(i, a, b) for (long long i = (a), max_i = (b); i < max_i; i++)
#define ALL(obj) begin(obj), end(obj)
#define RALL(obj) rbegin(obj), rend(obj)
#define fi first
#define se second
using ii = pair<Int, Int>;
vector<ii> dirs = {
    {1, 0}, {0, 1}, {-1, 0}, {0, -1},  // 4方向
    {1, 1}, {-1, 1}, {-1, -1}, {1, -1},  // 斜め
    {0, 0},  // 自身
};
Int get_msb(long long x) {
    assert(x != 0);
    return 63 - __builtin_clzll(x);
}
Int get_lsb(long long x) {
    assert(x != 0);
    return __builtin_ctzll(x);
}
template <class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return true; } return false; }
template <class T> inline bool chmin(T& a, const T& b) { if (a > b) { a = b; return true; } return false; }
template <class T, class S> vector<T> make_vec(size_t n, S x) { return vector<T>(n, x); }
template <class T, class... Ts> auto make_vec(size_t n, Ts... ts) { return vector<decltype(make_vec<T>(ts...))>(n, make_vec<T>(ts...)); }

// debug
template <class T> ostream& operator<<(ostream& s, const vector<T>& d) { REP (i, d.size()) s << d[i] << (i == d.size() - 1 ? "" : " "); return s; }
template <class T> ostream& operator<<(ostream& s, const vector<vector<T>>& d) { REP (i, d.size()) s << d[i] << (i == d.size() - 1 ? "" : "\n"); return s; }
template <class T, class S> ostream& operator<<(ostream& s, const pair<T, S>& p) { s << "{" << p.first << ", " << p.second << "}"; return s; }
template <class T> ostream& operator<<(ostream& s, const set<T> m) { for (auto it = m.begin(); it != m.end(); it++) { s << *it << (next(it) == m.end() ? "" : "\n"); } return s; }
template <class T> ostream& operator<<(ostream& s, const multiset<T> m) { for (auto it = m.begin(); it != m.end(); it++) { s << *it << (next(it) == m.end() ? "" : "\n"); } return s; }
template <class T, class S> ostream& operator<<(ostream& s, const map<T, S> m) { for (auto it = m.begin(); it != m.end(); it++) { s << *it << (next(it) == m.end() ? "" : "\n"); } return s; }
template <class T, class S> ostream& operator<<(ostream& s, const unordered_map<T, S> m) { for (auto it = m.begin(); it != m.end(); it++) { s << *it << (next(it) == m.end() ? "" : "\n"); } return s; }
#ifdef _MY_DEBUG
    #define dump(...) cerr << "/* " << #__VA_ARGS__ << " :[" << __LINE__ << ":" << __FUNCTION__ << "]" << endl, dump_func(__VA_ARGS__), cerr << "*/\n\n";
#else
    #define dump(...)
    #define endl "\n"
#endif
void dump_func() { cerr << endl; }
template <class Head, class... Tail> void dump_func(Head&& h, Tail&&... t) { cerr << h << (sizeof...(Tail) == 0 ? "" : ", "), dump_func(forward<Tail>(t)...); }

struct FastIO { FastIO() { cin.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(20); } } fast_io;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
constexpr Int MOD = 998244353;
// **********************************************************************************************
// **********************************************************************************************
// **********************************************************************************************
// **************************************** TEMPLATE END ****************************************
// **********************************************************************************************
// **********************************************************************************************
// **********************************************************************************************

template <class T>
T pow(T x, int n, const T UNION = 1) {
    T ret = UNION;
    while (n) {
        if (n & 1) ret *= x;
        x *= x;
        n >>= 1;
    }
    return ret;
}

template <int MD>
struct ModInt {
    int x;
    static unordered_map<int, int> to_inv;
    ModInt() : x(0) {}
    ModInt(long long x_) {
        if ((x = x_ % MD + MD) >= MD) x -= MD;
    }

    ModInt& operator+=(ModInt that) {
        if ((x += that.x) >= MD) x -= MD;
        return *this;
    }
    ModInt& operator*=(ModInt that) {
        x = (unsigned long long)x * that.x % MD;
        return *this;
    }
    ModInt& operator-=(ModInt that) {
        if ((x -= that.x) < 0) x += MD;
        return *this;
    }
    ModInt& operator/=(ModInt that) {
        x = (unsigned long long)x * that.inv().x % MD;
        return *this;
    }

    ModInt operator-() const { return -x < 0 ? MD - x : -x; }
    ModInt operator+(ModInt that) const { return ModInt(*this) += that; }
    ModInt operator*(ModInt that) const { return ModInt(*this) *= that; }
    ModInt operator-(ModInt that) const { return ModInt(*this) -= that; }
    ModInt operator/(ModInt that) const { return ModInt(*this) /= that; }
    bool operator==(ModInt that) const { return x == that.x; }
    bool operator!=(ModInt that) const { return x != that.x; }
    ModInt inv() const { return to_inv.count(this->x) ? to_inv[this->x] : (to_inv[this->x] = pow(*this, MD - 2).x); }
    friend ostream& operator<<(ostream& s, ModInt<MD> a) {
        s << a.x;
        return s;
    }
    friend istream& operator>>(istream& s, ModInt<MD>& a) {
        s >> a.x;
        return s;
    }
};
template <int MD>
unordered_map<int, int> ModInt<MD>::to_inv;
using mint = ModInt<MOD>;

vector<mint> fact, fact_inv;
void init_factorial(int n) {
    fact = vector<mint>(n + 1, 1);
    fact_inv = vector<mint>(n + 1);
    for (int i = 0; i < n; i++) fact[i + 1] = fact[i] * (i + 1);
    fact_inv[n] = mint(1) / fact[n];
    for (int i = n - 1; i >= 0; i--) fact_inv[i] = fact_inv[i + 1] * (i + 1);
    // for (int i = 0; i < n + 1; i++) assert(fact[i] * fact_inv[i] == 1);
}
mint comb(int n, int r) { return fact[n] * fact_inv[r] * fact_inv[n - r]; }

signed main() {
    Int n; cin >> n;
    if (n % 2) {
        cout << 0 << endl;
        return 0;
    }
    vector<mint> pows(n + 1, 1);
    REP (i, n) pows[i + 1] = pows[i] * 2;
    init_factorial(n + 1);
    mint ans = pow(mint(3), n);
    REP (x, n / 2) {
        ans -= comb(n, x) * pows[x] * 2;
    }
    cout << ans << endl;
}
