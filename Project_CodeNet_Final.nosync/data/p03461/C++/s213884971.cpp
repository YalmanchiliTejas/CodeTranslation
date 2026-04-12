#include <bits/stdc++.h>
#define REP(i, a, n) for(ll i = ((ll) a); i < ((ll) n); i++)
using namespace std;
typedef long long ll;

int main(void) {
  const ll N = 202, S = 1, T = 102, LabelX = -1, LabelY = -2;

  ll A, B;
  cin >> A >> B;
  vector< vector<ll> > D(A + 1, vector<ll>(B + 1));
  REP(i, 1, A + 1) REP(j, 1, B + 1) cin >> D[i][j];

  struct edge { ll u, v, c; };
  vector<edge> edges;
  vector< vector<bool> > ok(A + 1, vector<bool>(B + 1, false));

  REP(i, S, S + 100) edges.push_back((edge) { i, i + 1, LabelX });
  REP(i, T, T + 100) edges.push_back((edge) { i + 1, i, LabelY });

  REP(p, 0, 101) REP(q, 0, 101) REP(r, 0, 100 + 1) {
    bool f = true;
    REP(x, 1, A + 1) REP(y, 1, B + 1) f = f && D[x][y] <= p * x + q * y + r;
    if(!f) continue;
    ll cnt = 0;
    REP(x, 1, A + 1) REP(y, 1, B + 1) {
      if(!ok[x][y] && D[x][y] == p * x + q * y + r) {
        ok[x][y] = true;
        cnt++;
      }
    }
    if(cnt > 0) edges.push_back((edge) { S + p, T + q, r });
  }

  bool possible = true;
  REP(a, 1, A + 1) REP(b, 1, B + 1) possible = possible && ok[a][b];
  if(!possible) {
    cout << "Impossible" << endl;
  } else {
    cout << "Possible" << endl;
    cout << N << " " << edges.size() << endl;
    for(edge e : edges) {
      if(e.c >= 0) cout << e.u << " " << e.v << " " << e.c << endl;
      else cout << e.u << " " << e.v << " " << (e.c == LabelX ? "X" : "Y") << endl;
    }
    cout << S << " " << T << endl;
  }
}
