#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const int mod = 1000000007;

int main() {
  ll n;
  cin >> n;
  vector<ll> a(n);

  rep(i, n) cin >> a[i];

  deque<ll> dq;
  rep(i, n) {
    ll idx = lower_bound(dq.begin(), dq.end(), a[i]) - dq.begin();
    if (idx == 0)
      dq.push_front(a[i]);
    else
      dq[idx - 1] = a[i];
  }
  cout << dq.size() << endl;
  return 0;
}