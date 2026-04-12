#include <bits/stdc++.h>
using namespace std;

int main() 
{ 
    
        int f=0;
      string s;
      cin>>s;
      for(int i=0;i<4;i++)
      {
      if(s[0]=='B' && s[1]=='B' && s[2]=='B')
      {
        f=1;
      }
      else if(s[0]=='A' && s[1]=='A' && s[2]=='A')
      {
        f=1;
      }
    }
  if(f==1)
  {
    cout<<"No"<<endl;
  }
  else
  {
    cout<<"Yes"<<endl;
  }
     
    
}