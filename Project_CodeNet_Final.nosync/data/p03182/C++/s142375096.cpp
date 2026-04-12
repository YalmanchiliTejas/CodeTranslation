#include <bits/stdc++.h>
#define For(i, a, b) for(int (i)=(a); (i)<(b); ++(i))
#define rFor(i, a, b) for(int (i)=(a)-1; (i)>=(b); --(i))
#define rep(i, n) For((i), 0, (n))
#define rrep(i, n) rFor((i), (n), 0)
#define fi first
#define se second
using namespace std;
typedef long long lint;
typedef pair<int, int> pii;
typedef pair<pii, lint> ppl;
typedef pair<lint, lint> pll;
typedef complex<double> xy_t;

const lint mod = 1e9 + 7;

template<class T, class E> struct LazySegTree{
    typedef  function<T(T, T)> F;
    typedef  function<T(T, E)> G;
    typedef  function<E(E, E)> H;
    typedef  function<E(E, int)> P;
    int n = 1; F f; G g; H h; T et; E ee; P p;
    int cur = 0;
    vector<T> node;
    vector<E> lazy;
    vector<int> idx, len;

    LazySegTree(int n_, F f_, G g_, H h_, T et_, E ee_, P p_=[](E a, int b){return a;}):
    f(f_), g(g_), h(h_), et(et_), ee(ee_), p(p_){
        while(n < n_) n *= 2;
        node.resize(n*2-1, et);
        lazy.resize(n*2-1, ee);
        idx.resize(n, -1);
        len.resize(n*2-1, 0);
        For(i, n-1, n*2-1){
            len[i] = 1;
            int k = i;
            while(k){
                k = (k-1)/2;
                ++len[k];
            }
        }
    }

    inline void getidx(int a, int b){
        cur = 0;
        if(a == n-1 && b == 2*n-1) return;
        while(a & 1) a = (a-1)/2;
        while(b & 1) b = (b-1)/2;
        a = (a-1)/2;
        b = (b-1)/2;
        while(a || b){
            if(a >= b){
                idx[cur++] = a;
                a = (a-1)/2;
            }
            else{
                idx[cur++] = b;
                b = (b-1)/2;
            }
        }
        idx[cur++] = 0;
    }

    inline void eval(){
        rrep(k, cur){
            int i = idx[k];
            if(lazy[i] == ee) continue;
            lazy[i*2+1] = h(lazy[i*2+1], lazy[i]);
            node[i*2+1] = g(node[i*2+1], p(lazy[i], len[i*2+1]));
            lazy[i*2+2] = h(lazy[i*2+2], lazy[i]);
            node[i*2+2] = g(node[i*2+2], p(lazy[i], len[i*2+2]));
            lazy[i] = ee;
        }
    }

    void update(int a, int b, E x){
        a += n-1; b += n-1;
        getidx(a, b);
        eval();
        for(; a<b; a=(a-1)/2, b=(b-1)/2){
            if(!(a&1)){
                lazy[a] = h(lazy[a], x);
                node[a] = g(node[a], p(x, len[a]));
                a++;
            }
            if(!(b&1)){
                --b;
                lazy[b] = h(lazy[b], x);
                node[b] = g(node[b], p(x, len[b]));
            }
        }
        rep(k, cur){
            int i = idx[k];
            node[i] = f(node[i*2+1], node[i*2+2]);
        }
    }

    T query(int a, int b){
        a += n-1; b += n-1;
        getidx(a, b);
        eval();
        T vl = et, vr = et;
        for(; a<b; a=(a-1)/2, b=(b-1)/2){
            if(!(a&1)) vl = f(vl, node[a++]);
            if(!(b&1)) vr = f(node[--b], vr);
        }
        return f(vl, vr);
    }
};

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    ppl p[m];
    rep(i, m){
        int l, r;
        lint a;
        scanf("%d%d%lld", &l, &r, &a);
        p[i] = ppl(pii(l-1, r), a);
    }
    sort(p, p+m, [](const ppl &u, const ppl &v){return u.fi.se < v.fi.se;});

    auto f = [](lint x, lint y){return max(x, y);};
    auto g = plus<lint>();
    LazySegTree<lint, lint> lst(n, f, g, g, 0, 0);

    int cur = 0;
    rep(i, n){
        lint tmp = 0;
        tmp = max(tmp, lst.query(0, i));
        lst.update(i, i+1, tmp);

        while(cur < m && p[cur].fi.se == i+1){
            lst.update(p[cur].fi.fi, p[cur].fi.se, p[cur].se);
            ++cur;
        }
    }

    printf("%lld\n", max(0LL, lst.query(0, n)));
}