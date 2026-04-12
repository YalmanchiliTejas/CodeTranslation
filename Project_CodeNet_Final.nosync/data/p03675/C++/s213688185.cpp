#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  list<ll> B;
  for (ll i = 0; i < n; ++i) {
    ll ai;
    cin >> ai;
    if ((n % 2 == 0 && i % 2 == 0) || (n % 2 == 1 && i % 2 == 1)) {
      B.push_back(ai);
    } else {
      B.push_front(ai);
    }
  }
  for (auto itr = B.begin(); itr != B.end(); itr++) {
        std::cout << *itr << std::endl;
    }
}
