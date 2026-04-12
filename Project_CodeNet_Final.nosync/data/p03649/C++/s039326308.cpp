#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T> void assign(V<T>& v, int n, const T& a = T()) { v.assign(n, a); }
template<class T, class... U> void assign(V<T>& v, int n, const U&... u) { v.resize(n); for (auto&& i : v) assign(i, u...); }

int main() {
  cin.tie(NULL); ios::sync_with_stdio(false);
  int n; cin >> n;
  V<lint> a(n); for (int i = 0; i < n; i++) cin >> a[i];
  auto chk = [&](const V<lint>& a) {
    for (auto&& i : a) if (i >= n) return false;
    return true;
  };
  if (*max_element(a.begin(), a.end()) < 2 * (n + 1) * (n + 1)) {
    int res = 0;
    while (!chk(a)) {
      *max_element(a.begin(), a.end()) -= n + 1;
      for (auto&& i : a) i++;
      res++;
    }
    cout << res << '\n';
  } else {
    V<lint> b(n); for (int i = 0; i < n; i++) b[i] = a[i] % (n + 1) + (n + 1) * (n + 1);
    lint res = accumulate(a.begin(), a.end(), 0LL) - accumulate(b.begin(), b.end(), 0LL);
    while (!chk(b)) {
      (*max_element(b.begin(), b.end())) -= n + 1;
      for (auto&& i : b) i++;
      res++;
    }
    cout << res << '\n';
  }
}
