#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cinttypes>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

const int kSize = 'z' - 'a' + 1;

int main() {
//  freopen("../Console/1.txt", "rb", stdin);
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  cin >> N;

  vector<vector<int>> S(N, vector<int>(kSize, 0));
  for (int i = 0; i < N; ++i) {
    string s;
    cin >> s;
    for (char ch : s) {
      ++S[i][ch - 'a'];
    }
  }

  string result;
  for (int i = 0; i < kSize; ++i) {
    int mx = numeric_limits<int>::max();
    for (const auto& v : S) {
      mx = min(mx, v[i]);
    }

    for (int j = 0; j < mx; ++j) {
      result.push_back(i + 'a');
    }
  }

  cout << result << '\n';

  return 0;
}
