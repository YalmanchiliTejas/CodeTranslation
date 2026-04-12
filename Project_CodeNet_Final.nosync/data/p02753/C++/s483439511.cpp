#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin>>s;
  int x=0,y=0;
  for(int i=0;i<s.size();i++){
    if(s.at(i)=='A'){
      x+=1;}
   else{y+=1;}
  }
  if(x==0||y==0){
    cout<<"No"<<endl;}
  else{cout<<"Yes"<<endl;}
}