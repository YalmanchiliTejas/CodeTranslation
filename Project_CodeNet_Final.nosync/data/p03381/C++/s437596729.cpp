#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int a[N], b[N];

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);   
    b[i] = a[i];
  }
  sort(a + 1, a + 1 + n);
  int pos = n / 2;
  for(int i = 1; i <= n; ++i) {
    if(b[i] > a[pos]) printf("%d\n", a[pos]);
    else printf("%d\n", a[pos + 1]);
  }
  return 0;
}