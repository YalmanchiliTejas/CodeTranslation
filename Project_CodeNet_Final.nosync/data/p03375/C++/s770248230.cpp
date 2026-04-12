#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T> void assign(V<T>& v, int n, const T& a = T()) { v.assign(n, a); }
template<class T, class... U> void assign(V<T>& v, int n, const U&... u) { v.resize(n); for (auto&& i : v) assign(i, u...); }

lint mod;
inline lint emod(lint a, lint p = mod) { return (a % p + p) % p; }

inline lint invm(lint a, lint p = mod) { a %= p; return a == 1 ? 1 : -p / a * invm(p % a) % p; }

inline lint powm(lint a, lint n, lint p = mod) { return !n ? 1 : powm(a * a % p, n >> 1, p) * (n & 1 ? a : 1) % p; }

V<lint> fact, ifact;
void init_table(int n) {
  fact.assign(n + 1, 1), ifact.assign(n + 1, 1);
  for (int i = 2; i < n + 1; i++) fact[i] = i * fact[i - 1] % mod;
  ifact[n] = invm(fact[n]);
  for (int i = n; i > 2; i--) ifact[i - 1] = i * ifact[i] % mod;
}

lint comb(lint n, lint r) {
  if (n < 0 or r < 0 or r > n) return 0;
  return fact[n] * ifact[r] % mod * ifact[n - r] % mod;
}

int main() {
  cin.tie(NULL); ios::sync_with_stdio(false);
  lint n; cin >> n >> mod;
  init_table(n);
  VV<lint> s; assign(s, n + 2, n + 2);
  s[0][0] = 1;
  for (int i = 1; i < n + 2; i++) for (int j = 1; j < i + 1; j++) s[i][j] = (j * s[i - 1][j] + s[i - 1][j - 1]) % mod;
  lint res = powm(2, powm(2, n, mod - 1));
  for (int k = 1; k < n + 1; k++) {
    lint t = 0, c = 1, d = powm(2, n - k);
    for (int j = 0; j < k + 1; j++) {
      t = (t + c * s[k + 1][j + 1]) % mod;
      c = c * d % mod;
    }
    t = t * powm(2, powm(2, n - k, mod - 1)) % mod;
    res = (res - (k & 1 ? 1 : -1) * comb(n, k) * t) % mod;
  }
  cout << emod(res) << '\n';
}