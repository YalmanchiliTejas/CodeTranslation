#include <bits/stdc++.h>
using namespace std;
int main()
{
  string str;
  cin>>str;
  
  int cnt1=0,cnt2=0;
  
  for(int i=0;i<str.size();i++)
  {
    
    if(str[i]=='A')
      cnt1++;
    else
      cnt2++;
  }
  
  if(cnt1==3 || cnt2==3)
    cout<<"No"<<endl;
  else
    cout<<"Yes"<<endl;
}