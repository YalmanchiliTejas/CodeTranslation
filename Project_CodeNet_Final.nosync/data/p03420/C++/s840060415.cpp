#include <iostream>
#include <algorithm>
using namespace std;
#define int long long

signed main() {
  int n, k;
  cin >> n >> k;
  int count = 0;
  for (int i = 1; i <= n; i++) {
    int sho = n / i;
    int amari = n % i;
    count += sho * max(0LL, i - k);
    count += max(0LL, amari - k + 1);
  }
  if (k == 0) count -= n;
  cout << count << endl;
  return 0;
}
