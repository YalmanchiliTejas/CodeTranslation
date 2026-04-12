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

void solve() {
    int n;
    cin >> n;
    if (n >= 30)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}

signed main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
    cout.flush();
    return 0;
}