#include<iostream>
using namespace std;
 
int main()
{
  string s;
  bool result = true;
  
  cin >> s;
  for (char st : s)
      if (st != s[0]) { result = false; break; }
      
  if (result) cout << "No" << endl;
  else cout << "Yes" << endl;
 
  return 0;
}