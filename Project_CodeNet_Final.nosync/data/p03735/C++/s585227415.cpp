#include <cstdio>
#include <set>
#include <numeric>
#include <algorithm>

typedef long long i64;

const int N = 200000 + 10;

int n, x[N], y[N];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d%d", &x[i], &y[i]);
  for (int i = 1; i <= n; ++i) if (x[i] > y[i]) std::swap(x[i], y[i]);
  std::multiset<int> a(x + 1, x + n + 1), b(y + 1, y + n + 1);
  static int id[N];
  std::iota(id, id + n + 1, 0);
  std::sort(id + 1, id + n + 1, [&] (int u, int v) { return y[u] < y[v]; });
  auto f = [&] { return ((i64)*a.rbegin() - *a.begin()) * (*b.rbegin() - *b.begin()); };
  i64 ans = f();
  for (int i = n; i > 0; --i) {
    int z = id[i];
    a.erase(a.find(x[z]));
    b.erase(b.find(y[z]));
    std::swap(x[z], y[z]);
    a.insert(x[z]);
    b.insert(y[z]);
    ans = std::min(ans, f());
  }
  printf("%lld\n", ans);
  return 0;
}
