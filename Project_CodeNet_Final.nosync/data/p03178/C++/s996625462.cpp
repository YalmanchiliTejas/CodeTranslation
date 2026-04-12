#include <bits/stdc++.h>
using namespace std;

#define f(x, y, z) for (int x = (y), __ = (z); x < __; ++x)
#define _rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define mst(x, a) memset(x, a, sizeof(x))

typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
const int INF = 1 << 27;
const ll LLINF = (ll)1 << 60;
const int MOD = 1e9+7;

inline int mod(int x, int y) {
  return (x % y + y) % y;
}

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int D, K;
vector<int> dim;
int dp[2][100][2] = {};

int main() {
  dim.push_back(-1);
  do {
    char ch;
    scanf("%c", &ch);
    if (ch == '\n') break;
    dim.push_back(ch - '0');
  } while (true);
  scanf("%d", &D);

  // dp[i][mod][eq]
  dp[0][0][1] = 1;
  K = dim.size() - 1;
  int cur = 0, prev = 1;
  for (int i = 1; i <= K; i++) {
    swap(cur, prev);
    for (int state = 0; state < D; state++) {
      dp[cur][state][1] = dp[prev][(state - dim[i] + D) % D][1];

      int sum = 0;
      for (int j = 0; j <= 9; j++) {
        sum = (sum + dp[prev][mod(state - j, D)][0]) % MOD;
      }
      for (int j = 0; j < dim[i]; j++) {
        sum = (sum + dp[prev][mod(state - j, D)][1]) % MOD;
      }
      dp[cur][state][0] = sum;
    }
  }
  printf("%d\n", mod(dp[cur][0][0] + dp[cur][0][1] - 1, MOD));
}
