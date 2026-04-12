#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}


struct FastIO{
  FastIO(){
    cin.tie(0);
    ios::sync_with_stdio(0);
  }
}fastio_beet;


template <typename T,typename E>
struct SegmentTree{
  using F = function<T(T,T)>;
  using G = function<T(T,E)>;
  using H = function<E(E,E)>;
  Int n,height;
  F f;
  G g;
  H h;
  T ti;
  E ei;
  vector<T> dat;
  vector<E> laz;
  SegmentTree(F f,G g,H h,T ti,E ei):
    f(f),g(g),h(h),ti(ti),ei(ei){}
  
  void init(Int n_){
    n=1;height=0;
    while(n<n_) n<<=1,height++;
    dat.assign(2*n,ti);
    laz.assign(2*n,ei);
  }
  void build(const vector<T> &v){
    Int n_=v.size();
    init(n_);
    for(Int i=0;i<n_;i++) dat[n+i]=v[i];
    for(Int i=n-1;i;i--)
      dat[i]=f(dat[(i<<1)|0],dat[(i<<1)|1]);
  }
  inline T reflect(Int k){
    return laz[k]==ei?dat[k]:g(dat[k],laz[k]);
  }
  inline void eval(Int k){
    if(laz[k]==ei) return;
    laz[(k<<1)|0]=h(laz[(k<<1)|0],laz[k]);
    laz[(k<<1)|1]=h(laz[(k<<1)|1],laz[k]);
    dat[k]=reflect(k);
    laz[k]=ei;
  }
  inline void thrust(Int k){
    for(Int i=height;i;i--) eval(k>>i);
  }
  inline void recalc(Int k){    
    while(k>>=1)
      dat[k]=f(reflect((k<<1)|0),reflect((k<<1)|1));
  }
  void update(Int a,Int b,E x){
    thrust(a+=n);
    thrust(b+=n-1);
    for(Int l=a,r=b+1;l<r;l>>=1,r>>=1){
      if(l&1) laz[l]=h(laz[l],x),l++;
      if(r&1) --r,laz[r]=h(laz[r],x);
    }
    recalc(a);
    recalc(b);
  }
  void set_val(Int a,T x){
    thrust(a+=n);
    dat[a]=x;laz[a]=ei;
    recalc(a);
  }
  T query(Int a,Int b){
    thrust(a+=n);
    thrust(b+=n-1);
    T vl=ti,vr=ti;
    for(Int l=a,r=b+1;l<r;l>>=1,r>>=1) {
      if(l&1) vl=f(vl,reflect(l++));
      if(r&1) vr=f(reflect(--r),vr);
    }
    return f(vl,vr);
  }
};

//INSERT ABOVE HERE
signed main(){
  Int n,m;
  cin>>n>>m;
  vector<Int> l(m),r(m),a(m);
  for(Int i=0;i<m;i++) cin>>l[i]>>r[i]>>a[i];

  vector<vector<Int> > idx(n+1);
  for(Int i=0;i<m;i++) idx[r[i]].emplace_back(i);

  Int sum=0;
  for(Int i=0;i<m;i++) sum+=a[i];

  auto f=[](Int a,Int b){return min(a,b);};
  auto g=[](Int a,Int b){return a+b;};
  const Int INF = 1e15;
  SegmentTree<Int, Int> seg(f,g,g,INF,0);
  seg.build(vector<Int>(n+1,INF));
  seg.set_val(0,0);
  
  for(Int i=1;i<=n;i++){
    Int val=seg.query(0,i);
    seg.set_val(i,val);
    for(Int k:idx[i])
      seg.update(0,l[k],a[k]);
  }
  cout<<sum-seg.query(0,n+1)<<endl;
  return 0;
}
