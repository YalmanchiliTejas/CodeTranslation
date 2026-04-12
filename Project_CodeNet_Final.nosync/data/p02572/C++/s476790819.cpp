#include <bits/stdc++.h>
#define lli long long int

using namespace std;

int main() {
  lli n;
  int mod = 1000000007;
  std::cin >> n;
  std::vector<lli> v;
  lli sum = 0;
  for (lli i = 0; i < n; ++i) {
    int f;
    std::cin >> f;
    v.push_back(f);
    sum += f;
    sum %= mod;
  }
  lli ans = 0;
  for (int i = 0; i < (int)v.size(); ++i) {
    sum -= v[i];
    if (sum < 0) sum += mod;
    ans += v[i]*sum;
    ans %= mod;
  }
  std::cout << ans << std::endl;
}