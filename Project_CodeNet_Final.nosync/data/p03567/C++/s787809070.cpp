#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

using ll = long long;
using P = pair<int, int>;

const int INF = 1e9;
const int MOD = 1e9 + 7;

// 4近傍、8近傍
int dx[] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};

int main() {
  // 入力
  string s;
  cin >> s;

  bool ans = false;
  for (int i = 0; i < s.size() - 1; i++) {
    if (s[i] == 'A' && s[i+1] == 'C') ans = true;
  }

  // 解答
  cout << (ans ? "Yes" : "No") << endl;

  return 0;
}
