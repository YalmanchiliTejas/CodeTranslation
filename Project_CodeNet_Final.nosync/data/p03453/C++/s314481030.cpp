#include <assert.h>
#include <limits.h>
#include <stdio.h>

#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#include <utility>

using namespace std;

typedef long long LL;

static constexpr LL LIMIT = 1000000007;

LL norm(LL v) {
  return (v + LIMIT) % LIMIT;
}

LL sq(LL v) {
  return norm(v * v);
}

int main() {
  int N, M;
  int S, T;
  cin >> N >> M >> S >> T;
  vector<vector<pair<LL, int>>> edges(N+1);
  for (int i = 0; i < M; i++) {
    int u, v, d;
    cin >> u >> v >> d;
    edges[u].emplace_back(d, v);
    edges[v].emplace_back(d, u);
  }

  vector<LL> dists(N+1);
  {
    for (LL& d : dists) d = -1;
    multimap<LL, int> q;
    q.emplace(0, S);
    while (!q.empty()) {
      auto iter = q.begin();
      LL d = iter->first;
      int v = iter->second;
      q.erase(iter);
      if (dists[v] >= 0)
        continue;

      dists[v] = d;
      for (pair<LL, int> p : edges[v]) {
        q.emplace(d + p.first, p.second);
      }
    }
  }

  vector<LL> dp1(N+1);
  {
    for (LL& d : dp1) d = 0;
    dp1[S] = 1;

    multimap<LL, int> verts;
    for (size_t i = 1; i < dists.size(); i++) {
      verts.emplace(dists[i], i);
    }

    for (pair<LL, int> p : verts) {
      LL d = p.first;
      int v = p.second;
      if (v == S)
        continue;

      LL num_paths = 0;
      for (pair<LL, int> np : edges[v]) {
        LL nd = np.first;
        int nv = np.second;
        if (dp1[nv] > 0 && d - nd == dists[nv]) {
          num_paths = norm(num_paths + dp1[nv]);
        }
      }

      dp1[v] = num_paths;
    }
  }

  vector<LL> dp2(N+1);
  {
    for (LL& d : dp2) d = 0;
    dp2[T] = 1;

    multimap<LL, int> verts;
    for (size_t i = 1; i < dists.size(); i++) {
      verts.emplace(-dists[i], i);
    }

    for (pair<LL, int> p : verts) {
      LL d = -p.first;
      int v = p.second;
      if (v == T)
        continue;

      LL num_paths = 0;
      for (pair<LL, int> np : edges[v]) {
        LL nd = np.first;
        int nv = np.second;
        if (dp2[nv] > 0 && d + nd == dists[nv]) {
          num_paths = norm(num_paths + dp2[nv]);
        }
      }

      dp2[v] = num_paths;
    }
  }

  LL ans = sq(dp1[T]);
  LL dt = dists[T];

  for (int v = 1; v <= N; v++) {
    if (dists[v] * 2 == dt) {
      LL s = norm(sq(dp1[v]) * sq(dp2[v]));
      ans = norm(ans - s);
    }
  }

  for (int v = 1; v <= N; v++) {
    for (pair<LL, int> p : edges[v]) {
      LL c = p.first;
      int u = p.second;
      LL du = dists[u];
      LL dv = dists[v];
      if (du * 2 < dt && dv * 2 > dt && du + c == dv) {
        LL s = norm(sq(dp1[u]) * sq(dp2[v]));
        ans = norm(ans - s);
      }
    }
  }

  printf("%lld\n", ans);
}
