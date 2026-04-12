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
ll const MOD = 1000000007;

int main() {
  ll N;
  cin >> N;
  vector<ll> A(N), accum(N, 0);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    if (i == 0)
      accum[0] = A[0];
    else
      accum[i] = accum[i - 1] + A[i];
  }
  ll ans = 0;
  for (int i = 0; i < N; i++) {
    ll suma = A[i] * ((accum[N - 1] - accum[i]) % MOD);
    suma %= MOD;
    ans = (ans + suma) % MOD;
  }
  cout << ans << endl;
  return 0;
}