#include <bits/stdc++.h>
using namespace std;

long long n, x;
long long memo[55][2] = {0};

long long solve(long long now, long long p);

int main() {
  cin >> n >> x;
  memo[0][0] = memo[0][1] = 1;
  for(int i = 1; i <= n; ++i) {
    memo[i][0] = memo[i - 1][0] * 2 + 1;
    memo[i][1] = memo[i - 1][1] * 2 + 3;
  }
  cout << solve(n, x) << endl;
  return 0;
}

long long solve(long long now, long long p) {
  if(now == 0) return p == 1;
  if(p < 2) return 0;
  if(memo[now][1] == p) return memo[now][0];
  if(memo[now][1] / 2 + 1 == p) return memo[now - 1][0] + 1;
  if(memo[now][1] / 2 + 1 < p)
    return solve(now - 1, p - (memo[now][1] / 2) - 1) +
           memo[now - 1][0] + 1;
  else
    return solve(now - 1, p - 1);
}
