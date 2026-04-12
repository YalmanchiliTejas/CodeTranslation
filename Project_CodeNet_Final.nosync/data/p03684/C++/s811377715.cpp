#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;
typedef pair<ll, P> PPI;

#define fi first
#define se second
#define repl(i,a,b) for(ll i=(ll)(a);i<(ll)(b);i++)
#define rep(i,n) repl(i,0,n)
#define each(itr,v) for(auto itr:v)
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout<<#x"="<<x<<endl
#define mmax(x,y) (x>y?x:y)
#define mmin(x,y) (x<y?x:y)
#define maxch(x,y) x=mmax(x,y)
#define minch(x,y) x=mmin(x,y)
#define uni(x) x.erase(unique(all(x)),x.end())
#define exist(x,y) (find(all(x),y)!=x.end())
#define bcnt __builtin_popcount

#define INF INT_MAX/3

struct UnionFind{
  vector<int> v;
  UnionFind(int n) : v(n, -1) {}
  void init(){ for(int i = 0;i < v.size();i++)v[i]=-1; }
  int find(int x) { return v[x] < 0 ? x : v[x] = find(v[x]); }
  bool unite(int x, int y) {
    x = find(x); y = find(y);
    if (x == y) return false;
    if (-v[x] < -v[y]) swap(x, y);
    v[x] += v[y]; v[y] = x;
    return true;
  }
  bool root(int x) { return v[x] < 0; }
  bool same(int x, int y) { return find(x) == find(y); }
  int size(int x) { return -v[find(x)]; }
};

ll n,m;
P x[111111],y[111111];
PPI es[222222];

int main(){
	cin.sync_with_stdio(false);
  cin>>n;
  rep(i,n){
    cin>>x[i].fi>>y[i].fi;
    x[i].se=i; y[i].se=i;
  }
  sort(x,x+n); sort(y,y+n);
  rep(i,n-1){
    es[m++]=PPI(x[i+1].fi-x[i].fi,P(x[i+1].se,x[i].se));
    es[m++]=PPI(y[i+1].fi-y[i].fi,P(y[i+1].se,y[i].se));
  }
  sort(es,es+m);
  UnionFind uf(n);
  ll res=0;
  rep(i,m){
    if(!uf.same(es[i].se.fi,es[i].se.se)){
      uf.unite(es[i].se.fi,es[i].se.se);
      res+=es[i].fi;
    }
  }
  cout<<res<<endl;
	return 0;
}
