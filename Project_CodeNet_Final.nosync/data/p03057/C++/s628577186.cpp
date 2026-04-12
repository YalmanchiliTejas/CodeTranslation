#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define FILL(a, n, x) memset((a), (x), sizeof ((a)[0]) * (n))
#define COPY(a, n, b) memcpy((b), (a), sizeof ((a)[0]) * (n))
using namespace std;

typedef long long li;

const int mod = 1e9 + 7;
inline int Add(int x) { return x >= mod ? x - mod : x; }
inline void Add(int &x, int y) { x += y; if (x >= mod) x -= mod; }
inline int Sub(int x) { return x < 0 ? x + mod : x; }
inline void Sub(int &x, int y) { x -= y; if (x < 0) x += mod; }
inline int Mul(int x, int y) { return (li)x * y % mod; }

// ----------------------------------------

const int maxn = 2e5;

int n, m, lim;
char s[maxn + 1];
int dp[maxn + 1];
int sum[maxn + 2];

void GetLim(void) {
  int cnt = 0;
  for (int i = 0; i < m; ++i) {
    if (s[i] == 'R') ++cnt; else break;
  }
  if (cnt & 1) lim = cnt; else lim = cnt + 1;
  cnt = 0;
  for (int i = 0; i < m; ++i) {
    if (s[i] == 'R') ++cnt; else {
      if (cnt & 1) lim = min(lim, cnt);
      cnt = 0;
    }
  }
}

void SolveSame(void) {
  static int dp[maxn + 1][2][2];
  dp[0][0][0] = dp[0][1][1] = 1;
  for (int i = 1; i < n; ++i) {
    for (int x = 0; x <= 1; ++x) {
      for (int y = 0; y <= 1; ++y) {
        for (int z = 0; z <= 1; ++z) {
          if (y != 1 || z != 1) {
            Add(dp[i][x][z], dp[i - 1][x][y]);
          }
        }
      }
    }
  }
  int ans = Add(Add(dp[n - 1][0][0] + dp[n - 1][0][1]) + dp[n - 1][1][0]);
  printf("%d\n", ans);
}

int main(void) {
  scanf("%d%d%s", &n, &m, s);
  if (s[0] == 'B') {
    for (int i = 0; i < m; ++i) {
      s[i] ^= 'R' ^ 'B';
    }
  }
  if (count(s, s + m, 'R') == m) {
    // the same
    SolveSame();
    return 0;
  }

  GetLim();
  lim = lim + 1 >> 1;
  if (n & 1) {
    puts("0");
    return 0;
  }
  n /= 2;

  for (int i = 1; i <= lim; ++i) {
    Add(dp[i], 2 * i);
  }
  for (int i = 1; i <= n; ++i) {
    // printf("this is %d\n", i);
    // calc dp[i]
    int L = max(1, i - lim), R = i;
    Add(dp[i], Sub(sum[R] - sum[L]));
    sum[i + 1] = Add(sum[i] + dp[i]);
  }
  printf("%d\n", dp[n]);
  return 0;
}
