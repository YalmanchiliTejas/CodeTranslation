#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll N;
deque<ll> B;
bool Normal = true;

int main() {
  cin >> N;
  for (ll i = 0; i < N; ++i) {
    ll a;
    cin >> a;
    if (Normal)
      B.push_back(a);
    else
      B.push_front(a);
    Normal = !Normal;
  }
  for (ll i = 0; i < N; ++i)
    cout << (i == 0 ? "" : " ") << B[Normal ? i : N - 1 - i];
  return 0;
}
