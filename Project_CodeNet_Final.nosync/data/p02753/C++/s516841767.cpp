#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  int n,m;
  
  cin>>s;
  n=-1;
  m=-1;
  
  for(int i=0;i<3;i++)
  {
    if(s.at(i)=='A')
      m=1;
    else
      n=1;
  }
  if(n*m==1)
    cout<<"Yes"<<endl;
  else
    cout<<"No"<<endl;

}