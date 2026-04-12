#include <iostream>
#include <string>
#include <cstring>

const int MOD = 1e9 + 7;
const int MAX_K = 100000;

int f[MAX_K + 1][100], digits[MAX_K + 1], D;

inline int add(int x, int v) { return x + v >= MOD ? x + v - MOD : x + v; }

int dp(int pos, int limit, int mod) {
  if (pos < 1) return mod == 0;
  auto &ret = f[pos][mod];
  if (!limit && ret != -1) return ret;
  const int end = limit ? digits[pos] : 9;
  ret = 0;
  for (int i = 0; i <= end; ++i)
    ret = add(ret, dp(pos - 1, limit && (i == end), (mod + i) % D));
  return ret;
}

int main() {
  memset(f, -1, sizeof(f));
  std::string s;
  std::cin >> s >> D;
  int l = 0;
  for (auto i = s.crbegin(); i != s.crend(); ++i) digits[++l] = *i ^ 48;
  std::cout << add(dp(l, 1, 0), MOD - 1);
  return 0;
}