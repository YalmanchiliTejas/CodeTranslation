#include <stdio.h>
#include <string.h>

long long dp[13][5];
char s[13];

int main() {
  scanf("%s", s);
  int n = strlen(s);
  dp[0][0] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 4; j++) {
      int val = 0;
      for (int k = i; k < n; k++) {
        if (val == 0 && s[k] == '0') {
          dp[k + 1][j + 1] += dp[i][j];
          break;
        }
        val = val * 10 + (s[k] - '0');
        if (val <= 255) {
          dp[k + 1][j + 1] += dp[i][j];
        } else break;
      }
    }
  }
  printf("%lld\n", dp[n][4]);
}
