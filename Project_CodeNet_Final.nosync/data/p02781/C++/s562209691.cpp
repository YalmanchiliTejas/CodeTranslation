#include <stdio.h>
#include <string.h>
typedef long long ll;

int main(void) {
  ll i, j, k, ans, cnt = 1, n;
  char a[110];
  scanf("%s%lld", a, &k);
  n = strlen(a);
  ll cmb[n + 1][k + 2], p[k + 1];
  for(i = 0; i <= n; ++i) for(j = 0; j <= k; ++j) cmb[i][j] = 0;
  cmb[0][0] = 1;
  for(i = 0; i < n; ++i) for(j = 0; j <= k; ++j) 
    cmb[i + 1][j] += cmb[i][j], cmb[i + 1][j + 1] += cmb[i][j];
  p[0] = 1;
  for(i = 0; i < k; ++i) p[i + 1] = p[i] * 9;
  ans = cmb[n - 1][k] * p[k];
  ans += cmb[n - 1][k - 1] * (a[0] - '1') * p[k - 1];
  for(i = 1; i < n; ++i) {
    if(cnt == k) break;
    if(a[i] != '0') {
      ans += cmb[n - 1 - i][k - cnt] * p[k - cnt];
      cnt++;
      ans += (a[i] - '1') * cmb[n - 1 - i][k - cnt] * p[k - cnt];
    }
  }
  printf("%lld", ans + (cnt == k ? 1 : 0));
  return 0;
}