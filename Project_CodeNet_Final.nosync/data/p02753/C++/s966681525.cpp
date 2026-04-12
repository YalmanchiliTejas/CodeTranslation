#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin>>s;
  int i=0,c=0,d=0;
  while(s[i]!='\0'){
    if(s[i]=='A')
      c++;
    else
      d++;
    i++;
  }
  if(c!=0 && d!=0)
    cout<<"Yes";
  else
    cout<<"No";
}
