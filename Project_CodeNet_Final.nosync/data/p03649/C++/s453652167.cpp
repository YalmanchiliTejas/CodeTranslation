#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long lint;

lint solve(vector<lint> values) {
  const int n = values.size();
  lint result = 0;
  sort(values.begin(), values.end());
  for (int i = n - 1; i - 1 >= 0; --i) {
    const int nbig = n - i;
    lint rep_count = (values[i] - values[i - 1]) / (n + 1);
    result += rep_count * nbig;
    for (int j = i; j < n; ++j)
      values[j] += rep_count * (-n + nbig - 1);
    for (int j = 0; j < i; ++j)
      values[j] += rep_count * nbig;
    for (int j = 0; j + 1 < n; ++j)
      assert(values[j] <= values[j + 1]);
  }
  if (values[0] > n) {
    lint rep_count = (values[0] - n) / 1;
    result += rep_count * n;
    for (int j = 0; j < n; ++j)
      values[j] += rep_count * (-1);
  }
  while (*max_element(values.begin(), values.end()) >= n) {
    int max_id = max_element(values.begin(), values.end()) - values.begin();
    for (int i = 0; i < n; ++i) {
      if (i == max_id) values[i] -= n;
      else ++values[i];
    }
    ++result;
  }
  return result;
}

int main() {
  int n;
  cin >> n;
  vector<lint> values(n);
  for (int i = 0; i < n; ++i)
    cin >> values[i];
  cout << solve(values) << "\n";
  return 0;
}
