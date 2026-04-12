#include <cstdio>
#include <utility>
#include <algorithm>

using namespace std;

const int N = 200'009;

pair<int, int> a[N];
int ans[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i].first);
    a[i].second = i;
  }
  sort(a, a + n);
  for (int i = 0; i < n; ++i) {
    if (i >= n / 2) {
      ans[a[i].second] = a[n / 2 - 1].first;
    } else {
      ans[a[i].second] = a[n / 2].first;
    }
  }
  for (int i = 0; i < n; ++i) {
    printf("%d\n", ans[i]);
  }
}
