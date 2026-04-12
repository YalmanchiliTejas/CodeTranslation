#include <iostream>

using namespace std;
using ll = long long;
using ld = long double;

#define ALL(x) begin(x), end(x)
#define REP(i, n) for (size_t i = 0, i##_len = (n); i < i##_len; ++i)

const string YES = "Yes";
const string NO = "No";

void solve(ll N, ll M) {
  ;
  bool pred = N == M;
  cout << (pred ? YES : NO) << endl;
}

int main() {
  ll N;
  cin >> N;
  ll M;
  cin >> M;
  solve(N, M);
  return 0;
}
