#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<int> h(n);
  for(auto& i : h) cin >> i;
  int ans = 1;
  for(int i = 1; i < n; ++i)
  {
    int res = 0;
    for(int k = 0; k < i; ++k)
    {
      if(h[i] < h[k])
      {
        res = -1;
        break;
      }
    }
    if(res != -1) ++ans;
  }
  cout << ans << endl;
}