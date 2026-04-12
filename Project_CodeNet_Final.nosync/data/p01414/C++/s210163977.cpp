#include <bits/stdc++.h>
#define REP(i, a, n) for(ll i = ((ll) a); i < ((ll) n); i++)
using namespace std;
typedef int ll;

ll N, H[16], W[16];
char S[4][4];
const char Z[] = "RGB";
ll dp[1 << 16];

int main(void) {
  scanf("%d", &N);
  REP(i, 0, N) scanf("%d %d", H + i, W + i);
  REP(i, 0, 4) scanf("%s", S[i]);

  REP(i, 0, 1 << 16) dp[i] = -1;
  dp[0] = 0;
  queue<ll> q;
  q.push(0);
  while(q.size()) {
    if(dp[(1 << 16) - 1] != -1) break;
    ll s = q.front(); q.pop();
    REP(i, 0, N) {
      REP(py, -H[i] + 1, 4) REP(px, -W[i] + 1, 4) REP(c, 0, 3) {
        ll n = s;
        REP(y, max(py, 0), min(py + H[i], 4)) REP(x, max(px, 0), min(px + W[i], 4)) {
          if(S[y][x] == Z[c]) n = n | (1 << (y * 4 + x));
          else n = n & (~(1 << (y * 4 + x)));
        }
        if(dp[n] == -1) {
          dp[n] = dp[s] + 1;
          q.push(n);
        }
      }
    }
  }
  printf("%d\n", dp[(1 << 16) - 1]);
}

