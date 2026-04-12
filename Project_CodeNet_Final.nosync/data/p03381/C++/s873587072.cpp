#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<ll, ll> P;
ll Mod = 1000000007;
int main() {
  int N;
  cin >> N;
  vector<P> X(N);
  vector<ll> ans(N);
  for (ll i = 0; i < N; i++) {
    ll x;
    cin >> x;
    X[i].first = x;
    X[i].second = i;
  }
  sort(X.begin(),X.end());
  for (int i = 0; i < N; i++) {
    if (i < N / 2) {
      ans[X[i].second] = X[N/2].first;
    } else {
      ans[X[i].second] = X[N/2 - 1].first;
    }
  }
  for (int i = 0; i < N; i++) {
    cout << ans[i] << endl;
  }
  return 0;
}