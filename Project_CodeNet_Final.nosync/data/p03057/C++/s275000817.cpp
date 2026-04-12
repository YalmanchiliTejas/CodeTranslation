#include <bits/stdc++.h>

using namespace std;

const int md = (int) 1e9 + 7;

inline void add(int &x, int y) {
  x += y;
  if (x >= md) {
    x -= md;
  }
}

inline void sub(int &x, int y) {
  x -= y;
  if (x < 0) {
    x += md;
  }
}

inline int mul(int x, int y) {
  return (int) ((long long) x * y % md);
}

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  string s;
  cin >> n >> m >> s;
  if (s[0] == 'B') {
    for (auto &c : s) {
      c ^= 'R' ^ 'B';
    }
  }
  int first = m;
  for (int i = 0; i < m; ++i) {
    if (s[i] == 'B') {
      first = i;
      break;
    }
  }
  if (first == m) {
    vector<int> dp(4);
    dp[0] = dp[3] = 1;
    for (int i = 1; i < n; ++i) {
      vector<int> new_dp(4);
      for (int a = 0; a < 2; ++a) {
        for (int b = 0; b < 2; ++b) {
          for (int c = 0; c < 2; ++c) {
            if (!b || !c) {
              add(new_dp[a * 2 + b], dp[a * 2 + c]);
            }
          }
        }
      }
      swap(dp, new_dp);
    }
    int ans = 0;
    for (int i = 0; i < 3; ++i) {
      add(ans, dp[i]);
    }
    cout << ans << "\n";
    return 0;
  }
  int last = m - 1;
  while (s[last] == 'R') {
    --last;
  }
  int limit = n, cur = 0;
  for (int i = last; i >= -1; --i) {
    if (i == -1 || s[i] == 'B') {
      if (cur) {
        if (cur & 1) {
          limit = min(limit, cur + 1);
        } else if (i == -1) {
          limit = min(limit, cur + 2);
        }
        cur = 0;
      }
    } else {
      ++cur;
    }
  }
  vector<int> dp(n + 1);
  dp[0] = dp[2] = 1;
  for (int i = 4; i <= n; ++i) {
    dp[i] = mul(dp[i - 2], 2);
    if (i >= limit + 2) {
      sub(dp[i], dp[i - (limit + 2)]);
    }
  }
  int ans = 0;
  for (int i = 2; i <= limit; i += 2) {
    add(ans, mul(dp[n - i], i));
  }
  cout << ans << "\n";
  return 0;
}
