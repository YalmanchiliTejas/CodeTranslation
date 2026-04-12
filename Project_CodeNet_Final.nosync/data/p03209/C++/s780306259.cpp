#include <iostream>
#include <cmath>

using namespace std;
typedef long long ll;
ll N, X;

ll dfs(ll n, ll x) {
  if (x == 0) {
    return 0;
  }

  if (n == 0) {
    return 1;
  }
  ll ret = 0;
  // left ban
  x--;
  // if we eat all left n-1 burger
  if (x >= pow(2, n + 1) - 3) {
    ret += pow(2, n) - 1;
    x -= pow(2, n + 1) - 3;
  } else {
    return dfs(n-1, x);
  }
  // middle patty
  if (x > 0) {
    ret++;
    x--;
  }
  // right n-1 burger
  return ret + dfs(n-1, x);
}

void solve() {
  cout << dfs(N, X) << endl;
}

int main() {
  cin >> N >> X;
  solve();
}
