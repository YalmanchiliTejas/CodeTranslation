#include <bits/stdc++.h>
// debug
#define d(x) cerr << #x ":" << x << endl;
#define dd(x, y) cerr << "(" #x "," #y "):(" << x << "," << y << ")" << endl;
#define ddd(x, y, z)                                                     \
  cerr << "(" #x "," #y "," #z "):(" << x << "," << y << "," << z << ")" \
       << endl;
#define dump(v)              \
  cerr << #v ":[ ";          \
  for (auto macro_vi : v) {  \
    cerr << macro_vi << " "; \
  }                          \
  cerr << "]" << endl;
#define ddump(v)                       \
  cerr << #v ":" << endl;              \
  for (auto macro_row : v) {           \
    cerr << "[";                       \
    for (auto macro__vi : macro_row) { \
      cerr << macro__vi << " ";        \
    }                                  \
    cerr << "]" << endl;               \
  }
#define damp(m)                                                   \
  for (auto macro_pair : m) {                                     \
    cerr << macro_pair.first << ":" << macro_pair.second << endl; \
  }
#define dpair(p) \
  cerr << #p ":" \
       << "(" << p.first << "," << p.second << ")" << endl;
// iterate
#define rep(i, n) for (int i = (int)(0); i < (int)(n); i++)
#define repp(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define all(v) v.begin(), v.end()
using ll = long long;

using namespace std;

vector<ll> S(51, -1);
vector<ll> P(51, -1);

ll dfs(int k, ll x) {
  ll mid = S[k] / 2 + 1;
  dd(k, x);
  if (x == 1) {
    if (k == 0) {
      return 1;
    } else {
      return 0;
    }
  } else if (x < mid) {
    return dfs(k - 1, x - 1);
  } else if (x == mid) {
    return P[k - 1] + 1;
  } else if (x < S[k]) {
    return P[k - 1] + 1 + dfs(k - 1, x - (S[k - 1] + 2));
  } else if (x == S[k]) {
    return P[k];
  }
  return 1e18 - 1;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  S[0] = 1, P[0] = 1;
  for (int l = 1; l <= 50; l++) {
    S[l] = 2 * S[l - 1] + 3;
    P[l] = 2 * P[l - 1] + 1;
  }
  ll n, x;
  cin >> n >> x;
  cout << dfs(n, x) << endl;
  return 0;
}