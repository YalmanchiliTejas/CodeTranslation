#include<cstdio>
#include<algorithm>
using namespace std;

int main() {
  int n;
  while (1) {
    scanf("%d", &n);
    if (n == 0) break;
    int k;
    int maxn = -1;
    int minn = 1000000;
    int sum = 0;
    for (int i = 0; i < n; i++) {
      scanf("%d", &k);
      maxn = max(maxn, k);
      minn = min(minn, k);
      sum += k;
    }
    printf("%d\n", (sum - maxn - minn) / (n - 2));
  }
}

