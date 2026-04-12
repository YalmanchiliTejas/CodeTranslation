#include <stdio.h>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <complex>
#include <map>
#include <queue>
#include <array>
#include <bitset>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef long double ld;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;
//typedef long long int;

int main() {
std::ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vl a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  ll res = 0;
  for (int i = 0; i < 1000; ++i) {
    sort(a.begin(), a.end());
    if (a.back() - a[0] > n) {
      ll d = min((a.back() - n + 1) / n, (a.back() - a[0]) / (n + 1));
      a.back() -= d * n;
      for (int j = 0; j + 1 < n; ++j) a[j] += d;
      res += d;
    }
  }
  ll mi = a[0];
  for (int i = 0; i < n; ++i) {
    mi = min(mi, a[i]);
  }
  ll d = mi - (n - 1);
  if (d > 0) {
    res += n * d;
    for (int i = 0; i < n; ++i) a[i] -= d;
  }
  while (1) {
    bool go = 0;
    for (int i = 0; i < n; ++i) if (a[i] >= n) {
      a[i] -= n;
      for (int j = 0; j < n; ++j) if (i != j) ++a[j];
      ++res;
      go = 1;
    }
    if (!go) break;
  }
  cout << res << endl;
  return 0;
}