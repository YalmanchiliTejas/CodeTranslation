#include <iostream>

using namespace std;

int main()
{
  int n;
  cin >> n;
  int maxx=0;
  int ans=0;
  for(int i=0 ;i<n; ++i)
  {
    int k;
    cin >> k;
    if (k>maxx)
    {
      ans++;
      maxx=k;
    } else
    if (k==maxx)
    {
      ans++;
    }
  }
  cout << ans;
  return 0;
}