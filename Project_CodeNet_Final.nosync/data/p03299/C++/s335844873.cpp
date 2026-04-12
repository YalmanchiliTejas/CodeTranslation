#include <stdio.h>
#include <bits/stdc++.h>

#define FOR(i, n)     for(lli i = 0; i < (lli)(n); ++i)
#define FORU(i, j, k) for(lli i = (j); i <= (lli)(k); ++i)
#define FORD(i, j, k) for(lli i = (j); i >= (lli)(k); --i)

#define SQ(x) ((x)*(x))

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back

using namespace std;

template<typename... As>
struct tpl : public std::tuple<As...> {
  using std::tuple<As...>::tuple;
  tpl(){}
  tpl(std::tuple<As...> const& b) { std::tuple<As...>::operator=(b); }

  template<typename T = tuple<As...> >
  typename tuple_element<0, T>::type const&
  x() const { return get<0>(*this); }
  template<typename T = tuple<As...> >
  typename tuple_element<0, T>::type&
  x() { return get<0>(*this); }

  template<typename T = tuple<As...> >
  typename tuple_element<1, T>::type const&
  y() const { return get<1>(*this); }
  template<typename T = tuple<As...> >
  typename tuple_element<1, T>::type&
  y() { return get<1>(*this); }

  template<typename T = tuple<As...> >
  typename tuple_element<2, T>::type const&
  z() const { return get<2>(*this); }
  template<typename T = tuple<As...> >
  typename tuple_element<2, T>::type&
  z() { return get<2>(*this); }

  template<typename T = tuple<As...> >
  typename tuple_element<3, T>::type const&
  w() const { return get<3>(*this); }
  template<typename T = tuple<As...> >
  typename tuple_element<3, T>::type&
  w() { return get<3>(*this); }
};

using lli   = long long int;
using llu   = long long unsigned;

using pii   = tpl<lli, lli>;
using piii  = tpl<lli, lli, lli>;
using piiii = tpl<lli, lli, lli, lli>;
using vi    = vector<lli>;
using vii   = vector<pii>;
using viii  = vector<piii>;
using vvi   = vector<vi>;
using vvii  = vector<vii>;
using vviii = vector<viii>;

template<class T>
using min_queue = priority_queue<T, vector<T>, greater<T> >;
template<class T>
using max_queue = priority_queue<T>;

template<size_t... I>
struct my_index_sequence {
  using type = my_index_sequence;
  static constexpr array<size_t, sizeof...(I)> value = { {I...} };
};

namespace my_index_sequence_detail {
  template<typename I, typename J> struct concat;
  template<size_t... I, size_t... J>
  struct concat<my_index_sequence<I...>, my_index_sequence<J...> > :
    my_index_sequence<I..., (sizeof...(I)+J)...> { };
  template<size_t N> struct make_index_sequence :
    concat<typename make_index_sequence<N/2>::type, typename make_index_sequence<N-N/2>::type>::type { };
  template <> struct make_index_sequence<0> : my_index_sequence<>{};
  template <> struct make_index_sequence<1> : my_index_sequence<0>{};
}

template<class... A>
using my_index_sequence_for = typename my_index_sequence_detail::make_index_sequence<sizeof...(A)>::type;

template<class T, size_t... I>
void print_tuple(ostream& s, T const& a, my_index_sequence<I...>){
  using swallow = int[];
  (void)swallow{0, (void(s << (I == 0? "" : ", ") << get<I>(a)), 0)...};
}

template<class T>
ostream& print_collection(ostream& s, T const& a);
template<class... A>
ostream& operator<<(ostream& s, tpl<A...> const& a);
template<class... A>
ostream& operator<<(ostream& s, tuple<A...> const& a);
template<class A, class B>
ostream& operator<<(ostream& s, pair<A, B> const& a);

template<class T, size_t I>
ostream& operator<<(ostream& s, array<T, I> const& a) { return print_collection(s, a); }
template<class T>
ostream& operator<<(ostream& s, vector<T> const& a) { return print_collection(s, a); }
template<class T, class U>
ostream& operator<<(ostream& s, multimap<T, U> const& a) { return print_collection(s, a); }
template<class T>
ostream& operator<<(ostream& s, multiset<T> const& a) { return print_collection(s, a); }
template<class T, class U>
ostream& operator<<(ostream& s, map<T, U> const& a) { return print_collection(s, a); }
template<class T>
ostream& operator<<(ostream& s, set<T> const& a) { return print_collection(s, a); }

template<class T>
ostream& print_collection(ostream& s, T const& a){
  s << '[';
  for(auto it = begin(a); it != end(a); ++it){
    s << *it;
    if(it != prev(end(a))) s << " ";
  }
  return s << ']';
}

