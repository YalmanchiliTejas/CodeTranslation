#include <iostream>
#include <algorithm>

using namespace std;

#define rep(i,n) for(int i=0;i<(n);++i)
#define in(v) if (scanf("%d", &v)<1);
#define out(v) printf("%d\n", v)

int main() {
  int N; in(N);

  int X[N], sorted[N];
  rep(i, N) {
    in(X[i]);
    sorted[i] = X[i];
  }
  sort(sorted, sorted+N);
  int center_l = sorted[(N-1)/2], center_r = sorted[N/2];
  rep(i, N) {
    int index = lower_bound(sorted, sorted+N, X[i]) - sorted;
    out(index < N/2 ? center_r : center_l);
  }

  return 0;
}
