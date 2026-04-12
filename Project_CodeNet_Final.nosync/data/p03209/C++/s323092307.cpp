#include <bits/stdc++.h>
using namespace std;

long long count(int m, long long x, vector<long long> sum, vector<long long> pate) {
  if (m == 0) {
    if (x == 0) return 0;
    else return 1;
  }
  if (x <= 1) return 0;
  if (x <= sum.at(m) / 2) return count(m - 1, x - 1, sum, pate);
  if (x == sum.at(m) / 2 + 1) return pate.at(m - 1) + 1;
  if (x <= sum.at(m) - 1) return pate.at(m - 1) + 1 + count(m - 1, x - sum.at(m) / 2 - 1, sum, pate);
  if (x == sum.at(m)) return pate.at(m);
}

int main() {
  int n; cin >> n;
  long long x; cin >> x;
  vector<long long> sum(n + 1), pate(n + 1);
  sum.at(0) = pate.at(0) = 1;
  for (int i = 1; i <= n; i++) {
    sum.at(i) = sum.at(i - 1) * 2 + 3;
    pate.at(i) = pate.at(i - 1) * 2 + 1;
  }
  long long ans = count(n, x, sum, pate);
  cout << ans << endl;
}