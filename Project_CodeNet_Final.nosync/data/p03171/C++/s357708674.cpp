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
#define bn(x) ((1<<x)-1)
#define dup(x,y) (((x)+(y)-1)/(y))
#define newline puts("")
#define uni(x) x.erase(unique(rng(x)),x.end())
#define SP << " " <<
#define v(T) vector<T>
#define vv(T) v(v(T))
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vs = vector<string>;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
typedef vector<pii> vp;
typedef vector<tiii> vt;
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

ll dp[3100][3100];

int main () {
  int n;
  cin >> n;
  vi a(n);
  rep(i,n) cin >> a[i];

  rep(i,n) dp[i][i] = 0;
  for (int len = 1; len <= n; ++len) {
    for (int i = 0; i+len <= n; ++i) {
      int j = i + len;
      if ((n-len)%2 == 0) {
        dp[i][j] = max(dp[i+1][j]+a[i], dp[i][j-1]+a[j-1]);
      }
      else {
        dp[i][j] = min(dp[i+1][j]-a[i], dp[i][j-1]-a[j-1]);
      }
    }
  }

  cout << dp[0][n] << endl;
  return 0;
}