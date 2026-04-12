#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, n) for (int i = 0; i < (int) (n); i++)
#define reps(i, n) for (int i = 1; i <= (int) (n); i++)
#define all(x) (x).begin(), (x).end()
#define uniq(x) (x).erase(unique(all(x)), (x).end())
#define bit(n) (1LL << (n))
#define cdiv(a, b) (((a) - 1) / (b) + 1)
#define dump(x) cerr << #x " = " << (x) << endl
using vint = vector<int>;
using vvint = vector<vint>;
using pint = pair<int, int>;
using vpint = vector<pint>;
template<typename T> using priority_queue_rev = priority_queue<T, vector<T>, greater<T>>;
constexpr double PI = 3.1415926535897932384626433832795028;
constexpr int DY[8] = {0, 1, 0, -1, 1, 1, -1, -1};
constexpr int DX[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int gcd(int a, int b) {
    while (b) { swap(a %= b, b); }
    return a;
}
int lcm(int a, int b) { return a / gcd(a, b) * b; }
template<typename T> void fin(T mes) {
    cout << mes << endl;
    exit(0);
}
template<typename T, typename U> bool chmax(T &a, const U &b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
template<typename T, typename U> bool chmin(T &a, const U &b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}
template<typename T, typename U> ostream &operator<<(ostream &os, const pair<T, U> &rhs) {
    os << "(" << rhs.first << ", " << rhs.second << ")";
    return os;
}
template<typename T> ostream &operator<<(ostream &os, const vector<T> &rhs) {
    os << "{";
    for (auto itr = rhs.begin(); itr != rhs.end(); itr++) {
        os << *itr << (next(itr) != rhs.end() ? ", " : "");
    }
    os << "}";
    return os;
}
struct setup {
    static constexpr int PREC = 20;
    setup() {
        cout << fixed << setprecision(PREC);
        cerr << fixed << setprecision(PREC);
    };
} setup;

#include <vector>
#include <cassert>
#include <limits>

/*
 * @title 遅延評価セグメント木
 * @docs docs/data-structure/lazy-segment-tree.md
 */

template<typename M>
struct lazy_segment_tree {
    using T = typename M::T;
    using E = typename M::E;
    int n;
    std::vector<T> data;
    std::vector<E> lazy;
    lazy_segment_tree(int n) : n(n), data(n << 1, M::id_T()), lazy(n << 1, M::id_E()) {}
    lazy_segment_tree(const std::vector<T> &src) : n(src.size()), data(n << 1), lazy(n << 1, M::id_E()) {
        std::copy(src.begin(), src.end(), data.begin() + n);
        for (int i = n - 1; i > 0; i--) { data[i] = M::op_TT(data[i << 1 | 0], data[i << 1 | 1]); }
    }
    void propagate(int i) {
        if (i < 1) { return; }
        data[i] = M::op_TE(data[i], lazy[i]);
        if (i < n) {
            lazy[i << 1 | 0] = M::op_EE(lazy[i << 1 | 0], lazy[i]);
            lazy[i << 1 | 1] = M::op_EE(lazy[i << 1 | 1], lazy[i]);
        }
        lazy[i] = M::id_E();
    }
    void add(int l, int r, const E &x) {
        assert(0 <= l && l <= n);
        assert(0 <= r && r <= n);
        l += n, r += n - 1;
        for (int i = std::__lg(r); i > 0; i--) {
            propagate(l >> i);
            propagate(r >> i);
        }
        auto apply = [&](int i) { lazy[i] = M::op_EE(lazy[i], x), propagate(i); };
        for (int i = l, j = r + 1; i < j; i >>= 1, j >>= 1) {
            if (i & 1) { apply(i++); }
            if (j & 1) { apply(--j); }
        }
        while (l >>= 1, r >>= 1) {
            data[l] = M::op_TT(M::op_TE(data[l << 1 | 0], lazy[l << 1 | 0]),
                               M::op_TE(data[l << 1 | 1], lazy[l << 1 | 1]));
            data[r] = M::op_TT(M::op_TE(data[r << 1 | 0], lazy[r << 1 | 0]),
                               M::op_TE(data[r << 1 | 1], lazy[r << 1 | 1]));
        }
    }
    T get_sum(int l, int r) {
        assert(0 <= l && l <= n);
        assert(0 <= r && r <= n);
        l += n, r += n - 1;
        for (int i = std::__lg(r); i > 0; i--) { propagate(l >> i), propagate(r >> i); }
        T a = M::id_T(), b = M::id_T();
        for (r++; l < r; l >>= 1, r >>= 1) {
            if (l & 1) { propagate(l), a = M::op_TT(a, data[l++]); }
            if (r & 1) { propagate(--r), b = M::op_TT(data[r], b); }
        }
        return M::op_TT(a, b);
    }
};

struct rmaxq_and_raq {
    using T = long long;
    using E = long long;
    static T id_T() { return std::numeric_limits<T>::min(); };
    static E id_E() { return 0; };
    static T op_TT(const T &a, const T &b) { return std::max(a, b); }
    static E op_EE(const E &a, const E &b) { return a + b; }
    static T op_TE(const T &a, const E &b) { return a + b; }
};

int N, M;
int l[220000], r[220000], a[220000];
tuple<int, int, int> lra[220000];
signed main() {
    cin >> N >> M;
    rep(i, M) {
        cin >> l[i] >> r[i] >> a[i];
        l[i]--, r[i]--;
        lra[i] = {l[i], r[i], a[i]};
    }
    sort(lra, lra + M), reverse(lra, lra + M);
    lazy_segment_tree<rmaxq_and_raq> lst(vint(N + 1, 0));
    int cur = 0;
    for (int i = N - 1; i >= 0; i--) {
        lst.add(i, i + 1, lst.get_sum(i + 1, N + 1));
        while (cur < M && get<0>(lra[cur]) == i) {
            lst.add(i, get<1>(lra[cur]) + 1, get<2>(lra[cur]));
            cur++;
        }
    }
    cout << lst.get_sum(0, N + 1) << endl;
}