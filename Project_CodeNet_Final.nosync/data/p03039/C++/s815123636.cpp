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

int64 C(int64 n) {
  return n * (n + 1) / 2 % MOD;
}

int64 power_mod(int64 a, int n) {
  int64 ret = 1;
  for (; n; n >>= 1) {
    if (n & 1) ret = ret * a % MOD;
    a = a * a % MOD;
  }
  return ret;
}

const int K = 2e5 + 10;
int64 inv[K];

int main() {
  for (int i = 1; i < K; ++i) inv[i] = power_mod(i, MOD - 2);
  int64 n, m, k;
  scanf("%lld%lld%lld", &n, &m, &k);
  int64 ret = 1;
  for (int i = 0; i < k - 2; ++i) {
    ret = ret * (n * m - 2 - i) % MOD * inv[k - 2 - i] % MOD;
  }
  int64 X = 0, Y = 0;
  for (int i = 0; i < n; ++i) {
    int64 cur = C(i);
    // trace(i, C(i), C(n - i));
    X = (X + cur) % MOD;
  }
  for (int i = 0; i < m; ++i) {
    int64 cur = C(i);
    Y = (Y + cur) % MOD;
  }
  // trace(ret, X, Y);
  X = X * m % MOD * m % MOD;
  Y = Y * n % MOD * n % MOD;
  ret = ret * (X + Y) % MOD;
  printf("%lld\n", ret);
  return 0;
}
