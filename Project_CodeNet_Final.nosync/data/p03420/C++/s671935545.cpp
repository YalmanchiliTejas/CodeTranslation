#include<bits/stdc++.h>
using namespace std;

#define all(C) C.begin(),C.end()
typedef long long int Long;
typedef long double Double;
const int MAXN = 1e5 + 5;

int main() {
  int n, k;
  cin >> n >> k;

  Long ans = 0;
  if(k == 0) {
    ans = n * 1LL * n;
  } else {
    for(int b = k + 1; b <= n; ++b) {
      ans += (n / b) * 1LL * (b - k);
      ans += max(0, (n % b) - k + 1);
    }
  }

  printf("%lld\n", ans);
  return 0;
}