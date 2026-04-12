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

const int N = 1e4 + 10;
const int M = 100;
char s[N];
int a[N];
int dp[N][2][M];

void add(int& x, int y) {
  x = (x + y) % MOD;
}

int main() {
  scanf("%s", s);
  int n = strlen(s), m;
  scanf("%d", &m);
  for (int i = 0; i < n; ++i) {
    a[i] = s[i] - '0';
  }
  dp[0][1][0] = 1;
  for (int i = 0; i < n; ++i) {
    // touch = 0
    for (int j = 0; j < 10; ++j) {
      for (int k = 0; k < m; ++k) {
        int nk = (k + j) % m;
        add(dp[i + 1][0][nk], dp[i][0][k]);
      }
    }
    // touch = 1
    for (int j = 0; j < a[i]; ++j) {
      for (int k = 0; k < m; ++k) {
        int nk = (k + j) % m;
        add(dp[i + 1][0][nk], dp[i][1][k]);
      }
    }
    for (int k = 0; k < m; ++k) {
      int nk = (k + a[i]) % m;
      add(dp[i + 1][1][nk], dp[i][1][k]);
    }
    // for (int k = 0; k < m; ++k) {
    //   cout << k << " " << dp[i + 1][0][k] << " " << dp[i + 1][1][k] << endl;
    // }
  }
  int ret = ((dp[n][1][0] + dp[n][0][0]) % MOD + MOD - 1) % MOD;
  printf("%d\n", ret);
  return 0;
}
