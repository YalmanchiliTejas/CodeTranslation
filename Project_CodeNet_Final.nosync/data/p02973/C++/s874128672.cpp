#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdint>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <regex>
#include <set>
#include <sstream>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;
using ll = long long;

#define EPS (1e-7)

int main() {
  ll N;
  cin >> N;
  vector<ll> A(N);
  for (ll i = 0; i < N; i++) {
    cin >> A[i];
  }

  deque<ll> ans;
  ans.push_back(A[0]);
  for (ll i = 1; i < N; i++) {
    auto it = lower_bound(begin(ans), end(ans), A[i]);
    if (it == begin(ans)) {
      ans.push_front(A[i]);
    } else {
      auto pre = prev(it);
      *pre = A[i];
    }
  }

  cout << ans.size() << endl;
  return 0;
}
