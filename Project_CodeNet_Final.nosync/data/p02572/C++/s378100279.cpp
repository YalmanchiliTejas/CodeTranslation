#include <bits/stdc++.h>
 
#define M 1000000007
 
int main(void)
{
  int n;
  std::cin >> n;
 
  std::vector<int> a(n);
  // std::vector<uint64_t> sum(n+1, 0);
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
    sum += a[i];
    sum %= M;
  }
 
  long ans = 0;
  for (int i = 0; i < n-1; i++) {
    sum -= a[i];
    if (sum < 0) {
      sum += M;
    }

    ans += (sum * a[i]);
    ans %= M;
  }
 
  std::cout << ans << std::endl;
 
  return 0;
}