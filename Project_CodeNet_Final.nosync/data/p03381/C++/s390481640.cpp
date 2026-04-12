#include <bits/stdc++.h>
using namespace std;

int N;
int as[214514];
int bs[214514];

int main() {
  scanf("%d", &N);
  for (int i=0; i<N; i++) {
    scanf("%d", &as[i]);
    bs[i] = as[i];
  }
  sort(as, as+N);
  int l = as[N/2-1];
  int r = as[N/2];

  for (int i=0; i<N; i++) {
    if (bs[i] <= l) printf("%d\n", r);
    else printf("%d\n", l);
  }
}
