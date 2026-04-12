#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  long long tmp = 0;
  vector<long long> b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    tmp += a[i];
    b[i] = tmp;
  }
  long long ans = 0;
  int mod = 1000000007;
  for (int i = 0; i < n-1; i++) {
    long long sum = (b[n-1] - b[i])%mod;
    ans += (a[i]*sum)%mod;
    ans %= mod;
  }
  cout << ans << endl;
  return 0;
}