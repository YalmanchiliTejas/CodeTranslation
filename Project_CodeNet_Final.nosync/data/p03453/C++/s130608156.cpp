#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <stack>
#include <tuple>
#include <bitset>
#include <algorithm>
#include <functional>
#include <utility>
#include <iomanip>
#define mod(x) ((x % MOD) + MOD) % MOD
#define int long long int
#define rep(i, a, n) for(int i = a; i < n; ++i)
#define rrep(i, a, n) for(int i = n-1; i >= a; --i)

using namespace std;

typedef pair<int,int> P;
struct edge {
  int to, cost;
};

const int INF = 1e18;
const int MOD = 1e9+7;

template<typename T> ostream& operator<<(ostream& s, const vector<T>& v) {
  int len = v.size();
  for (int i = 0; i < len; ++i) {
    s << v[i]; if (i < len - 1) s << " ";
  }
  return s;
}


void dijkstra(vector< vector<edge> >& G, vector<int>& d, int s)
{
  priority_queue<P, vector<P>, greater<P> > que;
  fill(d.begin(), d.end(), INF);
  d[s] = 0;
  que.push(P(0, s));
  while(!que.empty()) {
    int temp_cost = que.top().first;
    int from = que.top().second;
    que.pop();
    if (d[from] < temp_cost) continue;
    for (int i = 0; i < G[from].size(); i++) {
      edge e = G[from][i];
      if (d[e.to] > d[from] + e.cost) {
        d[e.to] = d[from] + e.cost;
        que.push(P(d[e.to], e.to));
      }
    }
  }
}


signed main()
{
  int N, M, S, T;
  cin >> N >> M >> S >> T;
  S--; T--;
  vector< vector<edge> > G(N, vector<edge>());
  int U, V, D;
  for (int i = 0; i < M; i++) {
    cin >> U >> V >> D;
    U--; V--;
    G[U].push_back((edge){ V, D });
    G[V].push_back((edge){ U, D });
  }


  vector<int> d(N);
  dijkstra(G, d, S);

  vector<P> list(N);
  rep(i, 0, N) {
    list[i] = make_pair(d[i], i);
  }
  sort(list.begin(), list.end());

  vector< vector<int> > dp(2, vector<int>(N, 0));
  dp[0][S] = 1; dp[1][T] = 1;

  rep(i, 0, N) {
    int idx = list[i].second;
    rep(j, 0, G[idx].size()) {
      edge e = G[idx][j];
      if (d[idx] == d[e.to] + e.cost) {
        dp[0][idx] = mod(dp[0][idx] + dp[0][e.to]);
      }
    }
  }

  rrep(i, 0, N) {
    int idx = list[i].second;
    rep(j, 0, G[idx].size()) {
      edge e = G[idx][j];
      if (d[idx] + e.cost == d[e.to]) {
        dp[1][idx] = mod(dp[1][idx] + dp[1][e.to]);
      }
    }
  }


  int ans = mod(dp[0][T] * dp[0][T]);
  rep(i, 0, N) {
    if (d[i] * 2 == d[T]) {
      ans = mod(ans - mod(mod(dp[0][i]*dp[0][i]) * mod(dp[1][i]*dp[1][i])));
    }
  }
  rep(i, 0, N) {
    rep(j, 0, G[i].size()) {
      edge e = G[i][j];
      if (d[e.to] == d[i] + e.cost && d[i]*2 < d[T] && d[e.to]*2 > d[T]) {
        ans = mod(ans - mod(mod(dp[0][i]*dp[0][i]) * mod(dp[1][e.to]*dp[1][e.to])));
      }
    }
  }

  cout << ans << endl;

  return 0;
}
