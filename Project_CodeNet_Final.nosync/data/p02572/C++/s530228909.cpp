#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
ll INF = 1000000007;

int main() {
  ll n;
  cin >> n;
  vector<ll> a(n+1);
  ll vec_sum = 0;
  for(int i = 1;i <= n;i++) {
    cin >> a[i];
    vec_sum += a[i];
  }
  ll ans = 0;
  for(int i = 1;i <= n;i++) {
    vec_sum -= a[i];
    ans += a[i] * (vec_sum % INF);
    ans %= INF;
  }
  cout << ans << endl;
}