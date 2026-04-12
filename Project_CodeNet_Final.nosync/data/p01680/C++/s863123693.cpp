#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long int;

const ll MOD = 1000000007;
ll mod_pow(ll n, ll k) {
  ll ret = 1;
  for(; k>0; k>>=1) {
    if(k & 1) (ret *= n) %= MOD;
    (n *= n) %= MOD;
  }
  return ret;
}

const int S = 100010;
struct UnionFind {
  vector<int> node;
  int size_;
  UnionFind(int n) {
    node.resize(n, -1);
    size_ = n;
  }
  void reset() {
    fill(node.begin(), node.end(), -1);
  }
  int find(int x) {
    return node[x] < 0 ? x : node[x] = find(node[x]);
  }
  bool unite(int x, int y) {
    x = find(x), y = find(y);
    if(x == y) return false;
    size_--;
    node[x] += node[y];
    node[y] = x;
    return true;
  }
  int size() {
    return size_;
  }
};
  
int main() {
  ll N, M;
  while(cin >> N >> M, N || M) {
    UnionFind uf(N);
    for(int i=0; i<M; i++) {
      int a, b; cin >> a >> b;
      a--; b--;
      uf.unite(a, b);
    }

    int ans = mod_pow(2, uf.size());
    if(uf.size() != N) ans++;
    cout << ans << endl;
  }
  return 0;
}

