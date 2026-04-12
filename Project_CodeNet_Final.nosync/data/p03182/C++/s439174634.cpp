#include <iostream>
#include <math.h>
#include <queue>
#include <algorithm>
#include <map>
#include <set>
#include <cstdlib>
#include <unordered_map>
#include <numeric>
#include <functional>
#include <limits.h>

using namespace std;

#define fs first
#define sc second

typedef long long ll;
typedef pair<int, ll> P;
typedef tuple<int, int, ll> T;

// 0-index
template <class T0, class T1>
class LazySegmentTree{
private:
    void eval(int k, int len){
        node[k] = g(node[k], p(lazy[k], len));

        if(k < n-1){
            lazy[2 * k + 1] = f1(lazy[2 * k + 1], lazy[k]);
            lazy[2 * k + 2] = f1(lazy[2 * k + 2], lazy[k]);
        }
        lazy[k] = u1;
    }

    void update(int a, int b, T1 x, int k, int l, int r){
        eval(k, r - l);
        if(b <= l || r <= a) return;
        if(a <= l && r <= b){
            lazy[k] = f1(lazy[k], x);
            eval(k, r - l);
        }
        else{
            update(a, b, x, 2 * k + 1, l, (l + r) / 2);
            update(a, b, x, 2 * k + 2, (l + r) / 2, r);
            node[k] = f0(node[2 * k + 1], node[2 * k + 2]);
        }
    }

    T0 query(int a, int b, int k, int l, int r){
        if (r <= a || b <= l){
            return u0;
        }
        eval(k, r - l);
        if (a <= l && r <= b){
            return node[k];
        }
        T0 vl = query(a, b, 2 * k + 1, l, (l + r) / 2);
        T0 vr = query(a, b, 2 * k + 2, (l + r) / 2, r);
        return f0(vl, vr);
    }


public:
    int sz;  // 元の配列サイズ
    int n;
    vector<T0> node;
    vector<T1> lazy;
    using F0 = function<T0(T0, T0)>; F0 f0; T0 u0;
    using F1 = function<T1(T1, T1)>; F1 f1; T1 u1;
    using G = function<T0(T0, T1)>;  G g;
    using P = function<T1(T1, int)>; P p;

    /**
     *
     * @param v   初期状態
     * @param f0  値配列に対する操作(T0の演算)
     * @param u0  値配列に対する単位元(T0の単位元)
     * @param f1  遅延配列に対する操作(T1の演算)
     * @param u1  遅延配列に対する単位元(T1の単位元)
     * @param g   遅延配列の値を値配列に反映
     * @param p   遅延配列の値を値配列に反映させる際の区間の長さを考慮した前処理
     */
    LazySegmentTree(vector<ll> v, F0 f0, T0 u0, F1 f1, T1 u1, G g, P p):
            sz(v.size()), f0(f0), u0(u0), f1(f1), u1(u1), g(g), p(p){
        int sz = v.size();
        n = 1;
        while(n < sz) n *= 2;
        node.resize(2*n-1, u0);
        lazy.resize(2*n-1, u1);

        for(int i = 0; i < sz; i++){
            node[i+n-1] = v[i];
        }
        for(int i = n-2; i >= 0; i--){
            node[i] = f0(node[i*2+1], node[i*2+2]);
        }
    }

    void update(int a, int b, T1 x){
        update(a, b, x, 0, 0, n);
    }

    void update(int a, T1 x){
        update(a, a+1, x);
    }

    T0 query(int a, int b){
        return query(a, b, 0, 0, n);
    }

    T0 query(int a){
        return query(a, a+1);
    }
};


int main(){
    int N, M;
    cin >> N >> M;
    vector<P> intervals[210000];
    for(int i = 0; i < M; i++){
        int l, r;
        ll a;
        cin >> l >> r >> a;
        intervals[r].emplace_back(P(l, a));
    }

    vector<ll> v(N+2, 0);

    LazySegmentTree<ll, ll> seg(
            v,
            [](ll x, ll y) { return max(x, y); }, 0,
            [](ll x, ll y) { return x + y; }, 0,
            [](ll x, ll y) { return x + y; },
            [](ll x, int len) { return x; }
    );

    int lastR = 0;
    for(int i = 1; i <= N; i++){
        ll ma = seg.query(0, i);
        seg.update(i, i+1, ma);

        for(auto p: intervals[i]){
            int l = p.fs;
            ll a = p.sc;

            seg.update(l, i+1, a);
        }
    }

    cout << seg.query(0, N+1) << endl;


    return 0;
}