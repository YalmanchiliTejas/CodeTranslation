#include <cstdio>
#include <cstring>

using namespace std;

int n;
char s[109];

int go(int i, int k, int less) {
  if (n - i < k) {
    return 0;
  }
  if (k == 0) {
    return 1;
  }
  int res = 0;
  if (less == 1) {
    res = 1;
    for (int j = 0; j < k; ++j) {
      res *= n - i - j;
    }
    for (int j = 2; j <= k; ++j) {
      res /= j;
    }
    for (int j = 0; j < k; ++j) {
      res *= 9;
    }
  } else {
    int t = (int)(s[i] - '0');
    res += go(i + 1, k, t != 0);
    for (int j = 1; j < t; ++j) {
      res += go(i + 1, k - 1, 1);
    }
    if (t != 0) {
      res += go(i + 1, k - 1, 0);
    }
  }
  return res;
}

int main() {
  int k;
  scanf("%s%d", s, &k);
  n = (int)strlen(s);
  printf("%d\n", go(0, k, 0));
}
