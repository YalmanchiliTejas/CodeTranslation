#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll const INF = 1e10;

int main() {
  ll N; cin >> N;
  ll a[N];
  for (ll i = 0; i < N; i++) {
    cin >> a[i];
  }
  ll b[N];
  fill(b, b+N, INF);
  for (ll i = 0; i < N; i++) {
    *upper_bound(b, b+N, a[N-1-i]) = a[N-1-i];
  }
  ll res = 0;
  for (ll i = 0; i < N; i++) {
    if (b[i] != INF) {res++;}
  }
  cout << res << endl;
}
  