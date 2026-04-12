#include <bits/stdc++.h>
using namespace std;
using LL = int64_t;
using ULL = uint64_t;
using P = pair<LL, LL>;
#define rep(i, n) for (LL i = 0; i < (n); ++i)
//#define DEBUG

LL f(const vector<vector<LL>> &edges, vector<bool> &visited,
     const LL pos, const LL depth, const LL n) {
  #ifdef DEBUG
  string s = "";
  rep(i, depth) {
    s += "  ";
  }
  cout << s << pos << endl;
  #endif

  if (depth == n) {
    return (LL)1;
  }

  visited.at(pos) = true;
  LL sum = (LL)0;
  for (const auto i: edges.at(pos)) {
    //cout << "* " << i << endl;
    if (!visited.at(i)) {
      sum += f(edges, visited, i, depth + 1, n);
    }
  }
  visited.at(pos) = false;
  return sum;
}

int main() {
  LL n, m;
  cin >> n >> m;

  vector<vector<LL>> edges(n, vector<LL>());

  for (LL i = 0; i < m; ++i) {
    LL a, b;
    cin >> a >> b;
    edges[a - 1].push_back(b - 1);
    edges[b - 1].push_back(a - 1);
  }

  vector<bool> visited(n, false);
  cout << f(edges, visited, 0, 1, n) << endl;
  #ifdef DEBUG
  #endif
}

