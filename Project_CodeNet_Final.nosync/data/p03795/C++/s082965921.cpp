#include <bits/stdc++.h>
using namespace std;

int main()
{
  
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;
  long long ans = 800*n - (n/15)*200;
  cout << ans ;
  return 0;
}
