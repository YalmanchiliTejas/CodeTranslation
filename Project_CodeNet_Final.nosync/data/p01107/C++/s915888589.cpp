#include <bits/stdc++.h>
#define REP(i, a, n) for (ll i = ((ll) a); i < ((ll) n); i++)
using namespace std;
typedef long long ll;

const ll dy[4] = { +1, +0, -1, +0 };
const ll dx[4] = { +0, -1, +0, +1 };

int main(void) {
  while (1) {
    ll N, M;
    cin >> N >> M;
    if (N == 0 && M == 0) break;
    vector<string> S(N);
    REP(i, 0, N) cin >> S[i];

    vector<vector<ll>> state(N, vector<ll>(M));

    ll y = 0, x = 0, d = 0, cnt = 0;
    bool t1 = false, t2 = false, t3 = false;
    do {
      if (!t1 && y + 1 == N && x + 1 == 1) { t1 = true; cnt++; }
      if (!t2 && y + 1 == N && x + 1 == M) { t2 = true; cnt++; }
      if (!t3 && y + 1 == 1 && x + 1 == M) { t3 = true; cnt++; }

      state[y][x] |= 1 << cnt;

      ll ny = y + dy[d];
      ll nx = x + dx[d];
      if (0 <= ny && ny < N && 0 <= nx && nx < M && S[ny][nx] == '.') {
        y = ny;
        x = nx;
        d = (d + 1) % 4;
      } else {
        d = (d + 3) % 4;
      }
    } while (!(y == 0 && x == 0 && d == 0));

    bool ok = cnt == 3;
    REP(i, 0, N) REP(j, 0, M) {
      if (i == 0 && j == 0) continue;
      ok = ok && __builtin_popcount(state[i][j]) <= 1;
    }
    cout << (ok ? "YES" : "NO") << endl;
  }
}
