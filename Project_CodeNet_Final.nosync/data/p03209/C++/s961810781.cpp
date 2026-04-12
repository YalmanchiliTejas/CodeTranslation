#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

LL solve(long long N, long long X) {
  if (N == 0) {
    if (X <= 0)
      return 0;
    else
      return 1;
  }
  LL pan = 1;
  LL sum = 1;
  for (int i = 0; i < N - 1; i++) {
    pan = pan * 2 + 1;
    sum = sum * 2 + 3;
  }

  if (X <= sum + 1) {
    return solve(N - 1, X - 1);
  } else
    return pan + 1 + solve(N - 1, X - 2 - sum);
}

int main() {
  long long N;
  scanf("%lld", &N);
  long long X;
  scanf("%lld", &X);
  LL ans = solve(N, X);
  cout << ans << endl;
  return 0;
}
