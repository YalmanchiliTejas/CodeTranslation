#include <iostream>
#include <string>
using namespace std;
int main() {
  string s;
  bool a=false;
  cin>>s;
  if(s[0]!=s[1])
    a=true;
  if(s[0]!=s[2])
    a=true;
  if(s[1]!=s[2])
    a=true;
  if(a){
    cout<<"Yes"<<endl;
  }else{
    cout<<"No"<<endl;
  }
}