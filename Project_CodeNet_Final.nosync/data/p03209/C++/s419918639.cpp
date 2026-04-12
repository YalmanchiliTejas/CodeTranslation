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
#include <random>
#include <ctime>

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

const int N = 51;
int64 cnt[N], len[N];

int64 solve(int n, int64 m) {
  if (m == 0) return 0;
  if (n == 0) return 1;
  // trace(n, m);
  if (m <= 1 + len[n - 1]) {
    return solve(n - 1, m - 1);
  } else {
    return solve(n - 1, m - len[n - 1] - 2) + cnt[n - 1] + 1;
  }
}

int main() {
  len[0] = cnt[0] = 1;
  for (int i = 1; i < N; ++i) {
    cnt[i] = cnt[i - 1] * 2 + 1;
    len[i] = len[i - 1] * 2 + 3;
  }
  int64 n, m;
  cin >> n >> m;
  int64 ret = solve(n, m);
  cout << ret << endl;
  return 0;
}
