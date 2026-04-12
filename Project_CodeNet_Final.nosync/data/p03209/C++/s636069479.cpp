#include <bits/stdc++.h>

using namespace std;

using ull = unsigned long long;

// レベルnのx層目までに何枚パティがあるか
ull solve(int n, ull x, vector<ull> &len, vector<ull> &cnts) {
  if (x == 0) {
    return 0;
  }

  if (n == 0) {
    return 1;
  }

  if (x <= len[n - 1] + 1) {
    return solve(n - 1, x - 1, len, cnts);
  } else if (x == len[n - 1] + 2) {
    return cnts[n - 1] + 1;
  } else {
    x -= len[n - 1] + 2;
    ull ans = cnts[n - 1] + 1 + solve(n - 1, x, len, cnts);
    return ans;
  }
}

int main(int argc, const char *argv[]) {
  int n;
  ull x;
  cin >> n >> x;

  vector<ull> len(n + 1);
  len[0] = 1;
  for (int i = 1; i <= n; ++i) {
    len[i] = len[i - 1] * 2 + 3;
  }

  // cnts[i]: レベルiにパティが何枚あるか
  vector<ull> cnts(n + 1);
  cnts[0] = 1;
  for (int i = 1; i <= n; ++i) {
    cnts[i] = cnts[i - 1] * 2 + 1;
  }

  cout << solve(n, x, len, cnts) << '\n';

  return 0;
}
