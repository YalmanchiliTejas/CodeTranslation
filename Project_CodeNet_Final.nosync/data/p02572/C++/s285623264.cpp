#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define reps(i, n) for (int i = 1; i <= (n); ++i)
#define repd(i, n) for (int i = (n)-1; i >= 0; --i)
#define repds(i, n) for (int i = (n); i > 0; --i)
#define loop(i, x, n) for (int i = (x); i < (n); ++i)
#define loops(i, x, n) for (int i = (x); i <= (n); ++i)
#define loopd(i, x, n) for (int i = (x); i > (n); --i)
#define loopds(i, x, n) for (int i = (x); i >= (n); --i)
#define itrep(i, a) for (auto i = begin(a); i != end(a); ++i)
#define itrepd(i, a) for (auto i = rbegin(a); i != rend(a); ++i)
#define each(i, x) for (auto &&i : x)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(a) ((int)a.size())
#define pow2(n) (n * n)
#define int ll
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
template <class T>
using p_queue = priority_queue<T, vector<T>, greater<T>>;
constexpr ll inf = static_cast<ll>(1e18);
constexpr int iinf = static_cast<int>(1e9);
constexpr double dinf = 1e10;
constexpr ld ldinf = 1e18;
constexpr double eps = 1e-8;
ll mod = static_cast<ll>(1e9 + 7);
template <class T, class... Args>
constexpr void mins(T &a, Args... args) { a = min<T>({a, args...}); }
template <class T, class... Args>
constexpr void maxs(T &a, Args... args) { a = max<T>({a, args...}); }
template <class F>
class FixPoint : private F {
public:
    explicit constexpr FixPoint(F &&f) : F(std::forward<F>(f)) {}
    template <class... Args>
    constexpr decltype(auto) operator()(Args &&... args) const { return F::operator()(*this, std::forward<Args>(args)...); }
};
template <class F>
constexpr decltype(auto) funcs(F &&f) { return FixPoint<F>{std::forward<F>(f)}; }
template <class T>
std::vector<T> vecs(int n, T &&val) { return std::vector<T>(std::forward<int>(n), std::forward<T>(val)); }
template <class... Args>
decltype(auto) vecs(int n, Args &&... args) { return std::vector<decltype(vecs(std::forward<Args>(args)...))>(std::forward<int>(n), vecs(std::forward<Args>(args)...)); }
template <class V, class T>
void fill(V &x, const T &val) { x = val; }
template <class V, class T>
void fill(vector<V> &vec, const T &val) {
    for (auto &&v : vec)
        fill(v, val);
}

template <class T>
struct ModInt {
    T x;
    ModInt(T x = 0) : x((x + mod) % mod) {}
    ModInt &operator+=(const ModInt a) {
        if ((x += a.x) >= mod) x -= mod;
        return *this;
    }
    ModInt &operator-=(const ModInt a) {
        if ((x += mod - a.x) >= mod) x -= mod;
        return *this;
    }
    ModInt &operator*=(const ModInt a) {
        (x *= a.x) %= mod;
        return *this;
    }
    ModInt operator+(const ModInt a) const {
        ModInt res(*this);
        return res += a;
    }
    ModInt operator-(const ModInt a) const {
        ModInt res(*this);
        return res -= a;
    }
    ModInt operator*(const ModInt a) const {
        ModInt res(*this);
        return res *= a;
    }
    ModInt pow(T t) const {
        if (!t) return 1;
        ModInt a = pow(t >> 1);
        a *= a;
        if (t & 1) a *= *this;
        return a;
    }
    ModInt inv() const {
        return pow(mod - 2);
    }
    ModInt &operator/=(const ModInt a) {
        return (*this) *= a.inv();
    }
    ModInt operator/(const ModInt a) const {
        ModInt res(*this);
        return res /= a;
    }
};
template <class T>
std::ostream &operator<<(std::ostream &os, const ModInt<T> &m) {
    return os << m.x;
}
using mint = ModInt<long long>;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    mint ans = 0, sum = 0;
    rep(i, n) {
        ans += mint(a[i]) * sum;
        sum += a[i];
    }
    cout << ans << endl;
}

signed main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
    cout.flush();
    return 0;
}