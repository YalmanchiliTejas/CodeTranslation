#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
const int INF = 100100100;
using namespace std;

int main()
{
  int X, Y, Z;
  int res=0;
  cin >> X>>Y>>Z;

  X-= Z;
  res += X/(Y + Z);

  cout << res << endl;
}
