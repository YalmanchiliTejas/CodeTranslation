#include<bits/stdc++.h>
using namespace std;

int main()
{
  string s;
  cin >> s;
  int i;
  int ch = 0;
  for(i = 0; i < s.size()-1; i++)
  {
    if(s.at(i) == 'A' && s.at(i+1) == 'C')
    {
      ch = 1;
      break;
    }
  }
  if(ch == 1)
  {
    cout << "Yes" << endl;
  }
  else
  {
    cout << "No" << endl;
  }
}