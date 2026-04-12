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
const int MX = 200005;

// Union find
struct uf {
  vi d;
  uf(){}
  uf(int mx):d(mx,-1){}
  int root(int x) {
    if(d[x] < 0) return x;
    return d[x] = root(d[x]);
  }
  bool unite(int x, int y) {
    x = root(x); y = root(y);
    if(x == y) return false;
    if(d[x] > d[y]) swap(x,y);
    d[x] += d[y]; d[y] = x;
    return true;
  }
  int size(int x) { return -d[root(x)];}
};
//

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

vi conv(vi a) {
  int n = sz(a);
  rep(i,n) a[i]--;
  vi res;
  rep(i,n-1) {
    res.pb(min(a[i],a[i+1]));
  }
  return res;
}
mint f(vi a) {
  int n = sz(a);
  // cerr<<a<<endl;
  vp p(n);
  rep(i,n) p[i] = P(a[i],i);
  sort(rng(p)); reverse(rng(p));
  vi gid(n,-1);
  uf t(n);
  vi used;
  vp g;
  vvi to;
  for (int i = 0; i < n;) {
    int si = i;
    int now = p[si].fi;
    vvi chi;
    while (i < n && p[i].fi == now) {
      chi.pb(vi());
      int j = p[i].se;
      if (j && gid[t.root(j-1)] != -1) {
        int gi = gid[t.root(j-1)];
        t.unite(j,j-1);
        if (!used[gi]) {
          chi.back().pb(gi);
          used[gi] = 1;
          g[gi].se -= now;
        }
      }
      if (j+1 < n && gid[t.root(j+1)] != -1) {
        int gi = gid[t.root(j+1)];
        t.unite(j,j+1);
        if (!used[gi]) {
          chi.back().pb(gi);
          used[gi] = 1;
          g[gi].se -= now;
        }
      }
      if (j && (a[j-1] == now || t.root(j-1) != j-1)) {
        t.unite(j,j-1);
      }
      if (j+1 < n && (a[j+1] == now || t.root(j+1) != j+1)) {
        t.unite(j,j+1);
      }
      ++i;
    }
    vi js;
    srep(pi,si,i) {
      int j = p[pi].se;
      js.pb(t.root(j));
    }
    sort(rng(js)); uni(js);
    for (int j : js) {
      gid[j] = sz(used);
      used.pb(0);
      g.pb(P(t.size(j),now));
      to.pb(vi());
    }
    srep(pi,si,i) {
      int j = p[pi].se;
      int gi = gid[t.root(j)];
      for (int u : chi[pi-si]) to[gi].pb(u);
    }
  }
  mint res;
  int m = sz(g);
  // cerr<<"G "<<g<<endl;
  // rep(i,m) cerr<<to[i]<<endl;
  vm d1(m), d2(m);
  rep(i,m) {
    mint two = ex(2,g[i].se);
    d1[i] = two;
    int r = g[i].fi;
    mint x = 1, y = two-1;
    for (int j : to[i]) {
      r -= g[j].fi;
      d1[i] *= d1[j];
      x *= d2[j];
      y *= d1[j];
    }
    x *= ex(2,r);
    d2[i] = x+y;
  }
  // cerr<<d1<<endl;
  // cerr<<d2<<endl;
  res = d2.back();
  return res*2;
}

int main() {
  int n;
  scanf("%d",&n);
  vi a(n);
  cin>>a;
  a.insert(a.begin(),0);
  a.pb(0);
  ll cnt = 0;
  rrep(i,n) {
    int mx = max(a[i-1],a[i+1]);
    if (mx < a[i]) {
      cnt += a[i]-mx;
      a[i] = mx;
    }
  }
  rrep(i,n) {
    if (a[i] == 1) {
      ++cnt;
      a[i] = 0;
    }
  }
  // cerr<<a<<endl;
  mint ans = ex(2,cnt);
  vi x;
  rrep(i,n+1) {
    if (a[i]) {
      x.pb(a[i]);
    } else {
      if (sz(x)) {
        ans *= f(conv(x));
      }
      x = vi();
    }
  }

  cout<<ans<<endl;
  return 0;
}




















