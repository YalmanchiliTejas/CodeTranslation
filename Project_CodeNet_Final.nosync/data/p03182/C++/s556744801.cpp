/*
                  友利奈緒ぱわーでACしてくれ！！！！！！！！！！！！
                  Charlotteまだ見てない人は見ような！！！！！！！

                  ／　 /:／　　　　　　　　　　　 　 ＼:ヽ　＼
  　　　　　　　 /　　／　　　　　　 　 　 　 　 　 　 　 ＼　　ヽ
  　　　　　＼__L 彡　　　　　　　　　　　　　　　　　　　 ヽ　　',
  　　　　　　　ﾌ /　　　/　　/　 /　　　,　　 　 　 　 ヽ　　', 　ｊ
  　　　　　　　ﾚ　　　 /　　/ 　/　 　 　 　 　 　 　 　 ', 　ヽ　j
  　　　 　 　 // 　 　 !　/_l＿/__ノ 　　{ ＼}　　　　 　 ',　　',/
  　　　　　　i ﾊ 　 　 {　从j　ﾊ　i　　　 ',　 ト-､}　 i i　 }　　jj
  　　　　　　( ﾊ　　　(　 川　ハ ﾊ　 !　 '　ﾊ　 ﾊ　j j　,' 　 八
  　　　 ＜＿,ｨ∧　　　斗芹ﾃミxハ ﾊ　 ﾚ　} /__ﾚﾚ　/ 　 ∧ ＼　ﾉ
  　　　 　 　 ∨　＼ 　ゝ　辷:ソ　　 　)　芹ﾚ心ヾレ′　/ ト--　´
  　　　＼ｰ‐'　ﾉ　　 ＼ゝ　　　　　　 　 　 ゞ:_ソ "/ 　／ 　ヽ
  　　　　 　 フ　　　　i八 " "　　　,　　　　　　　ム彡　　　　＼
  　　　　 　/　　/　　j　 ト　　　　　　 　 　 " "イト＜　 　 　 ＼＼
  　　　　 /　　/　　　j　/／ヽ､ 　 ∩　　 　 イ　{ {　　￣ フフへ ＼＼
  　　　　(　／　　　 ,/ / 　　i　＞――＜ニニニﾆ┐　 〃／: : ヽ　ヽヽ
  　　　　／　　ィT´/ /┌―　￣￣ /::: , ,)　 　 　 〃／／: : : : : :}　ヽヽ)
  　　　/ /　 ∧ヾi┌― { {￣　　　 ﾉ:::トﾟ<　 　 　 ∥//: : : : : : : : i　 ﾉ ﾉ
  . 　　( 人　 {:ヽヾi∨　∧V　　　 /:::/　､ヽ　　　 ∥/: : : : : : : : : :}　/
  　　　V　( ∧: :＼'∨　∧V　　 ﾉ:::/　 ∧ 〉＿__∥: : : : : :／: : : :ﾚ
  　　 　 　 /∧: : : : ∨　∧V┬ｲ:::ﾉ　 〈 TT　|　|{{: : : : ／: : : : : ∧　　 ﾉ
  　　　 　 (　ハ: : : : :∨'T∧Vi　i (　 　 V　!　!　{{: : ／ : : : : : : /　ｰ　ノ
  　　　　　V　ハ: : : : :∨ﾍ∧V　i ゝゝ　 i／⌒＼{／ : : : : : : : /ｰ― ´
  　　　　　 ∨　ヽ: : : : :∨ﾍ∧∨i　〉 〉 /　/二　 ): : : : : : : : :/

          (https://seesaawiki.jp/asciiart/d/Charlotte より)
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long; using ull = unsigned long long;
#define int ll
// #define DEBUG 42
inline void nprint(){}
template <class Head, class... Tail>
inline void nprint(Head &&head, Tail &&... tail) {
    cout << head << endl;
    nprint(move(tail)...);
}
#ifdef DEBUG
  #define eprint(...) nprint(__VA_ARGS__)
#else
  #define eprint(...) if(0==1) cout << 1 << endl;
#endif
#define Yes(a) cout << (a ? "Yes" : "No") << endl
#define YES(a) cout << (a ? "YES" : "NO") << endl
#define POSSIBLE(a) cout << (a ? "POSSIBLE" : "IMPOSSIBLE") << endl
using cmp = complex<double>;
using vb = vector<bool>; using vvb = vector<vb>;
using vi = vector<int>; using vvi = vector<vi>;
using vl = vector<ll>; using vvl = vector<vl>;
template<class T> using V = vector<T>;
template<class T> using VV = vector<V<T>>;
#define fi first
#define se second
#define maxs(x,y) (x=max<ll>(x,y))
#define mins(x,y) (x=min<ll>(x,y))
using pii = pair<int,int>; using pll = pair<ll,ll>;
#define FOR(i,a,b) for(ll i = (a); i < (ll)(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define FORS(i,a,b) FOR(i,a,b+1)
#define REPS(i,n) REP(i,n+1)
#define RFOR(i,a,b) for(ll i = (ll)(b)-1;i >= a;--i)
#define RREP(i,n) RFOR(i,0,n)
#define RREPS(i,n) RREP(i,n+1)
#define RFORS(i,a,b) RFOR(i,a,b+1)
#define ALL(obj) (obj).begin(), (obj).end()
#define RALL(obj) (obj).rbegin(), (obj).rend()
#define PERM(c) sort(ALL(c)); for(bool cp = true;cp;cp = next_permutation(ALL(c)))
#define eb(val) emplace_back(val)
#define bitcnt(val) __builtin_popcountll(val)
const double PI = acos(-1), EPS = 1e-10;
constexpr ll MOD = 1E9+7;
// constexpr ll MOD = 998244353;
constexpr int dx[] = {1,0,-1,0}; constexpr int dy[] = {0,1,0,-1};
template<typename T1, typename T2> ostream& operator<<(ostream& s, const pair<T1, T2>& p){
  return s << "(" << p.first << ", " << p.second << ")";
}
template<class T> istream& operator>>(istream &is,vector<T> &st){
  for(size_t i=0;i<st.size();++i) is >> st[i];
  return is;
}
template<class T> istream& operator>>(istream &is,vector<vector<T>> &st){
  for(size_t i=0;i<st.size();++i) is >> st[i];
  return is;
}
template<class T> ostream& operator<<(ostream &os, const vector<T> &st){
  for(size_t i=0;i<st.size();++i){
    if(i==st.size()-1) os << st[i];
    else os << st[i] << " ";
  }
  return os;
}
template<class T> ostream& operator<<(ostream &os, const vector<vector<T>> &st){
  for(size_t i=0;i<st.size();++i){
    os << st[i];
    if(i!=st.size()-1) os << endl;
  }
  return os;
}
template<typename T=int, typename E=int>
struct segment_tree{
  typedef function<T(T,T)> F;
  typedef function<T(T,E)> G;
  typedef function<E(E,E)> H;
  typedef function<E(E,int)> P;

  vector<T> data;
  vector<E> lazy;

  F f;
  G g;

  int n;

  T tid;

  H h;
  E eid;

  P p;

  // f is query monoid for merge. tid is f's identity element.
  // g is function that updates data(member value). g is often same as h.
  // h is function that updates lazy(member value). eid is h's identity element.
  // s.t. g(g(a,b),c) = g(a,h(b,c))
  // p is function that updates data from lazy. It depends on f.
  // p(a,b) = f(a,a,..,a). (b is the number of arguments a in f.)

  // If you'd like to use this segment tree for single update segmentree,
  // you should ignore the latter than T tid arguments.

  // Some unnesessary if statements in default arguments of constractor exists
  // in order to erase compiler warnings.(e.g. f(a,b)=a causes warning including unused paramator b.)
  segment_tree(int size, F f, G g, T tid, H h=[](E a,E b){return b!=a?b:a;}, E eid=0, P p=[](E a, int b){b=0;return a+b;}):f(f),g(g),tid(tid),h(h),eid(eid),p(p){
    n = 1;
    while(n<size) n<<=1;
    data.assign(2*n-1,tid), lazy.assign(2*n-1,eid);
  }
  segment_tree(vector<T> v, F f, G g, T tid, H h=[](E a,E b){return b!=a?b:a;}, E eid=0, P p=[](E a, int b){b=0;return a+b;}):f(f),g(g),tid(tid),h(h),eid(eid),p(p){
    int size = v.size();
    n = 1;
    while(n<size) n<<=1;
    data.resize(2*n-1,tid);
    assign(v);
  }
  void assign(vector<T> v){
    assert((int)v.size()<=n);
    for(size_t i=0;i<v.size();++i) data[i+n-1] = v[i];
    for(int i=v.size();i<n;++i) data[i+n-1] = tid;
    for(int i=n-2;i>=0;--i) data[i] = f(data[2*i+1],data[2*i+2]);
    lazy.assign(2*n-1,eid);
  }
  inline void eval(int k, int len){
    if(lazy[k]==eid) return;
    // if k has children.
    if(len > 1){
      lazy[2*k+1] = h(lazy[2*k+1],lazy[k]);
      lazy[2*k+2] = h(lazy[2*k+2],lazy[k]);
    }
    data[k] = g(data[k],p(lazy[k],len));
    lazy[k] = eid;
  }
  inline void recalc(){
    recalc(0,n);
  }
  inline void recalc(int k,int len){
    eval(k,len);
    if(len==1) return;
    recalc(2*k+1,len/2);
    recalc(2*k+2,len/2);
  }
  void update(int i, E x){
    i += n-1;
    data[i] = g(data[i],x);
    while(i>0){
      i = (i-1)/2;
      data[i] = f(data[2*i+1],data[2*i+2]);
    }
  }
  void update(int a,int b,E x){
    update(a,b,x,0,0,n);
  }
  void update(int a, int b, E x,int k, int l, int r){
    eval(k,r-l);
    // [l,r) out of [a,b)
    if(b<=l||r<=a) return;
    // [l,r) in [a,b)
    if(a<=l && r<=b){
      lazy[k] = h(lazy[k],x);
      eval(k,r-l);
    }else{
      update(a,b,x,2*k+1,l,(l+r)/2);
      update(a,b,x,2*k+2,(l+r)/2,r);
      data[k] = f(data[2*k+1],data[2*k+2]);
    }
  }
  T find(int i){
    return find(i,i+1,0,0,n);
  }
  // [a,b)
  T find(int a,int b){
    return find(a,b,0,0,n);
  }
  T find(int a,int b,int k,int l,int r){
    eval(k,r-l);
    // [l,r) out of [a,b)
    if(r<=a||b<=l) return tid;
    // [l,r) in [a,b)
    if(a<=l&&r<=b) return data[k];
    // else
    return f(find(a,b,2*k+1,l,(l+r)/2),find(a,b,2*k+2,(l+r)/2,r));
  }
};
signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);
  int n,m;
  cin >> n >> m;
  V<vi> a(m,vi(3));
  REP(i,m){
    cin >> a[i];
    swap(a[i][0],a[i][1]);
  }
  sort(ALL(a));
  REP(i,m){
    swap(a[i][0],a[i][1]);
  }
  auto f = [](ll a,ll b){return max<ll>(a,b);};
  auto g = plus<ll>();
  segment_tree<ll,ll> t(vl(n+3,0),f,g,INT_MIN*10LL,g,0);
  int mid = 0;
  FORS(i,1,n+1){
    t.update(i,i+1,t.find(0,i));
    while(mid < m && a[mid][1]==i){
      t.update(a[mid][0],i+1,a[mid][2]);
      mid++;
    }
  }
  cout << t.find(n+1) << endl;
}
