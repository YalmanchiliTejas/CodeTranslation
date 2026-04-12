#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
  string str;
  cin >> str;
  bool a=0,b=0;
  for(int i=0;i<3;i++)if(str[i]=='A')a=1;
  for(int i=0;i<3;i++)if(str[i]=='B')b=1;
  if(a and b)cout << "Yes";
  else cout << "No";
}