#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using P = pair<int, int>;

const int INF = 1e9;
const ll MOD = 1e9 + 7;

// 4近傍、8近傍
int dx[] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};

int main() {
  int N;
  cin >> N;
  ll a[N];
  for (int i = 0; i < N; i++) cin >> a[i];

  ll sum = 0;
  for (int i = 0; i < N; i++) sum += a[i];
  ll ans = 0;
  for (int i = 0; i < N - 1; i++) {
    sum -= a[i];
    ans += (a[i] % MOD) * (sum % MOD) % MOD;
    ans %= MOD;
  }

  cout << ans << endl;
  return 0;
}
