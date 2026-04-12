#include <bits/stdc++.h>
using namespace std;

int n, a[100100];
vector<int> f[100100];

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];

  long long ans = 0;
  for (int i = 1; i < n - 1; i++)
  {
    long long score = 0;
    for (int j = 1; i * j < n - 1 && n - 1 - i * j > i; j++)
    {
      score += a[i * j] + a[n - 1 - i * j];
      if ((n - 1) % i == 0 && (n - 1) / i <= j * 2)
        break;
      ans = max(ans, score);
    }
  }

  cout << ans << endl;
}
