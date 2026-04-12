#include<iostream>
using namespace std;

int main()
{	
  
 string s;
  cin>>s;
  int f1=0,f2=0;
  for(int i=0;i<3;i++)
  {
    if(s[i]=='A')
  		f1++;
    if(s[i]=='B')
      f2++;
  }  
  if(f1>0 && f2>0)
    cout<<"Yes";
  else
    cout<<"No";

 return 0; 
}