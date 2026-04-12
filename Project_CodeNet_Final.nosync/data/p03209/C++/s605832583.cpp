#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a[51],p[51];

ll f(ll N, ll X) {
  if (N == 0 && X >= 1) {
    return 1;
  } else if (X <= 0) {
    return 0;
  } else if (X <= 1 + a[N - 1]) {
    return f(N - 1, X - 1);
  } else {
    return p[N - 1] + 1 + f(N - 1, X - 2 - a[N - 1]);
  }
}

int main() {
  ll n, x;
  cin >> n >> x;
  a[0] = 1;
  p[0] = 1;
  for (int i = 1; i <= 50; ++i) {
    a[i] = 2 * a[i - 1] + 3;
    p[i] = 2 * p[i - 1] + 1;
  }
  cout << f(n, x) << "\n";
  return 0;
}
//s=B+S+P+S+B