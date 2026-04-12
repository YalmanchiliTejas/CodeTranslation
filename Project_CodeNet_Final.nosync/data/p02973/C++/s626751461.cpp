#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;


int main()
{
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n)
  {
    cin >> a[i];
    a[i] = -a[i];
  }
  vector<int> ans;
  rep(i, n)
  {
    auto itr = upper_bound(ans.begin(), ans.end(), a[i]);
    if (itr == ans.end())
      ans.push_back(a[i]);
    else
      *itr = a[i];
  }
  cout << ans.size() << endl;
  return 0;
}