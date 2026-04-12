#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  int N;
  int i;
  scanf("%d", &N);
  int a[200010], b[200010];
  for (i = 0; i < N; i++) {
    scanf("%d", &a[i]);
    b[i] = a[i];
  }
  sort(a, a+N);
  double med = ((a[N/2-1]+a[N/2])*1.0)/2;
  for (i = 0; i < N; i++) {
    if (b[i] >= med) {
      printf("%d\n", a[N/2-1]);
    } else {
      printf("%d\n", a[N/2]);
    }
  }
  return 0;
}
