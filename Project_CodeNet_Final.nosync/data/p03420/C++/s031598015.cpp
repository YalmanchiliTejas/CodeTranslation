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
    ll q = N / b, r = N % b;
    res += max(0ll, b - K) * q;
    res += max(0ll, r - K + 1);
  }
  if (K == 0) {
    res -= N;
  }
  cout << res << endl;
  return 0;
}
