#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
struct UnionFind
{
  vector< int > data;
  UnionFind(int sz)
  {
    data.assign(sz, -1);
  }
  int find(int k)
  {
    if(data[k] < 0) return(k);
    return(data[k] = find(data[k]));
  }
  void unite(int x, int y)
  {
    x = find(x), y = find(y);
    if(x != y) {
      if(data[x] > data[y]) swap(x, y);
      data[x] += data[y];
      data[y] = x;
    }
  }
};   
int main()
{
  int N, M, power[100001];
  power[0] = 1;
  for(int i = 1; i < 100001; i++) {
    power[i] = 1LL * power[i - 1] * 2 % mod;
  }
  while(scanf("%d %d", &N, &M), N) {
    UnionFind tree(N);
    for(int i = 0; i < M; i++) {
      int x, y;
      scanf("%d %d", &x, &y);
      tree.unite(--x, --y);
    }
    int group = 0;
    for(int i = 0; i < N; i++) {
      group += tree.find(i) == i;
    }
    printf("%d\n", power[group] + (group != N));
  }
}