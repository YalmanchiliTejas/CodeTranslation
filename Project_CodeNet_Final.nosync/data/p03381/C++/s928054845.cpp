#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,a[200010],b[200010];
  scanf("%d", &n);
  for (int i=0;i<n;++i) {
    scanf("%d", a+i);
    b[i] = a[i];
  }
  sort(a, a+n);
  for (int i=0;i<n;++i) {
    if (b[i]<a[n/2]) printf("%d\n", a[n/2]);
    else printf("%d\n", a[n/2-1]);
  }
  return 0;
}