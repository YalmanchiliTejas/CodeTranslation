#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
  int n,y,z;
  cin >> n >> y >> z;
  
  n -= z;
  int ans = n / (y+z);
  
  cout << ans << endl;
  
  
}