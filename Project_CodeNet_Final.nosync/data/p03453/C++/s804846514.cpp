#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>

const int MAXN = 100004;
const int M = 1000000007;
const long long INF = 1e17;

typedef std::tuple<long long,int> ii;

int N, S, E;
long long dist[MAXN], dist2[MAXN];
int num[MAXN], num2[MAXN];
std::vector<int> edge[MAXN];
std::vector<int> cost[MAXN];

int main() {
  using namespace std;
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int q;
  cin >> N >> q;
  cin >> S >> E;

  for (int i = 0; i < q ; ++i) {
    int x, y, c;
    cin >> x >> y >> c;
    c <<= 1;
    edge[x].push_back(y);
    cost[x].push_back(c);
    edge[y].push_back(x);
    cost[y].push_back(c);
  }

  fill(dist, dist + N + 1, INF);
  dist[S] = 0;
  num[S] = 1;

  priority_queue<ii> pq;
  pq.emplace(0ll, S);

  do {
    long long nc;
    int np;
    std::tie(nc, np) = pq.top();
    nc = -nc;
    pq.pop();

    if (nc > dist[np]) continue;
    for (int i = 0; i < edge[np].size(); ++i) {
      const int xp = edge[np][i], xc = cost[np][i];
      if (nc + xc < dist[xp]) {
        dist[xp] = nc + xc;
        num[xp] = num[np];
        pq.emplace(-(nc + xc), xp);
      } else if (nc + xc == dist[xp]) {
        num[xp] = (num[xp] + num[np]) % M;
      }
    }
  } while(!pq.empty());

  fill(dist2, dist2 + N + 1, INF);
  dist2[E] = 0;
  num2[E] = 1;

  pq.emplace(0ll, E);

  do {
    long long nc;
    int np;
    std::tie(nc, np) = pq.top();
    nc = -nc;
    pq.pop();

    if (nc > dist2[np]) continue;
    for (int i = 0; i < edge[np].size(); ++i) {
      const int xp = edge[np][i], xc = cost[np][i];
      if (nc + xc < dist2[xp]) {
        dist2[xp] = nc + xc;
        num2[xp] = num2[np];
        pq.emplace(-(nc + xc), xp);
      } else if (nc + xc == dist2[xp]) {
        num2[xp] = (num2[xp] + num2[np]) % M;
      }
    }
  } while(!pq.empty());

  const long long ff = dist[E];
  const long long hf = (dist[E] >> 1);
  const int fn = num[E];
  long long ans = 0;
  for (int i = 1; i <= N; ++i) {
    if (dist[i] > hf) continue;
    if (dist[i] == hf) {
      const long long r1 = num[i] * (long long)num2[i] % M;
      const long long r2 = (M + fn - r1) % M;
      ans = (ans + (r1 * r2 % M)) % M;
      continue;
    }
    for (int j = 0; j < edge[i].size(); ++j) {
      const int xp = edge[i][j], xc = cost[i][j];
      if (dist[i] + dist2[xp] + xc != ff) continue;
      if (dist[i] + xc <= hf) continue;
      const long long r1 = num[i] * (long long)num2[xp] % M;
      const long long r2 = (M + fn - r1) % M;
      ans = (ans + (r1 * r2 % M)) % M;
    }
  }

  cout << ans << '\n';
  return 0;
}
