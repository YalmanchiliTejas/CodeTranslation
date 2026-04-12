// see https://github.com/LumaKernel/vimfiles/tree/master/snippets/cp-cpp/temp.snip
/// --- .lumrc Template {{{ ///
// #define DEBUG
// #define assert(...)
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using P = tuple<ll, ll>;
using P3 = tuple<ll, ll, ll>;
using VI = vector<int>;
using VL = vector<ll>;
using VVI = vector<VI>;
using VVL = vector<VL>;
using VP = vector<P>;
using VS = vector<string>;

#define omajinai ios::sync_with_stdio(false),cin.tie(0)

#define FOR(i,a,b) for(int i=int(a);i<int(b);++i)
#define FORI(i,a,b) for(int i=int(a);i<=int(b);++i)
#define REP(i,n) FOR(i,0,n)
#define REPI(i,n) FORI(i,0,n)
#define RFOR(i,a,b) for(int i=int(b)-1;i>=int(a);--i)
#define RFORI(i,a,b) for(int i=int(b);i>=int(a);--i)
#define RREP(i,n) RFOR(i,0,n)
#define RREPI(i,n) RFORI(i,0,n)

#define ALL(a) begin(a),end(a)
#define UNIQUE(a) (a).erase(unique(ALL(a)),(a).end())
#define PB push_back
#define EACH(i,c) REP(i,(c).size())
#define REACH(i,c) RREP(i,(c).size())
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort(ALL(c))

#define BR cout<<"\n";

#ifdef DEBUG
#define dump(...) cerr<<"["<<__LINE__<< "] "<<#__VA_ARGS__<<" = "<<make_tuple(__VA_ARGS__)<<"\n";
#else
#define dump(...)
#endif

#define YES(x) cout<<((x)?"YES":"NO")<<"\n";
#define Yes(x) cout<<((x)?"Yes":"No")<<"\n";
#define yes(x) cout<<((x)?"yes":"no")<<"\n";

int __int_temp; ll __ll_temp; string __string_temp;
#define oini (omajinai, cin>>__int_temp, __int_temp)
#define oinl (omajinai, cin>>__ll_temp, __ll_temp)
#define oins (omajinai, cin>>__string_temp, __string_temp)
#define ini (cin>>__int_temp, __int_temp)
#define inl (cin>>__ll_temp, __ll_temp)
#define ins (cin>>__string_temp, __string_temp)

#define isInside(y,x) (0<=(y)&&(y)<h&&0<=(x)&&(x)<w)

#define fi(x) (get<0>(x))
#define se(x) (get<1>(x))
#define th(x) (get<2>(x))
#define fo(x) (get<3>(x))
#define fif(x) (get<4>(x))

template <typename T> ostream &operator<<(ostream &o, const vector<T> &v) { o << '{'; EACH(i, v) o << v[i] << (i != (int)v.size()-1 ? ", " : ""); o << "}";  return o; }

template<int n, class...T> typename enable_if<(n>=sizeof...(T))>::type _ot(ostream &, tuple<T...> const &){}
template<int n, class...T> typename enable_if<(n< sizeof...(T))>::type _ot(ostream & os, tuple<T...> const & t){ os << (n==0?"":", ") << get<n>(t); _ot<n+1>(os, t); }
template<class...T> ostream & operator<<(ostream & os, tuple<T...> const & t){ _ot<0>(os, t); return os; }

template <typename T> inline void smax(T &a, T b) { a = a > b ? a : b; }
template <typename T> inline void smin(T &a, T b) { a = a < b ? a : b; }

template<typename T> inline int intlog2(T x);
template<> inline int intlog2(int x) { return x == 0 ? 0 : 32 - __builtin_clz(x); }
template<> inline int intlog2(ll x) { return x == 0 ? 0 : 64 - __builtin_clzll(x); }

constexpr double PI = acos(-1);

/// }}}--- ///

constexpr int INF = 1e9+1;
constexpr ll LINF = 1e18+1;
constexpr int MOD = 1e9+7;

/// --- MOD Library {{{ ///

int modadd(int a, int b) { return (((a + b) % MOD ) + MOD ) % MOD; }
void sadd(int &a, int b) { a = modadd(a, b); }
int modmul(int a, int b) { return (ll) a * b % MOD; }
void smul(int &a, int b) { a = modmul(a, b); }
int modpow(int a, ll b) {
  int res = 1;
  while(b){
    if(b & 1) smul(res, a);
    smul(a, a);
    b>>=1;
  }
  return res;
}
int inv(int a) {
  return modpow(a, MOD - 2);
}

/// }}}--- ///

/// --- MOD Combination Library {{{ ///

VI fact, invFact;

void initFactorial(int n) {
  n++;
  fact.resize(n); invFact.resize(n);
  fact[0] = 1;
  FOR(i, 1, n) fact[i] = modmul(fact[i - 1], i);
  invFact[n-1] = inv(fact[n - 1]);
  RREP(i, n-1) invFact[i] = modmul(invFact[i + 1], i + 1);
}

int C(int n, int r) {
  return modmul(fact[n], modmul(invFact[r], invFact[n - r]));
}

/// }}}--- ///

int dp2[1010][1010];
int solve2(int x, int y) {
  if(x == 0) return 1;
  if(~dp2[x][y]) return dp2[x][y];
  return dp2[x][y] =
  modmul(C(x-1, y-1), solve2(x-y, y));
}

int n=ini, a=ini, b=ini, c=ini, d=ini;
int dp[1010][1010];
int solve(int left, int p) {
  if(left == 0) return 1;
  if(a+p > b) return 0;
  if(~dp[left][p]) return dp[left][p];
  int res = solve(left, p+1);
  FORI(i, c, d) {
    if((a+p) * i > left) break;
    int tmp = solve(left - (a+p)*i, p+1);
    smul(tmp, C(left, (a+p)*i));
    smul(tmp, solve2((a+p)*i, a+p));
    sadd(res, tmp);
  }
  return dp[left][p] = res;
}

int main() {
  memset(dp, -1, sizeof dp);
  memset(dp2, -1, sizeof dp2);
  initFactorial(2000);
  cout << solve(n, 0) << endl;
}
