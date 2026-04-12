#include<bits/stdc++.h>

#define debug(x) cerr << #x << ": " << x << '\n'
#define debugArray(x,n) for(long long hoge = 0; (hoge) < (n); ++ (hoge)) cerr << #x << "[" << hoge << "]: " << x[hoge] << '\n'
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vll;
const ll INF = INT_MAX;
const ll MOD = 1e9+7;


template <typename M>
class lazSegmentTree{
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
    lazSegmentTree(){}
    lazSegmentTree(int n_)
    : height(ceil(log2(n_))), n(1 << height), dat(n * 2, M::ti()), laz(n * 2, M::ei()) {}
    lazSegmentTree(int n_, T v1)
    : height(ceil(log2(n_))), n(1 << height), dat(n * 2, v1), laz(n * 2, M::ei()) {init();}
    lazSegmentTree(const vector<T>& dat_)
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

struct RaddqRmaxq {
    using T = ll;
    using E = ll;
    static T ti() { return -INF; }
    static E ei() { return 0; }
    static T f(const T& l, const T& r) { return max(l, r); }
    static T g(const T& l, const E& r) { return l + r; }
    static E h(const E& l, const E& r) { return l + r; }
};

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll N,M;cin>>N>>M;
  vector<tuple<ll,ll,ll> > rla(M);
  for(ll i=0;i<M;i++){
    ll l,r,a;cin>>l>>r>>a;
    rla[i] = make_tuple(r,l,a);
  }
  sort(rla.begin(),rla.end());
  lazSegmentTree<RaddqRmaxq> dp(N+1);
  ll j=0;
  dp.set_val(0,0);
  for(ll i=1;i<=N;i++){
    dp.set_val(i,dp.query(0,i));
    while(get<0>(rla[j])==i){
      ll r,l,a;tie(r,l,a)=rla[j++];
      dp.update(l,r+1,a);
    }
  }
  cout<<dp.query(0,N+1)<<endl;
  return 0;
}
