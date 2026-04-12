#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
  ll n;
  cin >> n;
  vector<ll> vec(n);
  for (auto &v : vec)
    cin >> v;

  sort(vec.begin(), vec.end());

  ll ans = vec[n-1] - vec[0];
  ll a = 1;
  ll b = n - 2;
  while (a <= b) {
    if (a < b)
      ans += vec[b] - vec[a-1] + vec[b + 1] - vec[a];
    else
      ans += max(vec[a] - vec[a-1], vec[a+1] - vec[a]);
    ++a;
    --b;
  }

  cout << ans << endl;
}