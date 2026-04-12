#include <bits/stdc++.h>

using namespace std;
int main() {
  long long n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a.at(i);
  }

  const int md = 1e9 + 7;
  vector<long long> s(n + 1, 0);
  for (int i = 0; i < n; i++) {
    s[i + 1] = (s[i] % md + a[i]) % md;
  }
  long long ans = 0;
  for (int i = 0; i < n - 1; i++) {
    long long b = s[n] - s[i + 1];
    if (b < 0) b += md;

    ans = ((ans % md) + (a.at(i) * b) % md) % md;
  }
  cout << ans;
}
