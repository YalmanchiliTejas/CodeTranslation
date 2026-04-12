#include <bits/stdc++.h>
using namespace std;

constexpr int64_t mod = 1000000007;
vector<int64_t> fact, inv;

int64_t power(int64_t n, int64_t k) {
  if (k == 0) return 1;
  int64_t ans = power(n * n % mod, k / 2);
  if (k % 2) ans = ans * n % mod;
  return ans;
}

void init(int n) {
  fact.push_back(1);
  inv.push_back(1);
  for (int i = 0; i < n; i++) {
    fact.push_back((i + 1) * fact.at(i) % mod);
    inv.push_back(power(fact.at(i + 1), mod - 2));
  }
}

int64_t ncr(int n, int r) {
  if (n < r) return 0;
  return fact.at(n) * inv.at(r) % mod * inv.at(n - r) % mod;
}

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  init(n * m + k);
  int x = n * n * ncr(m + 1, 3) % mod + m * m * ncr(n + 1, 3) % mod;
  cout << x * ncr(n * m - 2, k - 2) % mod << endl;
}
