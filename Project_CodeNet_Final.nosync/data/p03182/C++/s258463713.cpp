#include <algorithm>
#include <cstdint>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, s, t) for (int i = s; i < t; i++)
#define ALL(obj) obj.begin(), obj.end()

const int iINF = 1e9;
const long long llINF = 1e18;
const int MOD = 1e9 + 7;
template <class T>
inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}

template <int MOD>
struct ModInt {
    long long val;
    constexpr ModInt(long long v = 0) noexcept : val(v % MOD) {
        if (val < 0) val += MOD;
    }
    constexpr int getmod() { return MOD; }
    constexpr ModInt operator-() const noexcept { return val ? MOD - val : 0; }
    constexpr ModInt operator+(const ModInt& r) const noexcept { return ModInt(*this) += r; }
    constexpr ModInt operator-(const ModInt& r) const noexcept { return ModInt(*this) -= r; }
    constexpr ModInt operator*(const ModInt& r) const noexcept { return ModInt(*this) *= r; }
    constexpr ModInt operator/(const ModInt& r) const noexcept { return ModInt(*this) /= r; }
    constexpr ModInt& operator+=(const ModInt& r) noexcept {
        val += r.val;
        if (val >= MOD) val -= MOD;
        return *this;
    }
    constexpr ModInt& operator-=(const ModInt& r) noexcept {
        val -= r.val;
        if (val < 0) val += MOD;
        return *this;
    }
    constexpr ModInt& operator*=(const ModInt& r) noexcept {
        val = val * r.val % MOD;
        return *this;
    }
    constexpr ModInt& operator/=(const ModInt& r) noexcept {
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
    constexpr bool operator==(const ModInt& r) const noexcept { return this->val == r.val; }
    constexpr bool operator!=(const ModInt& r) const noexcept { return this->val != r.val; }
    friend constexpr ostream& operator<<(ostream& os, const ModInt<MOD>& x) noexcept { return os << x.val; }

    friend constexpr istream& operator>>(istream& is, ModInt<MOD>& x) noexcept { return is >> x.val; }
    friend constexpr ModInt<MOD> modpow(const ModInt<MOD>& a, long long n) noexcept {
        if (n == 0) return 1;
        auto t = modpow(a, n / 2);
        t = t * t;
        if (n & 1) t = t * a;
        return t;
    }
};

using mint = ModInt<MOD>;

long long modPow(long long x, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return res;
}

long long extGCD(long long a, long long b, long long& x, long long& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    long long d = extGCD(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

long long gcd(long long a, long long b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }

template <typename T>
map<T, int> compress(vector<T> x) {
    map<T, int> res;
    sort(x.begin(), x.end());
    x.erase(unique(x.begin(), x.end()), x.end());
    for (int i = 0; i < x.size(); i++) {
        res[x[i]] = i;
    }

    return res;
}

template <typename T>
int former(const vector<T>& v, T x) {
    return upper_bound(v.begin(), v.end(), x) - v.begin() - 1;
}

template <typename T>
int latter(const vector<T>& v, T x) {
    return lower_bound(v.begin(), v.end(), x) - v.begin();
}

template <typename T>
using Vec = vector<T>;
template <typename T>
using VVec = vector<vector<T>>;
using LL = long long;

template <typename MonoidType, typename OperatorType>
struct LazySegmentTree {
    using MMtoM = function<MonoidType(MonoidType, MonoidType)>;
    using OOtoO = function<OperatorType(OperatorType, OperatorType)>;
    using MOtoM = function<MonoidType(MonoidType, OperatorType)>;
    using OItoO = function<OperatorType(OperatorType, int)>;

    // node, lazy, update flag (for lazy), identity element
    int n;
    vector<MonoidType> node;
    vector<OperatorType> lazy;
    vector<bool> need_update;
    MonoidType E0;
    OperatorType E1;

    // update / combine / lazy / accumulate function
    MOtoM upd_f;
    MMtoM cmb_f;
    OOtoO lzy_f;
    OItoO acc_f;

    void build(int m, vector<MonoidType> v = vector<MonoidType>()) {
        if (v != vector<MonoidType>()) m = v.size();
        n = 1;
        while (n < m) n *= 2;

        node = vector<MonoidType>(2 * n - 1, E0);
        lazy = vector<OperatorType>(2 * n - 1, E1);
        need_update = vector<bool>(2 * n - 1, false);
        if (v != vector<MonoidType>()) {
            for (int i = 0; i < m; i++) {
                node[n - 1 + i] = v[i];
            }
            for (int i = n - 2; i >= 0; i--) {
                node[i] = cmb_f(node[2 * i + 1], node[2 * i + 2]);
            }
        }
    }

    // initialize
    LazySegmentTree() {}
    LazySegmentTree(int n_, MonoidType E0_, OperatorType E1_, MOtoM upd_f_, MMtoM cmb_f_, OOtoO lzy_f_, OItoO acc_f_,
                    vector<MonoidType> v = vector<MonoidType>())
        : E0(E0_), E1(E1_), upd_f(upd_f_), cmb_f(cmb_f_), lzy_f(lzy_f_), acc_f(acc_f_) {
        build(n_, v);
    }

    void eval(int k, int l, int r) {
        if (!need_update[k]) return;
        node[k] = upd_f(node[k], acc_f(lazy[k], r - l));
        if (r - l > 1) {
            lazy[2 * k + 1] = lzy_f(lazy[2 * k + 1], lazy[k]);
            lazy[2 * k + 2] = lzy_f(lazy[2 * k + 2], lazy[k]);
            need_update[2 * k + 1] = need_update[2 * k + 2] = true;
        }
        lazy[k] = E1;
        need_update[k] = false;
    }

    void update(int a, int b, OperatorType x, int l, int r, int k) {
        eval(k, l, r);
        if (b <= l or r <= a) return;
        if (a <= l and r <= b) {
            lazy[k] = lzy_f(lazy[k], x);
            need_update[k] = true;
            eval(k, l, r);
        } else {
            int mid = (l + r) / 2;
            update(a, b, x, l, mid, 2 * k + 1);
            update(a, b, x, mid, r, 2 * k + 2);
            node[k] = cmb_f(node[2 * k + 1], node[2 * k + 2]);
        }
    }

    MonoidType query(int a, int b, int l, int r, int k) {
        if (b <= l or r <= a) return E0;
        eval(k, l, r);
        if (a <= l and r <= b) return node[k];
        int mid = (l + r) / 2;
        MonoidType vl = query(a, b, l, mid, 2 * k + 1);
        MonoidType vr = query(a, b, mid, r, 2 * k + 2);
        return cmb_f(vl, vr);
    }

    // update [a, b)-th element (applied value, x)
    void update(int a, int b, OperatorType x) { update(a, b, x, 0, n, 0); }

    // range query for [a, b)
    MonoidType query(int a, int b) { return query(a, b, 0, n, 0); }
};
int main() {
    int N, M;
    cin >> N >> M;
    VVec<pair<int, LL>> p(N + 1, Vec<pair<int, LL>>());
    REP(i, M) {
        int l, r;
        LL a;
        cin >> l >> r >> a;
        l--;
        p[r].push_back(make_pair(l, a));
    }
    LazySegmentTree<LL, LL> dp(N + 1, -llINF, 0,
        [](LL a, LL b) { return a + b; },
        [](LL a, LL b) { return max(a, b); },
        [](LL a, LL b) { return a + b; },
        [](LL a, int x) { return a; });

    dp.update(0, 1, -dp.query(0, 1));
    FOR(i, 1, N + 1) {
        LL A = 0;
        for (auto pp : p[i]) A += pp.second;
        LL ma = dp.query(0, i);
        dp.update(i, i + 1, ma + A - dp.query(i, i + 1));
        for (auto pp : p[i]) {
            int l = pp.first;
            LL a = pp.second;
            dp.update(l + 1, i, a);
        }
    }
    cout << dp.query(0, N + 1) << endl;
    return 0;
}