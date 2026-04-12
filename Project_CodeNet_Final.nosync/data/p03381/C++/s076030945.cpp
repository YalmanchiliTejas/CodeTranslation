#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 2147483647;

inline bool cmp(int a, int b) {
  return a > b;
}

const int maxn = 2e5 + 7;
int Data[maxn], a[maxn];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &Data[i]);
  memcpy(a + 1, Data + 1, sizeof(int) * n);
  sort(a + 1, a + n + 1, cmp);
  //for (int i = 1; i <= n; i++) cout << a[i] << endl;

  int mid = a[(n + 1) / 2];
  for (int i = 1; i <= n; i++) {
    //cout << mid << ' ' << n / 2 + 1 << ' ' << n / 2 << endl;
    if (Data[i] < mid) printf("%d\n", a[n / 2]);
    else if (Data[i] > mid) printf("%d\n", a[n / 2 + 1]);
    else {
      if (n / 2 == (n + 1) / 2) printf("%d\n", a[(n + 1) / 2 + 1]);
      else printf("%d\n", a[n / 2]);
    }
  }
  puts("");
  return 0;
}