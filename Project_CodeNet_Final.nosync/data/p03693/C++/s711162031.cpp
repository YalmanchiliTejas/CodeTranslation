#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;

int main()
{
  int r, g, b;
  cin >> r >> g >> b;
  
  int sum;
  sum = 100 * r + 10 * g + b;

  if (0 == sum % 4)
  {
    cout << "YES" << endl;
  }
  else
  {
    cout << "NO" << endl;
  }
    
  return 0;
}