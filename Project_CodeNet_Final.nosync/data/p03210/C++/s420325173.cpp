#include <iostream>

using namespace std;
using ll = long long;
using ld = long double;

#define ALL(x) begin(x), end(x)
#define REP(i, n) for (size_t i = 0, i##_len = (n); i < i##_len; ++i)

const string YES = "YES";
const string NO = "NO";

void solve(ll X) {
  bool pred = X == 7 || X == 5 || X == 3;
  cout << (pred ? YES : NO) << endl;
}

int main() {
  ll X;
  cin >> X;
  solve(X);
  return 0;
}
