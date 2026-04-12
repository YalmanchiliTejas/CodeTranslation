#include <iostream>
#include <array>
#include <algorithm>

using ll = long long;
using namespace std;

int main() {
  ll N;
  cin >> N;
  ll ret = 0, mx = 0, h;
  for (ll i = 0; i < N; i++) {
    cin >> h;
    if (h >= mx) ret++;
    mx = max(mx, h);
  }
  cout << ret << endl;
}
