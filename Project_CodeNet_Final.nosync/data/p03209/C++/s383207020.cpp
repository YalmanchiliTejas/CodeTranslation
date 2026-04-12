#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

void solve(long long N, long long X) {
  LL remain = X;
  if (N == 0 && X == 1) {
    cout << 1 << endl;
    return;
  }
  LL level = N - 1;
  LL ans = 0;
  for (; level >= 0; level--) {
    bool dec = true;
    LL sum = 1;
    LL pan = 1;
    for (int i = 0; i < level; i++) {
      sum = sum * 2 + 3;
      pan = pan * 2 + 1;
    }
    if (remain >= 2 * sum + 2) {
      cout << ans + pan * 2 + 1 << endl;
      return;
    }
    dec = (remain <= sum + 1);

    if (dec) {
      remain--;
      if (level == 0 && remain == 1) {
        ans += 1;
      }
    } else {
      remain -= sum + 2;
      ans += pan + 1;
    }
  }
  cout << ans << endl;
}

int main() {
  long long N;
  scanf("%lld", &N);
  long long X;
  scanf("%lld", &X);
  solve(N, X);
  return 0;
}
