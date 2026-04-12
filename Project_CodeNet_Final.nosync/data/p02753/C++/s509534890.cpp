#include<bits/stdc++.h>
using namespace std;
int main()
{
  string s;
  cin >> s;
  int i,a=0,b=0;
  for(i=0;i<=2;i++)
  {
    if(s[i]=='A')a++;
    else b++;
  }
  if(a==3 || b==3)cout << "No\n";
  else cout << "Yes\n";
}
