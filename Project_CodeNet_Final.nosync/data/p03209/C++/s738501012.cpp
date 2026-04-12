#include <bits/stdc++.h>

using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)

using ll = long long;

ll ps[51];
ll hs[51];

ll h(int n) {
  if (n == 0) return (hs[0] = 1);
  return (hs[n] = (2 * h(n - 1) + 1) + 2);
}

ll p(int n) {
  if (n == 0) return (ps[0] = 1);
  return (ps[n] = (2 * p(n - 1) + 1));
}

void init() {
  h(50);
  p(50);
}

ll calc(int n, ll k) {
  if (n == 0) {
    if (k == 1) return 1;
    return 0;
  }
  if (hs[n] <= k) return ps[n];

  ll s = hs[n-1];
  if (k <= s + 1) {
    return calc(n - 1, k - 1);
  } else if (k == s + 2) {
    return ps[n-1] + 1;
  } else if (s + 2 < k) {
    return ps[n-1] + 1 + calc(n - 1, k - s - 2);
  } else {
    cout << k << ' ' << s << endl;
    assert(false); // bug?
  }
}

int main() {
  int N;
  ll K;

  init();
  cin >> N >> K;
  cout << calc(N,K) << endl;

  return 0;
}
