#include <stdio.h>
using namespace std;
typedef long long ll;

ll max(ll a, ll b) {
  return a > b ? a : b;
}

int main(void) {
  ll i, j, k, n, max = 0, a, b, c, d, ans = 0;
  scanf("%lld", &n);
  for(i = 0; i < n; ++i) {
    scanf("%lld", &a);
    if(max <= a) max = a, ans++;
  }
  printf("%lld", ans);
  return 0;
}