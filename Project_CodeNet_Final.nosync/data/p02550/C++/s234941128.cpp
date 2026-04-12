// https://atcoder.jp/contests/abc179/submissions/16938175
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ll N, X, M;
  cin >> N >> X >> M;
  ll total = 0;
  ll x = X;
  vector<int> indices(M, -1);
  vector<int> a;
  int l = 0;
  while (indices[x] == -1) {
    indices[x] = l;
    total += x;
    a.push_back(x);
    x = (x * x) % M;
    l++;
  }
  int cycle = l - indices[x];
  ll cycleSum = 0;
  for (int i = indices[x]; i < l; i++) {
    cycleSum += a[i];
  }
  ll ans = 0;
  if (N <= l) {
    for (int i = 0; i < N; i++) {
      ans += a[i];
    }
  } else {
    ans += total;
    N -= l;
    ans += cycleSum * (N / cycle);
    N %= cycle;
    for (int i = 0; i < N; i++) {
      ans += a[indices[x] + i];
    }
  }
  cout << ans << endl;
}
