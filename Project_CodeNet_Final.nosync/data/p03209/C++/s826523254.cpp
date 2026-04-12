#include <bits/stdc++.h>
using namespace std;

long long burger(int n, long long x) {
  if (n == 0) return 1;
  long long len = (1LL << (n + 1)) - 3;
  long long p = (1LL << n) - 1;
  if (x == 1)
    return 0;
  else if (x <= len + 1)
    return burger(n - 1, x - 1);
  else if (x == len + 2)
    return p + 1;
  else if (x <= 2 * len + 2)
    return p + 1 + burger(n - 1, x - 2 - len);
  else
    return 2 * p + 1;
}

int main() {
  int n;
  long long x;
  cin >> n >> x;

  long long ans;

  ans = burger(n, x);

  cout << ans;
}