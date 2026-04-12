#include <iostream>
#include <vector>
#include <set>
using namespace std;
const long long mod = (1e9) + 7;

struct UnionFind{
  vector<int> data;
  UnionFind(int n) : data(n, -1) {}
  bool unite(int x, int y){
    x = find(x);
    y = find(y);
    if(x != y){
      if(data[y] < data[x]) swap(x,y);
      data[x] += data[y];//高さを更新
      data[y] = x;//親を更新
    }
    return x != y;
  }
  bool same(int x, int y){ return find(x) == find(y); }
  int find(int x){
    if(data[x] < 0) return x;
    return data[x] = find(data[x]);
  }
};

int main(){
  int N, M;
  while(cin >> N >> M, N){
    UnionFind uf(N);
    for(int i = 0; i < M; ++i){
      int a, b;
      cin >> a >> b;
      --a,--b;
      uf.unite(a,b);
    }
    long long ans = 1;
    set<int> S;
    for(int i = 0; i < N; ++i) S.insert(uf.find(i));
    for(size_t i = 0; i < S.size(); ++i) ans *= 2, ans %= mod;
    ans += (N != (int)S.size());
    ans %= mod;
    cout << ans << endl;
  }
  return 0;
}

