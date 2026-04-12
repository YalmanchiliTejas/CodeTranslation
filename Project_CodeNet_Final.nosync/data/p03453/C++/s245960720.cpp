#include <bits/stdc++.h>
#define REP(i, a, n) for(ll i = ((ll) a); i < ((ll) n); i++)
#define INF (1LL << 60)
#define MOD 1000000007LL
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

struct edge { ll v, dist; };

struct state {
  ll v, p, cost;
  bool operator>(const state s) const { return cost > s.cost; }
};

vector<pll> dijkstra(vector< vector<edge> > &E, ll S) {
  vector<pll> dp(E.size(), pll(INF, 0));
  priority_queue<state, vector<state>, greater<state> > q;
  q.push((state) { S, -1, 0 });

  while(!q.empty()) {
    ll v = q.top().v, p = q.top().p, cost = q.top().cost;
    q.pop();

    if(dp[v].first < cost) continue;
    (dp[v].second += (p != -1 ? dp[p].second : 1)) %= MOD;

    if(dp[v].first <= cost) continue;
    dp[v].first = cost;

    REP(i, 0, E[v].size()) {
      ll nv = E[v][i].v, ncost = cost + E[v][i].dist;
      if(dp[nv].first >= ncost) q.push((state) { nv, v, ncost });
    }
  }

  return dp;
}

int main(void) {
  ll N, M, S, T; cin >> N >> M >> S >> T; S--; T--;
  vector< vector<edge> > E(N);
  vector<ll> U(M), V(M), D(M);
  REP(i, 0, M) {
    cin >> U[i] >> V[i] >> D[i]; U[i]--; V[i]--;
    E[U[i]].push_back((edge) { V[i], D[i] });
    E[V[i]].push_back((edge) { U[i], D[i] });
  }

  vector<pll> dpS = dijkstra(E, S);
  vector<pll> dpT = dijkstra(E, T);
  ll dist = dpS[T].first, all = (dpS[T].second * dpS[T].second) % MOD;

  // cout << "dist: " << dist << endl;
  // cout << "all: " << all << endl;
  // cout << "dpS: ";
  // REP(i, 0, N) cout << "(" << dpS[i].first << ", " << dpS[i].second << "), ";
  // cout << endl;
  // cout << "dpT: ";
  // REP(i, 0, N) cout << "(" << dpT[i].first << ", " << dpT[i].second << "), ";
  // cout << endl;

  ll ans = 0;
  REP(i, 0, N) if(dpS[i].first + dpT[i].first == dist) {
    if(dpS[i].first == dpT[i].first) {
      ans += (((dpS[i].second * dpT[i].second) % MOD) * ((dpS[i].second * dpT[i].second) % MOD)) % MOD;
      ans %= MOD;
    }
  }
  // cout << "ans: " << ans << endl;
  REP(i, 0, M) {
    if(dpS[U[i]].first + dpT[V[i]].first + D[i] == dist) {
      if(dpS[U[i]].first + D[i] > dpT[V[i]].first && dpT[V[i]].first + D[i] > dpS[U[i]].first) {
        ans += (((dpS[U[i]].second * dpT[V[i]].second) % MOD) * ((dpS[U[i]].second * dpT[V[i]].second) % MOD)) % MOD;
        ans %= MOD;
      }
    }
    if(dpS[V[i]].first + dpT[U[i]].first + D[i] == dist) {
      if(dpS[V[i]].first + D[i] > dpT[U[i]].first && dpT[U[i]].first + D[i] > dpS[V[i]].first) {
        ans += (((dpS[V[i]].second * dpT[U[i]].second) % MOD) * ((dpS[V[i]].second * dpT[U[i]].second) % MOD)) % MOD;
        ans %= MOD;
      }
    }
  }
  // cout << "ans: " << ans << endl;
  cout << (all - ans + MOD) % MOD << endl;
}
