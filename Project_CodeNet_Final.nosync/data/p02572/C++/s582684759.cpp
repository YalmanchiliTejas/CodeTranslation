#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  int m = 1000000007;
  cin >> n;
  vector<int> values(n);
  for (int i = 0; i < n; i++) {
    cin >> values[i];
  }

  long long ans = 0;
  long long sum = 0;
  for (int i = n - 2; i >= 0; i--) {
    sum += values[i + 1];
    sum %= m;
    ans += values[i] * sum;
    ans %= m;
  }

  cout << (ans % m) << endl;
}
