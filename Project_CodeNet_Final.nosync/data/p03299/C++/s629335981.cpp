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

inline int add(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }

inline int sub(int a, int b) { return a >= b ? a - b : a - b + mod; }

inline int mul(int a, int b) { return llint(a) * b % mod; }

int powmod(int a, llint b) {
  if (b == 0) return 1;
  if (b & 1) return mul(a, powmod(a, b - 1));
  return powmod(mul(a, a), b / 2);
}

const int MAX = 110;

int h[MAX], pw[MAX];

pair<int, int> solve(int a, int b, int s) {
  if (b - a == 1) {
    int w = powmod(2, h[a] - s);
    return {w, w};
  }

  int m = *min_element(h + a, h + b);

  vector<pair<int, int>> v;
  int i = a;
  while (i < b) {
    int j = i;
    while (j < b && (h[i] == m) == (h[j] == m)) j++;
    v.push_back({i, j});
    i = j;
  }

  int fTotal = 1;
  int fAlternate = 2;

  for (auto& p : v) {
    int x = p.first, y = p.second;
    if (h[x] != m) {
      auto g = solve(x, y, m);
      fTotal = mul(fTotal, add(g.first, g.second));
      fAlternate = mul(fAlternate, g.first);
    } else {
      fTotal = mul(fTotal, pw[y - x]);
    }
  }

  fTotal = sub(fTotal, fAlternate);
  fAlternate = mul(fAlternate, powmod(2, m - s - 1));
  fTotal = add(fTotal, fAlternate);
  return {fAlternate, fTotal};
}

int main(void) {
  int N;
  scanf("%d", &N);
  REP(i, N) scanf("%d", &h[i]);

  pw[0] = 1;
  REP(i, N) pw[i + 1] = mul(pw[i], 2);

  auto g = solve(0, N, 0);
  printf("%d\n", g.second);
  return 0;
}
