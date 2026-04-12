#include <bits/stdc++.h>
using namespace std;

long long n, x, m;
vector<vector<long long>> memo, sum;

int main() {
  cin >> n >> x >> m;
  memo.assign(60, vector<long long>(m, 0));
  sum.assign(60, vector<long long>(m, 0));
  for (int i = 0; i < m; ++i) memo[0][i] = (long long)i * i % m;
  for (int i = 0; i < m; ++i) sum[0][i] = i;
  for (int i = 1; i < 60; ++i)
    for (int j = 0; j < m; ++j) {
      long long mid = memo[i - 1][j];
      memo[i][j] = memo[i - 1][mid];
      sum[i][j] = sum[i - 1][j] + sum[i - 1][mid];
    }
  long long res = 0;
  for (int i = 0; i < 60; ++i)
    if (n >> i & 1) {
      res += sum[i][x];
      x = memo[i][x];
    }
  cout << res << endl;
  return 0;
}