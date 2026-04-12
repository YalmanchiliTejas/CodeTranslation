#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <iomanip>
using namespace std;

#define int long long
typedef pair<int, int> P;
typedef pair<long long, P> P2;
#define rep(i, n) for (int i=0; i<(n); i++)
#define all(c) (c).begin(), (c).end()
#define uniq(c) c.erase(unique(all(c)), (c).end())
#define _1 first
#define _2 second
#define pb push_back
#define INF 1145141919
#define MOD 1000000007

int N;
int X[100000], Y[100000];
int U[100000], R[100000];

int find(int x) {
  if (U[x] == x) return x;
  return U[x] = find(U[x]);
}

void unite(int x, int y) {
  x = find(x), y = find(y);
  if (x == y) return;
  if (R[x] < R[y]) swap(x, y);
  U[y] = x;
  R[x] += R[y];
  R[y] = 0;
}

bool same(int x, int y) {
  return find(x) == find(y);
}

vector<P2> edges;

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  vector<P> xy, yx;
  cin >> N;
  for (int i=0; i<N; i++) U[i] = i, R[i] = 1;
  rep(i, N) {
    cin >> X[i] >> Y[i];
    xy.pb(P(X[i], i));
    yx.pb(P(Y[i], i));
  }
  sort(all(xy));
  sort(all(yx));
  for (int i=1; i<xy.size(); i++) {
    int a = xy[i-1]._2, b = xy[i]._2;
    edges.pb(P2(abs(X[a]-X[b]), P(a, b)));
  }
  for (int i=1; i<yx.size(); i++) {
    int a = yx[i-1]._2, b = yx[i]._2;
    edges.pb(P2(abs(Y[a]-Y[b]), P(a, b)));
  }
  long long sum = 0;
  sort(all(edges));
  for (P2 p : edges) {
    long long cost = p._1;
    int a = p._2._1, b = p._2._2;
    if (!same(a, b)) {
      sum += cost;
      unite(a, b);
    }
  }
  cout << sum << "\n";
  return 0;
}
