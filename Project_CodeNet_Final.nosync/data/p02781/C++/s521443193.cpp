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
#define maxs(x,y) (x = max(x,y))
#define mins(x,y) (x = min(x,y))
#define isin(x,l,r) ((l) <= (x) && (x) < (r))
#define sz(x) (i64)(x).size()
#define bit(n) (1LL<<(n))
typedef vector<i64> vi;
typedef vector<vi> vvi;
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
  string N;
  cin >> N;
  i64 K;
  cin >> K;

  i64 ans=0;

  if(K==1){
    ans = i64(N[0]-'0')+(sz(N)-1)*9;
  }
  if(K==2){
    ans += 9*9*(sz(N)-1)*(sz(N)-2)/2;
    ans += i64(N[0]-'0'-1)*9*(sz(N)-1);
    rep(i,1,sz(N)){
      if(N[i]=='0') continue;
      ans += i64(N[i]-'0');
      ans += (sz(N)-1-i)*9;
      break;
    }
  }
  if(K==3){
    ans += 9*9*9*(sz(N)-1)*(sz(N)-2)*(sz(N)-3)/(3*2);
    ans += i64(N[0]-'0'-1)*9*9*(sz(N)-1)*(sz(N)-2)/2;
    rep(i,1,sz(N)){
      if(N[i]=='0') continue;
      ans += 9*9*(sz(N)-1-i)*(sz(N)-2-i)/2;
      ans += i64(N[i]-'0'-1)*9*(sz(N)-1-i);
      rep(ii,i+1,sz(N)){
        if(N[ii]=='0') continue;
        ans += i64(N[ii]-'0');
        ans += (sz(N)-1-ii)*9;
        break;
      }
      break;
    }
  }

  cout << ans << endl;
}

int main()
{
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(15);
  Main();
}
