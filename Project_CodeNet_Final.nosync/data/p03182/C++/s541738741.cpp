#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int inf = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3fLL;

template <typename T, typename E = T>
class LazySegmentTree
{
public:
    LazySegmentTree(int n, const T &tunit, const E &eunit) : _tunit(tunit), _eunit(eunit)
    {
        _n = 1 << __lg(2 * n - 1);
        _data.resize(2 * _n - 1, tunit);
        _lazy.resize(2 * _n - 1, eunit);
    }

    void set(int k, const T &x) { _data[k + _n - 1] = x; }

    void build(void)
    {
        for (int i = _n - 2; i >= 0; i--) _data[i] = f(_data[2 * i + 1], _data[2 * i + 2]);
    }

    void update(int a, int b, const E &x) { return _update(a, b, x, 0, 0, _n); }

    T query(int a, int b) { return _query(a, b, 0, 0, _n); }

private:
    int _n;             // 要素数
    vector<T> _data;    // データを格納する配列
    vector<E> _lazy;    // 遅延評価するデータを格納する配列
    T _tunit;
    E _eunit;

    T f(const T &a, const T &b) { return max(a, b); }
    T g(const T &a, const E &b) { return a + b; }
    E h(const E &a, const E &b) { return a + b; }

    void eval(int k)
    {
        if (_lazy[k] == _eunit) return;
        if (k < _n - 1) {
            _lazy[2 * k + 1] = h(_lazy[2 * k + 1], _lazy[k]);
            _lazy[2 * k + 2] = h(_lazy[2 * k + 2], _lazy[k]);
        }
        _data[k] = g(_data[k], _lazy[k]);
        _lazy[k] = _eunit;
    }

    void _update(int a, int b, const E &x, int k, int l, int r)
    {
        eval(k);
        if (a <= l && r <= b) {
            _lazy[k] = h(_lazy[k], x); eval(k);
        } else if (a < r && l < b) {
            _update(a, b, x, 2 * k + 1, l, (l + r) >> 1);
            _update(a, b, x, 2 * k + 2, (l + r) >> 1, r);
            _data[k] = f(_data[2 * k + 1], _data[2 * k + 2]);
        }
    }

    T _query(int a, int b, int k, int l, int r)
    {
        eval(k);
        if (r <= a || b <= l) {
            return _tunit;
        } else if (a <= l && r <= b) {
            return _data[k];
        } else {
            T left = _query(a, b, k * 2 + 1, l, (l + r) >> 1);
            T right = _query(a, b, 2 * k + 2, (l + r) >> 1, r);
            return f(left, right);
        }
    }
};

struct S {
    int l, r; ll a;
    bool operator<(const S &rhs) const { return r < rhs.r; }
};

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m; cin >> n >> m;
    vector<S> v(m);
    for (int i = 0; i < m; i++) {
        cin >> v[i].l >> v[i].r >> v[i].a;
    }

    sort(v.begin(), v.end());

    LazySegmentTree<ll> seg(n + 1, 0, 0);
    for (int i = 0, j = 0; i < m && j <= n; j++) {
        seg.update(j, j + 1, seg.query(0, j));
        while (j == v[i].r) {
            seg.update(v[i].l, j + 1, v[i].a);
            i++;
        }
    }

    ll ans = seg.query(0, n + 1);
    cout << ans << endl;
    return 0;
}
