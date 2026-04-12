#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <memory>
#include <cstring>
#include <cassert>
#include <numeric>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cctype>
#include <unordered_map>
#include <unordered_set>
using namespace std;

#define REP2(i, m, n) for (int i = (int)(m); i < (int)(n); i++)
#define REP(i, n) REP2(i, 0, n)
#define ALL(S) (S).begin(), (S).end()
typedef long long ll;

class UnionFind{
  int num_components;
  std::vector<int> parent;
  std::vector<int> weight;
  std::vector<int> rank;
public:
  UnionFind(int N) : num_components(N),
                     parent(std::vector<int>(N)),
                     weight(std::vector<int>(N, 1)),
                     rank(std::vector<int>(N, 0)){
    for(int i = 0; i < N; i++) parent[i] = i;
  }
  
  int find(int x){
    if(x == parent[x]) return x;
    else return parent[x] = find(parent[x]);
  }
  
  int size(int x){
    return weight[find(x)];
  }

  
  bool same(int x, int y){
    return find(x) == find(y);
  }
    
  void unite(int x, int y){
    x = find(x);
    y = find(y);
    if(x == y) return;
    
    num_components--;
    if(rank[x] < rank[y]){
      weight[y] += weight[x];
      parent[x] = y;
    }else{
      weight[x] += weight[y];
      parent[y] = x;
      if(rank[x] == rank[y]) rank[y]++;
    }
  }
  
  int count(){
    return num_components;
  }
};

int main(){
  ios::sync_with_stdio(false);

  int n, m;
  while (cin >> n >> m && n + m){
    UnionFind uf(n);

    int a, b;
    REP(i, m){
      cin >> a >> b;
      uf.unite(a - 1, b - 1);
    }

    ll res = 1;
    const ll mod = 1000 * 1000 * 1000 + 7;

    REP(i, uf.count()){
      res *= 2;
      res %= mod;
    }
    
    if (m > 0) res = (res + 1) % mod;

    cout << res << endl;
  }
  return 0;
}