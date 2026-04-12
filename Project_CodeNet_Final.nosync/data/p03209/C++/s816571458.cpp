#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>

const int MaxN = 1000 + 5;

struct bign {
  int len;
  int a[MaxN];
};

inline std::istream& operator >> (std::istream& in, bign &x) {
  std::string str;
  std::cin >> str;
  x.len = str.length();
  for (int i = 0; i < x.len; ++i)
    x.a[i] = str[x.len - i - 1] - '0';
  return in;
}

inline std::ostream& operator << (std::ostream& out, bign x) {
  if (x.len == 0) {
    printf("%d", 0);
    return out;
  }
  for (int i = x.len - 1; i >= 0; --i)
    printf("%d", x.a[i]);
  return out;
}

inline bign operator + (bign x, bign y) {
  if (x.len < y.len) std::swap(x, y);
  for (int i = 0; i < y.len; ++i)
    x.a[i] += y.a[i];
  for (int i = 0; i < x.len; ++i) {
    x.a[i + 1] += x.a[i] / 10;
    x.a[i] %= 10;
  }
  if (x.a[x.len] != 0) x.len++;
  return x;
}

inline bign operator - (bign x, bign y) {
  for (int i = 0; i < y.len; ++i)
    x.a[i] -= y.a[i];
  for (int i = 0; i < x.len; ++i) {
    if (x.a[i] < 0) {
      x.a[i] += 10;
      x.a[i + 1]--;
    }
  }
  while (x.len > 0 && x.a[x.len - 1] == 0) x.len--;
  return x;
}

inline bign operator * (bign x, int y) {
  for (int i = 0; i < x.len; ++i)
    x.a[i] *= y;
  for (int i = 0; i < x.len; ++i) {
    x.a[i + 1] += x.a[i] / 10;
    x.a[i] %= 10;
  }
  while (x.a[x.len] != 0) {
    x.a[x.len + 1] += x.a[x.len] / 10;
    x.a[x.len] %= 10;
    x.len++;
  }
  return x;
}

inline bool operator == (bign x, bign y) {
  if (x.len != y.len) return false;
  for (int i = 0; i < x.len; ++i)
    if (x.a[i] != y.a[i]) return false;
  return true;
}

inline bool operator > (bign x, bign y) {
  if (x.len < y.len) return false;
  if (x.len > y.len) return true;
  for (int i = x.len - 1; i >= 0; --i) {
    if (x.a[i] > y.a[i]) return true;
    if (x.a[i] < y.a[i]) return false;
  }
  return false;
}

int N;
bign X;
bign _0, _1, _2, _3;
bign F[MaxN], G[MaxN];

void init() {
  scanf("%d", &N);
  std::cin >> X;

  _0.len = 0;
  _1.len = 1, _1.a[0] = 1;
  _2.len = 1, _2.a[0] = 2;
  _3.len = 1, _3.a[0] = 3;
}

bign dfs(int n, bign x) {
  if (x == _0) return _0;
  if (n == 0) return _1;
  if (x > F[n - 1] + _1) {
    return G[n - 1] + _1 + dfs(n - 1, x - F[n - 1] - _2);
  } else {
    return dfs(n - 1, x - _1);
  }
}

void solve() {
  F[0] = G[0] = _1;
  for (int i = 1; i <= N; ++i) {
    F[i] = (F[i - 1] * 2) + _3;
    G[i] = (G[i - 1] * 2) + _1;
  }

  std::cout << dfs(N, X) << std::endl;
}

int main() {
  init();
  solve();
  return 0;
}