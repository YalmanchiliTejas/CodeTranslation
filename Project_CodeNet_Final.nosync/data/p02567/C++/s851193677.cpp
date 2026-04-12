#include <bits/stdc++.h>
using namespace std;

// #include <atcoder/convolution>
// #include <atcoder/dsu>
// #include <atcoder/fenwicktree>
// #include <atcoder/lazysegtree>
// #include <atcoder/math>
// #include <atcoder/maxflow>
// #include <atcoder/mincostflow>
// #include <atcoder/modint>
// #include <atcoder/scc>

#include <algorithm>

#ifdef _MSC_VER
#include <intrin.h>
#endif

namespace atcoder {

namespace internal {

// @param n `0 <= n`
// @return minimum non-negative `x` s.t. `n <= 2**x`
int ceil_pow2(int n) {
    int x = 0;
    while ((1U << x) < (unsigned int)(n)) x++;
    return x;
}

// @param n `1 <= n`
// @return minimum non-negative `x` s.t. `(n & (1 << x)) != 0`
int bsf(unsigned int n) {
#ifdef _MSC_VER
    unsigned long index;
    _BitScanForward(&index, n);
    return index;
#else
    return __builtin_ctz(n);
#endif
}

}  // namespace internal

}  // namespace atcoder

#include <cassert>
#include <vector>

namespace atcoder {

template <class S, S (*op)(S, S), S (*e)()> struct segtree {
  public:
    segtree() : segtree(0) {}
    segtree(int n) : segtree(std::vector<S>(n, e())) {}
    segtree(const std::vector<S>& v) : _n(int(v.size())) {
        log = internal::ceil_pow2(_n);
        size = 1 << log;
        d = std::vector<S>(2 * size, e());
        for (int i = 0; i < _n; i++) d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }

    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    S get(int p) {
        assert(0 <= p && p < _n);
        return d[p + size];
    }

    S prod(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        S sml = e(), smr = e();
        l += size;
        r += size;

        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }
        return op(sml, smr);
    }

    S all_prod() { return d[1]; }

    template <bool (*f)(S)> int max_right(int l) {
        return max_right(l, [](S x) { return f(x); });
    }
    template <class F> int max_right(int l, F f) {
        assert(0 <= l && l <= _n);
        assert(f(e()));
        if (l == _n) return _n;
        l += size;
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!f(op(sm, d[l]))) {
                while (l < size) {
                    l = (2 * l);
                    if (f(op(sm, d[l]))) {
                        sm = op(sm, d[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = op(sm, d[l]);
            l++;
        } while ((l & -l) != l);
        return _n;
    }

    template <bool (*f)(S)> int min_left(int r) {
        return min_left(r, [](S x) { return f(x); });
    }
    template <class F> int min_left(int r, F f) {
        assert(0 <= r && r <= _n);
        assert(f(e()));
        if (r == 0) return 0;
        r += size;
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!f(op(d[r], sm))) {
                while (r < size) {
                    r = (2 * r + 1);
                    if (f(op(d[r], sm))) {
                        sm = op(d[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = op(d[r], sm);
        } while ((r & -r) != r);
        return 0;
    }

  private:
    int _n, size, log;
    std::vector<S> d;

    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
};

}  // namespace atcoder

// #include <atcoder/string>
// #include <atcoder/twosat>
using namespace atcoder;

using ld = long double;
#define int long long

#define F first
#define S second
#define s(x) set<x>
#define um(x, y) unordered_map<x, y>
#define m(x, y) map<x, y>
#define p(x, y) pair<x, y>
#define v(x) vector<x>
#define min_heap(t) priority_queue<t, vector<t>, greater<t>>
#define max_heap(t) priority_queue<t>

#define eb emplace_back
#define mp make_pair
#define bs binary_search
#define lb lower_bound
#define ub upper_bound

#define all(v) v.begin(), v.end()
#define ss(v) stable_sort(all(v))
#define fori(i, a, b) for (int i = a; i <= b; i++)
#define rofi(i, a, b) for (int i = a; i >= b; --i)
#define scn(v1)        \
    for (auto &x : v1) \
        cin >> x;
#define deb(x) cout << #x << "=" << x << endl;
#define R(x) reverse(all(x));

#define FILE_READ_IN freopen("input.txt", "r", stdin);
#define FILE_READ_OUT freopen("output.txt", "w", stdout);

#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define stprs(x) cout << fixed << setprecision(x);

const char nl = '\n';
const char sp = ' ';
const int mod1 = 1e9 + 7;
const int mod2 = 998244353;
const ld PI = acos(-1);

#define debug cerr
#define name(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

template<class A>
ostream& operator << (ostream& out, const set<A> &a) {
    out << "[";
    for (auto it = a.begin(); it != a.end(); ++it) {
        if (it != a.begin())
            out << ", ";
        out << *it;
    }
    return out << "]";
}

template<class A>
ostream& operator << (ostream& out, const vector<A> &a) {
    // out << "[";
    for (auto it = a.begin(); it != a.end(); ++it) {
        if (it != a.begin())
            // out << ", ";
            out << ' ';
        out << *it;
    }
    return out;
    return out << "]";
}

template<class A, class B>
ostream& operator << (ostream& out, const pair<A, B> &a) {
    return out <<  "(" << a.first << ", " << a.second << ")";
}

template<class A, class B>
ostream& operator << (ostream& out, const map<A, B> &a) {
    out << "[";
    for (auto it = a.begin(); it != a.end(); ++it) {
        if (it != a.begin()) {
            out << ", ";
        }
        out << *it;
    }
    return out << "]";
}
template<class A, class B>
ostream& operator << (ostream& out, const unordered_map<A, B> &a) {
    out << "[";
    for (auto it = a.begin(); it != a.end(); ++it) {
        if (it != a.begin()) {
            out << ", ";
        }
        out << *it;
    }
    return out << "]";
}

template<typename... T>
void read(T&... args) {
    ((cin >> args), ...);
}

template<typename... T>
void print(T... args) {
    ((cout << args), ...);
}

// variables and consts
// -- variables and consts --

int e() {
    return (int)(-1);
}

int op(int a, int b) {
    return max(a, b);
}

int target;

bool f(int a) {
    return a < target;
}

void solve(void) {
    int n, q;
    read(n, q);
    v(int) v1(n); scn(v1);
    segtree<int, op, e> st(v1);
    while (q--) {
        int t;
        read(t);
        if (t == 1) {
            int x, v;
            read(x, v);
            -- x;
            st.set(x, v);
        } else if (t == 2) {
            int l, r;
            read(l, r);
            print(st.prod(l-1, r), nl);
        } else {
            int p;
            read(p, target);
            -- p;
            print(st.max_right<f>(p)+1, nl);
        }
    }
}

int32_t main(void) {
    fastio
    int __ = 1;
    // read(__);
    while (__--) {
        solve();
    }
    return 0;
}
