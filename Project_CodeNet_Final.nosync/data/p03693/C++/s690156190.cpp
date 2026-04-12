#include <iostream>

using namespace std;
using ll = long long;
using ld = long double;

#define ALL(x) begin(x), end(x)
#define REP(i, n) for (size_t i = 0, i##_len = (n); i < i##_len; ++i)

const string YES = "YES";
const string NO = "NO";

void solve(ll r, ll g, ll b) {
  bool pred = (100*r+10*g+b) % 4 == 0;
  cout << (pred ? YES : NO) << endl;
}

int main() {
  ll r;
  cin >> r;
  ll g;
  cin >> g;
  ll b;
  cin >> b;
  solve(r, g, b);
  return 0;
}
