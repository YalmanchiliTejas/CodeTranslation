#include<bits/stdc++.h>
using namespace std;

int main()
{
  string S;
  cin>>S;
  int x=0, y=0;
  for(int i=0; i<3; i++)
  {
    if(S[i]=='A')
      x++;
    else
      y++;
  }
  if(x==3||y==3)
    cout<<"No";
  else
    cout<<"Yes";
  return 0;
}