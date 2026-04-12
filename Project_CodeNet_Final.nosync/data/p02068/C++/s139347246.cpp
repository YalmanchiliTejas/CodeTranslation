#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
vector<int> sieve(int n) {
  vector<int> primes;
  vector<bool> is_prime(n + 1, 1);
  is_prime[0] = 0;
  is_prime[1] = 0;
  for (int i = 2; i <= n; i++) {
    if (!is_prime[i]) continue;
    primes.push_back(i);
    for (int j = i + i; j <= n; j += i) {
      is_prime[j] = 0;
    }
  }
  return primes;
}
signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> primes = sieve(50000);
  set<int> st;
  vector<int> aa = a;
  for (int i = 0; i < n; i++) {
    for (int p : primes) {
      if (aa[i] % p == 0) {
        st.insert(p);
        while (aa[i] % p == 0) aa[i] /= p;
      }
    }
    if (aa[i] > 1) st.insert(aa[i]);
  }
  long long ans = 0;
  for (int x : st) {
    long long cur = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] % x == 0) cur += a[i];
    }
    ans = max(ans, cur);
  }
  cout << ans << '\n';
  return 0;
}
