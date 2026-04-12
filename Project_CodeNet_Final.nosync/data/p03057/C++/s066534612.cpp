#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
#define rng(a) a.begin(),a.end()
#define rrng(a) a.rbegin(),a.rend()
#define maxs(x,y) (x = max(x,y))
#define mins(x,y) (x = min(x,y))
#define limit(x,l,r) max(l,min(x,r))
#define lims(x,l,r) (x = max(l,min(x,r)))
#define isin(x,l,r) ((l) <= (x) && (x) < (r))
#define pb push_back
#define sz(x) (int)(x).size()
#define pcnt __builtin_popcountll
#define uni(x) x.erase(unique(rng(x)),x.end())
#define snuke srand((unsigned)clock()+(unsigned)time(NULL));
#define show(x) cout<<#x<<" = "<<x<<endl;
#define PQ(T) priority_queue<T,v(T),greater<T> >
#define bn(x) ((1<<x)-1)
#define dup(x,y) (((x)+(y)-1)/(y))
#define newline puts("")
#define v(T) vector<T>
#define vv(T) v(v(T))
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
template<typename T>inline istream& operator>>(istream&i,v(T)&v)
{rep(j,sz(v))i>>v[j];return i;}
template<typename T>string join(const v(T)&v)
{stringstream s;rep(i,sz(v))s<<' '<<v[i];return s.str().substr(1);}
template<typename T>inline ostream& operator<<(ostream&o,const v(T)&v)
{if(sz(v))o<<join(v);return o;}
template<typename T1,typename T2>inline istream& operator>>(istream&i,pair<T1,T2>&v)
{return i>>v.fi>>v.se;}
template<typename T1,typename T2>inline ostream& operator<<(ostream&o,const pair<T1,T2>&v)
{return o<<v.fi<<","<<v.se;}
template<typename T>inline ll suma(const v(T)& a) { ll res(0); for (auto&& x : a) res += x; return res;}
const double eps = 1e-10;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
#define dame { puts("-1"); return 0;}
#define yn {puts("YES");}else{puts("NO");}
const int MX = 200005;

// Mod int
const int mod = 1000000007;
struct mint {
  ll x;
  mint():x(0){}
  mint(ll x):x((x%mod+mod)%mod){}
  // mint(ll x):x(x){}
  mint& fix() { x = (x%mod+mod)%mod; return *this;}
  mint operator-() const { return mint(0) - *this;}
  mint& operator+=(const mint& a){ if((x+=a.x)>=mod) x-=mod; return *this;}
  mint& operator-=(const mint& a){ if((x+=mod-a.x)>=mod) x-=mod; return *this;}
  mint& operator*=(const mint& a){ (x*=a.x)%=mod; return *this;}
  mint operator+(const mint& a)const{ return mint(*this) += a;}
  mint operator-(const mint& a)const{ return mint(*this) -= a;}
  mint operator*(const mint& a)const{ return mint(*this) *= a;}
  bool operator<(const mint& a)const{ return x < a.x;}
  bool operator==(const mint& a)const{ return x == a.x;}
};
istream& operator>>(istream&i,mint&a){i>>a.x;return i;}
ostream& operator<<(ostream&o,const mint&a){o<<a.x;return o;}
typedef vector<mint> vm;
typedef vector<vm> vvm;
//

void one(int n) {
  mint ans = 0;
  rep(si,2) {
    vm dp(2);
    dp[si] = 1;
    rep(i,n-1) {
      vm p(2); swap(dp,p);
      dp[0] = p[0]+p[1];
      dp[1] = p[0];
    }
    ans += dp[0];
    if (!si) ans += dp[1];
  }
  cout<<ans<<endl;
}

mint two(int n, vi x) {
  vvm dp(2,vm(n+1));
  vvm ds(2,vm(n+1));
  dp[0][0] = 1;
  rep(i,n) {
    if (i) {
      rep(j,2) ds[j][i+1] = ds[j][i-1]+dp[j][i];
    } else {
      rep(j,2) ds[j][i+1] = dp[j][i];
    }
    rep(j,2) {
      int l = max(0,i-x[j]);
      dp[j][i+1] = ds[j^1][i+1]-ds[j^1][l];
    }
  }
  // rep(i,2) cerr<<dp[i]<<endl;
  mint res = 0;
  rep(i,n) {
    if (i%2 == 0) continue;
    if (i > x[0]) break;
    res += dp[1][n-i]*i;
  }
  // cerr<<x<<" "<<res<<endl;
  return res;
}

int main() {
  int n,m;
  scanf("%d%d",&n,&m);
  string s;
  cin>>s;
  vi a(1);
  char pre = s[0];
  rep(i,m) {
    if (pre != s[i]) a.pb(0);
    a.back()++;
    pre = s[i];
  }
  if (sz(a) == 1) {
    one(n);
    return 0;
  }
  vi x(2,INF);
  x[1] = 1;
  rep(i,sz(a)-1) {
    int now = 0;
    if (!i) {
      now = a[i]/2*2+1;
    } else {
      if (a[i]%2 == 0) continue;
      now = a[i];
    }
    mins(x[i&1],now);
  }
  mint ans;
  rep(ri,2) {
    ans += two(n,x);
    reverse(rng(x));
  }
  cout<<ans<<endl;
  return 0;
}




















