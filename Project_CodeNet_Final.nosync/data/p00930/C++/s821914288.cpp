#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
constexpr int IINF = INT_MAX;

template <typename Monoid, typename OperatorMonoid>
struct LazySegmentTree{
private:
    using F = function<Monoid(Monoid, Monoid)>;
    using G = function<Monoid(Monoid, OperatorMonoid)>;
    using H = function<OperatorMonoid(OperatorMonoid, OperatorMonoid)>;
    using P = function<OperatorMonoid(OperatorMonoid, int)>;
    int N;
    vector<Monoid> node;
    vector<OperatorMonoid> lazy;
    F f;
    G g;
    H h;
    P p;
    Monoid e;  // identity element
    OperatorMonoid oe;  // identity element

public:
    LazySegmentTree(){}
    LazySegmentTree(F f, G g, H h, Monoid e, OperatorMonoid oe, P p=[](OperatorMonoid a, int b){return a;}):f(f), g(g), h(h), e(e), oe(oe), p(p){}
    void init(int sz){
        N = 1;
        while(N < sz) N <<= 1;
        node.assign(2*N-1, e);
        lazy.assign(2*N-1, oe);
    }
    void build(vector<Monoid>& v){
        int sz = int(v.size());
        init(sz);
        for(int i=0; i<sz; i++){
            node[i+N-1] = v[i];
        }
        for(int i=N-2; i>=0; i--){
            node[i] = f(node[i*2+1], node[i*2+2]);
        }
    }
    void eval(int k, int len){
        if(lazy[k] != oe){
            node[k] = g(node[k], p(lazy[k], len));
            if(k < N-1){
                lazy[2*k+1] = h(lazy[2*k+1], lazy[k]);
                lazy[2*k+2] = h(lazy[2*k+2], lazy[k]);
            }
            lazy[k] = oe;
        }
    }
    Monoid update(int a, int b, OperatorMonoid x){return update(a, b, x, 0, 0, N);}
    Monoid update(int a, int b, OperatorMonoid x, int k, int l, int r){
        eval(k, r-l);
        if(b <= l || r <= a) return node[k];
        if(a <= l && r <= b){
            lazy[k] = h(lazy[k], x);
            return g(node[k], p(lazy[k], r-l));
        }
        return node[k] = f(update(a,b,x,2*k+1,l,(l+r)/2), update(a,b,x,k*2+2,(l+r)/2,r));
    }
    // [a,b)
    Monoid query(int a, int b){return query(a, b, 0, 0, N);}
    Monoid query(int a, int b, int k, int l, int r){
        eval(k, r-l);
        if(b <= l || r <= a) return e;
        if(a <= l && r <= b) return node[k];
        Monoid vl, vr;
        vl = query(a, b, 2*k+1, l, (l+r)/2);
        vr = query(a, b, 2*k+2, (l+r)/2, r);
        return f(vl, vr);
    }
};

int main() {
    int n, q;
    string s;
    cin >> n >> q >> s;
    vector<int> v(n);
    set<int> st;
    for(int i=0;i<n;i++){
        v[i] += (s[i]=='('?1:-1);
        if(s[i]==')') st.insert(i);
    }
    for(int i=0;i<n-1;i++){
        v[i+1] += v[i];
    }
    auto f = [=](int a, int b){return min(a,b);};
    auto g = [=](int a, int b){return a+b;};
    LazySegmentTree<int, int> seg(f,g,g,IINF,0);
    seg.build(v);
    for(;q>0;q--){
        int k;
        cin >> k;
        k--;
        if(s[k]=='('){
            s[k] = ')';
            st.insert(k);
            seg.update(k,n,-2);
            int ans = *st.begin();
            seg.update(ans,n,2);
            cout << ans+1 << endl;
            s[ans] = '(';
            st.erase(st.begin());
        }
        else{
            s[k] = '(';
            st.erase(k);
            seg.update(k,n,2);
            int ok = n-1, ng = -1;
            while(abs(ok-ng)>1){
                int mid = (ok+ng)/2;
                if(seg.query(mid,n)>=2){
                    ok = mid;
                }
                else{
                    ng = mid;
                }
            }
            seg.update(ok,n,-2);
            cout << ok+1 << endl;
            s[ok] = ')';
            st.insert(ok);
        }
    }
    return 0;
}

