#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n, k, m;
  cin >> n;
  int cnt = 1;
  cin >> m;
  for(int i = 0; i < n-1; ++i)
  {
    cin >> k;
  	if( m <= k)
    {
      cnt++;
      m = k;
    } 
  }
  cout << cnt ;
}