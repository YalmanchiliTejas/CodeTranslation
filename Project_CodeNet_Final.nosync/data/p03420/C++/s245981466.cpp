#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#include <bitset>
#define MOD (1000000007l)
#define rep(i, n) for(long i = 0; i < (n); i++)

using namespace std;

void solve() {
  long N, K;
  cin >> N >> K;
  long ans = 0;
  for (long b = 1; b <= N; b++) {
    long foo = N / b;
    // 3 で割ると 0, 1, 2
    ans += max(b - K, 0l) * foo;

    long bar = N % b;
    // 100 % 3 は 1
    ans += max(bar - K + 1, 0l);
  }
  // 0が含まれてるので調整する
  if (K == 0) ans -= N;
  cout << ans << endl;
}

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout.precision(12);
  solve();
  return 0;
}
