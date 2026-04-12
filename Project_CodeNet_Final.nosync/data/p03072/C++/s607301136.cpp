#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
  int n;

  cin >> n;

  vector<int> h(n);

  int ans = 1;

  rep(i, n)
  {
    cin >> h.at(i);
  }

  int max_h = h.at(0);

  for (int i = 1; i < n; i++)
  {
    max_h = max(max_h, h.at(i));

    // cout << max_h << endl;

    if (max_h == h.at(i))
    {
      ans += 1;
    }
  }

  cout << ans;
}
