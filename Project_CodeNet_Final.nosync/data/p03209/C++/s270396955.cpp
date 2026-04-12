#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

ll rec(int n, ll x) {
  if (n == 0) return 1;
  ll barg = (1LL << (n + 1)) - 3;
  ll Patty = (1LL << n) - 1;
  if (x == 1)
    return 0;
  else if (x <= barg + 1)
    return rec(n - 1, x - 1);
  else if (x == barg + 2)
    return Patty + 1;
  else if (x <= (barg + 1) * 2)
    return Patty + 1 + rec(n - 1, x - barg - 2);
  else
    return Patty * 2 + 1;
}

int main() {
  int n;
  ll x;
  cin >> n >> x;
  cout << rec(n, x) << endl;
}