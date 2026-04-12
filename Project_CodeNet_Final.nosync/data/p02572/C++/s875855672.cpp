#include <iostream>
#include <vector>

#define MOD 1000000007

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<long long> a(n);
  for (auto& v : a) {
    cin >> v;
  }
  
  vector<long long> sum(n - 1, 0);
  sum[n - 2] = a[n - 1];
  for (int i = n - 3; i >= 0; --i) {
    sum[i] = a[i + 1] + sum[i + 1];
    sum[i] %= MOD;
  }
  
  long long ans = 0;
  for (int i = 0; i < n - 1; ++i) {
    ans += a[i] * sum[i];
    ans %= MOD;
  }
  cout << ans << endl;
  
  return 0;
}