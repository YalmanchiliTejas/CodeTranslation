#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define FOR(i, n) for (int i = 0; i < n; i++)
ll ans = 0;
vector<ll> height(51);
vector<ll> p(51);
void bi_search(ll pos, ll level) {  // pos is 1-index
  //cerr << "pos:" << pos << "\tlevel:" << level << "\tans:" << ans << endl;
  if (level == 1) {
    ans += (pos > 1) + (pos > 2) + (pos > 3);
    return;
  }

  if (pos >= height[level - 1] + 2) ans++;
  if (pos >= height[level - 1] + 1) ans += p[level - 1];
  if (pos == height[level - 1] + 1 || pos == height[level - 1] + 2) {
    return;
  }

  if (pos > height[level - 1] + 2) {
    bi_search(pos - height[level - 1] - 2, level - 1);
  } else if (pos < height[level - 1] + 1)
    bi_search(pos - 1, level - 1);
}

int main() {
  ll n, x;
  cin >> n >> x;
  // ll a,b,c;
  // string s;
  FOR(i, n + 1) {
    height[i] = i ? 3 + 2 * height[i - 1] : 1;
    p[i] = i ? 1 + p[i - 1] * 2 : 1;
   // cerr << "height[" << i << "]:" << height[i];
   // cerr << "\tp[" << i << "]:" << p[i];
   // cerr << endl;
  }
  bi_search(x, n);
  //  cout << ((  )? "YES" : "NO) <<endl;
  //  cout << ((  )? "Yes" : "No) <<endl;
  cout << ans << endl;
  return 0;
}
