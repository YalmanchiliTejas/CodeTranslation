#include<iostream>
#include<string>
using namespace std;
int main(){
  string str;
  bool a=false;
  bool b=false;
  cin>>str;
  if(str[0]=='A'||str[1]=='A'||str[2]=='A'){
    a=true;
  }
  if(str[0]=='B'||str[1]=='B'||str[2]=='B'){
    b=true;
  }
  
  if(a&&b){
    cout<<"Yes"<<endl;
  }else{
    cout<<"No"<<endl;
  }
  return(0);
}