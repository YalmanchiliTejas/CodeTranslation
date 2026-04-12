#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  vector<long long> b(n+1);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    b[i+1] = b[i] + a[i];
  }
  int mod = 1000000007;
  long long ans = 0;
  for (int i = 0; i < n-1; i++) {
    long long sum = (b[n] - b[i+1])%mod;
    ans += a[i]*sum;
    ans %= mod;
  }
  cout << ans << endl;
}