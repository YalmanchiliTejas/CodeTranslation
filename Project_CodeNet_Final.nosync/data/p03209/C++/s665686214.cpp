#include <stdio.h>
#include <vector>
typedef long long ll;
using namespace std;

int main(void) {
  ll i, j, k, n, x, ans = 0;
  scanf("%lld%lld", &n, &x);
  for(i = n + 2; i >= 3; --i) {
    if((1ll << i) <= x + 3) {
     ans += (1ll << (i - 1)) - 1;
     x -= (1ll << i) - 3;
     if(x) x--, ans++;
    }
    if(x) x--;
  }
  if(x > 0) {
    if(x < 4) ans += x;
    else ans += 3;
  }
  printf("%lld", ans);
  return 0;
}