#ifdef __LOCAL
  #define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
template<typename T> bool chmax(T &a,T b) {if(a<b) {a=b; return true;} return false;}
template<typename T> bool chmin(T &a,T b) {if(a>b) {a=b; return true;} return false;}
#define itn int
#define fi first
#define se second
#define intmax numeric_limits<int>::max()
#define llmax numeric_limits<ll>::max()
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define rrep(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define rrep1(i,n) for(int i=(int)(n);i>=1;i--)
#define all(vec) vec.begin(),vec.end()
#define sortt(vec) sort((vec).begin(),(vec).end())
#define rsort(vec) sort((vec).rbegin(), (vec).rend())
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef tuple<ll,ll,ll> tlll;
typedef tuple<int,int,int> tiii;
const ll mod=1e9+7;
const int inf=1<<30;
const ll lnf=1ll<<60;

template <typename X, typename M,typename T>
struct SegTreeLazy{
  using FX=function<X(X, X)>;
  using FA=function<X(X, M)>;
  using FM=function<M(M, M)>;
  int n;
  FX fx;
  FA fa;
  FM fm;
  const X ex;
  const M em;
  vector<X> dat;
  vector<M> lazy;
  SegTreeLazy(int n_,FX fx_,FA fa_,FM fm_,X ex_,M em_)
    : n(),fx(fx_),fa(fa_),fm(fm_),ex(ex_),em(em_),dat(n_*4,ex),lazy(n_*4,em){
    int x=1;
    while(n_>x) x*=2;
    n=x;
  }

  void set(int i,X x) {dat[i+n-1]=x;}
  void build(){
    for(int k=n-2;k>=0;k--) dat[k]=fx(dat[2*k+1],dat[2*k+2]);
  }

  /* lazy eval */
  void eval(int k){
      if(lazy[k]==em) return;
      if(k < n - 1){
        lazy[k*2+1]=fm(lazy[k*2+1],lazy[k]);
        lazy[k*2+2]=fm(lazy[k*2+2],lazy[k]);
      }
      dat[k]=fa(dat[k],lazy[k]);
      lazy[k]=em;
  }

  void update(int a,int b,M x,int k,int l,int r){
    eval(k);
    if(a<=l&&r<=b){  // 完全に内側の時
      lazy[k]=fm(lazy[k],x);
      eval(k);
    }
    else if(a<r&&l<b){
      update(a,b,x,k*2+1,l,(l+r)/2);
      update(a,b,x,k*2+2,(l+r)/2,r);
      dat[k]=fx(dat[k*2+1],dat[k*2+2]);
    }
  }
  void update(int a,int b,M x) {update(a,b,x,0,0,n);}

  //O(log(n))
  X query(int a,int b) {return query_sub(a,b,0,0,n);}
  X query_sub(int a,int b,int k,int l,int r){
    eval(k);
    if(r<=a||b<=l){
      return ex;
    }
    else if(a<=l&&r<=b){
      return dat[k];
    }
    else{
      X vl=query_sub(a,b,k*2+1,l,(l+r)/2);
      X vr=query_sub(a,b,k*2+2,(l+r)/2,r);
      return fx(vl,vr);
    }
  }

  //O(log(n)+α??)
  X find_rightest(int a,int b,T x) {return find_rightest_sub(a,b,x,0,0,n);}  //[a,b)で x 以下の要素を持つ最右位置
  X find_leftest(int a,int b,T x) {return find_leftest_sub(a,b,x,0,0,n);}  //[a,b)で x 以下の要素を持つ最左位置
  X find_rightest_sub(int a,int b,T x,int k,int l,int r){
    eval(k);
    if(dat[k] < x ||r<=a||b<=l){
      return a-1;
    }
    else if (k>=n-1){
      return (k-(n-1));
    }
    else{
      X vr = find_rightest_sub(a,b,x,2*k+2,(l+r)/2,r);
      if (vr!=a-1){
          return vr;
      } else{
          return find_rightest_sub(a,b,x,2*k+1,l,(l+r)/2);
      }
    }
  }
  X find_leftest_sub(int a,int b,T x,int k,int l,int r){
    eval(k);
    if(dat[k] < x ||r<=a||b<=l){
      return b;
    }
    else if(k>=n-1){
      return (k-(n-1));
    }
    else{
      X vl=find_leftest_sub(a,b,x,2*k+1,l,(l+r)/2);
      if(vl!=b){
        return vl;
      }
      else{
        return find_leftest_sub(a,b,x,2*k+2,(l+r)/2,r);
      }
    }
  }
};

int main(){
  itn n,q; cin >> n >> q;

  using X=int;
  using M=int;
  auto fx=[](X x1,X x2) -> X {return max(x1,x2);};
  auto fa=[](X x,M m) -> X {return m;};
  auto fm=[](M m1,M m2) -> M {return m2;};
  int ex=-intmax;
  int em=-intmax;
  SegTreeLazy<X,M,int> rmq(n,fx,fa,fm,ex,em);
  
  for(int i=0;i<n;i++){
    int x; cin >> x;
    rmq.update(i,i+1,x);
  }

  vector<ll> ans(0);
  rep(i,q){
    itn t,a,b;
    cin >> t >> a >> b;
    if(t==1){
      a--;
      rmq.update(a,a+1,b);
    }
    else if(t==2){
      a--; b--;
      ans.push_back(rmq.query(a,b+1));
    }
    else{
      a--;
      ans.push_back(rmq.find_leftest(a,n,b)+1);
    }
  }
  rep(i,ans.size()){
    cout << ans[i] << endl;
  }
}