#include <bits/stdc++.h>

using namespace std;

typedef long long lli;
typedef double lld;
typedef vector<lli> vll;
typedef vector<bool> vbl;
typedef vector<double> vdl;
typedef vector<vector<lli>> mat;
typedef vector<vdl> mad;
typedef unordered_map<lli,unordered_map<lli,lli>> graph;
typedef complex<double> cmp;
typedef vector<cmp> vcl;

class union_find {
private:
  unordered_map<lli,lli> par;
  unordered_map<lli,lli> rnk;
public:
  // union_find (lli n){
  //   par = new vll(n);
  //   iota(par->begin(),par->end(),0);
  //   rnk = new vll(n,0);
  // }
  lli parent(lli x){
    if(par[x]) return par[x];
    else return par[x] = x;
  }
  lli find(lli x){
    if(parent(x) == x) return x;
    else return par[x] = find(parent(x));
  }
  void unite(lli x,lli y){
    x = find(x);y = find(y);
    if(x == y)return;
    if(rnk[x] < rnk[y]) par[x] = y;
    else {
      par[y] = x;
      if(rnk[x] == rnk[y]) rnk[x]++;
    }
  }
  bool same(lli x,lli y){
    return find(x) == find(y);
  }
};

lli n,m;
graph g;
graph t;
lli q;
union_find uf;
mat edge;
mat ans;
lli mst = 0;

void dfs(lli x, lli c, lli p, lli from){
  ans[from][x] = c;
  for(auto y : t[x]){
    if(y.first == p) continue;
    dfs(y.first, max(y.second, c), x, from);
  }
}


int main(){
  cin >> n >> m;
  edge = mat(m, vll(3));
  for(lli i=0;i < m;i++){
    cin >> edge[i][1] >> edge[i][2] >> edge[i][0];
  }
  sort(edge.begin(), edge.end());
  for(lli i = 0;i < m;i++){
    if(uf.same(edge[i][1], edge[i][2])) continue;
    uf.unite(edge[i][1], edge[i][2]);
    t[edge[i][1]][edge[i][2]] = t[edge[i][2]][edge[i][1]] = edge[i][0];
    mst += edge[i][0];
  }
  ans = mat(n+1,vll(n+1));
  for(lli i = 1;i <= n;i++){
    dfs(i, 0, 0, i);
  }
  cin >> q;
  for(lli i = 0;i <  q;i++){
    lli s,t;
    cin >> s >> t;
    cout << mst-ans[s][t] << endl;
  }
  return 0;
}
