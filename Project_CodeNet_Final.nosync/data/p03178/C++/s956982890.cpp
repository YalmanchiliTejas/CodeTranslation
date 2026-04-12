#include <bits/stdc++.h>
#define rep(i,n) for (int i = (0); i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
#define rng(x) (x).begin(),(x).end()
#define rrng(x) (x).rbegin(),(x).rend()
#define limit(x,l,r) max(l,min(x,r))
#define lims(x,l,r) (x = max(l,min(x,r)))
#define isin(x,l,r) ((l) <= (x) && (x) < (r))
#define show(x) cout << #x << " = " << (x) << endl
#define show2(x,y) cout << #x << " = " << (x) << ", " << #y << " = " << (y) << endl
#define show3(x,y,z) cout << #x << " = " << (x) << ", " << #y << " = " << (y) <<  ", " << #z << " = " << (z) << endl
#define showv(v) rep(i,v.size()) printf("%d%c", v[i], i==v.size()-1?'\n':' ')
#define showv2(v) rep(j,v.size()) showv(v[j])
#define showt(t,n) rep(i,n) printf("%d%c", t[i], i==n-1?'\n':' ')
#define showt2(t,r,c) rep(j,r) showt(t[j],c)
#define showvp(p) rep(i,p.size()) printf("%d %d\n", p[i].first, p[i].second);
#define printv(v) rep(i,v.size()) printf("%d\n", v[i])
#define printt(t,n) rep(i,n) printf("%d\n", t[i])
#define incl(v,x) find(rng(v),x)!=v.end()
#define incls(s,c) s.find(c)!=string::npos
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
#define pcnt __builtin_popcountll
#define bit(n,k) ((n>>k)&1) // nのk bit目
#define bn(x) ((1<<x)-1)
#define dup(x,y) (((x)+(y)-1)/(y))
#define newline puts("")
#define uni(x) x.erase(unique(rng(x)),x.end())
#define SP << " " <<
#define v(T) vector<T>
#define vv(T) v(v(T))
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
typedef vector<P> vp;
typedef vector<T> vt;
const int mod = 1000000007;
const double EPS = 1e-9;
const int INF = (1<<30)-1;
const ll INFLL = (1LL<<62)-1;
#define dame { puts("No"); return 0;}
#define yn {puts("Yes");}else{puts("No");}
inline int in() { int x; scanf("%d",&x); return x;}
template<typename T>inline ll suma(const v(T)& a) { ll res(0); for (auto&& x : a) res += x; return res;}
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

//const int mod = 1000000007;
// mint(a).pow(b) -> a^b
struct mint {
  ll x;
  mint(ll x=0):x(x%mod){}
  mint operator-() const { return mint(-x);}
  mint operator~() const { return mint(1) / *this;}
  mint& operator+=(const mint a) { if ((x+=a.x)>=mod) x-=mod; return *this;}
  mint& operator-=(const mint a) { if ((x+=mod-a.x)>=mod) x-=mod; return *this;}
  mint& operator*=(const mint a) { (x *= a.x) %= mod; return *this;}
  mint operator+(const mint a) const { mint res(*this); return res+=a;}
  mint operator-(const mint a) const { mint res(*this); return res-=a;}
  mint operator*(const mint a) const { mint res(*this); return res*=a;}
  mint pow(ll t) const {
    if (!t) return 1;
    mint a = pow(t>>1);
    a *= a;
    if (t&1) a *= *this;
    return a;
  }
  // for prime mod
  mint inv() const { return pow(mod-2);}
  mint& operator/=(const mint a) { return (*this) *= a.inv();}
  mint operator/(const mint a) const { mint res(*this); return res/=a;}
  bool operator<(const mint& a)const{ return x < a.x;}
  bool operator==(const mint& a)const{ return x == a.x;}
};
istream& operator>>(istream&i,mint&a){i>>a.x;return i;}
ostream& operator<<(ostream&o,const mint&a){o<<a.x;return o;}

mint dp[10005][105][2];

int main () {
  string s;
  int D;
  cin >> s >> D;
  int n = s.size();
  dp[0][0][0] = 1;
  rep(i,n)rep(j,D)rep(k,2) {
    int nd = s[i]-'0';
    rep(d,10) {
      int ni = i+1, nj = (j+d)%D, nk = k;
      if (k == 0) {
        if (d > nd) continue;
        if (d < nd) nk = 1;
      }
      dp[ni][nj][nk] += dp[i][j][k];
    }
  }
  mint ans = dp[n][0][0];
  ans += dp[n][0][1];
  ans -= 1;
  cout << ans << endl;
  return 0;
}