#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <iomanip>
#include <set>
#include <sstream>
#include <queue>
using namespace std;
typedef long long ll;

const int mod = 1'000'000'007;

int main() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int ans = 0;
  int x = 0;

  // for (int i = 0; i < n; i++) {
  //   ans += a[i] * x;
  //   x += a[i];
  // }

  for (int i = 0; i < n; i++) {
    ans = (ans + (ll)a[i] * x) % mod;
    x = (x + a[i]) % mod;
  }
  cout << ans << endl;
  return 0;
}