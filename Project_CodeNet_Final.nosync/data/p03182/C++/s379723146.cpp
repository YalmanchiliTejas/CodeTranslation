#define CPP_IO

#pragma region

#ifdef LOCAL
#define debug cout
#else
#define debug \
    if (0) cout
#endif

#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
using ll = long long;

template <typename T>
ostream& operator<<(ostream& os, vector<T> v) {
    os << "[ ";
    for (auto e : v) os << e << " ";
    return os << "]";
}

template <typename T, typename V>
ostream& operator<<(ostream& os, set<T, V> v) {
    os << "{ ";
    for (auto e : v) os << e << " ";
    return os << "}";
}

template <typename T, typename V, typename S>
ostream& operator<<(ostream& os, map<T, V, S> v) {
    os << "{ ";
    for (auto e : v) os << e << " ";
    return os << "}";
}

template <typename T, typename V>
ostream& operator<<(ostream& os, pair<T, V> x) {
    return os << "( " << x.first << ", " << x.second << " )";
}

template <typename T>
istream& operator>>(istream& is, vector<T>& v) {
    for (auto& e : v) is >> e;
    return is;
}

template <typename T, typename V>
istream& operator>>(istream& is, pair<T, V>& x) {
    return is >> x.first >> x.second;
}

template <typename T>
T divfloor(T a, T b) {
    assert(b != 0);
    if (a >= 0 && b > 0 || a <= 0 && b < 0) return a / b;
    return (a % b == 0) ? a / b : a / b - 1;
}

template <typename T>
T divceil(T a, T b) {
    assert(b != 0);
    if (a >= 0 && b > 0 || a <= 0 && b < 0) return (a % b == 0) ? a / b : a / b + 1;
    return a / b;
}

void solve();

int main() {
#ifdef LOCAL
    freopen("data.txt", "r", stdin);
#else
#ifdef CPP_IO
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
#endif
    solve();
}

#pragma endregion

/**
 * Status: Tested
 * Supports adding x to [l, r] and querying minimum in [l, r]
 */
template <typename U>
struct max_query_add_update_node {
    U lazy, mx;
    max_query_add_update_node()
        : lazy(0), mx(0) {
    }
    max_query_add_update_node(U x)
        : lazy(0), mx(x) {
    }
    max_query_add_update_node(max_query_add_update_node a, max_query_add_update_node b)
        : mx(max(a.mx, b.mx)), lazy(0) {
    }
    bool islazy() const {
        return lazy != 0;
    }
    void apply(U x) {
        mx += x;
        lazy += x;
    }
    void update_child(max_query_add_update_node& u) const {
        u.apply(lazy);
    }
    void unlazy() {
        lazy = 0;
    }
};

/**
 * Status: Tested
 * Lazy segment tree
 * T is the node type
 * U is the update type
 */
template <typename T, typename U>
class lazy_segtree {
   public:
    lazy_segtree(int n)
        : n(n), t(vector<T>(4 * n)) {
    }

    // Pass iterators [begin, end) of any type S such that T has constructor T(S)
    template <typename InputIterator>
    lazy_segtree(InputIterator begin, InputIterator end)
        : n(end - begin), t(vector<T>(4 * n)) {
        function<void(int, int, int)> build = [&](int u, int tl, int tr) {
            if (tl == tr)
                t[u] = T(*(begin + tl));
            else {
                int tm = (tl + tr) / 2;
                build(2 * u, tl, tm);
                build(2 * u + 1, tm + 1, tr);
                t[u] = T(t[2 * u], t[2 * u + 1]);
            }
        };
        build(1, 0, n - 1);
    }

    void update(int l, int r, U v) {
        update(1, 0, n - 1, l, r, v);
    }

    T query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }

   private:
    int n;
    vector<T> t;

    void pushdown(int u, int tl, int tr) {
        if (t[u].islazy() && tl != tr) {
            t[u].update_child(t[2 * u]);
            t[u].update_child(t[2 * u + 1]);
            t[u].unlazy();
        }
    }

    T query(int u, int tl, int tr, int l, int r) {
        pushdown(u, tl, tr);
        if (l <= tl && tr <= r) return t[u];
        int tm = (tl + tr) / 2;
        if (tm < l)
            return query(2 * u + 1, tm + 1, tr, l, r);
        if (tm >= r)
            return query(2 * u, tl, tm, l, r);
        return T(query(2 * u, tl, tm, l, r), query(2 * u + 1, tm + 1, tr, l, r));
    }

    void update(int u, int tl, int tr, int l, int r, U v) {
        pushdown(u, tl, tr);
        if (l <= tl && tr <= r) return t[u].apply(v);
        int tm = (tl + tr) / 2;
        if (l <= tm) update(2 * u, tl, tm, l, r, v);
        if (tm + 1 <= r) update(2 * u + 1, tm + 1, tr, l, r, v);
        t[u] = T(t[2 * u], t[2 * u + 1]);
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<ii>> add(n + 1);
    for (int i = 0; i < m; ++i) {
        int l, r, a;
        cin >> l >> r >> a;
        add[r].push_back({a, l});
    }
    lazy_segtree<max_query_add_update_node<ll>, ll> tree(n + 1);
    ll f;
    for (int i = 1; i <= n; ++i) {
        for (auto p : add[i]) tree.update(p.second, i, 1LL * p.first);
        f = tree.query(0, i).mx;
        tree.update(i + 1, i + 1, f);
    }
    cout << f << "\n";
}