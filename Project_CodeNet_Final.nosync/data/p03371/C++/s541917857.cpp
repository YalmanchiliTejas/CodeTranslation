#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define fin(x) cout << x << endl;

using namespace std;
using ll = long long;

int main(void) {
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  vector<ll> vec;
  rep(i, max(x, y) + 1) {
    ll val = 2 * c * i + max(0, x - i) * a + max(0, y - i) * b;
    vec.push_back(val);
  }
  vector<ll>::iterator iter = min_element(all(vec));
  cout << *iter << endl; 
  return 0;
}