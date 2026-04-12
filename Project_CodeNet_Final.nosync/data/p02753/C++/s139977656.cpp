#include <iostream>
#include <string>
using namespace std;

int main(){
  string str;
  cin>>str;
  int a=0,b=0;
  for(int i=0;i<3;i++){
    if(str[i]=='A'){ a++;}
    if(str[i]=='B'){ b++;}
  }
  
  if(a>0&&b>0){
    cout<<"Yes"<<endl;
  }else{
    cout<<"No"<<endl;
  }
  
  return 0;
}