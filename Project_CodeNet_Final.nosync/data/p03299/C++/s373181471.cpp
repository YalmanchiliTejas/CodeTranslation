#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;

int add(int x, int y) {
  x += y;
  if (x >= mod) {
    x -= mod;
  }
  return x;
}

int sub(int x, int y) {
  x -= y;
  if (x < 0) {
    x += mod;
  }
  return x;
}

int mul(int x, int y) {
  return (ll)x * y % mod;
}

int power(int x, int y) {
  int result = 1;
  for (; y; y >>= 1, x = mul(x, x)) {
    if (y & 1) {
      result = mul(result, x);
    }
  }
  return result;
}

pair<int, int> solve(int l, int r, int base, vector<int> &a) {
  int x = *min_element(a.begin() + l, a.begin() + r), coef = 1, all = 1, number = 0;
  for (int i = l; i < r; ++i) {
    if (a[i] != x) {
      int j = i;
      while (j + 1 < r && a[j + 1] != x) {
        ++j;
      }
      pair<int, int> value = solve(i, j + 1, x, a);
      i = j;
      coef = mul(coef, value.first);
      all = mul(all, add(value.first, value.second));
    } else {
      ++number;
    }
  }
  return make_pair(mul(coef, power(2, x - base)), add(mul(all, power(2, number)), mul(coef, sub(power(2, x - base), 2))));
}

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n;
  scanf("%d", &n);
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  printf("%d\n", solve(0, n, 0, a).second);
  return 0;
}
