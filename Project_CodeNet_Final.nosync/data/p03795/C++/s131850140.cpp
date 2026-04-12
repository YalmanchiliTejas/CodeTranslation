#include <bits/stdc++.h>

using namespace std;

int main()
{
  int a;
  cin >> a ;
  if (a >= 15)
    cout << (800*a)- ((a/15)*200) << endl;
  else
    cout << 800*a << endl;
return 0;

}