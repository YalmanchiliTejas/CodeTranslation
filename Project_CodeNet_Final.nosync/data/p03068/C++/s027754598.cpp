#include<iostream>
#include<string>
using namespace std;
int main(){
  int n,a;
  string s;
  cin>>n;
  cin>>s;
  cin>>a;
  for(int i=0;i<n;i++){
    if(s[i]!=s[a-1]){
      cout<<"*";
    }
    else{
      cout<<s[i];
    }
  }
  cout<<endl;
  return 0;
}