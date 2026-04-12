#include <iostream>

const int MAXN = 112345;
long long a[MAXN];

int main() {
  int n;
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }
  long long ans = 0;
  for (int d = 1; 2*d < n-1; ++d) {
    int s = 0;
    int g = n-1;
    long long cur = 0;
    while(true) {
      int ns = s + d;
      int ng = g - d;
      if (ns >= n-1 || ng <= d || ns == ng || ns - ng == d)   break;
      cur += a[ns] + a[ng];
      ans = std::max(ans, cur);
      s = ns;
      g = ng;
    }
  }
  std::cout << ans << std::endl;
}