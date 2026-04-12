#include <bits/stdc++.h>
using namespace std;

template<typename Monoid>
struct SegmentTree{
    typedef function<Monoid(Monoid,Monoid)> F;
    int n;
    F f;
    Monoid id;
    vector<Monoid> dat;
    SegmentTree(int n_,F f,Monoid id):f(f),id(id){init(n_);}
    void init(int n_){
        n=1;
        while(n<n_) n<<=1;
        dat.assign(n<<1,id);
    }
    void build(const vector<Monoid> &v){
        for (int i=0;i<v.size();++i) dat[i+n]=v[i];
        for (int i=n-1;i;--i) dat[i]=f(dat[i<<1|0],dat[i<<1|1]);
    }
    void update(int k,Monoid x){
        dat[k+=n]=x;
        while(k>>=1) dat[k]=f(dat[k<<1|0],dat[k<<1|1]);
    }
    Monoid query(int a,int b){
        if (a>=b) return id;
        Monoid vl=id,vr=id;
        for (int l=a+n,r=b+n;l<r;l>>=1,r>>=1){
            if (l&1) vl=f(vl,dat[l++]);
            if (r&1) vr=f(dat[--r],vr);
        }
        return f(vl,vr);
    }
    // most left position p that f[a...p] meets conditin "check"
    template<typename C>
    int find_first(int a,const C &check,Monoid &M,int k,int l,int r){
        if (l+1==r){
            M=f(M,dat[k]);
            return check(M)?k-n:-1;
        }
        int m=(l+r)>>1;
        if (m<=a) return find_first(a,check,M,k<<1|1,m,r);
        if (a<=l&&!check(f(M,dat[k]))){
            M=f(M,dat[k]);
            return -1;
        }
        int vl=find_first(a,check,M,k<<1|0,l,m);
        if (~vl) return vl;
        return find_first(a,check,M,k<<1|1,m,r);
    }
    template<typename C>
    int find_first(int a,const C &check){
        Monoid M=id;
        return find_first(a,check,M,1,0,n);
    }
    // most right position p that f[p...b) meets condition "check"
    template<typename C>
    int find_last(int b,const C &check,Monoid &M,int k,int l,int r){
        if (l+1==r){
            M=f(dat[k],M);
            return check(M)?k-n:-1;
        }
        int m=(l+r)>>1;
        if (b<=m) return find_last(b,check,M,k<<1|0,l,m);
        if (r<=b&&!check(f(dat[k],M))){
            M=f(dat[k],M);
            return -1;
        }
        int vr=find_last(b,check,M,k<<1|1,m,r);
        if (~vr) return vr;
        return find_last(b,check,M,k<<1|0,l,m);
    }
    template<typename C>
    int find_last(int b,const C &check){
        Monoid M=id;
        return find_last(b,check,M,1,0,n);
    }
    Monoid operator[](int i){return dat[i+n];}
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N,Q; cin >> N >> Q;
    vector<int> A(N);
    for (int i=0;i<N;++i) cin >> A[i];
    SegmentTree<int> seg(N,[](int a,int b){return max(a,b);},0);
    seg.build(A);
    for (;Q--;){
        int T; cin >> T;
        if (T==1){
            int X,V; cin >> X >> V;
            seg.update(--X,V);
        } else if (T==2){
            int L,R; cin >> L >> R;
            cout << seg.query(--L,R) << '\n';
        } else {
            int X,V; cin >> X >> V;
            int ans=seg.find_first(--X,[&](int x){return x>=V;});
            cout << (ans<0?N+1:ans+1) << '\n';
        }
    }
}