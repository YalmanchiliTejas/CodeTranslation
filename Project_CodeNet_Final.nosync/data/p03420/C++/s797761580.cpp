#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

using ll = long long;

int main()
{
  ll n, k;
  cin >> n >> k;

  ll sum = 0;
  for (ll b = k + 1; b <= n; b++)
  {
	sum += (n / b) * (b - k) + max<ll>(0ll, n % b - k + 1);
  }
  if (k == 0)
  {
	sum -= n;
  }
  cout << sum << endl;
}
