#include <bits/stdc++.h>

using namespace std;
using llong = long long;
using ldbl = long double;
using lpair = pair<llong, llong>;

#define ALL(x) x.begin(), x.end()

constexpr llong mod = 1e9+7;
constexpr llong inf = mod * mod;

int main() {
  llong N, X, M;
  cin >> N >> X >> M;

  if (X == 0) {
    cout << 0 << endl;
    return 0;
  }
  else if (N == 1) {
    cout << X << endl;
    return 0;
  }

  vector<llong> visited;
  map<llong, llong> use;
  llong ans = 0;
  while (!use.count(X) && N--) {
    use[X] = visited.size();
    visited.push_back(X);
    ans += X;
    X = X * X % M;
  }

  llong sum = 0;
  for (int i = use[X]; i < visited.size(); i++) {
    sum += visited[i];
  }

  llong len = visited.size() - use[X];
  ans += N / len * sum;
  N %= len;
  for (int i = 0; i < N; i++) {
    ans += visited[use[X] + i];
  }

  cout << ans << endl;

  return 0;
}