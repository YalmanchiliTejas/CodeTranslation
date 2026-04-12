#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll p = 1e9 + 7;
const ll MAXK = 10009;
const ll MAXD = 109;

ll memo[MAXK][MAXD][2];

int main() {
  string K; cin >> K;
  int D; cin >> D;
  memset(memo, -1, sizeof(memo));
  function<ll(int, int, int)> dp = [&](int i, int rem, int tight) {
    if (i == K.size()) return ll(rem == 0);
    else if (memo[i][rem][tight] != -1) return memo[i][rem][tight];
    else {
      int upperbound = tight ? (K[i] - '0') : 9;
      ll ret = 0;
      for (int d = 0; d <= upperbound; d++) {
        ret = (ret + dp(i + 1, (rem + d) % D, tight && (d == upperbound))) % p;
      }
      return memo[i][rem][tight] = ret;
    }
  };
  cout << ((dp(0, 0, 1) - 1) % p + p) % p << endl;
  return 0;
}
