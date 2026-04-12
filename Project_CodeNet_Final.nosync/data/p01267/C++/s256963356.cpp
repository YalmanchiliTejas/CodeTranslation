// Last Change: 06/25/2019 18:55:38.
#include <algorithm>
#include <array>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

namespace NS {
void LoopUntilZeroInpput() {
  int hogegegege = 0;
  while (cin >> hogegegege && hogegegege != 0) {
  }
}
} // namespace NS

ll N, A, B, C, X;

ll NextVal(ll x) {
  return (A * x + B) % C;
}

ll Solve() {
  ll ans = 0;
  vector<ll> Y(N);
  for (auto &&e : Y) {
    cin >> e;
  }

  for (ll i = 0; i < N; ++i) {
    while (X != Y[i]) {
      ++ans;
      X = NextVal(X);
      if (ans > 10000) {
        return -1;
      }
    }
    ++ans;
    X = NextVal(X);
  }
  return ans - 1;
}

int main() {
  while (cin >> N >> A >> B >> C >> X and N > 0) {
    cout << Solve() << endl;
  }
}

