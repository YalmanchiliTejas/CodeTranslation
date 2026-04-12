#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
ll a[50];

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(10);
  
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }
  ll ans = 0;
  for (int i = 0; i < 10000; i++) {
    ll s = 0;
    for (int j = 0; j < N; j++) {
      s += a[j] / N;
    }
    if (s == 0) break;
    for (int j = 0; j < N; j++) {
      ll k = a[j] / N;
      a[j] = a[j] - k * N + (s - k);
    }
    ans += s;
  }
  cout << ans << endl;

  return 0;
}