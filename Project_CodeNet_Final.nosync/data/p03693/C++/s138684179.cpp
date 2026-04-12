#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main() 
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  string r, b, g;
  cin >>r >> b >> g;

  string a = b + g;
  
  int x = stoi(a);
  
  if (x % 4 == 0)
  {
     cout << "YES" << endl;
  }
  else cout << "NO" << endl;

  return 0;
}

