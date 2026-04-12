#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <cfloat>
#include <complex>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;

int main() {
  ll N;

  cin >> N;

  string common;
  cin >> common;

  unordered_map<char, int> common_um;
  for (size_t i = 0; i < common.length(); i++) {
    common_um[common[i]]++;
  }

  for (int i = 1; i < N; i++) {
    string tmp;
    unordered_map<char, int> tmp_um;
    cin >> tmp;
    for (size_t i = 0; i < tmp.length(); i++) {
      tmp_um[tmp[i]]++;
    }
    for (auto& kv : common_um) {
      common_um[kv.first] = min(common_um[kv.first], tmp_um[kv.first]);
    }
  }

  string ans = "";
  for (auto& kv : common_um) {
    if (kv.second > 0) {
      for (int i = 0; i < kv.second; i++) ans += kv.first;
    }
  }

  sort(ans.begin(), ans.end());
  cout << ans << endl;

  return 0;
}
