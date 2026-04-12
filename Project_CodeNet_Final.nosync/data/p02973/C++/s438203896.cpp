#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

bool comp(int x, int y)
{
  return x >= y;
}

int main()
{
  int n; cin >> n;
  vector<int> a(n);
  rep(i, n)
    cin >> a[i];
  vector<int> last;
  last.push_back(a[0]);
  for (int i=1; i<n; i++)
  {
    auto itr = lower_bound(last.begin(), last.end(), a[i], comp);
    if (itr == last.end())
      last.push_back(a[i]);
    else
      *itr = a[i];
  }
  cout << last.size() << endl;
}
