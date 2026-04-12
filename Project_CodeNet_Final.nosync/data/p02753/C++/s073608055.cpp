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

struct uf{
  private:
    vi par, rank, size;
  public:
    uf(i64 n){ init(n); }
    void init(i64 n){
      par.resize(n);
      rank.resize(n,0);
      size.resize(n,1);
      rep(i,n) par[i] = i;
    }
    i64 root(i64 x){
      if(par[x] == x) return x;
      return par[x] = root(par[x]);
    }
    bool same(i64 x, i64 y){ return root(x) == root(y); }
    void unite(i64 x, i64 y){
      x = root(x), y = root(y);
      if(x==y) return;
      if(rank[x]==rank[y]) rank[x]++;
      if(rank[x]<rank[y]) swap(x,y);
      par[y] = x;
      size[x] += size[y];
    }
    i64 num(i64 x){ return size[root(x)]; }
};

void Main()
{
  v(char) s(3);
  rep(i,3) cin >> s[i];
  if(s[0] == s[1] && s[1] == s[2]) cout << "No\n";
  else cout << "Yes\n";

}

int main()
{
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(15);
  Main();
}
