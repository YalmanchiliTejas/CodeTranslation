#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;
#define rep(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define reps(i, n) for(int i=1, i##_len=(n); i<=i##_len; ++i)
#define rrep(i, n) for(int i=((int)(n)-1); i>=0; --i)
#define rreps(i, n) for(int i=((int)(n)); i>0; --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((int)(x).size())
#define pl(s) cout << (s) << "\n";
#define pls(...) {bool space = false; for(auto i : __VA_ARGS__) (cout << (space?" ":"") << i), space = true; cout << "\n";}
#define plexit(s) {cout << (s) << "\n"; exit(0);}
#define yes(s) cout << ((s)?"Yes":"No") << "\n";
#ifdef __LOCAL
#include <dump.hpp>
#define dump(...) DUMPOUT << "  " << string(#__VA_ARGS__) << ": " << "[" << to_string(__LINE__) << ":" << __FUNCTION__ << "]" << endl << "    ", dump_func(__VA_ARGS__)
#else
#define dump(...)
#endif
template<typename T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<typename T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
struct IOInit { IOInit() { cin.tie(nullptr); ios::sync_with_stdio(false); dump("READY"); /*cout << unitbuf;*/} } IO_INIT;
using ll = long long; using ull = unsigned long long; using ld = long double;
template<typename T = int> using V = vector<T>; template<typename T = int> using P = pair<T, T>;
using Vi = V<int>; using Vl = V<ll>; using Vd = V<ld>; using VVi = V<Vi>; using VVl = V<Vl>; using Pi = P<int>; using Pl = P<ll>; using Pd = P<ld>;
constexpr ll MOD = 1000000007; constexpr int INF = (1 << 30) - 1; constexpr ll INFL = 1LL << 60; constexpr ld EPS = 1e-12; constexpr ld PI = 3.141592653589793238462643383279;



signed main(void) {
  int h,w; cin >> h >> w;
  V<string> a(h);
  V<bool> rows(h);
  V<bool> cols(w);
  rep(i,h) {
    cin >> a[i];
    bool ok = false;
    rep(j,w) if (a[i][j] == '#') { ok = true; break; }
    rows[i] = ok;
  }
  rep(j,w) {
    bool ok = false;
    rep(i,h) if (a[i][j] == '#') { ok = true; break; }
    cols[j] = ok;
  }
  rep(i,h) {
    if (rows[i]) {
      rep(j,w) if (cols[j]) cout << a[i][j];
      cout << endl;
    }
  }

  return 0;
}
