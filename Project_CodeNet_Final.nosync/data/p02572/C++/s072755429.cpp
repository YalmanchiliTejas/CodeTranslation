#include <iostream>
#include <vector>
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define P pair<int, int>;
using namespace std;

const int mod = 100'0000'007;
int main(void)
{
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  int x = 0;
  int ans = 0;
  rep(i, n)
  {
    ans = (ans + (ll)a[i] * x) % mod;
    x = (a[i] + x) % mod;
  }

  cout << ans << endl;
  return 0;
}
