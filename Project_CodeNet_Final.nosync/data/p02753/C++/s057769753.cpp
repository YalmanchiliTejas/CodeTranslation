#include<bits/stdc++.h>
using namespace std;

int main()
{
  string s;
  cin >> s;
  
  char prev, curr;
  prev = s.at(0);
  
  for (int i = 1; i < 3; i ++)
  {
    curr = s.at(i);
    if (prev != curr)
    {
      cout << "Yes" << endl;
      return 0;
    }
    prev = curr;
  }
  
  cout << "No" << endl;
  return 0;
}
