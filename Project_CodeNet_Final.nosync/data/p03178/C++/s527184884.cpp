#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cctype>

#include <algorithm>
#include <random>
#include <bitset>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <limits>
#include <numeric>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int N = 10010, D = 110, P = 1000000007;

int d;
char s[N];
int dp[D], tmp[D];

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif

  scanf("%s%d", s + 1, &d);
  int n = strlen(s + 1);
  for (int i = 1; i <= n; ++i)
    s[i] -= '0';
  int sum = 0;
  for (int i = 1; i <= n; ++i) {
    memset(tmp, 0, sizeof(tmp));
    for (int j = 0; j < d; ++j)
      for (int v = 0; v < 10; ++v)
        if ((tmp[(j + v) % d] += dp[j]) >= P)
          tmp[(j + v) % d] -= P;
    for (int x = 0; x < s[i]; ++x)
      if (++tmp[(sum + x) % d] == P)
        tmp[(sum + x) % d] = 0;
    sum = (sum + s[i]) % d;
    memcpy(dp, tmp, sizeof(dp));
  }
  int ans = dp[0];
  if (sum == 0)
    if (++ans == P)
      ans = 0;
  if (--ans < 0)
    ans = P - 1;
  printf("%d\n", ans);

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}
