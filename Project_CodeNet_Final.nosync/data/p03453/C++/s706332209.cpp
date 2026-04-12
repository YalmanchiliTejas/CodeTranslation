#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
typedef pair<ll, int> PII;
constexpr int MAXN = 100000 + 5;
constexpr ll INF = 100000LL * 1000000000 + 100;
constexpr ll MOD = 1000000000 + 7;
int N, M, S, T;
int U, V;
ll D;
ll dad1[MAXN];
ll dist1[MAXN];

ll dad2[MAXN];
ll dist2[MAXN];
int UU[2 * MAXN];
int VV[2 * MAXN];
ll DD[2 * MAXN];
vector<vector<PII>> edges(MAXN);
ll dd(int S, int T, ll *dad, ll *dist) {
  // use priority queue in which top element has the "smallest" priority
  fill(dist, dist + N + 1, INF);
  dad[S] = 1;
  priority_queue<PII, vector<PII>, greater<PII>> Q;
  Q.push(make_pair(0, S));
  dist[S] = 0;
  while (!Q.empty()) {
    PII p = Q.top();
    Q.pop();
    int here = p.second;

    if (dist[here] != p.first) continue;
    for (vector<PII>::iterator it = edges[here].begin();
         it != edges[here].end(); it++) {
      if (dist[here] + it->first < dist[it->second]) {
        dist[it->second] = dist[here] + it->first;
        dad[it->second] = dad[here];
        Q.push(make_pair(dist[it->second], it->second));
      } else if (dist[here] + it->first == dist[it->second]) {
        dist[it->second] = dist[here] + it->first;
        dad[it->second] += dad[here];
        dad[it->second] %= MOD;
      }
    }
  }

  return dist[T];
}
int main() {
  ios::sync_with_stdio(false);
  cin >> N >> M >> S >> T;

  for (int i = 0; i < M; ++i) {
    cin >> U >> V >> D;
    UU[i] = U;
    VV[i] = V;
    DD[i] = D;
    edges[U].push_back(make_pair(D, V));
    edges[V].push_back(make_pair(D, U));
  }
  const ll mindist = dd(S, T, dad1, dist1);
  // cerr << "shortest path: " << mindist << endl;
  dd(T, S, dad2, dist2);
  ll tot = (dad1[T] * dad1[T]) % MOD;
  // cerr << "tot: " << tot << endl;
  for (int i = 1; i <= N; ++i) {
    if (dist1[i] == dist2[i] && dist1[i] == mindist / 2) {
      ll dec = (dad1[i] * dad2[i]) % MOD;
      dec = dec * dec % MOD;
      tot -= dec;
      tot %= MOD;
      tot += MOD;
      tot %= MOD;
    }
  }
  // cerr << "tot: " << tot << endl;

  for (int i = 0; i < M; ++i) {
    const ll d = DD[i];
    int u = UU[i];
    int v = VV[i];
    if (dist1[u] + d + dist2[v] == mindist && dist1[u] < mindist / 2 &&
        dist2[v] < mindist / 2) {
      ll dec = (dad1[u] * dad2[v]) % MOD;
      dec = dec * dec % MOD;
      tot -= dec;
      tot %= MOD;
      tot += MOD;
      tot %= MOD;
    } else {
      swap(u, v);
      if (dist1[u] + d + dist2[v] == mindist && dist1[u] < mindist / 2 &&
          dist2[v] < mindist / 2) {
      ll dec = (dad1[u] * dad2[v]) % MOD;
      dec = dec * dec % MOD;
      tot -= dec;
      tot %= MOD;
      tot += MOD;
      tot %= MOD;
      
      }
    }
  }
  cout << tot;
}