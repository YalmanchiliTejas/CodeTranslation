#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define BR "\n"
#define SP " "

int main() {
  ll N, A;
  cin >> N;

  vector<ll> V;
  cin >> A;
  V.push_back(A);

  for (int i = 1; i < N; i++) {
    cin >> A;
    auto l = lower_bound(V.begin(), V.end(), A);

    if (l != V.begin()) {
      V.erase(l - 1);
    }
    
    auto u = upper_bound(V.begin(), V.end(), A);
    V.insert(u, A);
  }
  cout << V.size() << BR;

  return 0;
}