#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n,k;
 string s;
  cin >> n >> s >> k;
  
	char c = s[k-1];
  
  for (int i = 0;i < s.length(); i++)
  {
  	if (s[i] != c)
		s[i] = '*';
  }
  cout << s << endl;
}