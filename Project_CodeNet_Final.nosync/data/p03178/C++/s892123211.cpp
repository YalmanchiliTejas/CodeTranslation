/* <ik:include(base.hpp)> */
/* subset of bits/stdc++.h */
#include<algorithm>
#include<iomanip>
#include<iostream>
#include<map>
#include<numeric>
#include<vector>

using namespace std;

using LL = long long;
using ULL = unsigned long long;
#define int LL
#define times(n, i)      uptil(0, n, i)
#define rtimes(n, i)     downto((n) - 1, 0, i)
#define upto(f, t, i)    for(auto i##0_to = (t), i = decltype(t)(f); i <= i##0_to; i++)
#define uptil(f, t, i)   for(auto i##0_to = (t), i = decltype(t)(f); i <  i##0_to; i++)
#define downto(f, t, i)  for(auto i##0_to = decltype(f)(t), i = (f); i >= i##0_to; i--)
#define downtil(f, t, i) for(auto i##0_to = decltype(f)(t), i = (f); i >  i##0_to; i--)
#define iter(v) begin(v), end(v)
#define citer(v) cbegin(v), cend(v)
#if defined(EBUG) && !defined(ONLINE_JUDGE)
  #define debug true
  #define _GLIBCXX_DEBUG
  #define _LIBCPP_DEBUG 2
  #define _LIBCPP_DEBUG2 2
  #define ln << endl
  #define dd(x) cerr << #x << " = " << (x) << ", "
  #define ddd(x) cerr << #x << " = " << (x) ln
#else
  #define debug false
  #define ln << '\n'
  #define dd(x) cerr
  #define ddd(x) cerr
#endif
#define tb << '\t'
#define sp << ' '
#define db dd
#define dbg ddd
#if __cplusplus >= 201703L
  #if debug
    #define PARABLE execution::par_unseq,
  #else
    #define PARABLE execution::seq,
  #endif
#else
  #define PARABLE /* none */
#endif
#define CS const
#define IL inline
#define RT return
#define TL template
#define lambda [&]
#define foldl accumulate
#define scanl accumulate
typedef struct unit{}unit;

TL<class T> void amax(T&v,const T&a){v=max(v,a);}
TL<class T> void amin(T&v,const T&a){v=min(v,a);}

namespace kpl {
  template<class V, class W>
  static inline void append(V& v, const W& w) { copy(PARABLE citer(w), back_inserter(v)); }

  template<class V>
  static inline auto flatten(const V& xss, unsigned reserve_size = 0) {
    vector<decltype(*begin(*begin(xss)))> ret;
    ret.reserve(reserve_size);
    for(const auto& xs : xss) append(ret, xs);
    ret.shrink_to_fit();
    return move(ret);
  }

