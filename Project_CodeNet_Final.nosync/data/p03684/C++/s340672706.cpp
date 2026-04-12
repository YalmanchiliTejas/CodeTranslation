#include <iostream>
#include <queue>
#include <algorithm>
#include <set>
#include <vector>
#include <string>

using namespace std; using ll=long long; const int INF=1e9; using P=pair<ll,ll>;
struct tp {ll c,i,j; bool operator<(const tp t) const {if (c!=t.c) return c<t.c; else if (i!=t.i) return i<t.i; else return j<t.j;}
bool operator>(const tp t) const {if (c!=t.c) return c>t.c; else if (i!=t.i) return i>t.i; else return j>t.j;}};
struct unf {
  vector<int> v; unf(int n){v.resize(n); for(int i=0;i<n;i++) v[i]=i;}
  int root(int x) { if (v[x]==x) return x; return v[x]=root(v[x]);}
  void unite(int x,int y) {int p=root(x), q=root(y); if (p==q) return; v[p]=q;}
  bool same(int x, int y) {return root(x)==root(y);}
  void print() {for(int x:v) cout<<x<<" "; cout<<endl;}
};

int main() {
  int n; cin>>n;
  P x[n], y[n]; unf uu(n);
  for(int i=0;i<n;i++) cin>>x[i].first>>y[i].first;
  for(int i=0;i<n;i++) x[i].second=y[i].second=i;

  sort(x,x+n); sort(y,y+n);

  priority_queue<tp, vector<tp>, greater<tp>> que;
  for(int i=0;i<n-1;i++) {
    que.push({x[i+1].first-x[i].first, x[i+1].second, x[i].second});
    que.push({y[i+1].first-y[i].first, y[i+1].second, y[i].second});
  }

  ll an=0;
  while(!que.empty()) {
    tp o = que.top(); que.pop();
    //cout<<o.c<<" "<<o.i<<" "<<o.j<<endl;
    if (uu.same(o.i, o.j)) continue;
    an += o.c;
    uu.unite(o.i, o.j);
  }
  cout<<an<<endl;
}