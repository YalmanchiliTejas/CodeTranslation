#include<iostream>
using namespace std;
int main(){
  string s;
  cin>>s;
  int cnta=0,cntb=0;
  for(int i=0;i<3;i++){
    if(s[i]=='A')	cnta++;
    else	cntb++;
  }
  if(cnta==3 || cntb==3)cout<<"No"<<endl;
  else	cout<<"Yes"<<endl;
  return 0;}