#include <bits/stdc++.h>
using namespace std;

int a[55][26];

int main()
{
  int n;
  cin >> n;
  for(int i=0;i<n;i++)
  {
    string s;
    cin >> s;
    for(int j=0;j<s.size();j++)
    {
      a[i][s[j]-'a']++;
    }
  }
  
  for(int j=0;j<26;j++)
  {
    int ret = 100;
    for(int i=0;i<n;i++)
    {
      ret = min(ret,a[i][j]);
    }
    for(int i=0;i<ret;i++)
    {
      printf("%c",'a'+j);
    }
  }
  cout << endl;
}
