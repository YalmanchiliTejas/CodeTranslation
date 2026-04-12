#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using f80 = __float80;
constexpr i64 INF = 1'010'000'000'000'000'017LL;
constexpr i64 MOD = 1'000'000'007LL;
static const int dy[4] = {0,1,0,-1}, dx[4] = {1,0,-1,0};
#define _overload3(_1,_2,_3,name,...) name
#define repi(i,start,end) for(i64 i=(start);i<(end);++i)
#define _rep(i,n) repi(i,0,n)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define rrep(i,start,end) for(i64 i=(start);i>end;--i)
#define pb push_back
#define rng(a) a.begin(),a.end()
#define isin(x,l,r) ((l) <= (x) && (x) < (r))
#define sz(x) (i64)(x).size()
#define bit(n) (1LL<<(n))
#define fi first
#define se second
#define show(x) cout<<#x<<" = "<<x<<endl;
#define PQ(T) priority_queue<T,v(T),greater<T> >
#define v(T) vector<T>
#define vv(T) v(v(T))
typedef v(i64) vi;
typedef v(vi) vvi;
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return true;}return false;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return true;}return false;}

i64 pow_mod(i64 n, i64 k, i64 m){
  i64 r = 1;
  for(;k;k>>=1){
    if(k&1) r=(r*n)%m;
    n=(n*n)%m;
  }
  return r;
}

void Main()
{
  i64 A,B,C,X,Y;
  cin >> A >> B >> C >> X >> Y;

  i64 ans = X*A + Y*B;
  chmin(ans,C*X*2+max(i64(0),Y-X)*B);
  chmin(ans,C*Y*2+max(i64(0),X-Y)*A);

  cout << ans << endl;

}

int main()
{
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(15);
  Main();
}
