#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int mod = 1e9 + 7;

inline int add(int a, int b) {
  return a+b >= mod ? a+b-mod : a+b;
}

inline int sub(int a, int b) {
  return a >= b ? a-b : a-b+mod;
}

inline int mul(int a, int b) {
  return llint(a)*b % mod;
}

int powmod(int a, llint b) {
  if (b == 0) return 1;
  if (b&1) return mul(a, powmod(a, b-1));
  return powmod(mul(a, a), b/2);
}

const int MAX = 110;

int h[MAX], pw[MAX];

pair<int, int> solve(int a, int b, int s) {
  if (b - a == 1) {
    return {powmod(2, h[a] - s - 1), 0};
  }

  assert(b - a > 1);
  int m = *min_element(h + a, h + b);

  vector<pair<int, int>> v;
  int i = a;
  while (i < b) {
    int j = i;
    while (j < b && (h[i] == m) == (h[j] == m)) j++;
    v.push_back({i, j});
    i = j;
  }

  int f0 = 0, f1 = 1;
  bool first = true;
  for (auto& p: v) {
    int x = p.first, y = p.second;
    if (h[x] != m) {
      if (y - x > 1) {
        auto g = solve(x, y, m);
        if (first) {
          f1 = mul(2, g.first);
          f0 = g.second;
        } else {
          f0 = mul(f0, add(mul(4, g.first), g.second));
          f0 = add(f0, mul(mul(2, f1), mul(2, g.first)));
          f0 = add(f0, mul(mul(2, f1), g.second));
          f1 = mul(f1, mul(2, g.first));
        }
      } else {
        if (first) {
          f0 = 0;
          f1 = powmod(2, h[x] - m);
        } else {
          f0 = mul(f0, 2);
          f0 = add(f0, mul(2, f1));
          f0 = mul(f0, powmod(2, h[x] - m));
          f1 = mul(f1, powmod(2, h[x] - m));
        }
      }
    } else {
      if (first) {
        f0 = sub(pw[y - x], 2);
        f1 = 1;
      } else {
        f0 = mul(f0, pw[y - x]);
        f0 = add(f0, mul(mul(2, f1), sub(pw[y - x], 1)));
      }
    }
    first = false;
  }

  int good_ways = powmod(2, m - s - 1);

  f1 = mul(f1, good_ways);

  return {f1, f0};
}

int main(void) {
  int N;
  scanf("%d", &N);
  REP(i, N) scanf("%d", &h[i]);

  pw[0] = 1;
  REP(i, N) pw[i + 1] = mul(pw[i], 2);

  auto g = solve(0, N, 0);

  int ret = add(mul(2, g.first), g.second);
  printf("%d\n", ret);
  return 0;
}
