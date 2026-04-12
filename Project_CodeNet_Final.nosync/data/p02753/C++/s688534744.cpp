#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin>>s;
  int j=0;
  for(int i=0;i<3;i++)
    if(s[i]=='A')
      j++;
  if(j==1||j==2)
    cout<<"Yes"<<endl;
  else
    cout<<"No"<<endl;
  return 0;
}