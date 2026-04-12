#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
  long long n;

  cin >> n;

  vector<long long> a(n);

  long long sum = 0;

  long long MOD = 1000000007;
  long long ans = 0;

  rep(i, n)
  {
    cin >> a.at(i);
    ans += a.at(i);
    ans %= MOD;
  }
  // cout << ans << endl;

  for (int i = 0; i < n; i++)
  {
    ans -= a.at(i);
    if (ans < 0)
      ans += MOD;
    sum += (a.at(i) * ans);
    sum %= MOD;
  }

  cout << sum;
}
