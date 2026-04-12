#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  int n, t = 1, max;
  cin >> n;
  vector<int> v(n);

  for (int i = 0; i < n; ++i)
    cin >> v[i];

  max = v[0];
  for (int i = 1; i < n; ++i)
  {
    if (v[i] >= max)
      t++;

    if (v[i] > max)
      max = v[i];
  }

  cout << t << "\n";
  return 0;
}