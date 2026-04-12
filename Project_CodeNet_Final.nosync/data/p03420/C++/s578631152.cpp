#include <algorithm>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <vector>
using namespace std;
using ll = long long;

int main() {
  ll N, K;
  cin >> N >> K;
  ll res = 0;
  for (ll b = 1; b <= N; b++) {
    // a < b
    res += max(0ll, b - max(K, 1ll));
    // a >= b
    if (K <= b - 1) {
      ll rem = (N - b + 1);
      res += rem / b * (b - 1 - K + 1);
      if (rem % b != 0 && K <= N % b) {
        res += N % b - K + 1;
      }
    }
  }
  cout << res << endl;
  return 0;
}
