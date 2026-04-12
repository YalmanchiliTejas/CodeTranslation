#include<bits/stdc++.h>
using namespace std;


int main()
{
  string s;
  int a=0,b=0;
  cin>>s;
  for(int i=0;i<s.size();i++){
    if(s[i]=='A')a=1;
    if(s[i]=='B')b=1;
  }
  if(a==1&&b==1) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}