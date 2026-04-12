#include "iostream"
#include "vector"

using namespace std;
typedef long long ll;

ll sum(int n, ll x)
{
  vector<ll> power_2(55);
  power_2[0] = 1;
  for (int i = 1; i < 55; i++)
  {
    power_2[i] = 2 * power_2[i - 1];
  }
  if (n == 0)
  {
    return x;
  }
  else
  {
    if (x == 0)
    {
      return 0;
    }
    else
    if (x < power_2[n + 1] - 1)
    {
      return sum(n - 1, x - 1);
    }
    else
    {
      return power_2[n + 1] - 1 - sum(n, power_2[n + 2] - 3 - x);
    }
  }
}

int main()
{
  int n;
  cin >> n;
  ll x;
  cin >> x;
  cout << sum(n, x) << endl;
}