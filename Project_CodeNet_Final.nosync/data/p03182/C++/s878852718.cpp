#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef tuple<ll, ll, ll> iii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
#define REP(i,n) for (ll i = 0; i < n; ++i)
#define REPR(i,n) for (ll i = n-1; i >= 0; --i)
#define FOR(i,m,n) for (ll i = m; i < n; ++i)
#define FORR(i,m,n) for (ll i = n-1; i >= m; --i)
#define FORE(x,xs) for (const auto& x : xs)
#define FORI(i,v) for (auto i = v.begin(); i != v.end(); i++)
#define ALL(v) v.begin(), v.end()
#define CHMIN(x,y) x = min(x, y)
#define CHMAX(x,y) x = max(x, y)
#define YES(b) cout << ((b) ? "YES" : "NO") << endl
#define Yes(b) cout << ((b) ? "Yes" : "No") << endl

template<class T> class SegmentTree {
private:
    int SIZE;
    vector<T> node, lazy;
    T nodeZero, lazyZero;
    function<T(T&, T&)> nodeUpdate, lazyUpdate, nodeUpdateWithLazy;
    const function<T(T&, T&)> add_function = [](T& l, T& r) { return l+r; };

    void eval(int k) {
        if (lazy[k] == lazyZero) return;
        if(k*2+1 < SIZE*2-1) {
            lazy[2*k+1] = lazyUpdate(lazy[2*k+1], lazy[k]);
            lazy[2*k+2] = lazyUpdate(lazy[2*k+2], lazy[k]);
        }
        node[k] = nodeUpdateWithLazy(node[k], lazy[k]);
        lazy[k] = lazyZero;
    }

    T add(int a, int b, T x, int k, int l, int r) {
        eval(k);

        if (b <= l || r <= a) return node[k];
        if (a <= l && r <= b) {
            lazy[k] = lazyUpdate(lazy[k], x);
            return nodeUpdateWithLazy(node[k], lazy[k]);
        }
        T t1 = add(a, b, x, 2*k+1, l, (l+r)/2), t2 = add(a, b, x, 2*k+2, (l+r)/2, r);
        node[k] = nodeUpdate(t1, t2);
        return node[k];
    }

    T query(int a, int b, int k, int l, int r) {
        eval(k);

        if (a <= l && r <= b) return node[k];
        bool left = !((l+r)/2 <= a || b <= l), right = !(r <= 1 || b <= (l+r)/2);
        if (left && right) {
            T t1 = query(a, b, 2*k+1, l, (l+r)/2), t2 = query(a, b, 2*k+2, (l+r)/2, r);
            return nodeUpdate(t1, t2);
        }
        if (left) return query(a, b, 2*k+1, l, (l+r)/2);
        return query(a, b, 2*k+2, (l+r)/2, r);
    }

    void init(int n) {
        SIZE = 1;
        while (SIZE < n) SIZE *= 2;
        node.resize(2*SIZE, nodeZero);
        lazy.resize(2*SIZE, lazyZero);
    }

public:
    SegmentTree() {}
    SegmentTree(
        int n,
        T nodeZero,
        T lazyZero,
        function<T(T&, T&)> nodeUpdate,
        function<T(T&, T&)> lazyUpdate,
        function<T(T&, T&)> nodeUpdateWithLazy
    ) : nodeZero(nodeZero),
        lazyZero(lazyZero),
        nodeUpdate(nodeUpdate),
        lazyUpdate(lazyUpdate),
        nodeUpdateWithLazy(nodeUpdateWithLazy) {
            init(n);
    }

    T add(int a, int b, T x) { return add(a, b, x, 0, 0, SIZE); }
    T query(int a, int b) { return query(a, b, 0, 0, SIZE); }

    void set(int a, T x) {
        function<T(T&, T&)> tmp1 = lazyUpdate,
                            tmp2 = nodeUpdateWithLazy;
        lazyUpdate = nodeUpdateWithLazy = add_function;
        add(a, a+1, x-query(a, a+1));
        lazyUpdate = tmp1;
        nodeUpdateWithLazy = tmp2;
    }

    SegmentTree<T> maxTree(int n) const {
        SegmentTree<T> ret(
            n,
            numeric_limits<T>::lowest(),
            T(0),
            [](T& l, T& r) { return max(l,r); },
            [](T& l, T& r) { return l+r; },
            [](T& l, T& r) { return l+r; });
        return ret;
    }

    SegmentTree<T> minTree(int n) const {
        SegmentTree<T> ret(
            n,
            numeric_limits<T>::max(),
            T(0),
            [](T& l, T& r) { return min(l,r); },
            [](T& l, T& r) { return l+r; },
            [](T& l, T& r) { return l+r; });
        return ret;
    }

    SegmentTree<T> sumTree(int n) const {
        SegmentTree<T> ret(
            n,
            T(0),
            T(0),
            [](T& l, T& r) { return l+r; },
            [](T& l, T& r) { return l+r; },
            [](T& l, T& r) { return l+r; });
        return ret;
    }
};

const int MAX = 2e5+10;
 
int N, M;
int L[MAX], R[MAX], A[MAX];
 
ll solve() {
    vvii sec(N);
    REP (i, M) sec[R[i]-1].push_back(ii(L[i]-1, A[i]));
 
    SegmentTree<ll> tree = SegmentTree<ll>().maxTree(N+1);
    REP (i, N) {
        ll tmp = 0;
        if (i) CHMAX(tmp, tree.query(0, i));
        tree.set(i, tmp);
        FORE (s, sec[i]) tree.add(s.first, i+1, s.second);
    }
    return max(0ll, tree.query(0, N));
}
 
int main() {
    cin >> N >> M;
    REP (i, M) cin >> L[i] >> R[i] >> A[i];
    cout << solve() << endl;
}