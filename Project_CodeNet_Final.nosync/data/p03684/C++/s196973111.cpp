#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <complex>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
P p[100000];
P x[100000];
P y[100000];

struct Edge{
  int s,t;
  Edge():s(0),t(0){}
  Edge(int s,int t):s(s),t(t){}
  bool operator < (const Edge& rhs) const;
};

ll len(Edge x){ // x \in E
  P p1 = p[x.s];
  P p2 = p[x.t];
  P v = P(p1.first-p2.first, p1.second-p2.second);
  return min(abs(v.first),abs(v.second));
}

bool Edge::operator < (const Edge& rhs) const{
  const Edge& lhs = *this;
  return len(lhs)<len(rhs);
}

vector<Edge> E;

struct UnionFind {
  vector<int> data;
  UnionFind(int size) : data(size, -1) { }
  bool unionSet(int x, int y) {
    x = root(x); y = root(y);
    if (x != y) {
      if (data[y] < data[x]) swap(x, y);
      data[x] += data[y]; data[y] = x;
    }
    return x != y;
  }
  bool findSet(int x, int y) {
    return root(x) == root(y);
  }
  int root(int x) {
    return data[x] < 0 ? x : data[x] = root(data[x]);
  }
  int size(int x) {
    return -data[root(x)];
  }
};

ll kruskal(){
  UnionFind UF(n);
  ll ret = 0;
  for(Edge e:E){
    if(!UF.findSet(e.s,e.t)){
      ret+=len(e);
      UF.unionSet(e.s,e.t);
    }
  }
  return ret;
}

int main(){
  cin>>n;
  for(int i=0;i<n;++i){
    int a,b;
    cin>>a>>b;
    p[i]=P(a,b);
    x[i]=P(a,i);
    y[i]=P(b,i);
  }
  sort(x,x+n);
  sort(y,y+n);

  for(int i=0;i<n-1;++i){
    E.push_back(Edge(x[i].second, x[i+1].second));
    E.push_back(Edge(y[i].second, y[i+1].second));
  }

  sort(E.begin(), E.end());
  cout << kruskal() << endl;
  return 0;
}
