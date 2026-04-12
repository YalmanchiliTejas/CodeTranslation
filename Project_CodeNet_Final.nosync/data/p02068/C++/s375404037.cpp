#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

template<class Z> map<Z, int> factorize(Z n) {
  map<Z, int> res;
  for (Z i = 2; i * i <= n; ++i) while (n % i == 0) ++res[i], n /= i;
  if (n != 1) ++res[n];
  return res;
}

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  V<> a(n); for (auto&& e : a) cin >> e;
  set<int> se;
  for (int e : a) for (const auto& f : factorize(e)) {
    se.insert(f.first);
  }
  lint res = 0;
  for (int d : se) {
    lint curr = 0;
    for (int e : a) if (e % d == 0) {
      curr += e;
    }
    res = max(res, curr);
  }
  cout << res << '\n';
}
