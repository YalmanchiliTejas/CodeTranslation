#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
  int n,t,i,j;
  string s;
  int c[26],m[26];
  cin >> n;
  fill(m,m+26,50);
  for(i=0;i<n;i++){
    cin >> s;
    fill(c,c+26,0);
    for(j=0;j<s.size();j++)
      c[(int)(s[j]-'a')]++;
    for(j=0;j<26;j++)
      m[j]=min(m[j],c[j]);
  }
  for(i=0;i<26;i++)
    for(j=0;j<m[i];j++)
      cout << (char)('a'+i);
  cout << endl;
  return 0;
}