#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
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
  ll n, x, m; cin >> n >> x >> m;
  map<int,int> mp;
  Vi a;
  int count = 0;
  ll sum = 0;
  while(mp.count(x) == 0) {
    a.push_back(x);
    sum += x;
    mp[x] = count;
    ++count;
    x = (ll) x * x % m;
  }
  // dump(mp);
  // dump(a,count,sum,x);
  if (n <= count) {
    ll ans = 0;
    rep(i,n) ans += a[i];
    plexit(ans)
  }
  ll c = 0;
  int s = count - mp[x];
  for (int i = mp[x]; i < count; ++i) c += a[i];
  ll ans = sum;
  n -= count;
  ans += n/s*c;
  // dump(sum,ans,n,s,c);
  n %= s;
  int si = mp[x];
  rep(i,n) ans += a[si+i];
  pl(ans)
  return 0;
}
