#include<iostream>
#include<string>
using namespace std;

int main(){
  string s;
  cin>>s;
  bool a = false;
  bool b = false;
  for(int i=0; s[i]; i++){
    if(s[i]=='A') a = true;
    else b=true;
  }
  if(a && b) cout<<"Yes";
  else cout<<"No";
}