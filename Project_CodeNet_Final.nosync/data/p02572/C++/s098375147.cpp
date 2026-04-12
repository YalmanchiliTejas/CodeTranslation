#include <bits/stdc++.h>

using namespace std;
using llong = long long;
using ldbl = long double;
using lpair = pair<llong, llong>;

#define ALL(x) x.begin(), x.end()

constexpr llong mod = 1e9+7;
constexpr llong inf = mod * mod;

int main() {
  llong N;
  vector<llong> A;
  vector<llong> rui;

  cin >> N;
  A.resize(N);
  rui.push_back(0);
  for (auto &in: A) {
    cin >> in;
    rui.push_back((rui.back() + in) % mod);
  }

  llong ans = 0;
  for (int i = 0; i < N; i++) {
    ans = (ans + A[i] * (rui[N] - rui[i + 1] + mod) % mod) % mod;
  }

  cout << ans << endl;

  return 0;
}