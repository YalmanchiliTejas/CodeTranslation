#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>
using namespace std;
typedef long long ll;
ll const INF = 1LL << 60;

int main() {
  ll N, K;
  cin >> N >> K;
  ll ans = 0;
  for (int b = 1; b <= N; b++) {
    ans += max(0LL, b - K) * (N / b) + max(0LL, N % b - K + 1);
  }
  if (K == 0) ans = N * N;
  cout << ans << endl;
  return 0;
}