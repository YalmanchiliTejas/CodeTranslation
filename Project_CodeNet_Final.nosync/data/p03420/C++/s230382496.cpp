#include <bits/stdc++.h>
#define FOR(i, a, b) for (long long i = (a); i < (b); i++)
using namespace std;
typedef long long ll;
int main() {
  ll n, k, ans = 0;
  cin >> n >> k;
  if (k == 0) return !printf("%lld\n", n * n);
  FOR(i, k + 1, n + 1) ans += n / i * (i - k) + max((ll)0, n % i - k + 1);
 printf("%lld\n", ans);
}
