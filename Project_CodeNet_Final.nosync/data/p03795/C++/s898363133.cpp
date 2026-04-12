#include <iostream>

using namespace std;
using ll = long long;
using ld = long double;

#define ALL(x) begin(x), end(x)
#define REP(i, n) for (size_t i = 0, i##_len = (n); i < i##_len; ++i)

void solve(ll N) { cout << N * 800 - (N / 15) * 200 << endl; }

int main() {
  ll N;
  cin >> N;
  solve(N);
  return 0;
}
