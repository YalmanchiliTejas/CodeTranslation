#include <cstdio>
#include <deque>
#include <algorithm>

using namespace std;

int n;
int a[222222];

int main(void) {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", a+i);
  deque<int> b;
  for (int i = 0; i < n; i++) {
    if (i%2 == 0) {
      b.push_back(a[i]);
    } else {
      b.push_front(a[i]);
    }
  }
  if (n%2 != 0) reverse(b.begin(), b.end());
  for (int i = 0; i < n; i++) {
    printf("%d%c", b[i], i == n-1 ? '\n' : ' ');
  }
  return 0;
}
