#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//INSERT ABOVE HERE

template<typename T>
struct BIT{
  Int n;
  vector<T> bit;

  BIT():n(-1){}
  BIT(Int n_, T d):n(n_), bit(n_ + 1, d){}

  T sum(Int i){
    T s = bit[0];
    for(Int x = i; x > 0; x -= (x&-x))
      s += bit[x];
    return s;
  }

  void add(Int i, T a){
    if(i == 0) return;
    for(Int x = i; x <= n; x += (x & -x))
      bit[x] += a;
  }

  void sum0(Int i){
    return sum(i + 1);
  }

  void add0(Int i,T a){
    add(i+1, a);
  }

  T query(Int l,Int r){
    return sum(r - 1) - sum(l - 1);
  }

  T query0(Int l,Int r){
    return sum(r) - sum(l);
  }
};

template<typename T, typename E>
struct SegmentTree{
  using F = function<T(T, T)>;
  using G = function<T(T, E)>;
  using H = function<E(E, E)>;
  Int n, height;
  F f;
  G g;
  H h;
  T ti;
  E ei;

  vector<T> dat;
  vector<E> laz;
  SegmentTree(Int n_, F f, G g, H h, T ti, E ei):
    f(f), g(g), h(h), ti(ti), ei(ei)
  {init(n_);}

  void init(Int n_){
    n = 1; height = 0;
    while(n < n_) n <<= 1, height++;
    dat.assign(2*n, ti);
    laz.assign(2*n, ei);
  }

  void build(Int n_, vector<T> v){
    for(Int i=0;i<n_;i++) dat[n+i] = v[i];
    for(Int i= n-1; i; i--)
      dat[i] = f(dat[ (i<<1)|0 ], dat[ (i<<1)|1 ]);
  }

  T reflect(Int k){
    return g(dat[k], laz[k]);
  }

  inline void eval(Int k){
    if(laz[k] == ei) return;
    laz[(k<<1) | 0] = h(laz[ (k<<1) | 0], laz[k]);
    laz[(k<<1) | 1] = h(laz[ (k<<1) | 1], laz[k]);
    dat[k] = reflect(k);
    laz[k] = ei;
  }

  void update(Int a,Int b,E x){
    a += n, b += n - 1;
    for(Int i=height;i;i--) eval(a>>i);
    for(Int i=height;i;i--) eval(b>>i);
    for(Int l=a, r=b+1; l < r; l>>=1, r>>=1){
      if(l & 1) laz[l] = h(laz[l], x), l++;
      if(r & 1) --r, laz[r] = h(laz[r], x);
    }

    while(a>>=1)
      dat[a] = f(reflect( (a<<1) | 0), reflect( (a<<1) | 1));

    while(b>>=1)
      dat[b] = f(reflect( (b<<1) | 0), reflect( (b<<1) | 1));
  }

  T query(Int a,Int b){
    a += n; b += n-1;
    for(Int i=height; i ; i--) eval(a >> i);
    for(Int i=height; i ; i--) eval(b >> i);
    T vl = ti, vr = ti;
    for(Int l = a, r = b+1; l < r; l>>=1, r>>=1){
      if(l & 1) vl = f(vl, reflect(l++));
      if(r & 1) vr = f(reflect(--r), vr);
    }
    return f(vl, vr);
  }
};



signed main(){
  Int n,k;
  cin>>n>>k;
  vector<Int> x(n);
  for(Int i=0;i<n;i++) cin>>x[i];

  BIT<Int> bit(n+1,0);
  Int rot=0;
  for(Int i=0;i<n;i++){
    rot+=i-bit.sum(x[i]);
    bit.add(x[i],1);
  }
  //cout<<rot<<endl;

  Int mv=rot-k;
  if(mv<0) mv=0;
  vector<Int> rev(n+1);
  for(Int i=0;i<n;i++) rev[x[i]]=i;

  const Int INF = 1e9;
  auto f=[](Int a,Int b){return min(a,b);};
  auto g=[](Int a,Int b){return b!=INF?b:a;};
  SegmentTree<Int, Int> seg(n,f,g,g,INF,INF);
  seg.build(n,x);

  //for(Int i=0;i<n;i++) cout<<i<<":"<<seg.query(i,i+1)<<endl;
  //for(Int i=0;i<n;i++) cout<<i<<":"<<seg.query(0,i+1)<<endl;
  
  BIT<Int> ss(n+1,0);
  for(Int i=0;i<n;i++) ss.add0(i,1);
  
  vector<Int> ans;
  for(Int i=0;i<n;i++){
    Int l=0,r=n;
    while(l+1<r){
      Int m=(l+r)>>1;
      if(ss.query0(0,m+1)<=mv+1) l=m;
      else r=m;
    }
    Int t=seg.query(0,r);
    //cout<<mv<<":"<<0<<" "<<r<<":"<<t<<endl;
    ans.emplace_back(t);
    mv-=ss.query0(0,rev[t]+1)-1;
    seg.update(rev[t],rev[t]+1,INF-1);
    ss.add0(rev[t],-1);
  }
  
  for(Int v:ans) cout<<v<<endl;
  return 0;
}

