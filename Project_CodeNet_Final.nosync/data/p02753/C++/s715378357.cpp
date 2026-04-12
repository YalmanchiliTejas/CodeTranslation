#include<bits/stdc++.h>
using namespace std;
int main()
{
  char str[3];
  cin>>str;
  if((str[0]=='A' && str[1]=='A' && str[2]=='A')||(str[0]=='B' && str[1]=='B' && str[2]=='B'))
    cout<<"No"<<endl;
  else
    cout<<"Yes"<<endl;
}