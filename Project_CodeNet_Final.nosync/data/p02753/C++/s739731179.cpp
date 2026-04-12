#include <bits/stdc++.h>
using namespace std;

int main()
{
  string s;
  cin >> s;
  bool found = false;
	if (s.find("AB") != string::npos)
  {
    found = true;
  }
  if (s.find("BA") != string::npos)
  {
    found = true;
  }
  cout << (found ? "Yes" : "No") << endl;
  return 0;
}
