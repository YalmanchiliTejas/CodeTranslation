#include <bits/stdc++.h>
using namespace std;

vector<long long> l(51);
vector<long long> p(51);

long long solve (int n, long long x) {
  assert(l[n] >= x && x >= 0);
  if (n == 0) {
    return x;
  }
  if (x == l[n]) {
    return p[n];
  }
  long long ans = 0;
  if (x > l[n - 1] + 1) {
    ans += p[n - 1] + 1;
    x -= l[n - 1] + 1;
  }
  if (x > 0) {
    ans += solve(n - 1, x - 1);
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  long long x;
  cin >> n >> x;
  l[0] = 1LL;
  p[0] = 1LL;
  for (int i = 1; i <= n; i++) {
    l[i] = l[i - 1] * 2 + 3;
    p[i] = p[i - 1] * 2 + 1;
  }
  cout << solve(n, x) << '\n';
}
