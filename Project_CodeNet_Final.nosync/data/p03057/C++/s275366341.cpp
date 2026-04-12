#include <bits/stdc++.h>

const int MOD = 1e9 + 7;

void update(int& x, int a)
{
  x += a;
  if (x >= MOD) {
    x -= MOD;
  }
}

int solve(int n, int m, const std::string& s)
{
  bool has_b = false;
  int max_len = -1;
  for (int i = 0, len = 0; i < m; ++ i) {
    if (i && s[i - 1] != s[i]) {
      if (s[i - 1] == s[0]) {
        if (max_len == -1) {
          max_len = len + 1;
        } else if (len & 1) {
          max_len = std::min(max_len, len + 1);
        }
      }
      // printf("%c %d\n", s[i - 1], len);
      len = 0;
    }
    has_b |= s[i] != s[0];
    len ++;
  }
  std::vector<int> dp(n);
  dp[0] = 1;
  if (has_b) {
    // <=> has A + has B + no consecutive B + len <= max_len
    for (int i = 2, j = 0, sum = 0; i < n; i += 2) {
      update(sum, dp[i - 2]);
      if (i - j > max_len + 1) {
        update(sum, MOD - dp[j]);
        j += 2;
      }
      dp[i] = sum;
    }
    int result = 0;
    for (int len = 2; len <= n && len - 1 <= max_len; len += 2) {
      update(result, 1LL * len * dp[n - len] % MOD);
    }
    return result;
  } else {
    // AA...A <=> has A + no consecutive B
    for (int i = 1, sum = 0; i < n; ++ i) {
      if (i >= 2) {
        update(sum, dp[i - 2]);
      }
      dp[i] = sum;
    }
    int result = 1; // no B
    for (int len = 2; len <= n; ++ len) {
      update(result, 1LL * len * dp[n - len] % MOD);
    }
    return result;
  }
}

int main()
{
  int n, m;
  while (std::cin >> n >> m) {
    std::string s;
    std::cin >> s;
    std::cout << solve(n, m, s) << std::endl;
  }
}
