#include <atcoder/all>
using namespace atcoder;
// >>> TEMPLATES
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using i32 = int32_t;
using i64 = int64_t;
using u32 = uint32_t;
using u64 = uint64_t;
#define int ll
#define double ld
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define rep1(i,n) for (int i = 1; i <= (int)(n); i++)
#define repR(i,n) for (int i = (int)(n)-1; i >= 0; i--)
#define rep1R(i,n) for (int i = (int)(n); i >= 1; i--)
#define loop(i,a,B) for (int i = a; i B; i++)
#define loopR(i,a,B) for (int i = a; i B; i--)
#define all(x) begin(x), end(x)
#define allR(x) rbegin(x), rend(x)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fst first
#define snd second
template <class Int> auto constexpr inf = numeric_limits<Int>::max()/2-1;
auto constexpr INF32 = inf<int32_t>;
auto constexpr INF64 = inf<int64_t>;
auto constexpr INF   = inf<int>;
#ifdef LOCAL
#include "debug.hpp"
#else
#define dump(...) (void)(0)
#define say(x) (void)(0)
#define debug if (0)
#endif
template <class T> using pque_max = priority_queue<T>;
template <class T> using pque_min = priority_queue<T, vector<T>, greater<T> >;
template <class T, class = typename T::iterator, class = typename enable_if<!is_same<T, string>::value>::type>
ostream& operator<<(ostream& os, T const& v) { bool f = true; for (auto const& x : v) os << (f ? "" : " ") << x, f = false; return os; }
template <class T, class = typename T::iterator, class = typename enable_if<!is_same<T, string>::value>::type>
istream& operator>>(istream& is, T &v) { for (auto& x : v) is >> x; return is; }
template <class T, class S> ostream& operator<<(ostream& os, pair<T,S> const& p) { return os << "(" << p.first << ", " << p.second << ")"; }
template <class T, class S> istream& operator>>(istream& is, pair<T,S>& p) { return is >> p.first >> p.second; }
struct IOSetup { IOSetup() { cin.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(15); } } iosetup;
template <class F> struct FixPoint : private F {
    constexpr FixPoint(F&& f) : F(forward<F>(f)) {}
    template <class... T> constexpr auto operator()(T&&... x) const { return F::operator()(*this, forward<T>(x)...); }
};
struct MakeFixPoint {
    template <class F> constexpr auto operator|(F&& f) const { return FixPoint<F>(forward<F>(f)); }
};
#define MFP MakeFixPoint()|
#define def(name, ...) auto name = MFP [&](auto &&name, __VA_ARGS__)
template <class T, size_t d> struct vec_impl {
    using type = vector<typename vec_impl<T,d-1>::type>;
    template <class... U> static type make_v(size_t n, U&&... x) { return type(n, vec_impl<T,d-1>::make_v(forward<U>(x)...)); }
};
template <class T> struct vec_impl<T,0> { using type = T; static type make_v(T const& x = {}) { return x; } };
template <class T, size_t d = 1> using vec = typename vec_impl<T,d>::type;
template <class T, size_t d = 1, class... Args> auto make_v(Args&&... args) { return vec_impl<T,d>::make_v(forward<Args>(args)...); }
template <class T> void quit(T const& x) { cout << x << endl; exit(0); }
template <class T, class U> constexpr bool chmin(T& x, U const& y) { if (x > y) { x = y; return true; } return false; }
template <class T, class U> constexpr bool chmax(T& x, U const& y) { if (x < y) { x = y; return true; } return false; }
template <class It> constexpr auto sumof(It b, It e) {
    using S = typename iterator_traits<It>::value_type;
    using T = conditional_t<is_signed_v<S>,i64,u64>;
    return accumulate(b,e,T{});
}
template <class T> int sz(T const& x) { return x.size(); }
template <class C, class T> int lbd(C const& v, T const& x) {
    return lower_bound(v.begin(), v.end(), x)-v.begin();
}
template <class C, class T> int ubd(C const& v, T const& x) {
    return upper_bound(v.begin(), v.end(), x)-v.begin();
}
const int dx[] = { 1,0,-1,0 };
const int dy[] = { 0,1,0,-1 };
constexpr int popcnt(ll x) { return __builtin_popcountll(x); }
template <class Int> Int rand(Int a, Int b) { // [a,b]
    static mt19937_64 mt{random_device{}()};
    return uniform_int_distribution<Int>(a,b)(mt);
}
i64 irand(i64 a, i64 b) { return rand<i64>(a,b); }
u64 urand(u64 a, u64 b) { return rand<u64>(a,b); }
// <<<
template <class A> using Segtree = segtree<typename A::Value, A::merge, A::unit>;

struct Max {
    using Value = int;
    constexpr static Value unit() { return -INF; }
    constexpr static Value merge(Value x, Value y) { return max(x,y); }
};

int32_t main() {
    int n,q; cin >> n >> q;
    vector<int> a(n); cin >> a;

    Segtree<Max> seg(a);
    rep (_,q) {
        int t,x,y; cin >> t >> x >> y;
        if (t == 1) {
            --x;
            seg.set(x,y);
        }
        if (t == 2) {
            --x;
            cout << seg.prod(x,y) << "\n";
        }
        if (t == 3) {
            --x;
            cout << seg.max_right(x,[&](int val) { return val < y; }) + 1 << "\n";
        }

    }

}
