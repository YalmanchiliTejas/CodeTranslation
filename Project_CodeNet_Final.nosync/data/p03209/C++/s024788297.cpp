#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

ll rec(ll n, ll x) {
  ll all = (1LL << n + 1) - 3;
  ll p = (1LL << n) - 1;
  if (x == 0)
    return 0;
  else if (x <= all + 1)
    return rec(n - 1, x - 1);
  else if (x <= all + 2)
    return p + 1;
  else if (x <= 2 * (all + 1))
    return p + 1 + rec(n - 1, x - all - 2);
  else
    return p * 2 + 1;
}

int main() {
  ll n, x;
  cin >> n >> x;

  cout << rec(n, x) << endl;
  return 0;
}