#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()

typedef long long ll;

const int N = 2e5;
ll a[N];
ll used[N];
ll sum[N];
ll pos[N];

void solve() {
  ll n, x, MOD; cin >> n >> x >> MOD;
  a[0] = x; used[x] = 1;
  ll period, periodsum;
  sum[0] = x;
  int pred = 0;
  for (int i = 1; ; i++) {
    ll v = (a[i - 1] * a[i - 1]) % MOD;
    if (used[v]) {
      pred = used[v] - 1;
      period = (i+1) - used[v];
      periodsum = sum[i - 1];
      if (pred != 0)
        periodsum -= sum[pred - 1];
      break;
    }
    a[i] = v; used[v] = i + 1;
    sum[i] = a[i] + sum[i - 1];
    //cout << i << " " << a[i] << " " << sum[i] << endl;
  }
  //cout << period << " " << periodsum << endl;
  if (n <= pred) {
    cout << sum[n - 1]; return;
  }
  ll res = ((n-pred) / period) * periodsum;
  if (pred != 0) res += sum[pred - 1];
  n -= pred;
  n %= period;
  n += pred;
  res += sum[n - 1];
  if (pred != 0) res -= sum[pred - 1];
  cout << res;
}

// CHECK LIMITS (n <= 10^5)
// CHECK CORNER CASES (n == 1)

int main() {
  ios::sync_with_stdio(NULL), cin.tie(0), cout.tie(0);
  cout.setf(ios::fixed), cout.precision(2);
  //cout << 1.0 * clock() / CLOCKS_PER_SEC << endl;
  solve();
}
