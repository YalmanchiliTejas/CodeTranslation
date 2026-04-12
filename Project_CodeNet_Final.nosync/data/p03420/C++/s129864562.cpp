#include <bits/stdc++.h>
#pragma GCC target("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
using i64 = int64_t;
using f80 = __float80;
static const int dy[4] = {0,1,0,-1}, dx[4] = {1,0,-1,0};
constexpr i64 INF = 1'010'000'000'000'000'017LL;
constexpr i64 MOD = 1'000'000'007LL;
#define _overload3(_1,_2,_3,name,...) name
#define repi(i,start,end) for(i64 i=(start);i<(end);++i)
#define _rep(i,n) repi(i,0,n)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define rrep(i,start,end) for(i64 i=(start);i>end;--i)
#define rng(a) a.begin(),a.end()
#define rrng(a) a.rbegin(),a.rend()
#define isin(x,l,r) ((l) <= (x) && (x) < (r))
#define show(x) cout<<#x<<" = "<<x<<endl;
#define PQ(T) priority_queue<T,v(T),greater<T> >
#define v(T) vector<T>
#define vv(T) v(v(T))
typedef v(i64) vi;
typedef v(vi) vvi;
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return true;}return false;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return true;}return false;}
template<typename T> ostream &operator<<(ostream &os, const vector< T > &v){
  rep(i,v.size()) os << v[i] << (i + 1 != v.size() ? " " : "");
  return os;
}
template<typename T> istream &operator>>(istream &is, vector< T > &v){
  for(T &in : v) is >> in;
  return is;
}

void Main()
{
  i64 N, K;
  cin >> N >> K;

  i64 ans = 0;
  rep(b, K + 1, N + 1){
    ans += (N / b) * (b - K);
    if(N % b >= K){
      ans += (N % b - K + 1);
    }
  }

  if(K==0) ans -= N;

  cout << ans << "\n";
}

int main()
{
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(15);
  Main();
}