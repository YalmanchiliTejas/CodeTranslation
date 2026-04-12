// #define _GLIBCXX_DEBUG
// #pragma GCC optimize("Ofast")
#pragma GCC diagnostic ignored "-Wsign-compare"
#include <bits/stdc++.h>
// #include <atcoder/all>
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define reps(i, s, n) for (int i = s; i < (int)(n); ++i)
#define rreps(i, s, n) for (int i = n - 1; (int)(s) <= i; --i)
// reps(s,n)[::-1]
using namespace std;
using ll = long long;
template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;
template <class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
template <class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
constexpr int INF = 1e9 + 7;
constexpr ll LINF = 1LL << 60;
class Prints {
private:
    class __Prints {
    public:
        __Prints(const char* _sep, const char* _term) : sep(_sep), term(_term) {}
        template <class... Args> void operator()(const Args&... args) const { print(args...); }
        template <typename T> void pvec(const T& vec, size_t sz) const {
            for (size_t i = 0; i < sz; i++) std::cout << vec[i] << (i == sz - 1 ? term : sep);
        }
        template <typename T> void pmat(const T& mat, size_t h, size_t w) {
            for (size_t i = 0; i < h; i++)
                for (size_t j = 0; j < w; j++) std::cout << mat[i][j] << (j == w - 1 ? term : sep);
        }

    private:
        const char *sep, *term;
        void print() const { std::cout << term; }
        void print_rest() const { std::cout << term; }
        template <class T, class... Tail> void print(const T& head, const Tail&... tail) const {
            std::cout << head, print_rest(tail...);
        }
        template <class T, class... Tail> void print_rest(const T& head, const Tail&... tail) const {
            std::cout << sep << head, print_rest(tail...);
        }
    };

public:
    Prints() {}
    __Prints operator()(const char* sep = " ", const char* term = "\n") const { return __Prints(sep, term); }
};

Prints print;

void solve() {
    ll a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    // x >= y とする
    if (x < y) {
        swap(a, b);
        swap(x, y);
    }
    ll ans = a * x + b * y;
    ans = min(c * 2 * x, ans);
    ans = min(c * 2 * y + (x - y) * a, ans);
    print()(ans);
}
int main() {
    cin.tie(nullptr);
    // ios_base::sync_with_stdio(false);
    // cout << fixed << setprecision(15);
    solve();
}