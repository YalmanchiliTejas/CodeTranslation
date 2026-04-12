#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll N;
vector<ll> H;

void solve() {
  ll res = 1;
  for (int i = 1; i < N; i++) {
    ll tmp = H[i];
    bool check = true;
    for (int j = 0; j < i; j++) {
      if (H[j] > tmp) {
        check = false;
      }
    }
    if (check) {
      res++;
    }
  }
  cout << res << "\n";
  return;
}

int main() {
  cin >> N;
  H.resize(N);
  for (int i = 0; i < N; i++) {
    cin >> H[i];
  }
  solve();
  return 0;
}
