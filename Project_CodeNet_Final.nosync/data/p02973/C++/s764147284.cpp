#include<bits/stdc++.h>

#define debug(x) cerr << #x << ": " << x << endl
#define debugArray(x,n) for(long long hoge = 0; (hoge) < (n); ++ (hoge)) cerr << #x << "[" << hoge << "]: " << x[hoge] << endl
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vll;
const ll INF = LLONG_MAX/2;
const ll MOD = 1e9+7;


template <typename M>
class LazySegmentTree{
private:
    using T=typename M::T;
    using E=typename M::E;
    int height,n;
    vector<T> dat;
    vector<E> laz;
    inline T reflect(int k){
        return laz[k]==M::ei()?dat[k]:M::g(dat[k],laz[k]);
    }
    inline void eval(int k){
        if(laz[k]==M::ei()) return;
        laz[(k<<1)|0]=M::h(laz[(k<<1)|0],laz[k]);
        laz[(k<<1)|1]=M::h(laz[(k<<1)|1],laz[k]);
        dat[k]=reflect(k);
        laz[k]=M::ei();
    }
    inline void thrust(int k){
        for(int i=height;i;i--) eval(k>>i);
    }
    inline void recalc(int k){
        while(k>>=1)
            dat[k]=M::f(reflect((k<<1)|0),reflect((k<<1)|1));
    }
    void init() {
        for (int i = n - 1; i >= 1; i--) dat[i] = M::f(dat[i<<1|0], dat[i<<1|1]);
    }
    void init(const vector<T>& dat_) {
        for (int i = 0; i < (int)dat_.size(); i++) dat[i + n] = dat_[i];
        init();
    }
public:
    LazySegmentTree(){}
    LazySegmentTree(int n_)
    : height(ceil(log2(n_))), n(1 << height), dat(n * 2, M::ti()), laz(n * 2, M::ei()) {}
    LazySegmentTree(int n_, T v1)
    : height(ceil(log2(n_))), n(1 << height), dat(n * 2, v1), laz(n * 2, M::ei()) {init();}
    LazySegmentTree(const vector<T>& dat_)
    : height(ceil(log2(dat_.size()))), n(1 << height), dat(n * 2, M::ti()), laz(n * 2, M::ei()) {
        init(dat_);
    }
    void update(int a,int b,E x){
        thrust(a+=n);thrust(b+=n-1);
        for(int l=a,r=b+1;l<r;l>>=1,r>>=1){
            if(l&1) laz[l]=M::h(laz[l],x),l++;
            if(r&1) --r,laz[r]=M::h(laz[r],x);
        }
        recalc(a);recalc(b);
    }
    void set_val(int a,T x){
        thrust(a+=n);
        dat[a]=x;laz[a]=M::ei();
        recalc(a);
    }
    T query(int a,int b){
        thrust(a+=n);thrust(b+=n-1);
        T vl=M::ti(),vr=M::ti();
        for(int l=a,r=b+1;l<r;l>>=1,r>>=1) {
            if(l&1) vl=M::f(vl,reflect(l++));
            if(r&1) vr=M::f(reflect(--r),vr);
        }
        return M::f(vl,vr);
    }
    T operator[](const int k){return query(k,k+1);}
};
struct RupdqRminq {
    struct T{
      ll val,idx;
      T(ll v,ll i):val(v),idx(i){}
    };
    using E = ll;
    static T ti() { return {INT_MAX,-1}; }
    static E ei() { return INF; }
    static T f(const T& l, const T& r) { return l.val<r.val? l:r; }
    static T g(const T& l, const E& r) { return r == ei() ? l : T(r,l.idx); }
    static E h(const E& l, const E& r) { return r == ei() ? l : r; }
};

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll N;cin>>N;
  ll A[N];
  vector<pair<ll,ll>> B(N);
  LazySegmentTree<RupdqRminq> seg(N);
  for(ll i=0;i<N;i++){
    cin>>A[i];
    B[i] = {A[i],-i};
    seg.set_val(i,{INT_MAX,i});
  }
  sort(B.begin(),B.end());
  ll ans=0;
  for(ll i=0;i<N;i++){
    ll a,j;tie(a,j)=B[i];
    j*=-1;
    //debug(j);
    auto q=seg.query(0,j);
    seg.set_val(j,{1,j});
    if(q.idx<0){
      ans++;
    }else{
      seg.set_val(q.idx,{INT_MAX,j});
    }
  }
  cout<<ans<<endl;
  return 0;
}
