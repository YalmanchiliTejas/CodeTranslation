#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin>>s;
  int f=0,fl=0;
  for(int i=0;i<3;i++){
    if(s[i]=='A'){
      f=1;}
    else{
      if(s[i]=='B')
        fl=1;
    }
  }
  if(f==1&&fl==1)
    cout<<"Yes"<<endl;
  else
    cout<<"No"<<endl;
}
  