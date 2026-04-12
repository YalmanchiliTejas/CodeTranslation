#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef long long ll;

int main()
{
  int n;
  int h[100];
  cin >> n;
  rep(i, n)
  {
    cin >> h[i];
  }
  int max = h[0];
  int ans = 1;
  for (int j = 1; j < n; j++)
  {
    if (h[j] >= max)
    {
      max = h[j];
      ans++;
    }
  }
  cout << ans << endl;
}