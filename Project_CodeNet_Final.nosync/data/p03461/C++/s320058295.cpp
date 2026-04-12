#include <bits/stdc++.h>
#define REP(i, a, n) for(ll i = ((ll) a); i < ((ll) n); i++)
#define INF (1LL << 60)
using namespace std;
typedef long long ll;

struct edge {
  ll v, dist;
};

struct state {
  ll v, cost;

  bool operator>(const state s) const {
    return cost > s.cost;
  }
};

vector<ll> dijkstra(vector< vector<edge> > &E, ll S) {
  vector<ll> dp(E.size(), INF);
  priority_queue<state, vector<state>, greater<state> > q;
  q.push((state) { S, 0 });

  while(!q.empty()) {
    ll v = q.top().v, cost = q.top().cost;
    q.pop();

    if(dp[v] <= cost) continue;
    dp[v] = cost;

    REP(i, 0, E[v].size()) {
      ll nv = E[v][i].v, ncost = cost + E[v][i].dist;
      if(dp[nv] > ncost) q.push((state) { nv, ncost });
    }
  }

  return dp;
}

int main(void) {
  ll A, B;
  cin >> A >> B;
  vector< vector<ll> > D(A + 1, vector<ll>(B + 1));
  REP(i, 1, A + 1) REP(j, 1, B + 1) cin >> D[i][j];

  struct data { ll p, q, r; };
  vector<data> e;
  vector< vector<bool> > ok(A + 1, vector<bool>(B + 1, false));

  REP(p, 0, 101) REP(q, 0, 101) REP(r, 0, 100 + 1) {
    bool f = true;
    REP(x, 1, A + 1) REP(y, 1, B + 1) {
      ll v = p * x + q * y + r;
      f = f && D[x][y] <= v;
    }
    if(!f) continue;
    ll cnt = 0;
    REP(x, 1, A + 1) REP(y, 1, B + 1) {
      ll v = p * x + q * y + r;
      if(!ok[x][y] && D[x][y] == v) {
        ok[x][y] = true;
        cnt++;
      }
    }
    if(cnt > 0) e.push_back((data) { p, q, r });
  }

  bool possible = true;
  REP(a, 1, A + 1) REP(b, 1, B + 1) possible = possible && ok[a][b];

  if(!possible) {
    cout << "Impossible" << endl;
    return 0;
  }

  ll N = 202, M = 200 + e.size(), S = 1, T = 102;
  cout << "Possible" << endl;
  cout << N << " " << M << endl;
  REP(i, S, S + 100) cout << i << " " << i + 1 << " X" << endl;
  REP(i, T, T + 100) cout << i + 1 << " " << i << " Y" << endl;
  REP(i, 0, e.size()) cout << S + e[i].p << " " << T + e[i].q << " " << e[i].r << endl;
  cout << S << " " << T << endl;

  REP(x, 1, A + 1) REP(y, 1, B + 1) {
    vector< vector<edge> > E(N + 1);
    REP(i, S, S + 100) E[i].push_back((edge) { i + 1, x });
    REP(i, T, T + 100) E[i + 1].push_back((edge) { i, y });
    REP(i, 0, e.size()) E[S + e[i].p].push_back((edge) { T + e[i].q, e[i].r });
    ll d = dijkstra(E, S)[T];
    assert(d == D[x][y]);
  }
}
