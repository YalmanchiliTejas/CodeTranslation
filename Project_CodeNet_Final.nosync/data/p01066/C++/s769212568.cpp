#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define repl(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repl(i,0,n)
#define all(x) (x).begin(),(x).end()
#define mmax(x,y) (x>y?x:y)
#define mmin(x,y) (x<y?x:y)
#define maxch(x,y) x=mmax(x,y)
#define minch(x,y) x=mmin(x,y)
#define uni(x) x.erase(unique(all(x)),x.end())
#define exist(x,y) (find(all(x),y)!=x.end())
#define bcnt __builtin_popcount

#define dbg(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
void _dbg(string){cerr<<endl;}
template<class H,class... T> void _dbg(string s,H h,T... t){int l=s.find(',');cerr<<s.substr(0,l)<<" = "<<h<<", ";_dbg(s.substr(l+1),t...);}
template<class T,class U> ostream& operator<<(ostream &o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream &o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}


class UnionFind {
public:
  int par[8], rank[8];
  UnionFind(){
    rep(i,8) par[i] = -1;
    rep(i,8) rank[i] = 0;
  }
  int find(int x){
    if(par[x]<0) return x;
    else return par[x] = find(par[x]);
  }
  void unite(int x, int y){
    x=find(x); y=find(y);
    if(x==y) return;
    if(rank[x] < rank[y]) swap(x,y);
    par[x] += par[y];
    par[y] = x;
    if(rank[x]==rank[y]) rank[x]++;
  }
  inline bool same(int x, int y){ return find(x) == find(y); }
  inline int size(int x){ return -par[find(x)]; }
};

int n;
int x[101],y[101];

int main(){
  scanf("%d",&n);
  rep(i,n) scanf("%d%d",x+i,y+i);

  using P = pair<int,int>;
  using PP = pair<P,int>;
  map<PP, vector<P>> lines;
  rep(i,n) repl(j,i+1,n){
    int dx=x[i]-x[j];
    int dy=y[i]-y[j];
    swap(dx,dy);
    dy = -dy;
    PP cp;
    if(dy==0){
      cp = PP({1,0}, y[i]+y[j]);
    }
    else if(dx==0){
      cp = PP({0,1}, x[i]+x[j]);
    }
    else{
      int g = __gcd(dx,dy);
      dx /= g; dy /= g;
      if(dx<0){ dx=-dx; dy = -dy; }
      cp = PP({dx,dy}, (y[i]+y[j])*dx - (x[i]+x[j])*dy);
    }
    lines[cp].push_back({i,j});
  }

  map<vector<int>, int> dp;
  vector<int> init(n);
  rep(i,n) init[i] = i;

  dp[init] = 0;
  int ref[8];
  for(auto &vp : lines){
    map<vector<int>, int> nxt(dp);
    for(auto &sv : dp){
      UnionFind uf;
      rep(i,n) uf.unite(i, sv.first[i]);
      for(auto &p : vp.second) uf.unite(p.first, p.second);

      rep(i,n) ref[i] = i;
      rep(i,n) ref[uf.find(i)] = min(i, ref[uf.find(i)]);
      vector<int> ns(n);
      rep(i,n) ns[i] = ref[uf.find(i)];

      auto itr = nxt.find(ns);
      if(itr == nxt.end()) nxt[ns] = sv.second + 1;
      else itr->second = min(itr->second, sv.second + 1);
    }
    swap(dp, nxt);
  }

  vector<int> fin(n,0);
  cout << dp[fin] << endl;

  return 0;
}

