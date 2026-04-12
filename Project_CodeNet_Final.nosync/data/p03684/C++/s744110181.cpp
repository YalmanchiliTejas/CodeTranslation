#include<bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(v) begin(v), end(v)

using int64 = long long;
const int INF = 1 << 30;
const int mod = 1e9 + 7;

struct UnionFind
{
  vector< int > data;

  UnionFind(int sz)
  {
    data.assign(sz, -1);
  }

  bool unite(int x, int y)
  {
    x = find(x), y = find(y);
    if(x == y) return (false);
    if(data[x] > data[y]) swap(x, y);
    data[x] += data[y];
    data[y] = x;
    return (true);
  }

  int find(int k)
  {
    if(data[k] < 0) return (k);
    return (data[k] = find(data[k]));
  }

  int size(int k)
  {
    return (-data[find(k)]);
  }
};


int main()
{
  int N, X[100000], Y[100000];

  cin >> N;
  rep(i, N) cin >> X[i] >> Y[i];
  vector< int > ord(N);
  iota(all(ord), 0);
  sort(all(ord), [&](int x, int y)
  {
    return (X[x] < X[y]);
  });

  vector< tuple< int, int, int > > es;
  for(int i = 1; i < N; i++) {
    es.emplace_back(X[ord[i]] - X[ord[i - 1]], ord[i], ord[i - 1]);
  }

  iota(all(ord), 0);
  sort(all(ord), [&](int x, int y)
  {
    return (Y[x] < Y[y]);
  });

  for(int i = 1; i < N; i++) {
    es.emplace_back(Y[ord[i]] - Y[ord[i - 1]], ord[i], ord[i - 1]);
  }

  sort(begin(es), end(es));

  int64 ret = 0;
  UnionFind uf(N);
  for(auto &e : es) {
    int a, b, c;
    tie(a, b, c) = e;
    if(uf.unite(b, c)) ret += a;
  }

  cout << ret << endl;
}