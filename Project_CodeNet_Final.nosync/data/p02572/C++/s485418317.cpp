#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = LONG_LONG_MAX / 2;
const ll mod = 1000000000 + 7;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main() {
  int N;
  cin >> N;
  vector<ll> v(N);
  vector<ll> sum(N, 0);
  for (int i = 0; i < N; i++) {
    cin >> v[i];
  }
  for (int i = 0; i < N - 1; i++) {
    sum[N - 2 - i] += sum[N - 1 - i] + v[N - 1 - i];
    sum[N - 2 - i] %= mod;
  }
  ll ans = 0;
  for (int i = 0; i < N; i++) {
    ans += v[i] * sum[i];
    ans %= mod;
  }
  cout << ans << endl;
}
