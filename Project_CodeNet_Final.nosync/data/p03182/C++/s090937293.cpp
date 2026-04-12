#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...) 0
#endif

template <class T>
struct segtree {
    int n;
    T def = 0;
    vector<T> node, lazy;
    vector<bool> flag;
    function<T(T, T)> f = [](T a, T b) { return max(a, b); };  // node-node
    function<T(T, T)> g = [](T a, T b) { return a + b; };      // node-lazy if add a + b

    segtree(int _n) {
        n = 1;
        while (n < _n) n *= 2;
        node.resize(2 * n - 1, def);
        lazy.resize(2 * n - 1);
        flag.resize(2 * n - 1, false);
    }
    segtree(vector<T> a) {
        n = 1;
        while (n < a.size()) n *= 2;
        node.resize(2 * n - 1, def);
        lazy.resize(2 * n - 1);
        flag.resize(2 * n - 1, false);
        for (int i = 0; i < a.size(); i++) node[i + n - 1] = a[i];
        for (int i = n - 2; i >= 0; i--)
            node[i] = f(node[i * 2 + 1], node[i * 2 + 2]);
    }

    inline void eval(int k, int l, int r) {
        if (!flag[k]) return;
        node[k] = g(node[k], lazy[k]);
        if (r - l > 1) {
            lazy[k * 2 + 1] = g(lazy[k * 2 + 1], lazy[k]);
            lazy[k * 2 + 2] = g(lazy[k * 2 + 2], lazy[k]);
            flag[k * 2 + 1] = flag[k * 2 + 2] = true;
        }
        lazy[k] = 0;
        flag[k] = false;
    }
    inline void update(int a, int b, T v, int k, int l, int r) {
        eval(k, l, r);
        if (b <= l || r <= a) return;
        if (a <= l && r <= b) {
            lazy[k] = g(lazy[k], v);
            flag[k] = true;
            eval(k, l, r);
        } else {
            update(a, b, v, 2 * k + 1, l, (l + r) / 2);
            update(a, b, v, 2 * k + 2, (l + r) / 2, r);
            node[k] = f(node[2 * k + 1], node[2 * k + 2]);
        }
    }
    inline T get(int a, int b, int k, int l, int r) {
        if (r < 0) r = n;
        eval(k, l, r);
        if (b <= l || r <= a) return def;
        if (a <= l && r <= b) return node[k];
        T vl = get(a, b, 2 * k + 1, l, (l + r) / 2);
        T vr = get(a, b, 2 * k + 2, (l + r) / 2, r);
        return f(vl, vr);
    }
    inline void update(int a, int b, T v) {
        update(a, b, v, 0, 0, n);
    }
    inline T get(int a, int b) {
        return get(a, b, 0, 0, n);
    }
    inline T get(int a) {
        return get(a, a + 1, 0, 0, n);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<pair<ll, ll>>> x(n + 2);
    rep(i, 0, m) {
        ll l, r, a;
        cin >> l >> r >> a;
        x[r].emplace_back(l, a);
    }
    segtree<ll> st(n + 2);
    rep(i, 1, n + 1) {
        ll tmp = 0;
        if (i) tmp = max(tmp, st.get(0, i));
        st.update(i, i + 1, tmp);
        for (auto p : x[i]) {
            st.update(p.first, i + 1, p.second);
        }
    }
    cout << max(0ll, st.get(0, n + 2)) << endl;
    return 0;
}