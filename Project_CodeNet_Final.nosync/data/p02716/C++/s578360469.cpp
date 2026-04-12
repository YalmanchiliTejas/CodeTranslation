#include <bits/stdc++.h>
using namespace std;
using PP = pair<int, int>;

const long inf = 1e18;
int n;
long a[200000];
map<PP, long> dp;
map<PP, long> dq;

long g(int i, int j);
long f(int i, int j) {
  if (i == 0 && j == 0) return 0;
  if (i == 0) return -inf;
  if (2 * j > i + 8) return -inf;
  if (2 * j < i - 8) return -inf;
  if (dp.count(PP(i, j))) return dp[PP(i, j)];
  long ans = a[i - 1] + g(i - 1, j - 1);
  return dp[PP(i, j)] = ans;
}

long g(int i, int j) {
  if (i == 0 && j == 0) return 0;
  if (i == 0) return -inf;
  if (2 * j > i + 8) return -inf;
  if (2 * j < i - 8) return -inf;
  if (dq.count(PP(i, j))) return dq[PP(i, j)];
  long ans = max(f(i - 1, j), g(i - 1, j));
  return dq[PP(i, j)] = ans;
}

int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i];
  cout << max(f(n, n / 2), g(n, n / 2)) << endl;
}