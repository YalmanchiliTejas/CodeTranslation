#include <bits/stdc++.h>
using namespace std;
#define repl(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repl(i,0,n)
#define mp(a,b) make_pair((a),(b))
#define pb(a) push_back((a))
#define all(x) (x).begin(),(x).end()
#define uniq(x) sort(all(x)),(x).erase(unique(all(x)),end(x))
#define fi first
#define se second
#define dbg(...) _dbg(#__VA_ARGS__",", __VA_ARGS__)
void _dbg(string){cout<<endl;}
template<class H,class... T> void _dbg(string s,H h,T... t){int l=s.find(',');cout<<s.substr(0,l)<<" = "<<h<<", ";_dbg(s.substr(l+1),t...);}
template<class T,class U> ostream& operator<<(ostream& o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream& o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

#define INF 1120000000
#define long long long // for codeforces

class UnionFind {
public:
  vector<int> par, rank; // parent(negative := its root and abs-value is its size), depth
  UnionFind(int sz) : par(sz, -1), rank(sz, 0){}
  int find(int x){
    if(par[x]<0) return x;
    else return par[x] = find(par[x]);
  }
  void unite(int x, int y){
    x=find(x); y=find(y);
    if(x==y) return;  // already belong to same tree
    if(rank[x] < rank[y]){  // y becomes parent node
      par[y] += par[x];
      par[x] = y;
    } else {  // x becomes parent node
      par[x] += par[y];
      par[y] = x;
      if(rank[x]==rank[y]) rank[x]++;
    }
  }
  bool same(int x, int y){ return find(x) == find(y); }
  int size(int x){ return -par[find(x)]; }
};


int main(){
  int n;
  cin>>n;
  vector<pair<pair<int,int>,int>> vec(n);
  rep(i,n) cin>>vec[i].fi.fi>>vec[i].fi.se;
  rep(i,n) vec[i].se=i;

  vector<pair<int,pair<int,int>>> vv;

  sort(all(vec));
  rep(i,n-1){ vv.pb(mp(vec[i+1].fi.fi-vec[i].fi.fi, mp(vec[i].se,vec[i+1].se))); }

  rep(i,n) swap(vec[i].fi.fi, vec[i].fi.se);
  sort(all(vec));
  rep(i,n-1){ vv.pb(mp(vec[i+1].fi.fi-vec[i].fi.fi, mp(vec[i].se,vec[i+1].se))); }

  sort(all(vv));

  UnionFind uf(n);

  long ans = 0;
  for(auto pp : vv){
    int x =pp.se.fi, y =pp.se.se;
    if(!uf.same(x,y)){
      uf.unite(x,y);
      ans += pp.fi;
    }
  }
  cout << ans << endl;

  return 0;
}
