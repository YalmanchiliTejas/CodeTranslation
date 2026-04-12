#pragma GCC target("avx2,avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long; 
using pii = pair<int, int>;
using pll = pair<long long, long long>;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()
constexpr char ln = '\n';

///////////////////////////////////////////////////////////////////////////

template<typename T, typename F>
struct SegmentTree {
  private:
    F op;
    T e;
    int _n, size ,log;
    vector<T> node;

  public:
    SegmentTree() {}
    SegmentTree(F op, T e, int n) : SegmentTree(op, e, vector<T>(n, e)) {}
    SegmentTree(F op, T e, const vector<T>& v) : op(op), e(e), _n(v.size()), log(0) {
        while ((1<<log) < _n) log++;
        size = 1 << log;
        node = vector<T> (2 * size, e);
        for (int i = 0; i < _n; i++) node[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }

    // (0-indexed)
    void set(int p, T x) {
        assert(0 <= p && p < _n);
        p += size;
        node[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    // [l, r) (0-indexed)
    T get(int l, int r) {
        if (l >= r) return e;
        T resl = e, resr = e;
        l += size; r += size;
        while (l < r) {
            if (l & 1) resl = op(resl, node[l++]);
            l >>= 1;
            if (r & 1) resr = op(node[--r], resr);
            r >>= 1;
        }
        return op(resl, resr);
    }

    T all_get() {return node[1];}

    template <typename C> 
    int max_right(int l, C check) {
        assert(0 <= l && l <= _n);
        assert(check(e));
        if (l == _n) return _n;
        l += size;
        T sm = e;
        do {
            while (~l & 1) l >>= 1;
            if (!check(op(sm, node[l]))) {
                while (l < size) {
                    l = (2 * l);
                    if (check(op(sm, node[l]))) {
                        sm = op(sm, node[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = op(sm, node[l]);
            l++;
        } while ((l & -l) != l);
        return _n;
    }

    template <typename C> 
    int min_left(int r, C check) {
        assert(0 <= r && r <= _n);
        assert(check(e));
        if (r == 0) return 0;
        r += size;
        T sm = e;
        do {
            r--;
            while (r > 1 && (r & 1)) r >>= 1;
            if (!check(op(node[r], sm))) {
                while (r < size) {
                    r = (2 * r + 1);
                    if (f(op(node[r], sm))) {
                        sm = op(node[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = op(node[r], sm);
        } while ((r & -r) != r);
        return 0;
    }

    T operator[](int p) {
        assert(0 <= p && p < _n);
        return node[p + size];
    }

  private:

    void update(int k) { node[k] = op(node[2 * k], node[2 * k + 1]); }
};

//////////////////////////////////////////////////////////////////////////////////////

void yosupo() {
    int N,Q; cin >> N >> Q;
    vector<ll> A(N);
    rep(i,N) cin >> A[i];

    auto f=[](ll a, ll b) {return a+b;};
    const ll id = 0;
    SegmentTree seg(f,id,A);
    while (Q--) {
        int t; cin >> t;
        if (t) {
            int l,r; cin >> l >> r;
            cout << seg.get(l,r) << ln;
        } else {
            int p,x; cin >> p >> x;
            seg.set(p,seg[p]+x);
        }
    }
}

void practice2_j() {
    int N,Q; cin >> N >> Q;
    vector<int> A(N);
    rep(i,N) cin >> A[i];

    auto f=[](int a, int b) {return max(a,b);};
    const int id = -1;
    SegmentTree seg(f,id,A);

    while (Q--) {
        int t; cin >> t;
        if (t==1) {
            int x,v; cin >> x >> v;
            x--;
            seg.set(x,v);
        } else if (t==2) {
            int l,r; cin >> l >> r;
            l--;
            cout << seg.get(l,r) << ln;
        } else {
            int x,v; cin >> x >> v;
            x--;
            auto check=[&](int val) {return v > val;};
            cout << seg.max_right(x,check)+1 << ln;
        }
    }
}

void DSL_2_G() {
}

int main() {
    //yosupo();
    practice2_j();
    //DSL_2_G();
}

/*
  verified on 2020/05/26
  https://judge.yosupo.jp/problem/point_add_range_sum
  https://atcoder.jp/contests/practice2/tasks/practice2_j
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G&lang=ja
*/
