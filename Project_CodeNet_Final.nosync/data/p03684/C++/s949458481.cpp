#include <bits/stdc++.h>
using namespace std;
struct unionfind{
  vector<int> p;
  unionfind(int n){
    p = vector<int>(n, -1);
  }
  int root(int x){
    if (p[x] == -1){
      return x;
    } else {
      p[x] = root(p[x]);
      return p[x];
    }
  }
  bool same(int x, int y){
    return root(x) == root(y);
  }
  void unite(int x, int y){
    x = root(x);
    y = root(y);
    if (x != y){
      p[x] = y;
    }
  }
};
int main(){
  int N;
  cin >> N;
  vector<pair<int, int>> X(N), Y(N);
  for (int i = 0; i < N; i++){
    int x, y;
    cin >> x >> y;
    X[i] = make_pair(x, i);
    Y[i] = make_pair(y, i);
  }
  sort(X.begin(), X.end());
  sort(Y.begin(), Y.end());
  vector<tuple<int, int, int>> E;
  for (int i = 0; i < N - 1; i++){
    int v = X[i].second;
    int w = X[i + 1].second;
    int d = X[i + 1].first - X[i].first;
    E.push_back(make_tuple(d, v, w));
  }
  for (int i = 0; i < N - 1; i++){
    int v = Y[i].second;
    int w = Y[i + 1].second;
    int d = Y[i + 1].first - Y[i].first;
    E.push_back(make_tuple(d, v, w));
  }
  sort(E.begin(), E.end());
  int M = E.size();
  unionfind UF(N);
  long long ans = 0;
  for (int i = 0; i < M; i++){
    int d = get<0>(E[i]);
    int v = get<1>(E[i]);
    int w = get<2>(E[i]);
    if (!UF.same(v, w)){
      UF.unite(v, w);
      ans += d;
    }
  }
  cout << ans << endl;
}