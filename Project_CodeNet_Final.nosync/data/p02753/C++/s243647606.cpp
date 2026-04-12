#include<iostream>
using namespace std;
int main(){
  string str;
  cin>>str;
  int flag = 0;
  if(str[0]!=str[1]||str[1]!=str[2])
    cout<<"Yes";
  else
    cout<<"No";
  return 0;
}