template<class... A>
ostream& operator<<(ostream& s, tpl<A...> const& a){
  s << '(';
  print_tuple(s, a, my_index_sequence_for<A...>{});
  return s << ')';
}

template<class... A>
ostream& operator<<(ostream& s, tuple<A...> const& a){
  s << '(';
  print_tuple(s, a, my_index_sequence_for<A...>{});
  return s << ')';
}

template<class A, class B>
ostream& operator<<(ostream& s, pair<A, B> const& a){
  return s << "(" << get<0>(a) << ", " << get<1>(a) << ")";
}

//------------------------------------------------------------------------------

// --- BEGIN SNIPPET MODULAR ---

const lli MOD = 1e9+7;

inline lli fexp(lli a, lli b, lli m=MOD) {
  lli r = 1;
  while(b){
    if(b&1) r = (r*a)%m;
    a = (a*a)%m;
    b /= 2;
  }
  return r;
}

inline lli invmod(lli a, lli m=MOD) {
  return fexp(a, m-2, m);
}

lli nmod(lli x) { return (x%MOD+MOD)%MOD; }

struct Zn {
  lli x;
  Zn(lli x_) : x(x_) {
    x %= MOD;
    if(x<0) x = (x+MOD)%MOD;
  }

  Zn operator+(Zn const& o) const { return Zn(x+o.x); }
  Zn operator-(Zn const& o) const { return Zn(x-o.x); }
  Zn operator*(Zn const& o) const { return Zn(x*o.x); }

  Zn& operator+=(Zn const& o) { return *this = *this+o; }
  Zn& operator-=(Zn const& o) { return *this = *this-o; }
  Zn& operator*=(Zn const& o) { return *this = *this*o; }
};

pii egcd(lli a, lli b) {
  if(a%b==0) {
    return mt(0,1);
  }else{
    pii p = egcd(b,a%b);
    int u=p.x(), v=p.y();
    return mt(v, u-(a/b)*v);
  }
}

// solve x*a = b [mod m]
int solveInv(lli a, lli b, lli m) {
  if(b==0) return 0;
  pii p = egcd(a,m);
  lli g=__gcd(m,a);
  return (((b/g)*p.x())%m+m)%m;
}

// --- END SNIPPET MODULAR ---

const int N = 200;
lli H[N];
// lli dp[N+1][N+1];

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  lli n; cin>>n;
  FOR(i,n) cin>>H[i];
  function<pii(lli,lli,lli)> f = [&](lli from, lli i, lli j) -> pii { // (val with only hor, full val)
    if(i>j) return pii(1,1);
    lli a = i;
    FORU(b,i,j) if(H[b]<H[a]) a = b;
    lli x1,y1,x2,y2;
    tie(x1,y1) = f(H[a],i,a-1);
    tie(x2,y2) = f(H[a],a+1,j);

    lli x30 = (fexp(2, H[a]-from)) * x1 % MOD * x2 % MOD;
    lli x3 = (fexp(2, H[a]-from) - 1 + MOD) * x1 % MOD * x2 % MOD;
    lli y3 = ((a!=i?2:1)*(a!=j?2:1)%MOD*y1%MOD*y2%MOD + x3) % MOD;
    return mt(x30,y3);
  };
  lli x,y; tie(x,y) = f(1,0,n-1);
  cout << (2*y)%MOD << endl;
  // set<lli> allH(H,H+n);
  // allH.insert(0);
  // vi HS(all(allH));
  // int m = HS.size();
  // HS.eb((lli)1e10);
  // memset(dp,0,sizeof(dp));
  // dp[0][m] = 1;
  // lli last = 0;
  // FOR(i,n) {
  //   lli h = H[i];
  //   FOR(j,m+1) if(dp[i][j]) {
  //     cerr << mt(i,j) << " " << dp[i][j] << " " << HS[j] << " " << h << endl;
  //     if(HS[j] <= h) {
  //       (dp[i+1][j] += fexp(2, max(0ll,h-max(1ll,last))) * dp[i+1][j] % MOD) %= MOD;
  //     }else{
  //       (dp[i+1][m] += (last==0?1:2)*dp[i][j]) %= MOD;
  //       FOR(k,m) if(HS[k] > max(1ll,last) && HS[k] <= h) {
  //         (dp[i+1][k] += (last==0?1:2)*dp[i][j]%MOD*(fexp(2,HS[k]-(k==1?1:HS[k-1]))-1+MOD)%MOD*fexp(2,h-HS[k])%MOD) %= MOD;
  //       }
  //     }
  //   }
  //   last = h;

  //   FOR(j,m+1) cerr << dp[i+1][j] << " ";
  //   cerr << endl;
  // }
  // lli ans = 0;
  // FOR(i,m+1) (ans += dp[n][i]) %= MOD;
  // cout << (2*ans)%MOD << endl;
  return 0;
}
