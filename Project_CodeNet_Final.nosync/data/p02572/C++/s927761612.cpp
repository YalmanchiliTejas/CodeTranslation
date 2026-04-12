#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

long long MOD = 1e9 + 7;

int main() {
  int n;
  cin >> n;
  vector<long long> a(n);
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i] %= MOD;
    sum += a[i];
  }

  long long s = 0;
  for (int i = 0; i < n; i++) {
    sum -= a[i];
    s += (a[i] * (sum % MOD)) % MOD;
  }

  cout << s % MOD << '\n';


  return 0;
}
