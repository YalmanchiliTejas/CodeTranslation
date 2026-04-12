#include <bits/stdc++.h>
#define REP(i, a, n) for(ll i = ((ll) a); i < ((ll) n); i++)
using namespace std;
typedef long long ll;

const ll INF = 1LL << 60;

ll R, C, M;
char S[50][50];
ll unit[50][50], on[50][50], off[50][50], Y[1000], X[1000];

bool dfs(ll y, ll x, ll gy, ll gx, vector<ll> &ty, vector<ll> &tx, vector< vector<bool> > &used) {
  if(used[y][x]) return false;
  used[y][x] = true;

  ty.push_back(y);
  tx.push_back(x);

  if(y == gy && x == gx) return true;

  ll dd[5] = { 0, -1, 0, 1, 0 };
  REP(i, 0, 4) {
    ll ny = y + dd[i], nx = x + dd[i + 1];
    if(0 <= ny && ny < R && 0 <= nx && nx < C && S[ny][nx] == '.') {
      if(dfs(ny, nx, gy, gx, ty, tx, used)) return true;
    }
  }

  ty.resize(ty.size() - 1);
  tx.resize(tx.size() - 1);

  return false;
}

int main(void) {
  cin >> R >> C >> M;
  REP(i, 0, R) REP(j, 0, C) cin >> S[i][j];
  REP(i, 0, R) REP(j, 0, C) cin >> unit[i][j];
  REP(i, 0, R) REP(j, 0, C) cin >> on[i][j];
  REP(i, 0, R) REP(j, 0, C) cin >> off[i][j];
  REP(i, 0, M) cin >> Y[i] >> X[i];

  ll y = Y[0], x = X[0];
  ll ans = on[y][x], t = 1;

  ll last[R][C];
  REP(i, 0, R) REP(j, 0, C) last[i][j] = -INF;
  last[y][x] = 0;

  REP(i, 0, M - 1) {
    vector<ll> ty, tx;
    vector< vector<bool> > used(R, vector<bool>(C, false));
    dfs(Y[i], X[i], Y[i + 1], X[i + 1], ty, tx, used);

    REP(j, 1, ty.size()) {
      y = ty[j];
      x = tx[j];

      if(last[y][x] < 0) {
        ans += on[y][x];
      } else {
        ll d = t - last[y][x];
        if(d * unit[y][x] <= off[y][x] + on[y][x]) {
          ans += d * unit[y][x];
        } else {
          ans += off[y][x] + on[y][x];
        }
      }

      last[y][x] = t++;
    }
  }

  REP(i, 0, R) REP(j, 0, C) {
    if(last[i][j] >= 0) ans += off[i][j];
  }

  cout << ans << endl;
}

