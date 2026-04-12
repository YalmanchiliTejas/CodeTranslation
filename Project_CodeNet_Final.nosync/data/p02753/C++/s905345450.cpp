#include<iostream>
using namespace std;
int main(){
  string s;
  cin>>s;
  char c=s[0];
  if(s[1]!=c or s[2]!=c)
    cout<<"Yes";
  else
    cout<<"No";
  return 0;
}
  