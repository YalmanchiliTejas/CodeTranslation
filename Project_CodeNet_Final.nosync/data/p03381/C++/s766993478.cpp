#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

namespace Header_Template {
  typedef long long li;
  template<class T>inline void read(T &x) {
    x = 0;
    T tmp = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') tmp = -1, c = getchar();
    while (c >= '0' && c <= '9')
      x = (x << 1) + (x << 3) + c - '0', c = getchar();
    x *= tmp;
  }
  template<class T>inline void Max(T &x, T y) {
    if (y > x) x = y;
  }
  template<class T>inline void Min(T &x, T y) {
    if (y < x) x = y;
  }
}
using namespace Header_Template;

const int N = 2e5 + 10;
int n, a[N], v[N];

int c[N];
inline int lowbit(int x) { return x & -x; }
void Add(int x, int val) {
  for (; x <= n; x += lowbit(x))
    c[x] += val;
}
int Query(int x) {
  int res = 0;
  for (; x; x -= lowbit(x))
    res += c[x];
  return res;
}

int main(void) {
  read(n);
  for (int i = 1; i <= n; ++i)
    read(a[i]), v[i] = a[i];
  sort(v + 1, v + 1 + n);
  int m = unique(v + 1, v + 1 + n) - v - 1;
  for (int i = 1; i <= n; ++i)
    a[i] = lower_bound(v + 1, v + 1 + m, a[i]) - v;
  
  for (int i = 1; i <= n; ++i) Add(a[i], 1);
  for (int i = 1; i <= n; ++i) {
    if (i > 1) Add(a[i - 1], 1);
    Add(a[i], -1);
    int l = 1, r = m, res = 1;
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (Query(mid) >= n / 2) res = mid, r = mid - 1;
      else l = mid + 1;
    }
    printf("%d\n", v[res]);
  }

  return 0;
}
