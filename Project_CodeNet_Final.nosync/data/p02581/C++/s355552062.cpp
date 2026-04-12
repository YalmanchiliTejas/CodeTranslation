#include <bits/stdc++.h>
using namespace std;
using lint = long long;
const int MAXN = 6005;
const int INF = 1e5;
int A[MAXN], nxt[MAXN], dp[MAXN][MAXN], ans = 0, base = 0, N;
inline int Cost(int a, int b, int c) {
  return A[a] == A[b] && A[b] == A[c];
}
void chmax(int &x, int val) {
  x = max(x, val);
}
inline void Transition(int i, int j, int cur) {
  if (cur > 3 * N) return;
  if (cur == 3 * N)
    return void(chmax(ans, dp[i][j] + Cost(i, j, cur)));
  for (int u = 1; u <= 3; ++u)
    for (int v = u + 1; v <= 3; ++v)
      chmax(dp[cur + u - 1][cur + v - 1], dp[i][j] + Cost(i, j, cur + (u ^ v) - 1));
 
  for (int c : {i, j}) {
    chmax(dp[c][cur + 0], dp[i][j] + Cost(i ^ j ^ c, cur + 1, cur + 2));
    chmax(dp[c][cur + 1], dp[i][j] + Cost(i ^ j ^ c, cur + 0, cur + 2));
    chmax(dp[c][cur + 2], dp[i][j] + Cost(i ^ j ^ c, cur + 0, cur + 1));
  }
}
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
 
  cin >> N;
  for (int i = 1; i <= 3 * N; i++) {
    cin >> A[i];
  }
 
  while (true) {
    bool change = false;
    for (int i = 3; i + 2 <= 3 * N; i += 3) {
      if (A[i] == A[i + 1] && A[i + 1] == A[i + 2]) {
        base += 1;
        for (int j = i + 3; j <= 3 * N; j++) {
          A[j - 3] = A[j];
        }
        N -= 1;
        change = true;
        break;
      }
    }
    if (!change) {
      break;
    }
  }
  
  vector<int> last(3 * N + 1, 3 * N + 1);
  for (int i = 3 * N; i > 0; i--) {
    nxt[i] = last[A[i]];
    last[A[i]] = i;
  }
  for (int i = 0; i < MAXN; i++) {
    for (int j = 0; j < MAXN; j++) {
      dp[i][j] = -INF;
    }
  }
  dp[1][2] = 0;
  for (int i = 1; i <= 3 * N; i++) {
    for (int j = i + 1; j <= 3 * N; j++) {
      Transition(i, j, (j + 3) / 3 * 3);
      // Find next occurrence of A[i]
      if (j / 3 * 3 < nxt[i] / 3 * 3) {
        Transition(i, j, nxt[i] / 3 * 3);
      }
      if (j / 3 * 3 < nxt[j] / 3 * 3) {
        Transition(i, j, nxt[j] / 3 * 3);
      }
    }
  }
 
  cout << ans + base << "\n";
  return 0;
}
