#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<pii> vpii;

struct pair_hash {
  size_t operator() (const pair<int, int> &p) const {
    return hash<int>()(p.first) ^ hash<int>()(p.second);
  }
};

int main() {
  int N, M;
  cin >> N >> M;
  vi a(M), b(M);
  for (int i = 0; i < M; i++) {
    cin >> a[i] >> b[i];
    a[i] -= 1;
    b[i] -= 1;
  }

  vvi G(N);
  for (int i = 0; i < M; i++) {
    G[a[i]].push_back(b[i]);
    G[b[i]].push_back(a[i]);
  }

  vvi d(N, vi(1 << N));
  queue<pair<int, int>> q;
  d[0][1] = 1;
  q.push({0, 1});

  while(q.size()) {
    pair<int, int> from = q.front();
    q.pop();

    for (int to: G[from.first]) {
      if (((1 << to) & from.second) == 0) {
        if (d[to][(1 << to) | from.second] == 0) q.push({to, (1 << to) | from.second});
        d[to][(1 << to) | from.second] += d[from.first][from.second];
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < N; i++) {
    ans += d[i][(1 << N) - 1];
  }
  cout << ans << endl;
}
