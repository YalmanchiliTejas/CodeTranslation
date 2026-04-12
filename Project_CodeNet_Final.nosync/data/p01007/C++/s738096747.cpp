#include <bits/stdc++.h>
#define REP(i, a, n) for(ll i = ((ll) a); i < ((ll) n); i++)
using namespace std;
typedef long long ll;

ll N, M;
ll A[15][15];

bool used[15][15];

void dfs(ll r, ll c, ll x) {
  if(used[r][c]) return;
  used[r][c] = true;

  A[r][c] = !A[r][c];

  ll dd[5] = { 0, 1, 0, -1, 0 };
  REP(k, 0, 4) {
    ll nr = r + dd[k];
    ll nc = c + dd[k + 1];
    if(0 <= nr && nr < N && 0 <= nc && nc < N && A[nr][nc] == x) {
      dfs(nr, nc, x);
    }
  }
}

int main(void) {
  cin >> N >> M;
  REP(i, 0, N) REP(j, 0, N) cin >> A[i][j];

  REP(_, 0, M) {
    ll O;
    cin >> O;

    if(O == 0) {
      ll r, c, size, angle; cin >> r >> c >> size >> angle; r--; c--;
      ll B[15][15];
      while(angle > 0) {
        REP(i, 0, N) REP(j, 0, N) B[i][j] = A[i][j];
        REP(i, r, r + size) REP(j, c, c + size) {
          B[r + (j - c)][c + size - 1 - (i - r)] = A[i][j];
        }
        REP(i, 0, N) REP(j, 0, N) A[i][j] = B[i][j];
        angle -= 90;
      }
    }
    if(O == 1) {
      ll r, c, size; cin >> r >> c >> size; r--; c--;
      REP(i, r, r + size) REP(j, c, c + size) A[i][j] = !A[i][j];
    }
    if(O == 2) {
      ll r; cin >> r; r--;
      REP(i, 0, N - 1) swap(A[r][i], A[r][i + 1]);
    }
    if(O == 3) {
      ll r; cin >> r; r--;
      for(ll i = N - 1; i > 0; i--) swap(A[r][i], A[r][i - 1]);
    }
    if(O == 4) {
      ll r, c; cin >> r >> c; r--; c--;
      REP(i, 0, N) REP(j, 0, N) used[i][j] = false;
      dfs(r, c, A[r][c]);
    }
  }

  REP(i, 0, N) REP(j, 0, N) cout << A[i][j] << (j + 1 != N ? " " : "\n");
}