  template<class I>
  static inline bool is_in(I x, I l, I r) { /* Of course half-open interval [l,r) is used */
    return l <= x && x < r;
  }
}
/* <ik:include(mod.hpp)> */
#ifndef MOD
#ifdef MOD9
#define MOD 1000000009
#elif defined MOD998244353
#define MOD 998244353
#else
#define MOD 1000000007
#endif
#endif
/* <ik:include(power.hpp)> */
TL<class T> T power(T x,ULL n){T rt(1);while(n){if(n%2)rt*=x;x*=x;n/=2;}RT rt;}
/* </ik:include(power.hpp)> */
IL int modulo(int a,int m){a%=m;RT a>=0?a:a+m;}
TL<ULL mod=MOD>class MInt{
  /*
    int with modulo.
    `mod` must be a prime for `log`.
    `mod` must be coprime to `val` for `inv` and to `m.val` for `operator/` and `operator/=`.
  */
  /*! https://ei1333.github.io/luzhiled/snippets/other/mod-int.html */
public:
  int val;
  MInt():val(0){}
  explicit MInt(int v):val(modulo(v,mod)){}
  MInt&operator+=(CS MInt&m){val+=m.val;if(val>=mod)val-=mod;RT*this;}
  MInt&operator-=(CS MInt&m){val-=m.val;if(val<0)val+=mod;RT*this;}
  MInt&operator*=(CS MInt&m){val=val*m.val%mod;RT*this;}
  MInt&operator/=(CS MInt&m){val=val*m.inv().val%mod;RT*this;}
  MInt operator+(CS MInt&m)CS{RT MInt(*this)+=m;}
  MInt operator-(CS MInt&m)CS{RT MInt(*this)-=m;}
  MInt operator*(CS MInt&m)CS{RT MInt(*this)*=m;}
  MInt operator/(CS MInt&m)CS{RT MInt(*this)/=m;}
  MInt operator-()CS{MInt m;m.val=val?mod-val:0;RT m;}
  bool operator==(CS MInt&m)CS{RT val==m.val;}
  bool operator!=(CS MInt&m)CS{RT val!=m.val;}
  //MInt pow(int n)CS{MInt x(*this),rt(1);while(n){if(n%2)rt*=x;x*=x;n/=2;}RT rt;}
  MInt pow(int n)CS{RT power(*this,n);}
  MInt inv()CS{int a=val,b=mod,x=1,y=0,t;while(b){t=a/b;swap(b,a-=t*b);swap(y,x-=t*y);}RT(MInt)x;}
  friend ostream&operator<<(ostream&o,CS MInt<mod>&m){RT o<<m.val;}
  friend istream&operator>>(istream&i,MInt<mod>&m){int v;i>>v;m=MInt<mod>(v);RT i;}
};
using mint=MInt<>;
#pragma rab:gsub \b(\d+)m\b mint(\1)
/* </ik:include(mod.hpp)> */
/* <ik:include(vector_usings.hpp)> */
TL<class T> using vec = vector<T>;
TL<class T> using vvec = vec<vec<T>>;
#define VUSE(v,t)using P##v=pair<t,t>;using V##v=vec<t>;using W##v=vvec<t>
VUSE(I,int);VUSE(M,mint);VUSE(PI,PI);VUSE(PM,PM);
/* </ik:include(vector_usings.hpp)> */
/* <ik:include(debug.hpp)> */
TL<class T>
IL istream&operator>>(istream&s,vec<T>&v){for(auto&&p:v)s>>p;RT s;}
TL<class T,class S>
IL ostream&operator<<(ostream&s,CS pair<T,S>&p){RT s<<"("<<p.first<<","<<p.second<<")";}
TL<class T>
IL ostream&operator<<(ostream&,CS vec<T>&);
TL<class T,class S>
IL ostream&operator<<(ostream&,CS map<T,S>&);
#define DEFINE_ITER_OUTPUT(s,x,sep){int i=0;for(CS auto&x##0_elem:x){if(i++)s<<sep;s<<x##0_elem;}RT s;}
TL<class T>
IL ostream&operator<<(ostream&s,CS vec<T>&v)DEFINE_ITER_OUTPUT(s,v,' ')
TL<class T,class S>
IL ostream&operator<<(ostream&s,CS map<T,S>&m)DEFINE_ITER_OUTPUT(s,m,' ')
TL<class T>
IL ostream&operator<<(ostream&s,CS vec<vec<T>>&w)DEFINE_ITER_OUTPUT(s,w,'\n')
TL<class T,class S>
IL ostream&operator<<(ostream&s,CS vec<map<T,S>>&v)DEFINE_ITER_OUTPUT(s,v,'\n')
/* </ik:include(debug.hpp)> */

void solve();

signed main() {
  if(debug) {
    cerr << "mod = " << MOD ln;
  } else {
    cin.tie(0);
    ios::sync_with_stdio(0);
  }
  cout << fixed << setprecision(20);
  cerr << fixed << setprecision(20);

  solve();

  return 0;
}
/* </ik:include(base.hpp)> */

string K;int D;
mint memo[10000][2][100];
bool visited[10000][2][100];

/*! http://luzhiled.hatenablog.com/entry/2017/12/03/124453 */
mint pyon(int i = 0, bool free = false, int sum = 0) {
  if(i == K.size()) return mint(sum == 0);
  mint &ans = memo[i][free][sum];
  if(visited[i][free][sum]) return ans;
  visited[i][free][sum] = true;

  int r = free ? 9 : K[i] - '0';
  upto(0, r, j) {
    ans += pyon(i+1, free || j != r, (sum + j) % D);
  }
  return ans;
}

void solve(){
// "KD
/* <foxy.memo-area> */
cin>>K;cin>>D;
/* </foxy.memo-area> */
  cout << pyon() - mint(1) ln;
}
