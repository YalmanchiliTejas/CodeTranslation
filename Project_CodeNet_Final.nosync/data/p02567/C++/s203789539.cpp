
#include <bits/stdc++.h>

#include <atcoder/all>
#define For(i, a, b) for (int(i) = (int)(a); (i) < (int)(b); ++(i))
#define rFor(i, a, b) for (int(i) = (int)(a)-1; (i) >= (int)(b); --(i))
#define rep(i, n) For((i), 0, (n))
#define rrep(i, n) rFor((i), (n), 0)
#define fi first
#define se second
using namespace std;
using namespace atcoder;
typedef long long lint;
typedef unsigned long long ulint;
typedef pair<int, int> pii;
typedef pair<lint, lint> pll;
template <class T>
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
template <class T>
bool chmin(T &a, const T &b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T>
T div_floor(T a, T b) {
    if (b < 0) a *= -1, b *= -1;
    return a >= 0 ? a / b : (a + 1) / b - 1;
}
template <class T>
T div_ceil(T a, T b) {
    if (b < 0) a *= -1, b *= -1;
    return a > 0 ? (a - 1) / b + 1 : a / b;
}

constexpr lint mod = 1000000007;
constexpr lint INF = mod * mod;
constexpr int MAX = 200010;

int op(int x, int y) { return max(x, y); }

int e() { return -1; }

int val;
bool f(int x) { return x < val; }

int main() {
    int n, q;
    scanf("%d%d", &n, &q);
    vector<int> a(n);
    rep(i, n) scanf("%d", &a[i]);
    segtree<int, op, e> st(a);
    rep(_, q) {
        int t;
        scanf("%d", &t);
        if (t == 1) {
            int x, v;
            scanf("%d%d", &x, &v);
            st.set(x - 1, v);
        } else if (t == 2) {
            int l, r;
            scanf("%d%d", &l, &r);
            printf("%d\n", st.prod(l - 1, r));
        } else {
            int x;
            scanf("%d%d", &x, &val);
            printf("%d\n", st.max_right<f>(x - 1) + 1);
        }
    }
}