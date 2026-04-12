#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n, x, m;
  cin >> n >> x >> m;
  vector <ll> a(1, x);
  if (n < 1e6) {
    ll ans = x;
    while (--n) {
      x = x * x % m;
      ans += x;
    }
    cout << ans;
    return 0;
  }
  vector <int> last(m, -1);
  for (int i = 0; i < 2 * m; i++)
    a.push_back(a.back() * a.back() % m);
  for (int i = 0; i < a.size(); i++) {
    if (last[a[i]] == -1)
      last[a[i]] = i;
    else {
      ll ans = 0;
      int left = last[a[i]];
      int right = i;
      for (int i = 0; i < left; i++)
        ans += a[i];
      n -= left;
      vector <ll> sumpre(right - left);
      for (int i = 0; i < right - left; i++)
        sumpre[i] = (i ? sumpre[i - 1] : 0) + a[i + left];
      ll cel = n / (right - left), r = n % (right - left);
      ans += cel * sumpre[right - left - 1] + (r ? sumpre[r - 1] : 0);
      cout << ans;
      return 0;
    }
  }
  return 0;
}
