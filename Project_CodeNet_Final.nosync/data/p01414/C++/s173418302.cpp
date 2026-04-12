#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define int ll

#define FOR(i, a, n) for (ll i = (ll)a; i < (ll)n; ++i)
#define REP(i, n) FOR(i, 0, n)

const int INF = (1LL<<30);

char col[] = {'R', 'G', 'B'};
string board[4];
int n, d[1<<16], h[20], w[20];
signed main(void)
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> n;
  REP(i, n) cin >> h[i] >> w[i];
  REP(i, 4) cin >> board[i];

  REP(i, 1<<16) d[i] = INF;
  d[0] = 0;
  queue<int> que;
  que.push(0);

  while(que.size()) {
    int bit = que.front(); que.pop();
    if(bit == (1LL<<16)-1) break;
    // i番目のはんこで左上を(y,x)で色をcとして押す
    REP(i, n) FOR(y, -h[i]+1, 4) FOR(x, -w[i]+1, 4) REP(c, 3) {
      int n_bit = bit;
      FOR(ny, max(0LL, y), min(y+h[i],4LL)) FOR(nx, max(0LL, x), min(x+w[i],4LL)) {
        // 押した結果同じ色なら1に、違う色なら0に
        if(board[ny][nx] == col[c]) n_bit |= 1<<(ny*4+nx);
        else n_bit &= ~(1<<(ny*4+nx));
      }
      if(d[n_bit] == INF) {
        d[n_bit] = d[bit] + 1;
        que.push(n_bit);
      }
    }
  }

  cout << d[(1LL<<16)-1] << endl;

  return 0;
}

