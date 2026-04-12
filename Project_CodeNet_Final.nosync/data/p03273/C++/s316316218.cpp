#define _USE_MATH_DEFINES
#include <cassert>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <complex>
#include <cmath>
#include <numeric>
#include <bitset>
#include <functional>

using namespace std;

#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
  cerr << name << ": " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << ": " << arg1 << " |";
  __f(comma + 1, args...);
}

typedef long long int64;
typedef pair<int, int> ii;
const int INF = 1 << 29;
const int MOD = 1e9 + 7;

const int N = 200;
string s[N];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
  }
  set<int> rows, cols;
  for (int i = 0; i < n; ++i) {
    int sum = 0;
    for (int j = 0; j < m; ++j) {
      sum += s[i][j] == '.';
    }
    if (sum == m) rows.insert(i);
  }
  for (int j = 0; j < m; ++j) {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
      sum += s[i][j] == '.';
    }
    if (sum == n) cols.insert(j);
  }
  for (int i = 0; i < n; ++i) {
    if (rows.count(i)) continue;
    string cur = "";
    for (int j = 0; j < m; ++j) {
      if (cols.count(j)) continue;
      cur += s[i][j];
    }
    cout << cur << endl;
  }
  return 0;
}
