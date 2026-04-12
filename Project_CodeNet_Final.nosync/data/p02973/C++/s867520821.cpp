#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll N;
multiset<ll> C;

int main() {
  cin >> N;
  for (ll i = 0; i < N; ++i) {
    ll a;
    cin >> a;
    auto it = C.lower_bound(a);
    if (it != C.begin()) C.erase(prev(it));
    C.insert(a);
  }
  cout << C.size() << endl;
  return 0;
}
