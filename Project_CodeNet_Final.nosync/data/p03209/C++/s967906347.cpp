#include "bits/stdc++.h" // {{{
#ifdef DEBUG
#undef DEBUG
#endif
using namespace std; typedef long long ll; typedef pair<int,int> pii;
#define val         const auto
#define eb          emplace_back
#define emp         emplace
#define fi          first
#define se          second
#define outl(x)     cout << (x) << '\n'
#define rep(i,n)    for(int i=0; i < (int)(n); ++i)
#define repr(i,h,l) for(int i=(h); i >= (int)(l); --i)
#define reps(i,s,t) for(int i=(s); i <= (int)(t); ++i)
#define ALL(x)      begin(x), end(x)
#define TMPLT(T,U)  template<class T, class U>
#define ten(p)      ((long long)(1e##p))
#define FILL(a,v)   memset((a), (v), sizeof(a))
#ifdef  DEBUG
#define debug(...)  fprintf(stderr, __VA_ARGS__)
#define show(x)     clog << #x << " \t\t= " << (x) << '\n'
#define show2(x,y)  clog << '(' << #x << ',' << #y << ")\t\t= " << '(' << (x) << "\t, " << (y) << ")\n"
#define LN()        fputs("\n--------------------------------\n", stderr)
#else
#define debug(...)
#define show(x)
#define show2(x,y)
#define LN()
#endif
#define def(op) inline bool operator op (const T &that) const { return comp(that) op 0; }
template<class T> struct Ordered
{ virtual int comp(const T &that) const = 0; def(==); def(!=); def(<); def(<=); def(>); def(>=); };
#undef def
namespace {
  constexpr int INF = 0x3f3f3f3f; constexpr ll LINF = 0x3f3f3f3f3f3f3f3fLL; ostringstream _oss;
  TMPLT(T,U) inline constexpr common_type_t<T,U> gcd(T x, U y)
  { return (x<y)? gcd(y,x) : (y <= 0)? x : gcd(y, x % y); }
  TMPLT(T,U) inline bool chmax(T &a, const U &b){return b>a ? a=b,1 : 0;}
  TMPLT(T,U) inline bool chmin(T &a, const U &b){return b<a ? a=b,1 : 0;}
  TMPLT(T,U) inline constexpr ll lcm(T x, U y) { return (ll)x/gcd(x,y) * y; }
  template<class T>   string toString(const T &x){ _oss.str(""); _oss << x; return _oss.str(); }
  template<class Itr> string mkString(Itr begin, Itr end, const char *sp = " ") {
    _oss.str(""); for(Itr i=begin; i != end; ++i) { if(i != begin)_oss << sp; _oss << *i; }
    return _oss.str();
  }
  // }}}

constexpr int MX = ten(5) + 10;

ll memoP[55], memoB[55], memoA[55];

ll paty(int n)
{
  if (n == 0) {
    return 1;
  }
  ll &ret = memoP[n];
  if (~ret) return ret;
  return ret = 2LL * paty(n-1) + 1;
}

ll ban(int n)
{
  if (n == 0) {
    return 0;
  }
  ll &ret = memoB[n];
  if (~ret) return ret;
  return ret = 2LL * ban(n-1) + 2;
}

ll wa(int n) { return paty(n) + ban(n); }

ll N, X;

// sum = pの総数
// tail
ll slv(int n, ll sum, ll tail)
{
  if (n == 0) {
    return 1;
  }
  show(n);
  ll k = tail;

  // 1
  {
    k += 1;
    debug("[1] k=%lld, sum=%lld\n", k, sum);
    if (k > X) {
      return slv(n-1, sum, k-1);
    }
    else if (k == X) {
      return sum;
    }
  }

  // 2
  {
    k += wa(n-1);
    sum += paty(n-1);
    debug("[2] k=%lld, sum=%lld\n", k, sum);
    if (k > X) {
      return slv(n-1, sum-paty(n-1), k-wa(n-1));

    }
    else if (k == X) {
      return sum;
    }
  }

  // 3
  {
    k += 1;
    sum += 1;
    debug("[3] k=%lld, sum=%lld\n", k, sum);
    if (k > X) {
      return slv(n-1, sum-1, k-1);

    }
    else if (k == X) {
      return sum;
    }
  }

  // 4
  {
    k += wa(n-1);
    sum += paty(n-1);
    if (k > X) {
      return slv(n-1, sum-paty(n-1), k-wa(n-1));

    }
    else if (k == X) {
      return sum;
    }
  }


  // 5
  {
    k += 1;
    if (k > X) {
      return slv(n-1, sum, k-1);

    }
    else if (k == X) {
      return sum;
    }
  }

  exit(1);
}


void Xx_main_xX(const vector<char*> &args)
{
  paty(50);
  ban(50);
  cin >> N >> X;

  FILL(memoP, -1);
  FILL(memoB, -1);
  FILL(memoA, -1);


  /*
  ll p = paty(N);
  ll b = ban(N);

  show(p);
  show(b);
  show(p+b);
  */

  ll ans = slv(N, 0, 0);
  outl(ans);
}

} // {{{
signed main(signed argc, char *argv[]) {
#ifndef DEBUG
  ios::sync_with_stdio(false); cin.tie(nullptr);
#endif
  cout << fixed << setprecision(9); Xx_main_xX(vector<char*>(argv, argv+argc)); return 0;
} // }}}

