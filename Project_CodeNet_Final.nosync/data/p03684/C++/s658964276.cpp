#include <bits/stdc++.h>
using namespace std;

struct UnionFind{
  vector<int> p;
  UnionFind(int n){
    p.resize(n);
    for(int i=0; i<n; i++)  p[i] = i;
  }
  int find(int x){
    if(p[x] == x)  return x;
    return p[x] = find(p[x]);
  }
  void unite(int x, int y){
    x = find(x);
    y = find(y);
    if(x == y)  return;
    p[x] = y;
  }
};

int main(){
  int n;  cin >> n;
  vector<tuple<int, int, int>> xyn(n);  // <0>:x  <1>:y  <2>:idenfi.. number
  vector<vector<pair<int, int>>> g(n);  // first:cost   second:to
  for(int i=0; i<n; i++){
    cin >> get<0>(xyn[i]) >> get<1>(xyn[i]);
    get<2>(xyn[i]) = i;
  }
  vector<tuple<int, int, int>> edge;  // 0:cost  1:from  2:to
  sort(xyn.begin(), xyn.end(), [](auto &a, auto &b){ return get<0>(a) < get<0>(b);});
  for(int i=1; i<n; i++){
    //    g[get<2>(xyn[i-1])].push_back({get<0>(xyn[i])-get<0>(xyn[i-1]), get<2>(xyn[i])});
    //    g[get<2>(xyn[i])].push_back({get<0>(xyn[i])-get<0>(xyn[i-1]), get<2>(xyn[i-1])});
    edge.push_back({get<0>(xyn[i])-get<0>(xyn[i-1]), get<2>(xyn[i-1]), get<2>(xyn[i])});
  }
  sort(xyn.begin(), xyn.end(), [](auto &a, auto &b){ return get<1>(a) < get<1>(b);});
  for(int i=1; i<n; i++){
    //    g[get<2>(xyn[i-1])].push_back({get<1>(xyn[i])-get<1>(xyn[i-1]), get<2>(xyn[i])});
    //    g[get<2>(xyn[i])].push_back({get<1>(xyn[i])-get<1>(xyn[i-1]), get<2>(xyn[i-1])});
    edge.push_back({get<1>(xyn[i])-get<1>(xyn[i-1]), get<2>(xyn[i-1]), get<2>(xyn[i])});
  }
  sort(edge.begin(), edge.end());
  long ans = 0;
  UnionFind uf(n);
  for(auto nowe : edge){
    if(uf.find(get<1>(nowe)) == uf.find(get<2>(nowe)))  continue;
    uf.unite(get<1>(nowe), get<2>(nowe));
    ans += get<0>(nowe);
  }

  //  for(int i=0; i<n; i++)
  //    cout << get<0>(xyn[i]) << " " << get<1>(xyn[i]) << get<2>(xyn[i]) << endl;

  cout << ans << endl;

  return 0;
}
