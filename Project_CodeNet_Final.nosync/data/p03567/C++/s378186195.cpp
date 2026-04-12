#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s;
  cin >> s;
 bool f = false; 
for (int i = 1;i < s.length(); i++)
{
  if (s[i-1] == 'A' && s[i] == 'C')
    f = true;
}
  if (f)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}
