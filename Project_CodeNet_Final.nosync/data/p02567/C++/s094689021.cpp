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
    template<typename C>
    int find_subtree(int k,const C &check,Monoid &M,bool type){
        while(k<n){
            Monoid nxt=type?f(dat[k<<1|type],M):f(M,dat[k<<1|type]);
            if (check(nxt)) k=k<<1|type;
            else M=nxt,k=k<<1|(type^1);
        }
        return k-n;
    }
    // min i s.t. f(seg[a],seg[a+1],...,seg[i]) satisfy "check"
    template<typename C>
    int find_first(int a,const C &check){
        Monoid L=id;
        if (a<=0){
            if (check(f(L,dat[1]))) return find_subtree(1,check,L,false);
            return -1;
        }
        int b=n;
        for (int l=a+n,r=b+n;l<r;l>>=1,r>>=1){
            if (l&1){
                Monoid nxt=f(L,dat[l]);
                if (check(nxt)) return find_subtree(l,check,L,false);
                L=nxt; ++l;
            }
        }
        return -1;
    }
    // max i s.t. f(seg[i],...,seg[b-2],seg[b-1]) satisfy "check"
    template<typename C>
    int find_last(int b,const C &check){
        Monoid R=id;
        if (b>=n){
            if (check(f(dat[1],R))) return find_subtree(1,check,R,true);
            return -1;
        }
        int a=n;
        for (int l=a,r=b+n;l<r;l>>=1,r>>=1){
            if (r&1){
                Monoid nxt=f(dat[--r],R);
                if (check(nxt)) return find_subtree(r,check,R,true);
                R=nxt;
            }
        }
        return -1;
    }
    Monoid operator[](int i){return dat[i+n];}
};

// https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_A

void DSL_2_A(){
    int n,q; cin >> n >> q;

    SegmentTree<int> seg(n,[](int a,int b){return min(a,b);},INT_MAX);

    for (;q--;){
        int c,x,y; cin >> c >> x >> y;
        if (!c) seg.update(x,y);
        else cout << seg.query(x,y+1) << '\n';
    }
}

// https://atcoder.jp/contests/practice2/tasks/practice2_j

void practice2_j(){
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
            cout << (~ans?ans+1:N+1) << '\n';
        }
    }
}

// https://atcoder.jp/contests/abc130/tasks/abc130_d

void ABC130_D(){
    int N; long long K; cin >> N >> K;
    vector<long long> a(N);
    for (int i=0;i<N;++i) cin >> a[i];

    SegmentTree<long long> seg(N,[](long long a,long long b){return a+b;},0);
    seg.build(a);
    long long ans=0,sum=0;

    for (int i=0;i<N;++i){
        int nxt=seg.find_first(i,[&](long long x){return x>=K;});
        if (~nxt) ans+=N-nxt;
    }

    cout << ans << '\n';
}

// https://atcoder.jp/contests/arc033/tasks/arc033_3

void ARC033_C(){
    const int MAX_X=2e5+10;
    int Q; cin >> Q;

    SegmentTree<int> seg(MAX_X,[](int a,int b){return a+b;},0);

    for (;Q--;){
        int T,X; cin >> T >> X;
        if (T==1) seg.update(X,seg[X]+1);
        else {
            int ans=seg.find_first(0,[&](int x){return x>=X;});
            cout << ans << '\n';
            seg.update(ans,seg[ans]-1);
        }
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    practice2_j();
}