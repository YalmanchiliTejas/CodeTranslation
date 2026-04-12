#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  int n;
  scanf("%d", &n);
  vector<ll> a(n);
  for (int i = 0; i < n; i++) {
    scanf("%lld", &a[i]);
  }
  ll result = 0;
  while (true) {
    ll maxi = 0;
    int maxIdx = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] >= maxi) {
        maxi = a[i];
        maxIdx = i;
      }
    }
    if (maxi < n) break;
    ll quot = a[maxIdx] / n;
    result += quot;
    a[maxIdx] %= n;
    for (int i = 0; i < n; i++) {
      if (i == maxIdx) continue;
      a[i] += quot;
    }
  }
  printf("%lld\n", result);
  return 0;
}
