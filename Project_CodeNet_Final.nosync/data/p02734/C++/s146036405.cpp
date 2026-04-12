/* #region Head */

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pll = pair<ll, ll>;
template <class T> using vc = vector<T>;
template <class T> using vvc = vc<vc<T>>;
using vll = vc<ll>;
using vvll = vvc<ll>;
using vld = vc<ld>;
using vvld = vvc<ld>;
using vs = vc<string>;
using vvs = vvc<string>;
template <class T, class U> using um = unordered_map<T, U>;
template <class T> using pq = priority_queue<T>;
template <class T> using pqa = priority_queue<T, vc<T>, greater<T>>;

#define REP(i, m, n) for (ll i = (m), i##_len = (ll)(n); i < i##_len; ++(i))
#define REPM(i, m, n) for (ll i = (m), i##_max = (ll)(n); i <= i##_max; ++(i))
#define REPR(i, m, n) for (ll i = (m), i##_min = (ll)(n); i >= i##_min; --(i))
#define REPD(i, m, n, d) for (ll i = (m), i##_len = (ll)(n); i < i##_len; i += (d))
#define REPMD(i, m, n, d) for (ll i = (m), i##_max = (ll)(n); i <= i##_max; i += (d))
#define REPI(itr, ds) for (auto itr = ds.begin(); itr != ds.end(); itr++)
#define ALL(x) begin(x), end(x)
#define SIZE(x) ((ll)(x).size())
#define PERM(c)                                                                                                        \
    sort(ALL(c));                                                                                                      \
    for (bool c##p = 1; c##p; c##p = next_permutation(ALL(c)))
#define UNIQ(v) v.erase(unique(ALL(v)), v.end());

#define endl '\n'
#define sqrt sqrtl
#define floor floorl
#define log2 log2l

constexpr ll INF = 1'010'000'000'000'000'017LL;
constexpr ll MOD = 998244353LL; // 1e9 + 7
constexpr ld EPS = 1e-12;
constexpr ld PI = 3.14159265358979323846;

// vector 入力
template <typename T> istream &operator>>(istream &is, vc<T> &vec) {
    for (T &x : vec) is >> x;
    return is;
}

// vector 出力 (for dump)
template <typename T> ostream &operator<<(ostream &os, vc<T> &vec) {
    ll len = SIZE(vec);
    os << "{";
    for (int i = 0; i < len; i++) os << vec[i] << (i == len - 1 ? "" : ", ");
    os << "}";
    return os;
}

// vector 出力 (inline)
template <typename T> ostream &operator>>(ostream &os, vc<T> &vec) {
    ll len = SIZE(vec);
    for (int i = 0; i < len; i++) os << vec[i] << (i == len - 1 ? "\n" : " ");
    return os;
}

// pair 入力
template <typename T, typename U> istream &operator>>(istream &is, pair<T, U> &pair_var) {
    is >> pair_var.first >> pair_var.second;
    return is;
}

// pair 出力
template <typename T, typename U> ostream &operator<<(ostream &os, pair<T, U> &pair_var) {
    os << "(" << pair_var.first << ", " << pair_var.second << ")";
    return os;
}

// map 出力
template <typename T, typename U> ostream &operator<<(ostream &os, map<T, U> &map_var) {
    os << "{";
    REPI(itr, map_var) {
        os << *itr;
        itr++;
        if (itr != map_var.end()) os << ", ";
        itr--;
    }
    os << "}";
    return os;
}

// um 出力
template <typename T, typename U> ostream &operator<<(ostream &os, um<T, U> &map_var) {
    os << "{";
    REPI(itr, map_var) {
        os << *itr;
        auto itrcp = itr;
        itrcp++;
        if (itrcp != map_var.end()) os << ", ";
    }
    os << "}";
    return os;
}

// set 出力
template <typename T> ostream &operator<<(ostream &os, set<T> &set_var) {
    os << "{";
    REPI(itr, set_var) {
        os << *itr;
        itr++;
        if (itr != set_var.end()) os << ", ";
        itr--;
    }
    os << "}";
    return os;
}

// dump
#define DUMPOUT cerr
void dump_func() { DUMPOUT << endl; }
template <class Head, class... Tail> void dump_func(Head &&head, Tail &&... tail) {
    DUMPOUT << head;
    if (sizeof...(Tail) > 0) {
        DUMPOUT << ", ";
    }
    dump_func(move(tail)...);
}

// chmax (更新「される」かもしれない値が前)
template <typename T, typename U, typename Comp = less<>> bool chmax(T &xmax, const U &x, Comp comp = {}) {
    if (comp(xmax, x)) {
        xmax = x;
        return true;
    }
    return false;
}

// chmin (更新「される」かもしれない値が前)
template <typename T, typename U, typename Comp = less<>> bool chmin(T &xmin, const U &x, Comp comp = {}) {
    if (comp(x, xmin)) {
        xmin = x;
        return true;
    }
    return false;
}

// ローカル用
#define DEBUG_

#ifdef DEBUG_
#define DEB
#define dump(...)                                                                                                      \
    DUMPOUT << "  " << string(#__VA_ARGS__) << ": "                                                                    \
            << "[" << to_string(__LINE__) << ":" << __FUNCTION__ << "]" << endl                                        \
            << "    ",                                                                                                 \
        dump_func(__VA_ARGS__)
#else
#define DEB if (false)
#define dump(...)
#endif

struct AtCoderInitialize {
    static constexpr int IOS_PREC = 15;
    static constexpr bool AUTOFLUSH = false;

    AtCoderInitialize() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        cout << fixed << setprecision(IOS_PREC);
        if (AUTOFLUSH) cout << unitbuf;
    }
} ATCODER_INITIALIZE;

string yes = "Yes", no = "No";
// string yes = "YES", no = "NO";

/* #endregion */

/* #region mint */

// 自動で MOD を取る整数
struct mint {
    ll x;
    mint(ll x = 0) : x((x % MOD + MOD) % MOD) {}
    mint &operator+=(const mint a) {
        if ((x += a.x) >= MOD) x -= MOD;
        return *this;
    }
    mint &operator-=(const mint a) {
        if ((x += MOD - a.x) >= MOD) x -= MOD;
        return *this;
    }
    mint &operator*=(const mint a) {
        (x *= a.x) %= MOD;
        return *this;
    }
    mint operator+(const mint a) const {
        mint res(*this);
        return res += a;
    }
    mint operator-(const mint a) const {
        mint res(*this);
        return res -= a;
    }
    mint operator*(const mint a) const {
        mint res(*this);
        return res *= a;
    }
    // O(log(t))
    mint pow(ll t) const {
        if (!t) return 1;
        mint a = pow(t >> 1); // ⌊t/2⌋ 乗
        a *= a;               // ⌊t/2⌋*2 乗
        if (t & 1)            // ⌊t/2⌋*2 == t-1 のとき
            a *= *this;       // ⌊t/2⌋*2+1 乗 => t 乗
        return a;
    }

    // for prime mod
    mint inv() const {
        return pow(MOD - 2); // オイラーの定理から， x^(-1) ≡ x^(p-2)
    }
    mint &operator/=(const mint a) { return (*this) *= a.inv(); }
    mint operator/(const mint a) const {
        mint res(*this);
        return res /= a;
    }
    bool operator==(const mint a) const { return this->x == a.x; }
    bool operator==(const ll a) const { return this->x == a; }

    // mint 入力
    friend istream &operator>>(istream &is, mint &x) {
        is >> x.x;
        return is;
    }

    // mint 出力
    friend ostream &operator<<(ostream &os, mint x) {
        os << x.x;
        return os;
    }
};

/* #endregion */

/**
Problem
 */
void solve() {
    ll n, s;
    cin >> n >> s;
    vll a(n);
    cin >> a;

    vc<vc<vc<mint>>> dp(n + 1, vc<vc<mint>>(s + 1, vc<mint>(3, 0)));
    dp[0][0][0] = 1;
    REP(i, 0, n) {
        dp[i + 1][0][0] = dp[i][0][0];
        REPM(j, 0, s) {
            // dump(i, j);
            dp[i + 1][j][1] = dp[i][j][1] + dp[i][j][0];
            dp[i + 1][j][2] = dp[i][j][2] + dp[i][j][1];
            if (j - a[i] >= 0) {
                dp[i + 1][j][1] += dp[i][j - a[i]][0] + dp[i][j - a[i]][1];
                // dp[i + 1][j][2] += dp[i][j - a[i]][1] + dp[i][j - a[i]][2];
            }
        }
    }
    // dump(dp[n][s]);
    cout << accumulate(ALL(dp[n][s]), mint(0)) << endl;
}

/**
 * エントリポイント．
 * @return 0.
 */
int main() {
    solve();
    return 0;
}
