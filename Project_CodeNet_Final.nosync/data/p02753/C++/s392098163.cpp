#include<bits/stdc++.h>
using namespace std;

int main()
{
  string s;
  cin >> s;
  int a = (s[0] == 'A') + (s[1] == 'A') + (s[2] == 'A');
  if(a > 0 and a < 3)
           cout << "Yes\n";
   else
           cout << "No\n";

  return 0;
}