#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
#define rng(a) a.begin(),a.end()
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
const int MX = 3005;

// ll solve(vi a) {
//   if (sz(a)&1) {
//     ll res = 0;
//     rep(i,sz(a)) res += (i&1)?-a[i]:a[i];
//     return res;
//   }
//   ll res = -LINF;
//   rep(ti,2) {
//     vi b = a;
//     ll now = 0;
//     if (ti) {
//       now = b.back();
//       b.pop_back();
//       now -= solve(b);
//     } else {
//       now = b[0];
//       b.erase(b.begin());
//       now -= solve(b);
//     }
//     maxs(res,now);
//   }
//   return res;
// }

ll dp[MX][MX];
int used[MX][MX];
vi a;

ll dfs(int l, int r) {
  if (l == r) return 0;
  if (used[l][r]) return dp[l][r];
  used[l][r] = 1;
  ll res = -LINF;
  maxs(res, a[l]-dfs(l+1,r));
  maxs(res, a[r-1]-dfs(l,r-1));
  return dp[l][r] = res;
}

int main() {
  int n;
  scanf("%d",&n);
  a = vi(n);
  cin>>a;
  // ll ans = solve(a);
  // cout<<ans<<endl;
  cout<<dfs(0,n)<<endl;
  return 0;
}




















