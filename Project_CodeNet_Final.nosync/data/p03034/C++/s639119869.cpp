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

const int N = 1e5 + 10;
int64 s[N];

int64 gcd(int64 a, int64 b) {
  while (b) {
    int64 c = a;
    a = b;
    b = c % b;
  }
  return a;
}

vector<int64> L[N], R[N];

int64 solve(int64 A, int64 B, int64 n) {
  int64 step = (n - A) / (A - B);
  if (n % (A - B) == 0 && n / (A - B) <= 2 * step) return -1;
  // int64 C = gcd(A, A - B);
  // int64 mins = A / C;
  // // trace(A, B, n, mins, step);
  // if (mins <= step) return -1;
  // trace(A, B, step, L[A - B][step], R[A - B][step]);
  int64 ret = L[A - B][step] + R[A - B][step];
  return ret;
}

int main() {
  int n;
  scanf("%d", &n);
  --n;
  for (int i = 0; i <= n; ++i) {
    scanf("%lld", &s[i]);
  }
  for (int k = 1; k < n; ++k) {
    int64 cur = 0;
    for (int i = 0; i <= n; i += k) {
      cur += s[i];
      L[k].push_back(cur);
    }
  }
  for (int k = 1; k < n; ++k) {
    int64 cur = 0;
    for (int i = 0; i <= n; i += k) {
      cur += s[n - i];
      R[k].push_back(cur);
    }
  }
  // for (int k = 1; k < n; ++k) {
  //   trace(k, sum[k].size());
  //   for (auto& it : sum[k]) {
  //     cout << it << " ";
  //   }
  //   cout << endl;
  // }
  int64 ret = 0;
  for (int A = 2; A < n; ++A) {
    int m = n - A;
    for (int C = 1; C * C <= m; ++C) {
      if (m % C) continue;
      int B = A - C;
      if (B > 0 && B < A) ret = max(ret, solve(A, B, n));
      B = A - m / C;
      if (B > 0 && B < A) ret = max(ret, solve(A, B, n));
    }
  }
  printf("%lld\n", ret);
  return 0;
}
