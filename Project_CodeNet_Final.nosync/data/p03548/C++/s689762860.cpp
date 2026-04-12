#include <iostream>

using namespace std;
using ll = long long;
using ld = long double;

#define ALL(x) begin(x), end(x)
#define REP(i, n) for (size_t i = 0, i##_len = (n); i < i##_len; ++i)

void solve(ll X, ll Y, ll Z) {
  cout << (X-Z)/(Y+Z) << endl;
}

int main() {
  ll X;
  cin >> X;
  ll Y;
  cin >> Y;
  ll Z;
  cin >> Z;
  solve(X, Y, Z);
  return 0;
}
