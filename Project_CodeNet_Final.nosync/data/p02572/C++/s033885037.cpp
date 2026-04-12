# include <stdio.h>
# include <string.h>
# include <algorithm>
# define mod 1000000007
using namespace std;

long long a[10010000];
long long h, n;

int main() {
  scanf("%lld", &n);
  for (int i = 0; i < n; i++) {
    scanf("%lld", a + i);
    h += a[i];
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    h -= a[i];
    ans = (ans + ((h) % mod * a[i]) % mod) % mod;
  }
  printf("%lld\n", ans);
}