// #define _GLIBCXX_DEBUG // for STL debug (optional)
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <cstring>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <complex>
#include <cmath>
#include <limits>
#include <cfloat>
#include <climits>
#include <ctime>
#include <cassert>
#include <numeric>
#include <fstream>
#include <functional>
#include <bitset>
using namespace std;
using ll = long long int;
using int64 = long long int;
 
template<typename T> void chmax(T &a, T b) {a = max(a, b);}
template<typename T> void chmin(T &a, T b) {a = min(a, b);}
template<typename T> void chadd(T &a, T b) {a = a + b;}
 
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
const int INF = 1LL << 29;
const ll LONGINF = 1LL << 60;
const ll MOD = 1000000007LL;

template <typename MonoidType, typename OperatorType>
struct LazySegmentTree {
    using MMtoM = function< MonoidType(MonoidType, MonoidType) >;
    using OOtoO = function< OperatorType(OperatorType, OperatorType) >;
    using MOtoM = function< MonoidType(MonoidType, OperatorType) >;
    using OItoO = function< OperatorType(OperatorType, int) >;

    // node, lazy, update flag (for lazy), identity element
    int n;
    vector<MonoidType> node;
    vector<OperatorType> lazy;
    vector<bool> need_update;
    MonoidType E0;
    OperatorType E1;

    // update / combine / lazy / accumulate function
    MOtoM upd_f;
    MMtoM cmb_f;
    OOtoO lzy_f;
    OItoO acc_f;

    void build(int m, vector<MonoidType> v = vector<MonoidType>()) {
        if(v != vector<MonoidType>()) m = v.size();
        n = 1; while(n < m) n *= 2;

        node = vector<MonoidType>(2*n-1, E0);
        lazy = vector<OperatorType>(2*n-1, E1);
        need_update = vector<bool>(2*n-1, false);
        if(v != vector<MonoidType>()) {
            for(int i=0; i<m; i++) {
                node[n-1+i] = v[i];
            }
            for(int i=n-2; i>=0; i--) {
                node[i] = cmb_f(node[2*i+1], node[2*i+2]);
            }
        }
    }

    // initialize
    LazySegmentTree() {}
    LazySegmentTree(int n_, MonoidType E0_, OperatorType E1_,
                    MOtoM upd_f_, MMtoM cmb_f_, OOtoO lzy_f_, OItoO acc_f_,
                    vector<MonoidType> v = vector<MonoidType>()) :
        E0(E0_), E1(E1_),
        upd_f(upd_f_), cmb_f(cmb_f_), lzy_f(lzy_f_), acc_f(acc_f_) {
        build(n_, v);
    }

    void eval(int k, int l, int r) {
        if(!need_update[k]) return;
        node[k] = upd_f(node[k], acc_f(lazy[k], r - l));
        if(r - l > 1) {
            lazy[2*k+1] = lzy_f(lazy[2*k+1], lazy[k]);
            lazy[2*k+2] = lzy_f(lazy[2*k+2], lazy[k]);
            need_update[2*k+1] = need_update[2*k+2] = true;
        }
        lazy[k] = E1;
        need_update[k] = false;
    }

    void update(int a, int b, OperatorType x, int l, int r, int k) {
        eval(k, l, r);
        if(b <= l or  r <= a) return;
        if(a <= l and r <= b) {
            lazy[k] = lzy_f(lazy[k], x);
            need_update[k] = true;
            eval(k, l, r);
        }
        else {
            int mid = (l + r) / 2;
            update(a, b, x, l, mid, 2*k+1);
            update(a, b, x, mid, r, 2*k+2);
            node[k] = cmb_f(node[2*k+1], node[2*k+2]);
        }
    }

    MonoidType query(int a, int b, int l, int r, int k) {
        if(b <= l or  r <= a) return E0;
        eval(k, l, r);
        if(a <= l and r <= b) return node[k];
        int mid = (l + r) / 2;
        MonoidType vl = query(a, b, l, mid, 2*k+1);
        MonoidType vr = query(a, b, mid, r, 2*k+2);
        return cmb_f(vl, vr);
    }

    // update [a, b)-th element (applied value, x)
    void update(int a, int b, OperatorType x) {
        update(a, b, x, 0, n, 0);
    }

    // range query for [a, b)
    MonoidType query(int a, int b) {
        return query(a, b, 0, n, 0);
    }

    void dump() {
        fprintf(stderr, "[lazy]\n");
        for(int i=0; i<2*n-1; i++) {
            if(i == n-1) fprintf(stderr, "xxx ");
            if(lazy[i] == E1) fprintf(stderr, "  E ");
            else fprintf(stderr, "%3d ", lazy[i]);
        }
        fprintf(stderr, "\n");

        fprintf(stderr, "[node]\n");
        for(int i=0; i<2*n-1; i++) {
            if(i == n-1) fprintf(stderr, "xxx ");
            if(node[i] == E0) fprintf(stderr, "  E ");
            else fprintf(stderr, "%3d ", node[i]);
        }
        fprintf(stderr, "\n");
    }
};

int main() {
    int N; cin >> N;
    vector<int> A(N);
    for(int i=0; i<N; i++) cin >> A[i];

    // 差分: 左 - 右
    vector<int> B(N);
    int H = N / 2;
    for(int i=0; i<H; i++) {
        B[i] = A[i] - A[N-1-i];
    }

    using PI = pair<ll, ll>;

    const PI E0(LONGINF, -LONGINF);
    const ll E1 = 0;
    LazySegmentTree<PI, ll> seg(H, E0, E1,
                                [](PI a, ll b) {
                                    a.first += b;
                                    a.second += b;
                                    return a;
                                },
                                [](PI a, PI b) {
                                    ll x = min(a.first, b.first);
                                    ll y = max(a.second, b.second);
                                    return make_pair(x, y);
                                },
                                [](ll a, ll b) {
                                    return a + b;
                                },
                                [](ll a, int x) {
                                    return a;
                                },
                                vector<PI>(H, make_pair(0, 0)));
    for(int i=0; i<H; i++) seg.update(i, i+1, B[i]);

    int Q; cin >> Q;
    for(int i=0; i<Q; i++) {
        int l, r, x; cin >> l >> r >> x; l--;

        int dl = max(H - l, 0);
        int dr = max(r - H, 0);

        int d = min(dl, dr);
        // fprintf(stderr, "### query %d: d = %d\n", i, d);
        if(d > 0) {
            int ql = l, qr = H - d;
            // fprintf(stderr, "? 1: l = %d, r = %d\n", ql, qr);
            if(ql < qr) {
                // fprintf(stderr, "q1: l = %d, r = %d\n", ql, qr);
                seg.update(ql, qr, x);
            }
        }
        if(d > 0) {
            int ql = N - r, qr = H - d;
            // fprintf(stderr, "? 2: l = %d, r = %d\n", ql, qr);
            if(ql < qr) {
                // fprintf(stderr, "q2: l = %d, r = %d\n", ql, qr);
                seg.update(ql, qr, -x);
            }
        }
        if(d == 0) {
            int ql = l, qr = r;
            if(ql >= H) {
                swap(ql, qr);
                ql = N - ql, qr = N - qr, x = -x;
            }
            // fprintf(stderr, "q3: l = %d, r = %d\n", ql, qr);
            seg.update(ql, qr, x);
        }

        auto res = seg.query(0, H);
        if(res.first == 0 and res.second == 0) cout << 1 << endl;
        else cout << 0 << endl;
    }
    return 0;
}

