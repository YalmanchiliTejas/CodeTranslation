#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define each(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define rng(a) a.begin(),a.end()
#define maxs(x,y) x = max(x,y)
#define mins(x,y) x = min(x,y)
#define pb push_back
#define sz(x) (int)(x).size()
#define pcnt __builtin_popcount
#define uni(x) x.erase(unique(rng(x)),x.end())
#define snuke srand((unsigned)clock()+(unsigned)time(NULL));
#define df(x) int x = in()
#define dame { puts("-1"); return 0;}
#define show(x) cout<<#x<<" = "<<x<<endl;
#define PQ(T) priority_queue<T,vector<T>,greater<T> >
#define bn(x) ((1<<x)-1)
#define newline puts("")
#define v(T) vector<T>
#define vv(T) vector<vector<T>>
using namespace std;
typedef long long int ll;
typedef unsigned uint;
typedef unsigned long long ull;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
inline int in() { int x; scanf("%d",&x); return x;}
inline void priv(vi a) { rep(i,sz(a)) printf("%d%c",a[i],i==sz(a)-1?'\n':' ');}
template<typename T>istream& operator>>(istream&i,vector<T>&v)
{rep(j,sz(v))i>>v[j];return i;}
template<typename T>string join(const vector<T>&v)
{stringstream s;rep(i,sz(v))s<<' '<<v[i];return s.str().substr(1);}
template<typename T>ostream& operator<<(ostream&o,const vector<T>&v)
{if(sz(v))o<<join(v);return o;}
template<typename T1,typename T2>istream& operator>>(istream&i,pair<T1,T2>&v)
{return i>>v.fi>>v.se;}
template<typename T1,typename T2>ostream& operator<<(ostream&o,const pair<T1,T2>&v)
{return o<<v.fi<<","<<v.se;}
const ll LINF = 1e18;
const double eps = 1e-10;

// Mod int
const int mod = 998244353;
struct mint {
  ll x;
  mint():x(0){}
  mint(ll x):x((x%mod+mod)%mod){}
  // mint(ll x):x(x){}
  mint& fix() { x = (x%mod+mod)%mod; return *this;}
  mint& operator+=(const mint& a){ if((x+=a.x)>=mod) x-=mod; return *this;}
  mint& operator-=(const mint& a){ if((x+=mod-a.x)>=mod) x-=mod; return *this;}
  mint& operator*=(const mint& a){ (x*=a.x)%=mod; return *this;}
  mint& operator/=(const mint& a){ (x*=a.ex(mod-2).x)%=mod; return *this;}
  mint operator+(const mint& a)const{ return mint(*this) += a;}
  mint operator-(const mint& a)const{ return mint(*this) -= a;}
  mint operator*(const mint& a)const{ return mint(*this) *= a;}
  mint operator/(const mint& a)const{ return mint(*this) /= a;}
  mint ex(ll t) const {
    if(!t) return 1;
    mint res = ex(t/2);
    res *= res;
    return (t&1)?res*x:res;
  }
  bool operator<(const mint& a)const{ return x < a.x;}
  bool operator==(const mint& a)const{ return x == a.x;}
};
mint ex(mint x, ll t) { return x.ex(t);}
istream& operator>>(istream&i,mint&a){i>>a.x;return i;}
ostream& operator<<(ostream&o,const mint&a){o<<a.x;return o;}
typedef vector<mint> vm;
struct comb {
  vm f, g;
  comb(){}
  comb(int mx):f(mx+1),g(mx+1) {
    f[0] = 1;
    rrep(i,mx) f[i] = f[i-1]*i;
    g[mx] = f[mx].ex(mod-2);
    for(int i=mx;i>0;i--) g[i-1] = g[i]*i;
  }
  mint c(int a, int b) {
    if (a < b) return 0;
    return f[a]*g[b]*g[a-b];
  }
};
//

const int MX = 10005, INF = 1001001001;
// mint dp[MX][MX][MX];
v(vm) dp;

mint dfs(int a1, int a3) {
  mint& now = dp[a1][a3];
  if (now.x != -1) return now;
  if (!a1 && !a3) return now = 1;
  now = 0;
  if (a1) {
    now += dfs(a1-1,a3)*a1*a1;
    // if (a3) {
    //   now += dfs(a1-1,a2+1,a3-1)*a1*a3;
    // }
  }
  if (a1) {
    if (a3) {
      now += dfs(a1,a3-1)*a1*a3;
    }
  }
  // if (a3) {
  //   now += dfs(a1,a2,a3-1)*a3;
  //   if (a3 >= 2) now += dfs(a1+1,a2+1,a3-2)*(a3*(a3-1));
  // }
  // cerr<<a1<<" "<<a2<<" "<<a3<<" "<<now<<endl;
  return now;
}

int main() {
  string sa, sb;
  cin>>sa>>sb;
  int n = sz(sa);
  vi a(4);
  rep(i,n) {
    int x = 0;
    if (sa[i] == '1') x |= 1;
    if (sb[i] == '1') x |= 2;
    a[x]++;
  }

  // dp[a[1]][a[2]][a[3]] = 1;
  int a1 = a[1];
  int a2 = a[2];
  int a3 = a[3];
  // dp[0][0][0] = 1;
  // rep(i,a1+1)rep(j,a2+1)rep(k,a3+1) {
  //   if (!dp[i][j][k].x) continue;
  //   dp[i+1][j+1][k] += dp[i][j][k]*(a1-i)*(a2-j);
  //   dp[i][j+1][k+1] += dp[i][j][k]*(a3-k)*(a2-j);
  //   dp[i][j][k+1] += dp[i][j][k]*(a3-k)*(a2-j);
  //   if (i < j) dp[i+1][j][k] += dp[i][j][k]*(a1-i)*(j-i);
  // }
  // cout<<dp[a1][a2][a3]<<endl;

  // rep(i,MX)rep(j,MX)rep(k,MX) dp[i][j][k].x = -1;
  mint e; e.x = -1;
  dp = v(vm)(a1+1,vm(a3+1,e));
  // dp = vv(vm)(a1+1,v(vm)(a2+1,vm(a3+1,e)));
  // cout<<dfs(a1,a2,a3)<<endl;
  mint ans = 0;
  comb c(100005);
  rep(i,a3+1) {
    mint now = c.c(a3,i)*c.c(a1+a3,i)*c.f[i]*c.f[i];
    ans += dfs(a1,a3-i)*now;
  }
  cout<<ans<<endl;
  return 0;
}




















