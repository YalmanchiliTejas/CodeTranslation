#include <bits/stdc++.h>

using namespace std;

int main()
{
  int a, b, somma=0;
  char s[3];

  for(int c=0; c<3; c++)
    cin>>s[c];

  if(s[0] == s[1] && s[1]==s[2])
    cout<<"No";
  else
    cout<<"Yes";
}
