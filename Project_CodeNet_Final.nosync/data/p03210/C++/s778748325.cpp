#include "bits/stdc++.h" // {{{
using namespace std; typedef long long ll; typedef pair<int,int> pii;
#define val         const auto
#define eb          emplace_back
#define emp         emplace
#define fi          first
#define se          second
#define outl(x)     cout << (x) << '\n'
#define rep(i,n)    for(int i=0; i < (int)(n); ++i)
#define repr(i,h,l) for(int i=(h); i >= (int)(l); --i)
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
  TMPLT(T,U) inline constexpr common_type_t<T,U> gcd(T x, U y)
  { return (x<y)? gcd(y,x) : (y <= 0)? x : gcd(y, x % y); }
  TMPLT(T,U) inline bool chmax(T &a, const U &b){return b>a ? a=b,1 : 0;}
  TMPLT(T,U) inline bool chmin(T &a, const U &b){return b<a ? a=b,1 : 0;}
  TMPLT(T,U) inline constexpr ll lcm(T x, U y) { return (ll)x/gcd(x,y) * y; }
  template<class Itr> string mkString(Itr begin, Itr end, const char *sp = " ") {
    static ostringstream oss; oss.str("");
    for(Itr i=begin; i != end; ++i) { if(i != begin)oss << sp; oss << *i; }
    return oss.str();
  }
  constexpr int INF = 0x3f3f3f3f; constexpr ll LINF = 0x3f3f3f3f3f3f3f3fLL;
  // }}}

constexpr int MX = ten(5) + 10;

void _main(const vector<char*> &args)
{
  int n; cin >> n;
  bool f = n == 3 || n == 5 || n == 7;
  outl(f ? "YES" : "NO");
}

} // {{{
signed main(signed argc, char *argv[]) {
#ifndef DEBUG
  ios::sync_with_stdio(false); cin.tie(nullptr);
#endif
  cout << fixed << setprecision(9); _main(vector<char*>(argv, argv+argc)); return 0;
} // }}}

