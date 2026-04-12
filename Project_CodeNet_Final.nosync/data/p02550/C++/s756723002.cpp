// -----------------------------------
// author   : MatsuTaku
// country  : Japan
// created  : 09/19/20 20:59:59
// -----------------------------------

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);

  ll n; int x,m; cin>>n>>x>>m;
  vector<ll> A={x};
  A.reserve(m);
  int s = 0;
  {
    vector<int> used(m, -1);
    used[x] = 0;
    while (true) {
      ll a = A.back()*A.back()%m;
      if (used[a] == -1) {
        used[a] = A.size();
        A.push_back(a);
      } else {
        s = used[a];
        break;
      }
    }
  }
  int f = A.size();
  for (int i = 1; i < s; i++) {
    A[i] += A[i-1];
  }
  for (int i = s+1; i < f; i++) {
    A[i] += A[i-1];
  }
  ll ans = 0;
  if (s > 0)
    ans += A[min((ll)s-1, n-1)];
  if (n > s) {
    ll l = n-s;
    ll k = f-s;
    ll c = l/k;
    ll d = l%k;
    ans += c * A[f-1] + (d > 0 ? A[s+d-1] : 0);
  }
  cout << ans << endl;

  return 0;
}
