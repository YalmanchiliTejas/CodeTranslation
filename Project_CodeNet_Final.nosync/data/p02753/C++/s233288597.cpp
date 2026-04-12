#include <iostream>
#include <string>

using namespace std;

string solve(string s)
{
  for(int i = 0; i < s.size()-1; i++)
    if(s[i] != s[i+1])
      return "Yes";
  return "No";
}


int main()
{
  string s;
  cin >> s;
  cout << solve(s) << endl;
  return 0;
}