#include <bits/stdc++.h>
using namespace std;
int main(){
  char s[3];
  cin>>s[0]>>s[1]>>s[2];
  if(s[0]==s[1]&&s[0]==s[2]&&s[1]==s[2]){
    cout<<"No"<<endl;
    return 0;
  }
  cout<<"Yes"<<endl;
  return 0;
}