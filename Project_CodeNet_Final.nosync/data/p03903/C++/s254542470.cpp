#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <algorithm>
#include <bitset>
#include <complex>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include <cassert>
#include <functional>

typedef long long ll;
using namespace std;

#ifndef LOCAL
#define debug(...) ;
#else
#define debug(...) cerr << __LINE__ << " : " << #__VA_ARGS__ << " = " << _tostr(__VA_ARGS__) << endl;

template<typename T>
ostream &operator<<(ostream &out, const vector<T> &v);

template<typename T1, typename T2>
ostream &operator<<(ostream &out, const pair<T1, T2> &p) {
  out << "{" << p.first << ", " << p.second << "}";
  return out;
}

template<typename T>
ostream &operator<<(ostream &out, const vector<T> &v) {
  out << '{';
  for (const T &item : v) out << item << ", ";
  out << "\b\b}";
  return out;
}

void _tostr_rec(ostringstream &oss) {
  oss << "\b\b \b";
}

template<typename Head, typename... Tail>
void _tostr_rec(ostringstream &oss, Head &&head, Tail &&... tail) {
  oss << head << ", ";
  _tostr_rec(oss, forward<Tail>(tail)...);
}

template<typename... T>
string _tostr(T &&... args) {
  ostringstream oss;
  int size = sizeof...(args);
  if (size > 1) oss << "{";
  _tostr_rec(oss, forward<T>(args)...);
  if (size > 1) oss << "}";
  return oss.str();
}
#endif

#define mod 1000000007 //1e9+7(prime number)
#define INF 1000000000 //1e9
#define LLINF 2000000000000000000LL //2e18
#define SIZE 400010

/* UnionFind */

struct UnionFind {
  vector<int> data;
  UnionFind(int s): data(s, -1) {}

  int root(int x) {
    if (data[x] < 0) return x;
    return data[x] = root(data[x]);
  }

  bool set(int x, int y) {
    x = root(x);
    y = root(y);
    if (x == y) return false;
    if (data[x] > data[y]) swap(x, y);
    data[x] += data[y];
    data[y] = x;
    return true;
  }

  bool check(int x, int y) {
    return root(x) == root(y);
  }

  int size(int x) {
    return -data[root(x)];
  }
};

vector<pair<int, int>> G[SIZE];
int depth[SIZE], parent[20][SIZE];
int dp[20][SIZE];

void dfs(int now, int back = -1, int d = 0, int c = 0) {
  depth[now] = d;
  parent[0][now] = back;
  dp[0][now] = c;

  for (auto e : G[now]) {
    int to = e.first;
    int c = e.second;
    if (back == to) continue;
    dfs(to, now, d + 1, c);
  }
}

int main() {
  int N, M, Q, a[SIZE], b[SIZE], c[SIZE];
  ll ans = 0;
  pair<int, int> es[SIZE];

  scanf("%d%d", &N, &M);

  UnionFind uf(N);

  for (int i = 0; i < M; i++) {
    scanf("%d%d%d", a + i, b + i, c + i);
    a[i]--;
    b[i]--;
    es[i] = {c[i], i};
  }

  sort(es, es + M);

  for (int i = 0; i < M; i++) {
    int idx = es[i].second;

    if (uf.set(a[idx], b[idx])) {
      G[a[idx]].push_back({b[idx], c[idx]});
      G[b[idx]].push_back({a[idx], c[idx]});
      ans += c[idx];
    }
  }

  dfs(0);

  for (int i = 0; i < 15; i++) {
    for (int j = 0; j < N; j++) {
      if (parent[i][j] != -1) {
        parent[i + 1][j] = parent[i][parent[i][j]];
        dp[i + 1][j] = max(dp[i][j], dp[i][parent[i][j]]);
      } else {
        parent[i + 1][j] = -1;
        dp[i + 1][j] = 0;
      }
    }
  }

  scanf("%d", &Q);

  for (int i = 0; i < Q; i++) {
    int S, T;
    scanf("%d%d", &S, &T);
    S--;
    T--;

    if (depth[S] > depth[T]) swap(S, T);

    int maxC = 0;

    for (int i = 15; i >= 0; i--) {
      if (depth[S] + (1 << i) > depth[T]) continue;

      maxC = max(maxC, dp[i][T]);
      T = parent[i][T];
    }

    assert(depth[S] == depth[T]);

    for (int i = 15; i >= 0; i--) {
      if (parent[i][S] != parent[i][T]) {
        maxC = max({maxC, dp[i][S], dp[i][T]});
        S = parent[i][S];
        T = parent[i][T];
      }
    }

    if (S != T) {
      assert(parent[0][S] == parent[0][T]);
      maxC = max({maxC, dp[0][S], dp[0][T]});
    }

    debug(maxC);
    printf("%lld\n", ans - maxC);
  }

  return 0;
}