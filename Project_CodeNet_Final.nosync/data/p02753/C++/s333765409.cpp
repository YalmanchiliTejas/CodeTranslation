#include<bits/stdc++.h>
using namespace std;
int main()
{
  string s;
  int countA=0,countB=0;
  cin>>s;
  for(int i=0;i<3;i++)
  {
    if(s[i]=='A')
      countA++;
    else countB++;
  }
  if(countA==2||countB==2)
    cout<<"Yes";
    else cout<<"No";
  return 0;
}