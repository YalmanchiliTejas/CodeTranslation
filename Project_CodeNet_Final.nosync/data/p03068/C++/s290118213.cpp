#include <iostream>
#include <string>

using namespace std;

int main()
{
  int n;
  cin >> n;
  string s;
  cin >> s;
  int k;
  cin >> k;
  k--;
  for(int i=0; i<n; ++i)
   if (s[i]!=s[k]) cout << '*'; else cout << s[i];
  return 0;
}