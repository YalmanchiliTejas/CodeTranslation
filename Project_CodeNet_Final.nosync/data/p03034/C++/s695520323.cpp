#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

template<class Z> V<Z> divisor(Z n) {
  V<Z> res;
  Z i;
  for (i = 1; i * i < n; ++i) if (n % i == 0) res.push_back(i), res.push_back(n / i);
  if (i * i == n) res.push_back(i);
  sort(begin(res), end(res));
  return res;
}

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  V<lint> s(n); for (auto&& e : s) cin >> e;
  VV<lint> c(n);
  for (int d = 1; d < n; ++d) {
    c[d].resize(n / d + 1);
    for (int i = 0; i < n / d; ++i) {
      c[d][i + 1] = c[d][i] + s[d * i] + s[n - 1 - d * i];
    }
  }
  lint res = 0;
  for (int A = 1; A < n; ++A) for (int k : divisor(n - 1 - A)) {
    int B = A - (n - 1 - A) / k;
    if (B <= 0 or B >= A) continue;
    if (A <= k * (A - B) and !(A % (A - B))) continue;
    lint curr = c[A - B][k + 1];
    res = max(res, curr);
  }
  cout << res << '\n';
}