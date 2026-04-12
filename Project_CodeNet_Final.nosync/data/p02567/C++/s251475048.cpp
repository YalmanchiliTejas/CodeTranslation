#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <class T> using vec = vector<T>;
template <class T> using vvec = vector<vec<T>>;

template<typename Monoid,typename F>
class SegmentTree{
private:
    int sz;
    vector<Monoid> seg;
    const F op;
    const Monoid e;
public:
    SegmentTree(int n,const F op,const Monoid &e):op(op),e(e){
        sz = 1;
        while(sz<=n) sz <<= 1;
        seg.assign(2*sz,e);
    }
    void set(int k, const Monoid &x){
        seg[k+sz] = x;
    }
    void build(){
        for(int i=sz-1;i>0;i--){
            seg[i] = op(seg[2*i],seg[2*i+1]);
        }
    }
    void update(int k,const Monoid &x){
        k += sz;
        seg[k] = x;
        while(k>>=1){
            seg[k] = op(seg[2*k],seg[2*k+1]);
        }
    }
    Monoid query(int l,int r){
        Monoid L = e,R = e;
        for(l+=sz,r+=sz;l<r;l>>=1,r>>=1){
            if(l&1) L = op(L,seg[l++]);
            if(r&1) R = op(seg[--r],R);
        }
        return op(L,R);
    }
    Monoid operator[](const int &k)const{
        return seg[k+sz];
    }
    template<typename C>
    int find_subtree(int a,const C &check,Monoid &M,bool type) {
        while(a<sz) {
            Monoid nxt = type ? op(seg[2*a+type],M) : op(M,seg[2*a+type]);
            if(check(nxt)) a = 2*a+type;
            else M = nxt, a = 2*a+1-type;
        }
        return a - sz;
    }

    template<typename C>
    int find_first(int a,const C &check) {
        Monoid L = e;
        if(a <= 0) {
            if(check(op(L,seg[1]))) return find_subtree(1,check,L,false);
            return -1;
        }
        int b = sz;
        for(a+=sz,b+=sz;a<b;a>>=1,b>>=1) {
            if(a&1) {
                Monoid nxt = op(L,seg[a]);
                if(check(nxt)) return find_subtree(a,check,L,false);
                L = nxt;
                ++a;
            }
        }
        return -1;
    }

    template<typename C>
    int find_last(int b,const C &check) {
        Monoid R = e;
        if(b >= sz) {
            if(check(op(seg[1], R))) return find_subtree(1, check, R, true);
            return -1;
        }
        int a = sz;
        for(b+=sz; a<b; a>>=1,b>>=1) {
            if(b&1) {
                Monoid nxt = op(seg[--b],R);
                if(check(nxt)) return find_subtree(b,check,R,true);
                R = nxt;
            }
        }
        return -1;
    }
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N,Q;
    cin >> N >> Q;
    SegmentTree seg(N,[](int a,int b){return max(a,b);},-1);
    for(int i=0;i<N;i++){
        int a;
        cin >> a;
        seg.set(i,a);
    }
    seg.build();
    while(Q--){
        int t;
        cin >> t;
        if(t==1){
            int x,v;
            cin >> x >> v;
            x--;
            seg.update(x,v);
        }else if(t==2){
            int l,r;
            cin >> l >> r;
            l--,r--;
            cout << seg.query(l,r+1) << "\n";
        }else{
            int x,v;
            cin >> x >> v;
            x--;
            int res = seg.find_first(x,[&](int a){return v<=a;});
            cout << (res==-1? N+1:res+1) << "\n";
        }
    }
}