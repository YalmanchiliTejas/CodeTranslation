#include<bits/stdc++.h>
using namespace std;

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);

  string s;
  cin >> s;

  int a = 0,b = 0;

  if(s[0] == 'A')
  {
    a++;
  } 
  else
  {
    b++;
  }

  if(s[1] == 'A')
  {
    a++;
  } 
  else
  {
    b++;
  }

  if(s[2] == 'A')
  {
    a++;
  } 
  else
  {
    b++;
  }

  if(a && b)
  {
    cout << "Yes" << '\n';
  }
  else
  {
    cout << "No" << '\n';
  }

  return 0;
}
