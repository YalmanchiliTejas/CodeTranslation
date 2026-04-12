#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
  for(int tci = 0; ; ++tci) {
    int n; scanf("%d", &n);
    if(n==0) break;
    int m0v=0, m1v=1000, sum=0;
    for(int i = 0; i < n; ++i) {
      int x; scanf("%d", &x);
      sum += x;
      m0v = max(m0v, x);
      m1v = min(m1v, x);
    }
    printf("%d\n", (sum-m0v-m1v)/(n-2));
  }
  return 0;
}