#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long lint;

const int mod = 1e9 + 7;

struct edge_t {
  int other, dist;
};

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  int start, finish;
  scanf("%d %d", &start, &finish), --start, --finish;

  vector<vector<edge_t>> adj(n);
  for (int i = 0; i < m; ++i) {
    int a, b, dist;
    scanf("%d %d %d", &a, &b, &dist), --a, --b;
    adj[a].push_back({b, dist});
    adj[b].push_back({a, dist});
  }

  vector<lint> mindist(n, LLONG_MAX);
  priority_queue<pair<lint, int>,
                 vector<pair<lint, int>>,
                 greater<pair<lint, int>>> pq;
  mindist[start] = 0LL;
  pq.emplace(mindist[start], start);
  while (!pq.empty()) {
    lint mindist_v;
    int v;
    tie(mindist_v, v) = pq.top();
    pq.pop();
    if (mindist_v != mindist[v])
      continue;
    for (const edge_t &ed : adj[v])
      if (mindist[ed.other] > mindist[v] + ed.dist) {
        mindist[ed.other] = mindist[v] + ed.dist;
        pq.emplace(mindist[ed.other], ed.other);
      }
  }
  vector<int> nodebydist(n);
  iota(nodebydist.begin(), nodebydist.end(), 0);
  sort(nodebydist.begin(), nodebydist.end(),
       [&](int a, int b) { return mindist[a] < mindist[b]; });

  vector<int> startcount(n, 0);
  startcount[start] = 1;
  for (const int &v : nodebydist) {
    if (v == start) continue;
    for (const edge_t &ed : adj[v]) {
      int u = ed.other;
      if (mindist[v] == mindist[u] + ed.dist) {
        startcount[v] += startcount[u];
        if (startcount[v] >= mod) startcount[v] -= mod;
      }
    }
  }

  vector<int> finishcount(n, 0);
  finishcount[finish] = 1;
  reverse(nodebydist.begin(), nodebydist.end());
  for (const int &v : nodebydist) {
    if (v == finish) continue;
    for (const edge_t &ed : adj[v]) {
      int u = ed.other;
      if (mindist[u] == mindist[v] + ed.dist) {
        finishcount[v] += finishcount[u];
        if (finishcount[v] >= mod) finishcount[v] -= mod;
      }
    }
  }

  assert(finishcount[start] == startcount[finish]);

  int result = (lint)finishcount[start] * finishcount[start] % mod;
  for (int v = 0; v < n; ++v) {
    if (2 * mindist[v] == mindist[finish]) {
      int path_through = (lint)startcount[v] * finishcount[v] % mod;
      result = (result - (lint)path_through * path_through) % mod;
      if (result < 0) result += mod;
    }
    for (const edge_t &ed : adj[v]) {
      const int u = ed.other;
      if (mindist[u] == mindist[v] + ed.dist &&
          2 * mindist[v] < mindist[finish] &&
          mindist[finish] < 2 * mindist[u]) {
        int path_through = (lint)startcount[v] * finishcount[u] % mod;
        result = (result - (lint)path_through * path_through) % mod;
        if (result < 0) result += mod;
      }
    }
  }
  printf("%d\n", result);
  return 0;
}
